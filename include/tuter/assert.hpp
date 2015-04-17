
#ifndef TUTER_ASSERT_HPP
#define TUTER_ASSERT_HPP

#include <iostream>
//#include <string>

//user-friendly macro
#define tuter_are_equal(X,Y) tuter::run_are_equal(X,Y,__LINE__ ,__FILE__)

namespace tuter
{

//prototypes

template <typename T> void display_assert_values(T, T);
template <typename T> std::string display_single_asert_value(T);
template <typename T> bool are_equal(T, T);
template <typename T> void run_are_equal(T, T, int, const char*);

//prototypes: specializations

template <> bool are_equal<int>(int value, int should_be);
template <> bool are_equal<char>(char value, char should_be);

template <> std::string display_single_asert_value<int>(int value);
template <> std::string display_single_asert_value<float>(float value);

//assert values display

template <typename T> void display_assert_values(T value, T should_be)
{
   std::cout << "  given value was:    " << display_single_asert_value(value) << std::endl
             << "  expected value was: " << display_single_asert_value(should_be) << std::endl;
}

//assert values display helper template

template <typename T> std::string display_single_asert_value(T value)
{
    if(value){} //removes warnings about unused value

    //unknown type, be safe, do not display it.
    //functions which specializes this template will do that job
    return std::string("<display not implemented for that type>");
}

//are_equal template

template <typename T> bool are_equal(T value, T should_be)
{
    std::cout << "assert: template" << std::endl;
    //simply call operator ==
    return (value == should_be);
}

//are_equal function runner

template <typename T> void run_are_equal(T value, T should_be, int line_num, const char* file_path)
{
    if(!are_equal(value,should_be))
    {
        std::cout << "assert are_equal failed" << std::endl
                  << "  in file: " << file_path << std::endl
                  << "  at line: " << line_num << std::endl;
        display_assert_values(value, should_be);
    }
}


} //namespace tuter

#endif // TUTER_ASSERT_HPP

