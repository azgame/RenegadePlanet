// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RPPrototype/RPPrototypeGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRPPrototypeGameMode() {}
// Cross Module References
	RPPROTOTYPE_API UClass* Z_Construct_UClass_ARPPrototypeGameMode_NoRegister();
	RPPROTOTYPE_API UClass* Z_Construct_UClass_ARPPrototypeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_RPPrototype();
// End Cross Module References
	void ARPPrototypeGameMode::StaticRegisterNativesARPPrototypeGameMode()
	{
	}
	UClass* Z_Construct_UClass_ARPPrototypeGameMode_NoRegister()
	{
		return ARPPrototypeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ARPPrototypeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARPPrototypeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_RPPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARPPrototypeGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "RPPrototypeGameMode.h" },
		{ "ModuleRelativePath", "RPPrototypeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARPPrototypeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARPPrototypeGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARPPrototypeGameMode_Statics::ClassParams = {
		&ARPPrototypeGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ARPPrototypeGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARPPrototypeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARPPrototypeGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARPPrototypeGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARPPrototypeGameMode, 649453567);
	template<> RPPROTOTYPE_API UClass* StaticClass<ARPPrototypeGameMode>()
	{
		return ARPPrototypeGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARPPrototypeGameMode(Z_Construct_UClass_ARPPrototypeGameMode, &ARPPrototypeGameMode::StaticClass, TEXT("/Script/RPPrototype"), TEXT("ARPPrototypeGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARPPrototypeGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
