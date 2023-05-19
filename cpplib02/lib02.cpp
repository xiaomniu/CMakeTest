#include "lib02.h"
#include "lib0201.h"

double Sub(double a, double b){
    return a - b + Sub01(a, b);
}