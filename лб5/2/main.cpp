#include <iostream>
#include <cmath>

// Задаем функцию f(x) для разложения
double f(double x) {
    return x * x;
}

// Функция для вычисления коэффициентов a_n в разложении в ряд Фурье
double calculateCoefficient(int n) {
    double sum = 0;
    for (int k = 0; k < 1000; ++k) {
        double x = k * 0.001;
        sum += f(x) * cos(n * x) * 0.001;
    }
    return sum / M_PI;
}

int main() {
    int N = 5; // Порядок разложения
    double a[N];

    for (int n = 0; n < N; ++n) {
        a[n] = calculateCoefficient(n);
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
    std::cout << "...\n";

    return 0;
}
