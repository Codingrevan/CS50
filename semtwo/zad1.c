#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f_1D_sinus(double x);
double f_1D_kwadratowa(double x);
double f_2D_sincos(double x, double y);
double f_2D_2x_plus_cos(double x, double y);
double integrate_1D(double x_0, double x_n, size_t n);
double integrate_2D(double x_0, double x_n, double y_0, double y_n, size_t n);
double integrate(double x_0, double x_n, double y_0, double y_n, size_t  n, double (*f1d)(double), double (*f2d)(double, double));

int main(void){
	double wynik1 = integrate(1.0, 12.0, 0.0, 0.0, 1000, f_1D_sinus, NULL);
	double wynik2 =	integrate(-5.0, 6.0, 0.0, 0.0, 1000, f_1D_kwadratowa, NULL);
	double wynik3 = integrate(-3.14151, 1.0, 1.0, 12.0, 1000, NULL, f_2D_sincos);
	double wynik4 = integrate(-3.1415, 6.0, -10.0, 5.0, 1000, NULL, f_2D_2x_plus_cos);
	printf("%lf\n%lf\n%lf\n%lf\n", wynik1, wynik2, wynik3, wynik4);
	return 0;
}

double f_1D_sinus(double x){
	return sin(x);
}

double f_1D_kwadratowa(double x){
	return x * x + 2 * x - 14.5;
}

double f_2D_sincos(double x, double y){
	return sin(x) * cos(y);
}

double f_2D_2x_plus_cos(double x, double y){
	return 2 * x + cos(y);
}

double integrate_1D(double x_0, double x_n, size_t n){
	double h = (x_n - x_0) / n;
    double s = f_1D_sinus(x_0) + f_1D_sinus(x_n);
    for (size_t i = 1; i < n; i++){
    	double x_i = x_0 + i * h;
        s += 2. * f_1D_sinus(x_i);
    }
    return 0.5 * s * h;
}

double integrate_2D(double x_0, double x_n, double y_0, double y_n, size_t n){
	double h_x = (x_n - x_0) / n;
    double h_y = (y_n - y_0) / n;
    double s = f_2D_sincos(x_0, y_0) + f_2D_sincos(x_0, y_n) + f_2D_sincos(x_n, y_0) + f_2D_sincos(x_n, y_n);
    for (size_t i = 1; i < n; i++){
    	double x_i = x_0 + i * h_x;
        for (size_t j = 1; j < n; j++){
        	double y_j = y_0 + j * h_y;
            s += 4. * f_2D_sincos(x_i, y_j);
        }
        	s += 2. * (f_2D_sincos(x_i, y_0) + f_2D_sincos(x_i, y_n));
            double y_i = y_0 + i * h_y;
            s += 2. * (f_2D_sincos(x_0, y_i) + f_2D_sincos(x_n, y_i));
    }
    return 0.25 * s * h_x * h_y;
}

double integrate(double x_0, double x_n, double y_0, double y_n, size_t  n, double (*f1d)(double), double (*f2d)(double, double)){

	auto double my_integrate_1D(double x_0, double x_n, size_t n, double (*f1d)(double));

	auto double my_integrate_2D(double x_0, double x_n, double y_0, double y_n, size_t n, double (*f2d)(double, double));

	if(f1d != NULL)
		return my_integrate_1D(x_0, x_n, n, f1d);
	else
		return my_integrate_2D(x_0, x_n, y_0, y_n, n, f2d);

	double my_integrate_1D(double x_0, double x_n, size_t n, double (*f1d)(double)){
		double h = (x_n - x_0) / n;
    	double s = f1d(x_0) + f1d(x_n);
    	for (size_t i = 1; i < n; i++){
    		double x_i = x_0 + i * h;
        	s += 2. * f1d(x_i);
   		}
    	return 0.5 * s * h;
	}

	double my_integrate_2D(double x_0, double x_n, double y_0, double y_n, size_t n, double (*f2d)(double, double)){
		double h_x = (x_n - x_0) / n;
   		double h_y = (y_n - y_0) / n;
    	double s = f2d(x_0, y_0) + f2d(x_0, y_n) + f2d(x_n, y_0) + f2d(x_n, y_n);
    	for (size_t i = 1; i < n; i++){
    		double x_i = x_0 + i * h_x;
        	for (size_t j = 1; j < n; j++){
        		double y_j = y_0 + j * h_y;
           		s += 4. * f2d(x_i, y_j);
        	}
        	s += 2. * (f2d(x_i, y_0) + f2d(x_i, y_n));
        	double y_i = y_0 + i * h_y;
        	s += 2. * (f2d(x_0, y_i) + f2d(x_n, y_i));
    	}
    	return 0.25 * s * h_x * h_y;
    }
}
