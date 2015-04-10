
#ifndef TUTER_EXPOSER_HPP
#define TUTER_EXPOSER_HPP

namespace tuter
{

class exposer
{
public:
    static exposer* get_instance();

private:
    static exposer* _instance;

    exposer();
    ~exposer();
};

}

#endif // TUTER_EXPOSER_HPP

