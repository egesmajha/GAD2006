// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "COAGameModeBase.h"

#ifdef AGD_COAGameModeBase_generated_h
#error "COAGameModeBase.generated.h already included, missing '#pragma once' in COAGameModeBase.h"
#endif
#define AGD_COAGameModeBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ACOAGameModeBase *********************************************************
struct Z_Construct_UClass_ACOAGameModeBase_Statics;
AGD_API UClass* Z_Construct_UClass_ACOAGameModeBase_NoRegister();

#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACOAGameModeBase(); \
	friend struct ::Z_Construct_UClass_ACOAGameModeBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AGD_API UClass* ::Z_Construct_UClass_ACOAGameModeBase_NoRegister(); \
public: \
	DECLARE_CLASS2(ACOAGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AGD"), Z_Construct_UClass_ACOAGameModeBase_NoRegister) \
	DECLARE_SERIALIZER(ACOAGameModeBase)


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACOAGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACOAGameModeBase(ACOAGameModeBase&&) = delete; \
	ACOAGameModeBase(const ACOAGameModeBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACOAGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACOAGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACOAGameModeBase) \
	NO_API virtual ~ACOAGameModeBase();


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h_12_PROLOG
#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACOAGameModeBase;

// ********** End Class ACOAGameModeBase ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAGameModeBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
