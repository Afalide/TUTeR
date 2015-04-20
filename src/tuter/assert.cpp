
#include "tuter/assert.hpp"
//#include <string>
#include <sstream>
#include <iostream>

//are_equal template specializations

namespace tuter
{

void display_file_and_line(int line_num, const char* file_path)
{
    std::cout << "  in file: " << file_path << std::endl
              << "  at line: " << line_num << std::endl;
}

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

//assert values display helper template specializations

template <> std::string display_single_asert_value<int>(int value)
{
    std::ostringstream conv;
    conv << value;

    return std::string(conv.str());
}

template <> std::string display_single_asert_value<float>(float value)
{
    std::ostringstream conv;
    conv << value;

    return std::string(conv.str());
}


} //namespace tuter
