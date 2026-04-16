// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AGDCharacter.h"

#ifdef AGD_AGDCharacter_generated_h
#error "AGDCharacter.generated.h already included, missing '#pragma once' in AGDCharacter.h"
#endif
#define AGD_AGDCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AAGDCharacter ************************************************************
#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


struct Z_Construct_UClass_AAGDCharacter_Statics;
AGD_API UClass* Z_Construct_UClass_AAGDCharacter_NoRegister();

#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAGDCharacter(); \
	friend struct ::Z_Construct_UClass_AAGDCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AGD_API UClass* ::Z_Construct_UClass_AAGDCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AAGDCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/AGD"), Z_Construct_UClass_AAGDCharacter_NoRegister) \
	DECLARE_SERIALIZER(AAGDCharacter)


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AAGDCharacter(AAGDCharacter&&) = delete; \
	AAGDCharacter(const AAGDCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAGDCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAGDCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AAGDCharacter) \
	NO_API virtual ~AAGDCharacter();


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_21_PROLOG
#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AAGDCharacter;

// ********** End Class AAGDCharacter **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
