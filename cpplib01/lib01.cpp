#include "lib01.h"
#include "lib0101.h"

double Add(double a, double b) {
    return a + b + Add01(a, b);
}
