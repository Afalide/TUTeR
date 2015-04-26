
#include "tuter/assert/display.hpp"

#include <iostream>

namespace tuter
{

void display_file_and_line(int line_num, const char* file_path)
{
    std::cout << "  in file: " << file_path << std::endl
              << "  at line: " << line_num << std::endl;
}

template <> std::string display_single_asert_value<int>(int value)
{
//    std::ostringstream conv;
//    conv << value;
//
//    return std::string(conv.str());
    return std_convert(value);
}

template <> std::string display_single_asert_value<float>(float value)
{
//    std::ostringstream conv;
//    conv << value;
//
//    return std::string(conv.str());
    return std_convert(value);
}

template <> std::string display_single_asert_value<const char*>(const char* value)
{
//    std::ostringstream conv;
//    conv << value;
//
//    return std::string(conv.str());
    return std_convert(value);
}

} //namespace tuter
