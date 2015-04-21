
#ifndef TUTER_ASSERT_NOT_EQUALS_HPP
#define TUTER_ASSERT_NOT_EQUALS_HPP

#include "tuter/assert.hpp"

#define tassert_not_equals(X,Y) tuter::run_not_equals(X,Y,__LINE__ ,__FILE__)

namespace tuter
{

template <typename T> bool not_equals(T, T);
template <typename T> void run_not_equals(T, T, int, const char*);

template <typename T> bool not_equals(T value, T should_not_be)
{
    return (value != should_not_be);
}

template <typename T> void run_not_equals(T value, T should_not_be, int line_num, const char* file_path)
{
    if(!not_equals(value, should_not_be))
    {
        std::cout << "inequality assert failed" << std::endl;
        display_file_and_line(line_num, file_path);
        display_base_value(value);
        display_compared_value_unexpected(should_not_be);
    }
}

} //namespace tuter

#endif // TUTER_ASSERT_NOT_EQUALS_HPP

