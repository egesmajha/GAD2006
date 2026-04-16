// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAGD_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	AGD_API UFunction* Z_Construct_UDelegateFunction_AGD_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_AGD;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_AGD()
	{
		if (!Z_Registration_Info_UPackage__Script_AGD.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_AGD_OnEnemyDied__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/AGD",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xD842FF8C,
			0xFEF5C9DD,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_AGD.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_AGD.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_AGD(Z_Construct_UPackage__Script_AGD, TEXT("/Script/AGD"), Z_Registration_Info_UPackage__Script_AGD, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xD842FF8C, 0xFEF5C9DD));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
