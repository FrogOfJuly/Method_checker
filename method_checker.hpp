#include <type_traits>

namespace utils {
    template<template<typename> class TypeChecker, typename Type>
    struct is_supported {

        template<typename Type_, typename =void>
        struct type_checker : std::false_type{};

        template<typename Type_>
        struct type_checker<Type_, std::void_t<TypeChecker<Type_>>> : std::true_type{};

        static constexpr bool value = type_checker<Type>::value;
    };
}