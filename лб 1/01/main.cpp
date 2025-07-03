#include <iostream>//для ввода и вывода информации 
#include <cmath>//для синуса
#include <iomanip>//для вывода чисел после запятой
double f(double x) {
double e = 2.718;
return  (sin(x) * sin(x)) / (9 + 0.3 * cos(x)); 
}
//функция
double simpsonIntegration(double a, double b, int n) {
    //расчитываем высоту
double h = (b - a) / n;
//
double sum = f(a) + f(b);

for (int i = 1; i < n; i += 2) {
sum += 4 * f(a + i * h);
}

for (int i = 2; i < n - 1; i += 2) {
sum += 2 * f(a + i * h);
}

return sum * h / 3;
}
double Runge(double a, double b, int n) {
    int kolvo = n;
    double sum = 0.0;
    double J,J1,Jude;
    float itog;
    float eps = 0;
    while (abs(eps) < 0.001) {
        kolvo*=2;
        J = simpsonIntegration(a,b,kolvo);
        Jude = kolvo / 2;
        J1 = simpsonIntegration(a,b,Jude);
        eps = (J-J1)/15;
        if(eps < 0.001) {
            std::cout<<eps<<std::endl;
            break;
            
        }
        
    }
    itog = J + eps;
    std::cout << std::fixed << std::setprecision(50) << itog << std::endl;
    /*
    for(int i = 2; i <= kolvo; i*=2) {
        J = simpsonIntegration(a,b,i);
        if(i == kolvo) {
            int Jude = i / 2;
            for(int j = 2; j <= Jude; j*=2) {
                J1 = simpsonIntegration(a,b,j);
            }
        }
        
        
    }
    
    float eps = (J - J1) / 15;
    std::cout<<eps<<std::endl;
    
    if(eps < 0.001) {
        itog = J + eps;
        
    }
    std::cout << std::fixed << std::setprecision(50) << itog << std::endl;*/
}
int main() {
    double a = 0.0;
    double b = 3.0;
    int n=2;
   
    Runge(a,b,n);
}