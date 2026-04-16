// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "COAAvatar.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCOAAvatar() {}

// ********** Begin Cross Module References ********************************************************
AGD_API UClass* Z_Construct_UClass_ACOAAvatar();
AGD_API UClass* Z_Construct_UClass_ACOAAvatar_NoRegister();
AGD_API UClass* Z_Construct_UClass_ACOABaseCharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_AGD();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACOAAvatar ***************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ACOAAvatar;
UClass* ACOAAvatar::GetPrivateStaticClass()
{
	using TClass = ACOAAvatar;
	if (!Z_Registration_Info_UClass_ACOAAvatar.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("COAAvatar"),
			Z_Registration_Info_UClass_ACOAAvatar.InnerSingleton,
			StaticRegisterNativesACOAAvatar,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ACOAAvatar.InnerSingleton;
}
UClass* Z_Construct_UClass_ACOAAvatar_NoRegister()
{
	return ACOAAvatar::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACOAAvatar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "COAAvatar.h" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mSpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "COAAvatar" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "COAAvatar" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stamina_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStamina_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaminaGainRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaminaDrainRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStaminaDrained_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRunning_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaminaTickInterval_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/COAAvatar.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ACOAAvatar constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mSpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mCamera;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Stamina;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxStamina;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StaminaGainRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StaminaDrainRate;
	static void NewProp_bStaminaDrained_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStaminaDrained;
	static void NewProp_bRunning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRunning;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StaminaTickInterval;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ACOAAvatar constinit property declarations *********************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACOAAvatar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ACOAAvatar_Statics

// ********** Begin Class ACOAAvatar Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_mSpringArm = { "mSpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, mSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mSpringArm_MetaData), NewProp_mSpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_mCamera = { "mCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, mCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mCamera_MetaData), NewProp_mCamera_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_RunSpeed = { "RunSpeed", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, RunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunSpeed_MetaData), NewProp_RunSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_Stamina = { "Stamina", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, Stamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stamina_MetaData), NewProp_Stamina_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_MaxStamina = { "MaxStamina", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, MaxStamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStamina_MetaData), NewProp_MaxStamina_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_StaminaGainRate = { "StaminaGainRate", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, StaminaGainRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaminaGainRate_MetaData), NewProp_StaminaGainRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_StaminaDrainRate = { "StaminaDrainRate", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, StaminaDrainRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaminaDrainRate_MetaData), NewProp_StaminaDrainRate_MetaData) };
void Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bStaminaDrained_SetBit(void* Obj)
{
	((ACOAAvatar*)Obj)->bStaminaDrained = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bStaminaDrained = { "bStaminaDrained", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACOAAvatar), &Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bStaminaDrained_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStaminaDrained_MetaData), NewProp_bStaminaDrained_MetaData) };
void Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bRunning_SetBit(void* Obj)
{
	((ACOAAvatar*)Obj)->bRunning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bRunning = { "bRunning", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACOAAvatar), &Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bRunning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRunning_MetaData), NewProp_bRunning_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACOAAvatar_Statics::NewProp_StaminaTickInterval = { "StaminaTickInterval", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACOAAvatar, StaminaTickInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaminaTickInterval_MetaData), NewProp_StaminaTickInterval_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACOAAvatar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_mSpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_mCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_RunSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_Stamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_MaxStamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_StaminaGainRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_StaminaDrainRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bStaminaDrained,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_bRunning,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACOAAvatar_Statics::NewProp_StaminaTickInterval,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACOAAvatar_Statics::PropPointers) < 2048);
// ********** End Class ACOAAvatar Property Definitions ********************************************
UObject* (*const Z_Construct_UClass_ACOAAvatar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACOABaseCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_AGD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACOAAvatar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACOAAvatar_Statics::ClassParams = {
	&ACOAAvatar::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACOAAvatar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACOAAvatar_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACOAAvatar_Statics::Class_MetaDataParams), Z_Construct_UClass_ACOAAvatar_Statics::Class_MetaDataParams)
};
void ACOAAvatar::StaticRegisterNativesACOAAvatar()
{
}
UClass* Z_Construct_UClass_ACOAAvatar()
{
	if (!Z_Registration_Info_UClass_ACOAAvatar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACOAAvatar.OuterSingleton, Z_Construct_UClass_ACOAAvatar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACOAAvatar.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ACOAAvatar);
ACOAAvatar::~ACOAAvatar() {}
// ********** End Class ACOAAvatar *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h__Script_AGD_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACOAAvatar, ACOAAvatar::StaticClass, TEXT("ACOAAvatar"), &Z_Registration_Info_UClass_ACOAAvatar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACOAAvatar), 3964822584U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h__Script_AGD_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h__Script_AGD_1684731889{
	TEXT("/Script/AGD"),
	Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h__Script_AGD_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h__Script_AGD_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
