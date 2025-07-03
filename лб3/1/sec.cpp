#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return pow(2, x) - 2 * pow(x, 2) + 1;
}

double derivative(double x) {
    return pow(2, x) * log(2) - 4 * x;
}

double newtonMethod(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iteration = 0;
    
    while (fabs(func(x)) > epsilon && iteration < maxIterations) {
        x = x - func(x) / derivative(x);
        iteration++;
    }
    
    return x;
}

int main() {
    double initialGuess = 1.5;  // Начальное предположение
    double epsilon = 0.0001;    // Точность
    int maxIterations = 100;    // Максимальное количество итераций
    
    double init = -2.0;
    double root1 = newtonMethod(initialGuess, epsilon, maxIterations);
    double root = newtonMethod(init, epsilon, maxIterations);
    
    cout << "Root: " << root << endl;
    
    cout<< root1<<endl;
    return 0;
}