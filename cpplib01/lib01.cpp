#include "lib01.h"
#include "lib0101.h"


double Add02(double a, double b) {
    return a + b + Add01(a, b) + Add01(a, b);
}
double Add(double a, double b) {
    return a + b + Add02(a, b);
}
