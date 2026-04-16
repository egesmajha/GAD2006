// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "COAAvatar.h"

#ifdef AGD_COAAvatar_generated_h
#error "COAAvatar.generated.h already included, missing '#pragma once' in COAAvatar.h"
#endif
#define AGD_COAAvatar_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ACOAAvatar ***************************************************************
struct Z_Construct_UClass_ACOAAvatar_Statics;
AGD_API UClass* Z_Construct_UClass_ACOAAvatar_NoRegister();

#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACOAAvatar(); \
	friend struct ::Z_Construct_UClass_ACOAAvatar_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AGD_API UClass* ::Z_Construct_UClass_ACOAAvatar_NoRegister(); \
public: \
	DECLARE_CLASS2(ACOAAvatar, ACOABaseCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AGD"), Z_Construct_UClass_ACOAAvatar_NoRegister) \
	DECLARE_SERIALIZER(ACOAAvatar)


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACOAAvatar(ACOAAvatar&&) = delete; \
	ACOAAvatar(const ACOAAvatar&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACOAAvatar); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACOAAvatar); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACOAAvatar) \
	NO_API virtual ~ACOAAvatar();


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h_12_PROLOG
#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACOAAvatar;

// ********** End Class ACOAAvatar *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_Public_COAAvatar_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
