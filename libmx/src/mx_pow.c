#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double c = n;
    
    if (pow <= 0) return 1;
    for(--pow; pow > 0; pow--)
        n = n * c;
    return n;  
}
