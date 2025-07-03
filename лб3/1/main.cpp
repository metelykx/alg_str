#include <iostream>
#include <cmath>
//функция с формулой
double f(double x) {
    return pow(2,x) - 2*pow(x,2) + 1;
}
double derivative(double x) {
    return log(2) * pow(2, x) - 4 * x;
}
double newtonMethod(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iteration = 0;
    
    while (fabs(f(x)) > epsilon && iteration < maxIterations) {
        x = x - derivative(x) / derivative(x);
        iteration++;
    }
    
    return x;
}
void findroot(double eps,double a, double b) {
    double sui;
    while ((b-a) >= eps) {
        //координата серидины отрезка
        sui = (a+b)/2;
        //если 
        if(f(sui)*f(a) > 0.0) {
            a = sui;
        } else if (f(sui)*f(a)<0.0) {
            b = sui;
        } else {
            break;
        }
    }

    std::cout<<sui<<std::endl;
}
//две точки с точностью epsilon
int main() {
    double eps = 0.0001;
    double a = 0.5;
    double b = 1.5;

    double a1 = 2.0;
    double b1 = 3.0;
    findroot(eps,a,b);
    findroot(eps,a1,b1);


    double root1 = newtonMethod(a,b,eps);
    
    std::cout << "Root: " << root1 << std::endl;

    double root2 = newtonMethod(a1,b1,eps);
    
    std::cout << "Root: " << root2 << std::endl;
}