// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "MyAssetActionUtility.generated.h"

/*
 * Rename the selected assets
 * SearchPatttern - file pattern to search for
 * ReplacePattern - file pattern to replace
 * SearchCase Enum for case checking
 */
UCLASS()
class CPPTOOLAUTO_API UMyAssetActionUtility : public UAssetActionUtility
{
	GENERATED_BODY()

public:
	UFUNCTION(CallInEditor)
		void RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase);
private:
	/*
		Prints a message to the screen
	*/
	void PrintToScreen(FString Message, FColor Color);
	/// <summary>
	/// Give Feedback to the user
	/// </summary>
	void GiveFeedback(FString Method, uint32 Counter);
};