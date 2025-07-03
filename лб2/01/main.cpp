#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для печати матрицы
void printMatrix(const vector<vector<double>>& A) {
    for (const auto& row : A) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

// Функция для применения метода Гаусса-Жордана
vector<double> gaussJordan(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        A[i].push_back(b[i]);
    }

    // Прямой ход
    for (int i = 0; i < n; i++) {
        // Поиск максимального элемента в текущем столбце
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Перестановка строк
        swap(A[maxRow], A[i]);

        // Нормализация строки
        for (int k = i + 1; k <= n; k++) {
            A[i][k] /= A[i][i];
        }
        A[i][i] = 1;

        // Обнуление элементов в столбце
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double c = A[k][i];
                for (int j = i; j <= n; j++) {
                    A[k][j] -= A[i][j] * c;
                }
                A[k][i] = 0;
            }
        }
    }

    // Извлечение решений
    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = A[i][n];
    }

    return x;
}

int main() {
    vector<vector<double>> A = {{4, 1, -1}, {2, 3, 0}, {1, -1, 5}};
    vector<double> b = {7, 7, 11};

    vector<double> x = gaussJordan(A, b);

    cout << "Решение системы: " << endl;
    for (int i = 0; i < x.size(); i = i - 3) {
        cout << "x" << " = " << x[i] << endl;
    }
    for(int i =1; i < x.size(); i = i-2) {
        cout<< "y" << " = "<<x[i]<<endl;
    }
    for(int i = 2; i < x.size(); i = i-4) {
        cout<< "z" << " = "<<x[i]<<endl;
    }

    return 0;
}