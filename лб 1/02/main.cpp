#include <iostream>
#include <cmath>
#include <random>

double integrand(double x) {
    double e = 2.718; // значение числа e
    return 1 / (10+(6*sin(x+e))); 
}

double monte_carlo_integration(int num_points, double a, double b) {
    double s1_1 = 0.0;
    double s2_1 = 0.0;
    double s3_1 = 0.0;
    
    
    double s1_2 = 0.0;
    double s2_2 = 0.0;
    double s3_2 = 0.0;
    
    
    //случайные числа
    //источник случайных чисел
    //для создания объекта который будет использоваться в качетсве источника случаных чисел для инициализации генератора случайных чисел при помощи объекта снизу
    //обеспечивает начальное зерно
    std::random_device rd;
    std::mt19937 gen(rd());
    //создается равномерное распределение dis на интервале от а и б
    std::uniform_real_distribution<double> dis(a, b);

    for (int i = 0; i < num_points; ++i) {
        //генерирует случаыное вещ число из равномерного распределения на заданном интервале
        double x = dis(gen);
        double y = dis(gen);
        double z = dis(gen);
        
        s1_1 += integrand(x);
        s2_1 += integrand(y);
        s3_1 += integrand(z);
        
    }
    double s1 = (s1_1+s2_1+s3_1)/3;
    
     for (int i = 0; i < num_points; ++i) {
        //генерирует случаыное вещ число из равномерного распределения на заданном интервале
        double x = dis(gen);
        double y = dis(gen);
        double z = dis(gen);
        
        s1_2 += integrand(x);
        s2_2 += integrand(y);
        s3_2 += integrand(z);
        
    }
    double s_2 = (pow(s1_2,2)+pow(s2_2,2) + pow(s3_2,2)) / 3;

    double amega = sqrt(abs(s_2 - pow(s1,2)));
    
 double s = s1;

     std::cout<<amega<<std::endl;
     double s4 = s1 - amega;
     std::cout<<s4<<std::endl;
return (b - a) * s / num_points;
}

int main() {
    int num_points = 1000000;
    double a = 0.0;
    double b = 1.0;
    double integral_estimate = monte_carlo_integration(num_points, a, b);
    
   std::cout << "Оценка интеграла: " << integral_estimate << std::endl;
   

    return 0;
}
