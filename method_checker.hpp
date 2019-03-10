#include <type_traits>

namespace utils {
    template<template<typename> class TypeChecker, typename Type>
    struct is_supported {
        struct supported {
        };
        struct not_supported {
        };

        template<typename Type_>
        static supported check(typename std::decay<TypeChecker<Type_>>::type *);

        template<typename Type_>
        static not_supported check(...);

        static constexpr bool value = std::is_same<decltype(check<Type>(nullptr)), supported>::value;
    };
}