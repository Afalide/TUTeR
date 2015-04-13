
#ifndef TUTER_ASSERT_HPP
#define TUTER_ASSERT_HPP

#include <iostream>

#define macro_are_equal(X,Y) run_are_equal(X,Y,__LINE__ ,__FILE__)

//are_equal template

template <typename T> bool are_equal(T value, T should_be)
{
    std::cout << "assert: template" << std::endl;
    //simply call operator ==
    return (value == should_be);
}

//are_equal template specializations

template <> bool are_equal<char>(char value, char should_be)
{
    std::cout << "assert: char" << std::endl;
    //case-sensitive comparizon:
    return value == should_be;

}

template <> bool are_equal<int>(int value, int should_be)
{
    std::cout << "assert: int" << std::endl;
    return value == should_be;
}

//are_equal function runner

template <typename T> void run_are_equal(T value, T should_be, int line_num, const char* file_path)
{
    if(!are_equal(value,should_be))
    {
        std::cout << "assert are_equal failed" << std::endl
                  << "  in file: " << file_path << std::endl
                  << "  at line: " << line_num << std::endl;
    }
}

#endif // TUTER_ASSERT_HPP

