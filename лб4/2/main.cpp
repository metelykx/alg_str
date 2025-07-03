#include <iostream>
#include <cmath>

using namespace std;

// Функции, представляющие систему уравнений
double f1(double x, double y) {
    return cos(x + 0.5) - y - 2;
}

double f2(double x, double y) {
    return sin(y) - 2 * x - 1;
}

// Производные функций по переменным x и y
double df1_dx(double x, double y) {
    return -sin(x + 0.5);
}

double df1_dy(double x, double y) {
    return -1;
}

double df2_dx(double x, double y) {
    return -2;
}

double df2_dy(double x, double y) {
    return cos(y);
}

// Метод простой итерации
void simpleIterationMethod(double x0, double y0, double epsilon) {
    double x = x0;
    double y = y0;
    double x_prev, y_prev;
    int iterations = 0;

    do {
        x_prev = x;
        y_prev = y;

        x = (sin(y_prev) - 1) / 2;
        y = cos(x_prev + 0.5) - 2;

        iterations++;
        
    } while (fabs(x - x_prev) > epsilon || fabs(y - y_prev) > epsilon);

    cout << "Метод простой итерации:" << endl;
    cout << "Корни системы: x = " << x << ", y = " << y << endl;
    cout << "Количество итераций: " << iterations << endl;
}

// Метод Ньютона (минимизация функционала)
void newtonMethod(double x0, double y0, double epsilon) {
    double x = x0;
    double y = y0;
    double x_prev, y_prev;
    int iterations = 0;

    do {
        x_prev = x;
        y_prev = y;

        double detJ = df1_dx(x_prev, y_prev) * df2_dy(x_prev, y_prev) - df1_dy(x_prev, y_prev) * df2_dx(x_prev, y_prev);

        x = x_prev - (f1(x_prev, y_prev) * df2_dy(x_prev, y_prev) - f2(x_prev, y_prev) * df1_dy(x_prev, y_prev)) / detJ;
        y = y_prev - (-f1(x_prev, y_prev) * df2_dx(x_prev, y_prev) + f2(x_prev, y_prev) * df1_dx(x_prev, y_prev)) / detJ;

        iterations++;
  
    } while (fabs(x - x_prev) > epsilon || fabs(y - y_prev) > epsilon);

    cout << "Метод Ньютона:" << endl;
    cout << "Корни системы: x = " << x << ", y = " << y << endl;
    cout << "Количество итераций: " << iterations << endl;
}

int main() {
    double x0 = 0.0; // Начальное приближение для x
    double y0 = 3.0; // Начальное приближение для y
    double epsilon = 0.0001; // Точность

    simpleIterationMethod(x0, y0, epsilon);
    newtonMethod(x0, y0, epsilon);

    return 0;
}