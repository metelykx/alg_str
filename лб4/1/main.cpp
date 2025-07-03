#include <iostream>
#include <vector>

double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double targetX)
{
    double result = 0.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        double term = y[i];

        for (size_t j = 0; j < x.size(); ++j)
        {
            if (i != j)
            {
                term *= (targetX - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main()
{
    std::vector<double> x = { 1, 2, 3, 4, 5 };
    std::vector<double> y = { 1.1, 1.55, 1.9, 2.3, 2.6 };

    double targetX = 2.8;
    double interpolatedY = lagrangeInterpolation(x, y, targetX);

    std::cout << "Interpolated y at x = " << targetX << " is " << interpolatedY << std::endl;

    return 0;
}