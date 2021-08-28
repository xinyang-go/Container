//
// Created by xinyang on 2021/8/27.
//

#ifndef _CONTAINER_HPP_
#define _CONTAINER_HPP_

#include <algorithm>

namespace Utils {
    /**
     * Literal class type that wraps a constant expression string.
     *
     * Uses implicit conversion to allow templates to *seemingly* accept constant strings.
     */
    template<size_t N>
    struct StringLiteral {
        constexpr StringLiteral(const char (&str)[N]) {
            std::copy_n(str, N, value);
        }

        char value[N];
    };

    template<Utils::StringLiteral Key>
    struct KeyMatcher {
    };
}


template<Utils::StringLiteral Key, typename T>
struct Field {
    constexpr static Utils::StringLiteral key = Key;
    using type = T;

    type obj;

    type &r_(Utils::KeyMatcher<Key>) { return obj; }

    const type &c_(Utils::KeyMatcher<Key>) const { return obj; }
};

//
namespace Utils {
    template<typename T>
    constexpr bool is_field = false;

    template<Utils::StringLiteral Key, typename T>
    constexpr bool is_field<Field<Key, T>> = true;
}


template<typename ...Fields>
struct Container : Fields ... {
    static_assert((Utils::is_field<Fields> && ...), "Container must consist of Field.");

    Container() = default;

    explicit Container(typename Fields::type &&...args) : Fields(std::forward<typename Fields::type>(args)) ... {}

    template<Utils::StringLiteral Key>
    auto &r() { return r_(Utils::KeyMatcher<Key>{}); }

    template<Utils::StringLiteral Key>
    const auto &c() const { return c_(Utils::KeyMatcher<Key>{}); }

private:
    using Fields::r_...;
    using Fields::c_...;

    template<Utils::StringLiteral Key>
    auto &r_(Utils::KeyMatcher<Key>) { static_assert(sizeof(Key) != sizeof(Key), "invalid Key!"); }

    template<Utils::StringLiteral Key>
    const auto &c_(Utils::KeyMatcher<Key>) const { static_assert(sizeof(Key) != sizeof(Key), "invalid Key!"); }
};

#endif /* _CONTAINER_HPP_ */
