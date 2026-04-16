// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "COAGameModeBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCOAGameModeBase() {}

// ********** Begin Cross Module References ********************************************************
AGD_API UClass* Z_Construct_UClass_ACOAGameModeBase();
AGD_API UClass* Z_Construct_UClass_ACOAGameModeBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_AGD();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACOAGameModeBase *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ACOAGameModeBase;
UClass* ACOAGameModeBase::GetPrivateStaticClass()
{
	using TClass = ACOAGameModeBase;
	if (!Z_Registration_Info_UClass_ACOAGameModeBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("COAGameModeBase"),
			Z_Registration_Info_UClass_ACOAGameModeBase.InnerSingleton,
			StaticRegisterNativesACOAGameModeBase,
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
	return Z_Registration_Info_UClass_ACOAGameModeBase.InnerSingleton;
}
UClass* Z_Construct_UClass_ACOAGameModeBase_NoRegister()
{
	return ACOAGameModeBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACOAGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "COAGameModeBase.h" },
		{ "ModuleRelativePath", "Public/COAGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class ACOAGameModeBase constinit property declarations *************************
// ********** End Class ACOAGameModeBase constinit property declarations ***************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACOAGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ACOAGameModeBase_Statics
UObject* (*const Z_Construct_UClass_ACOAGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AGD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACOAGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACOAGameModeBase_Statics::ClassParams = {
	&ACOAGameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACOAGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ACOAGameModeBase_Statics::Class_MetaDataParams)
};
void ACOAGameModeBase::StaticRegisterNativesACOAGameModeBase()
{
}
UClass* Z_Construct_UClass_ACOAGameModeBase()
{
	if (!Z_Registration_Info_UClass_ACOAGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACOAGameModeBase.OuterSingleton, Z_Construct_UClass_ACOAGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACOAGameModeBase.OuterSingleton;
}
ACOAGameModeBase::ACOAGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ACOAGameModeBase);
ACOAGameModeBase::~ACOAGameModeBase() {}
// ********** End Class ACOAGameModeBase ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h__Script_AGD_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACOAGameModeBase, ACOAGameModeBase::StaticClass, TEXT("ACOAGameModeBase"), &Z_Registration_Info_UClass_ACOAGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACOAGameModeBase), 4074646941U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h__Script_AGD_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h__Script_AGD_2237671488{
	TEXT("/Script/AGD"),
	Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h__Script_AGD_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h__Script_AGD_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
