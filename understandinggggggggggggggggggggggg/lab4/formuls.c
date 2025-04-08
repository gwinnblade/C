#include <math.h>

double calc_perimeter(double a, double b, double c) {
	return a+b+c;
}

double calc_area(double a, double b, double c) {
	double p = (a+b+c) / 2; // формула площади по полупериметру
	return sqrt(p*(p-a) * (p-b) * (p-c));
}
