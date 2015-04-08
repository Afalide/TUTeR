
#ifndef TUTER_SYMBOLS_HPP
#define TUTER_SYMBOLS_HPP

#include <vector>

#define TUTER_DECLARE_FN_NAME      _tuter_create_test_areas
#define TUTER_DECLARE_TESTS_BEGIN  std::vector<stuff*> TUTER_DECLARE_FN_NAME () { std::vector<stuff*> __vec;
#define TUTER_DECLARE_TESTS_END    return __vec; }
#define TUTER_DECLARE(X)           __vec.push_back(new X );

#endif // TUTER_SYMBOLS_HPP
