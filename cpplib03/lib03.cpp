#include "lib03.h"
#include "lib01.h"
double Mul(double a, double b){
    return a * b * Add(a, b);
}