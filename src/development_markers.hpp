// src/development_markers.hpp

#ifndef PHYSICALLY_BASED_ANIMATIONS_VULKAN_SRC_DEVELOPMENT_MARKERS_HPP
#define PHYSICALLY_BASED_ANIMATIONS_VULKAN_SRC_DEVELOPMENT_MARKERS_HPP

#pragma once

// Internals
// Externals
// Standard Library
#include <type_traits>
//

#if defined(mut)
#    error "mut marker macro is already defined"
#endif

#if defined(cpy)
#    error "cpy marker macro is already defined"
#endif

#if defined(def)
#    error "def marker macro is already defined"
#endif

#if defined(__clang__)
#    define mut [[clang::annotate("mut")]]
#    define cpy [[clang::annotate("cpy")]]
#else
#    define mut
#    define cpy
#endif

#define def auto

namespace physically_based_animations_vulkan
{
template <typename T>
[[nodiscard]] constexpr def copy(const T& value) -> std::remove_cvref_t<T>
{
    return value;
}
}  // namespace physically_based_animations_vulkan

#endif  // PHYSICALLY_BASED_ANIMATIONS_VULKAN_SRC_DEVELOPMENT_MARKERS_HPP
