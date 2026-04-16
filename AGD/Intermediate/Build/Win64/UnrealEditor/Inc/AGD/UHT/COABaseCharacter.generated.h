// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "COABaseCharacter.h"

#ifdef AGD_COABaseCharacter_generated_h
#error "COABaseCharacter.generated.h already included, missing '#pragma once' in COABaseCharacter.h"
#endif
#define AGD_COABaseCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ACOABaseCharacter ********************************************************
struct Z_Construct_UClass_ACOABaseCharacter_Statics;
AGD_API UClass* Z_Construct_UClass_ACOABaseCharacter_NoRegister();

#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COABaseCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACOABaseCharacter(); \
	friend struct ::Z_Construct_UClass_ACOABaseCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AGD_API UClass* ::Z_Construct_UClass_ACOABaseCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(ACOABaseCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AGD"), Z_Construct_UClass_ACOABaseCharacter_NoRegister) \
	DECLARE_SERIALIZER(ACOABaseCharacter)


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COABaseCharacter_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACOABaseCharacter(ACOABaseCharacter&&) = delete; \
	ACOABaseCharacter(const ACOABaseCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACOABaseCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACOABaseCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACOABaseCharacter) \
	NO_API virtual ~ACOABaseCharacter();


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COABaseCharacter_h_9_PROLOG
#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COABaseCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COABaseCharacter_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COABaseCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACOABaseCharacter;

// ********** End Class ACOABaseCharacter **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COABaseCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
