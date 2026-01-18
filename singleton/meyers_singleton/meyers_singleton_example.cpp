#include "meyers_singleton.hpp"
#include <iostream>

int main() {
    meyers_singleton::getInstance().setI(42);
    const auto i = meyers_singleton::getInstance().getI();
        //expected i = 42

    std::cout << "i: " << meyers_singleton::getInstance().getI() << "\n"
                << "d: "<< meyers_singleton::getInstance().getD() << "\n";

    return 0;
}