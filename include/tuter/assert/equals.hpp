
#ifndef TUTER_ASSERT_EQUALS_HPP
#define TUTER_ASSERT_EQUALS_HPP

#include "tuter/assert.hpp"

#define tuter_assert_equals(X,Y) tuter::run_equals(X,Y,__LINE__ ,__FILE__)

namespace tuter
{

template <typename T> bool equals(T, T);
template <typename T> void run_equals(T, T, int, const char*);

//template <> bool equals<char>(char value, char should_be);

template <typename T> bool equals(T value, T should_be)
{
    return (value == should_be);
}

template <typename T> void run_equals(T value, T should_be, int line_num, const char* file_path)
{
    if(!equals(value, should_be))
    {
        std::cout << "equality assert failed" << std::endl;
        display_file_and_line(line_num, file_path);
        display_base_value(value);
        display_compared_value_expected(should_be);
    }
}

} //namespace tuter

#endif // TUTER_ASSERT_EQUALS_HPP

