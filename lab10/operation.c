#include "operation.h"
#include <stdarg.h>

double main_sum(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int sum = 0;
    
    for(int i=0; i<count; i++) {
        sum = sum + va_arg(args, int);
    }
    va_end(args);
    return sum;
}

double main_max(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int max = va_arg(args, int);
    
    for(int i=1; i<count; i++) {
        int x = va_arg(args, int);
        if(x > max) max = x;
    }
    
    va_end(args);
    return max;
}

double main_min(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int min = va_arg(args, int);
    
    for(int i=1; i<count; i++) {
        int x = va_arg(args, int);
        if(x < min) min = x;
    }
    
    va_end(args);
    return min;
}

double main_avg(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int sum = 0;
    
    for(int i=0; i<count; i++) {
        sum = sum + va_arg(args, int);
    }
    
    va_end(args);
    return (double)sum / count;
}

