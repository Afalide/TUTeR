
#ifndef TUTER_EXPOSE_HPP
#define TUTER_EXPOSE_HPP

#include <vector>
#include "tuter/caller.hpp"

// TUTER DECLARE

#define tuter_declare(X) \
class caller_##X : public tuter::caller<X> \
{ \
public: \
    caller_##X(); \
    virtual ~caller_##X(); \
}; \
caller_##X::~caller_##X(){} \
caller_##X::caller_##X() \
{

#define tuter_add(X) add_function(& X);

#define tuter_declare_end }

// TUTER EXPORT

#define TUTER_EXPOSE_FN         expose_tests
#define TUTER_EXPOSE_FN_QUOTES  "expose_tests"

#define tuter_export \
extern "C" \
{ \
    namespace tuter \
    { \
        __declspec(dllexport) std::vector<tuter::test*> TUTER_EXPOSE_FN(); \
        std::vector<tuter::test*> TUTER_EXPOSE_FN () \
        { \
            std::vector<tuter::test*> vec; \

#define tuter_expose(X) \
            vec.push_back(new caller_##X);

#define tuter_export_end \
            return vec; \
        } \
    } \
}

#endif // TUTER_EXPOSE_HPP

