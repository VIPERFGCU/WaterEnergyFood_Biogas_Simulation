#include "SimBackend/SB_PlantBedFunctions.h"

/**
 * See header file for documentation.
 */
void USB_PlantBedFunctions::getGrowthAmount(
	// Input parameters.
	const float deltaTime,
	const float liquidConsumptionCoeff,
	const float plantGrowthCoeff,
    const float plantCount, // float for simplicity in calculations - Jordan
	const float liquidAvailable,
	const float currentPlantHeight,
	const float maxPlantHeight,
	// Output parameters.
	float& liquidConsumed,
	float& plantGrowthAmount
) {
    // Convert input rate (days) to seconds for calculations
    double fullPlantGrowthCoeff = plantGrowthCoeff / (3600.0 * 24.0 * 6); // Factor of 6 to reduce plant growth speed to be where it should  be
    double fullLiquidConsumptionCoeff = liquidConsumptionCoeff / (3600.0 * 24.0);

    // Create temporary 64-bit floating point numbers for the math
    double liquidConsumedDouble = 0.0;
    double plantGrowthAmountDouble = 0.0;
	// Ensure there is available liquid and growth height.
	if (liquidAvailable > 0.0 && currentPlantHeight < maxPlantHeight) {
		// Calculate coefficient ratio (i.e. liquid gallons required per foot of plant growth per plant).
		double liquidPerPlant = fullLiquidConsumptionCoeff / fullPlantGrowthCoeff;

		// Calculate prospective output parameters.
		liquidConsumedDouble = deltaTime * fullLiquidConsumptionCoeff * plantCount;
		plantGrowthAmountDouble = deltaTime * fullPlantGrowthCoeff;

		// Check if there is enough available liquid.
		if (liquidConsumedDouble > liquidAvailable) {
			// Reduce the liquid consumption.
			liquidConsumedDouble = liquidAvailable;
			// Since the liquid consumption was reduced, the plant growth must also be
			// reduced using the appropriate ratio.
			plantGrowthAmountDouble = liquidConsumed / liquidPerPlant / plantCount;
		}

		// Check if there is enough available height.
		if (currentPlantHeight + plantGrowthAmountDouble > maxPlantHeight) {
			// Reduce the plant growth.
			plantGrowthAmountDouble = maxPlantHeight - currentPlantHeight;
			// Since plant growth was reduced, the liquid consumed must also be reduced
			// using the appropriate ratio.
			liquidConsumedDouble = plantGrowthAmountDouble * liquidPerPlant * plantCount;
		}
	}
	else {
		// If there is either no more liquid to consume or no more height to grow,
		// do not consume any liquid and do not grow the plants at all.
		liquidConsumedDouble = 0.0;
		plantGrowthAmountDouble = 0.0;
	}

	// Truncate results back to 32-bit floating point numbers for Unreal Engine
	plantGrowthAmount = plantGrowthAmountDouble;
	liquidConsumed = liquidConsumedDouble;

	return;
}
