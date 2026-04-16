// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AGDGameMode.h"

#ifdef AGD_AGDGameMode_generated_h
#error "AGDGameMode.generated.h already included, missing '#pragma once' in AGDGameMode.h"
#endif
#define AGD_AGDGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AAGDGameMode *************************************************************
struct Z_Construct_UClass_AAGDGameMode_Statics;
AGD_API UClass* Z_Construct_UClass_AAGDGameMode_NoRegister();

#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAGDGameMode(); \
	friend struct ::Z_Construct_UClass_AAGDGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AGD_API UClass* ::Z_Construct_UClass_AAGDGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AAGDGameMode, AGameModeBase, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AGD"), Z_Construct_UClass_AAGDGameMode_NoRegister) \
	DECLARE_SERIALIZER(AAGDGameMode)


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AAGDGameMode(AAGDGameMode&&) = delete; \
	AAGDGameMode(const AAGDGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAGDGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAGDGameMode); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AAGDGameMode) \
	NO_API virtual ~AAGDGameMode();


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDGameMode_h_12_PROLOG
#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AAGDGameMode;

// ********** End Class AAGDGameMode ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
