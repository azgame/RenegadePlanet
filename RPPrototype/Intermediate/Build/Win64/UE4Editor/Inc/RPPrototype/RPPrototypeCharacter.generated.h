// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RPPROTOTYPE_RPPrototypeCharacter_generated_h
#error "RPPrototypeCharacter.generated.h already included, missing '#pragma once' in RPPrototypeCharacter.h"
#endif
#define RPPROTOTYPE_RPPrototypeCharacter_generated_h

#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_SPARSE_DATA
#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_RPC_WRAPPERS
#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARPPrototypeCharacter(); \
	friend struct Z_Construct_UClass_ARPPrototypeCharacter_Statics; \
public: \
	DECLARE_CLASS(ARPPrototypeCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RPPrototype"), NO_API) \
	DECLARE_SERIALIZER(ARPPrototypeCharacter)


#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_INCLASS \
private: \
	static void StaticRegisterNativesARPPrototypeCharacter(); \
	friend struct Z_Construct_UClass_ARPPrototypeCharacter_Statics; \
public: \
	DECLARE_CLASS(ARPPrototypeCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RPPrototype"), NO_API) \
	DECLARE_SERIALIZER(ARPPrototypeCharacter)


#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARPPrototypeCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARPPrototypeCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARPPrototypeCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARPPrototypeCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARPPrototypeCharacter(ARPPrototypeCharacter&&); \
	NO_API ARPPrototypeCharacter(const ARPPrototypeCharacter&); \
public:


#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARPPrototypeCharacter(ARPPrototypeCharacter&&); \
	NO_API ARPPrototypeCharacter(const ARPPrototypeCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARPPrototypeCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARPPrototypeCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARPPrototypeCharacter)


#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ARPPrototypeCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ARPPrototypeCharacter, FollowCamera); }


#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_10_PROLOG
#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_SPARSE_DATA \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_RPC_WRAPPERS \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_INCLASS \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_SPARSE_DATA \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_INCLASS_NO_PURE_DECLS \
	RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RPPROTOTYPE_API UClass* StaticClass<class ARPPrototypeCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID RPPrototype_Source_RPPrototype_RPPrototypeCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
