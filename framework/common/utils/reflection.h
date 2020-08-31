#include <string>
#include <type_traits>

#define GEN_MEMBER_FUNC_CHECK_CLASS(func_identifier, func_return_type, func_name, ...) \
    struct HasMemberFuncInspector_##func_identifier##_##func_return_type##_##func_name{ \
        template < \
            typename T, \
            typename U = typename std::decay_t<decltype(std::declval<T>().func_name(__VA_ARGS__))>, \
            typename = typename std::enable_if_t<std::is_same_v<func_return_type, U>> \
        > \
        static std::true_type Check(int); \
        template <typename> \
        static std::false_type Check(...); \
    }; \
    template <typename T> \
    struct HasMemberFunc_##func_identifier##_##func_return_type##_##func_name : public decltype(HasMemberFuncInspector_##func_identifier##_##func_return_type##_##func_name::Check<T>(0)){};


#define GEN_MEMBER_CHECK_CLASS(member_type, member_name) \
    struct HasMemberInspector_##member_type##_##member_name { \
        template < \
            typename T, \
            typename U = typename std::decay_t<decltype(T::member_name)>, \
            typename = typename std::enable_if_t<std::is_same_v<member_type, U>> \
        > \
        static std::true_type Check(int); \
        template <typename> \
        static std::false_type Check(...); \
    }; \
    template <typename T> \
    struct HasMember_##member_type##_##member_name : public decltype(HasMemberInspector_##member_type##_##member_name::Check<T>(0)){};