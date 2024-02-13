// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210806.1

#pragma once
#ifndef WINRT_Windows_System_Diagnostics_Telemetry_1_H
#define WINRT_Windows_System_Diagnostics_Telemetry_1_H
#include "winrt/impl/Windows.System.Diagnostics.Telemetry.0.h"
WINRT_EXPORT namespace winrt::Windows::System::Diagnostics::Telemetry
{
    struct __declspec(empty_bases) IPlatformTelemetryClientStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPlatformTelemetryClientStatics>
    {
        IPlatformTelemetryClientStatics(std::nullptr_t = nullptr) noexcept {}
        IPlatformTelemetryClientStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlatformTelemetryRegistrationResult :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPlatformTelemetryRegistrationResult>
    {
        IPlatformTelemetryRegistrationResult(std::nullptr_t = nullptr) noexcept {}
        IPlatformTelemetryRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlatformTelemetryRegistrationSettings :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPlatformTelemetryRegistrationSettings>
    {
        IPlatformTelemetryRegistrationSettings(std::nullptr_t = nullptr) noexcept {}
        IPlatformTelemetryRegistrationSettings(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
