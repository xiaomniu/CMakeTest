
#include <iostream>
#include "lib03.h"
#include "lib04.h"

int main(int argc, const char** argv) {
    double a = 16;
    double b = 3;

#ifdef HBLJ_LOG
    std::cout << " HBLJ_LOG " << std::endl;
#endif

    
    std::cout << "Mul: "<< Mul(a, b) << std::endl;
    std::cout << "Dev: "<< Dev(a, b) << std::endl;

    return 1;
}