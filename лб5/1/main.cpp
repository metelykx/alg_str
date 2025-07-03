#include <iostream>
#include <cmath>

// Задаем функцию f(x) для разложения
double f(double x) {
    return x*x;
}

// Функция для численного интегрирования методом Симпсона
double integrateSimpson(double a1, double b, int n, int order) {
    double h = (b - a1) / n;
    double sum = 0;

    for (int i = 0; i <= n; ++i) {
        double x = a1 + i * h;
        double coeff = f(x) * cos(order * x);
        
        if (i == 0 || i == n) {
            sum += coeff;
        } else if (i % 2 == 0) {
            sum += 2 * coeff;
        } else {
            sum += 4 * coeff;
        }
    }

    return sum * h / 3;
}

double integrateSimpson1(double a1, double b, int n, int order) {
    double h = (b - a1) / n;
    double sum = 0;

    for (int i = 0; i <= n; ++i) {
        double x = a1 + i * h;
        double coeff = f(x) * sin(order * x);
        
        if (i == 0 || i == n) {
            sum += coeff;
        } else if (i % 2 == 0) {
            sum += 2 * coeff;
        } else {
            sum += 4 * coeff;
        }
    }

    return sum * h / 3;
}

// Функция для вычисления коэффициентов a_n в разложении в ряд Фурье
double calculateCoefficient(int n,double a1, double b) {
    return integrateSimpson(a1, b, 1000, n) / a1;
}
double calculateCoef(int n, double a1, double b) {
    return integrateSimpson1(a1,b,1000,n)/a1;
}

int main() {
    int N = 5; // Порядок разложения
    double a[N];
    double a1 = 1.0;
    double b = 2.0;
    double b1[N];

    for (int n = 0; n < N; ++n) {
        a[n] = calculateCoefficient(n,a1,b);
        std::cout << "a_" << n << " = " << a[n] << std::endl;
    }

    // Вывод разложения в ряд Фурье
    std::cout << "f(x) = ";
    for (int n = 0; n < N; ++n) {
        if (n == 0) {
            std::cout << a[n] / 2 << " + ";
        } else {
            std::cout << a[n] << " * cos(" << n << "x) + ";
        }
    }
    for (int n = 0; n < N; ++n) {
        if (n == 0) {
            std::cout << b1[n] / 2 << " + ";
        } else {
            std::cout << b1[n] << " * sin(" << n << "x) + ";
        }
    }
for (int n = 0; n < N; ++n) {
        b1[n] = calculateCoefficient(n,a1,b);
        std::cout << "b_" << n << " = " << b1[n] << std::endl;
    }



    return 0;
}
