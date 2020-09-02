
#include "CoreMinimal.h"
#include "AssetActionUtility.h"

#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "Sound/SoundWave.h"
#include "Engine/Texture.h"
#include "Blueprint/UserWidget.h"
#include "Animation/MorphTarget.h"
#include "Components/SkeletalMeshComponent.h"

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
	
	/// <summary>
	/// Checks if a texture's dimensions are a power of two
	/// </summary>
	UFUNCTION(CallInEditor)
		void CheckPowerOfTwo();

	//asset renamer
	UFUNCTION(CallInEditor)
		void AddPrefixes();
	UFUNCTION(CallInEditor)
		void CleanupFolder(FString ParentFolder = FString("/Game"));
private:

	const TMap<UClass*, FString> PrefixMap = {
		{UBlueprint::StaticClass(), TEXT("BP_")},
		{UStaticMesh::StaticClass(), TEXT("SM_")},
		{UMaterial::StaticClass(), TEXT("M_")},
		{UMaterialInstance::StaticClass(), TEXT("MI_")},
		{UMaterialFunctionInterface::StaticClass(), TEXT("MF_")},
		{UParticleSystem::StaticClass(), TEXT("PS_")},
		{USoundCue::StaticClass(), TEXT("SC_")},
		{USoundWave::StaticClass(), TEXT("S_")},
		{UTexture::StaticClass(), TEXT("T_")},
		{UTexture2D::StaticClass(), TEXT("T_")},
		{UUserWidget::StaticClass(), TEXT("UW_")},
		{UMorphTarget::StaticClass(), TEXT("MT_")},
		{USkeletalMeshComponent::StaticClass(), TEXT("SK_")}
	};
	//return 1 is number is a power of 2
	bool IsPowerOfTwo(int32 NumberToCheck);

	/*
		Prints a message to the screen
	*/
	void PrintToScreen(FString Message, FColor Color);
	/// <summary>
	/// Give Feedback to the user
	/// </summary>
	void GiveFeedback(FString Method, uint32 Counter);
};
