
#ifndef TUTER_RUNNER_HPP
#define TUTER_RUNNER_HPP

#include "tuter/test.hpp"

#include <vector>

namespace tuter
{

class runner
{
public:
    runner();
    ~runner();
    void run_all(const char* so_path);

private:

    typedef std::vector<test*> (*expose_tests_fn)();

    bool _search_exposer();
};

}

#endif // TUTER_RUNNER_HPP

