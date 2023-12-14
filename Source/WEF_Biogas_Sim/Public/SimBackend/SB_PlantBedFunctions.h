#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SB_PlantBedFunctions.generated.h"

/**
 * Author: Garrett Fairburn
 * Created: 2019-07-01
 *
 * This class provides static, blueprint-callable functions to assist the SB_PlantBed actor component class.
 */
UCLASS()
class WEF_BIOGAS_SIM_API USB_PlantBedFunctions : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

		/**
		* Assuming parameters from an SB_PlantBed and SB_LiquidContainer component that belong to the same actor,
		* calculate how much liquid to consume from the SB_LiquidContainer and how many feet the plants should grow
		* in the SB_PlantBed for a given frame. Factors in how nutrient rich the water is and adjusted plant growth accordingly
		*
		* This functionality was implemented as a static C++ function rather than a blueprint method of SB_PlantBed
		* because the calculation involves nested if statments that would be unnecessarily difficult to implement
		* using blueprints. Additionally, 64-bit floating-point precision is needed for several of the calculations.
		*
		* INPUTS:
		*  deltaTime: the time (in seconds) that has elapsed since the previous frame
		*  liquidConsumptionCoeff: the amount of liquid (in gallons) to consume per day per plant
		*  nutrientUsageCoeff: the amount of nutrients consumed per gallon of water
		*  plantGrowthCoeff: the height (in feet) that the plants should grow per day
		*  plantCount: how many plants to calculate for
		*  liquidAvailable: the amount of liquid (in gallons) that the SB_LiquidContainer has
		*  currentPlantHeight: the current height (in feet) of the SB_PlantBed's plants
		*  maxPlantHeight: the maximum allowable height (in feet) of the SB_PlantBed's plants
		*  nutrientRatio: how nutrient rich the water is, affecting how fast plants grow (less than 1 reduces speed, 1 is base speed, and 1.05 is maximum effect)
		*
		* OUTPUTS:
		*  liquidConsumed: the amount of liquid (in gallons) to consume for this frame
		*  plantGrowthAmount: the height (in feet) that the plants should grow for this frame
		*  nutrientConsumed: how much of the nutrients from the water has been consumed
		*/
		UFUNCTION(BlueprintCallable, Category = "SB_PlantBedFunctions")
		static void getGrowthAmount(
			// Input parameters.
			const float deltaTime,
			const float liquidConsumptionCoeff,
			const float nutrientUsageCoeff,
			const float plantGrowthCoeff,
		     const float plantCount,
			const float liquidAvailable,
			const float currentPlantHeight,
			const float maxPlantHeight,
			 const float nutrientRatio,
			// Output parameters.
			float& liquidConsumed,
			float& plantGrowthAmount,
			float& nutrientConsumed
		);
};
