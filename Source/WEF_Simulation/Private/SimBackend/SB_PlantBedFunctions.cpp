#include "SB_PlantBedFunctions.h"

/**
 * See header file for documentation.
 */
void USB_PlantBedFunctions::getGrowthAmount(
	// Input parameters.
	const float deltaTime,
	const float liquidConsumptionCoeff,
	const float plantGrowthCoeff,
	const float liquidAvailable,
	const float currentPlantHeight,
	const float maxPlantHeight,
	// Output parameters.
	float& liquidConsumed,
	float& plantGrowthAmount
) {
	// Ensure there is available liquid and growth height.
	if (liquidAvailable > 0.0 && currentPlantHeight < maxPlantHeight) {
		// Calculate coefficient ratio (i.e. liquid gallons required per foot of plant growth).
		float liquidPerPlant = liquidConsumptionCoeff / plantGrowthCoeff;

		// Calculate prospective output parameters.
		liquidConsumed = deltaTime * liquidConsumptionCoeff;
		plantGrowthAmount = deltaTime * plantGrowthCoeff;

		// Check if there is enough available liquid.
		if (liquidConsumed > liquidAvailable) {
			// Reduce the liquid consumption.
			liquidConsumed = liquidAvailable;
			// Since the liquid consumption was reduced, the plant growth must also be
			// reduced using the appropriate ratio.
			plantGrowthAmount = liquidConsumed / liquidPerPlant;
		}

		// Check if there is enough available height.
		if (currentPlantHeight + plantGrowthAmount > maxPlantHeight) {
			// Reduce the plant growth.
			plantGrowthAmount = maxPlantHeight - currentPlantHeight;
			// Since plant growth was reduced, the liquid consumed must also be reduced
			// using the appropriate ratio.
			liquidConsumed = plantGrowthAmount * liquidPerPlant;
		}
	} else {
		// If there is either no more liquid to consume or no more height to grow,
		// do not consume any liquid and do not grow the plants at all.
		liquidConsumed = 0.0;
		plantGrowthAmount = 0.0;
	}

	return;
}