// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwinStickShooter/TwinStickShooterGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTwinStickShooterGameModeBase() {}
// Cross Module References
	TWINSTICKSHOOTER_API UClass* Z_Construct_UClass_ATwinStickShooterGameModeBase_NoRegister();
	TWINSTICKSHOOTER_API UClass* Z_Construct_UClass_ATwinStickShooterGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TwinStickShooter();
// End Cross Module References
	void ATwinStickShooterGameModeBase::StaticRegisterNativesATwinStickShooterGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATwinStickShooterGameModeBase_NoRegister()
	{
		return ATwinStickShooterGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TwinStickShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TwinStickShooterGameModeBase.h" },
		{ "ModuleRelativePath", "TwinStickShooterGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwinStickShooterGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics::ClassParams = {
		&ATwinStickShooterGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATwinStickShooterGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATwinStickShooterGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATwinStickShooterGameModeBase, 1195956069);
	template<> TWINSTICKSHOOTER_API UClass* StaticClass<ATwinStickShooterGameModeBase>()
	{
		return ATwinStickShooterGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATwinStickShooterGameModeBase(Z_Construct_UClass_ATwinStickShooterGameModeBase, &ATwinStickShooterGameModeBase::StaticClass, TEXT("/Script/TwinStickShooter"), TEXT("ATwinStickShooterGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATwinStickShooterGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
