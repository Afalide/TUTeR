
#ifndef TUTER_ASSERT_DISPLAY_HPP
#define TUTER_ASSERT_DISPLAY_HPP

#include <iostream>

namespace tuter
{

//internal use prototypes

void display_file_and_line(int line_num, const char* file_path);
template <typename T> void display_base_value(T);
template <typename T> void display_compared_value_expected(T);
template <typename T> void display_compared_value_unexpected(T);

//specializable prototypes templates

template <typename T> std::string display_single_asert_value(T);

//prototypes specializations

template <> std::string display_single_asert_value<int>(int value);
template <> std::string display_single_asert_value<float>(float value);

//assert values display

template <typename T> void display_base_value(T value)
{
    std::cout << "  given value was:      " << display_single_asert_value(value) << std::endl;
}

template <typename T> void display_compared_value_expected(T value)
{
    std::cout << "  expected value was:   " << display_single_asert_value(value) << std::endl;
}

template <typename T> void display_compared_value_unexpected(T value)
{
    std::cout << "  unexpected value was: " << display_single_asert_value(value) << std::endl;
}

//assert values display: type description helper template

template <typename T> std::string display_single_asert_value(T value)
{
    (void) value; //removes warnings about unused value

    //unknown type, be safe, do not display it.
    //functions which specializes this template will do that job
    return std::string("<display not implemented for that type>");
}

} //namespace tuter

#endif // TUTER_ASSERT_DISPLAY_HPP

