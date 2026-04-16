// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AGDPlayerController.h"

#ifdef AGD_AGDPlayerController_generated_h
#error "AGDPlayerController.generated.h already included, missing '#pragma once' in AGDPlayerController.h"
#endif
#define AGD_AGDPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AAGDPlayerController *****************************************************
struct Z_Construct_UClass_AAGDPlayerController_Statics;
AGD_API UClass* Z_Construct_UClass_AAGDPlayerController_NoRegister();

#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDPlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAGDPlayerController(); \
	friend struct ::Z_Construct_UClass_AAGDPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AGD_API UClass* ::Z_Construct_UClass_AAGDPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AAGDPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/AGD"), Z_Construct_UClass_AAGDPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AAGDPlayerController)


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDPlayerController_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAGDPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AAGDPlayerController(AAGDPlayerController&&) = delete; \
	AAGDPlayerController(const AAGDPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAGDPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAGDPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAGDPlayerController) \
	NO_API virtual ~AAGDPlayerController();


#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDPlayerController_h_16_PROLOG
#define FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDPlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDPlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDPlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AAGDPlayerController;

// ********** End Class AAGDPlayerController *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_PC_Documents_Unreal_Projects_AGD_Source_AGD_AGDPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
