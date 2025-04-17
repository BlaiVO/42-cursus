#include <iostream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    srand(time(0));
    switch (rand() % 3)
    {
        case 0:
            return new A();
            break;
        case 1:
            return new B();
            break;
        case 2:
            return new C();
            break;
    }
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Object is type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object is type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object is type C" << std::endl;
    else
        std::cout << "Object is not A, B or C" << std::endl;
}

void identify(Base &p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "Object is type A" << std::endl;
    }
    catch (...) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "Object is type B" << std::endl;
        }
        catch (...) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "Object is type C" << std::endl;
            }
            catch (...) {
                std::cout << "Object is not A, B or C" << std::endl;
            }
        }
    }
}

int main()
{
    Base *base = generate();
    Base *base2 = new Base();
    identify(base);
    identify(*base);

    identify(base2);
    identify(*base2);

    delete base;
    delete base2;

    return 0;
}