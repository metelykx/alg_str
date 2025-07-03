#include <iostream>
#include <cmath>
#include <random>

double integrand(double x) {
    double e = 2.718; // значение числа e
    return 1.0 / (10 + 6 * sin(x + e));
}

double monte_carlo_integration(int num_points, double a, double b) {
    double integral_sum = 0.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(a, b);

    for (int i = 0; i < num_points; ++i) {
        double x = dis(gen);
        integral_sum += integrand(x);
    }

    return (b - a) * integral_sum / num_points;
}

int main() {
    int num_points = 1000000;
    double a = 0.0;
    double b = 1.6;
    double integral_estimate = monte_carlo_integration(num_points, a, b);
    std::cout << "Оценка интеграла: " << integral_estimate << std::endl;

    return 0;
}
