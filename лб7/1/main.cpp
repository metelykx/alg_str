#include <iostream>//подключение для вывода
#include <vector>//подключения для динамических массивов
#include <algorithm>
//структура представляет собой предмет с весом и ценностью
struct Item {
    int weight;
    int value;
};
//принимает сколько можно внести в рюкзак и вектор айтамов в качестве данных 
int knapsack(int capacity, const std::vector<Item>& items) {
    //кол-во предметов
    int n = items.size();
    //dp - это двумерный вектор, который будет хранить максимальную ценность, которую можно достичь для каждого веса от 1 до capacity и для каждого предмета от 1 до n.
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));
//Внешний цикл перебирает предметы, от 1 до n.
    for (int i = 1; i <= n; i++) {
        //Внутренний цикл перебирает веса, от 1 до capacity.
        for (int w = 1; w <= capacity; w++) {
            //
            //
            //- Если вес текущего предмета меньше или равен w, функция сравнивает два варианта:
            //Для каждого предмета i и веса w функция проверяет, превышает ли вес текущего предмета вес w. Если да, максимальная ценность такая же, как и для предыдущего предмета при том же весе (`dp[i-1][w]`).
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                // Включение текущего предмета (использование максимальной ценности от предыдущего предмета при весе w - items[i-1].weight плюс ценность текущего предмета: `dp[i-1][w - items[i-1].weight] + items[i-1].value`).
    // Функция затем выбирает максимальное из этих двух значений и сохраняет его в dp[i][w].
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    std::vector<Item> items = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};
    int capacity = 5;
    std::cout << "Maximum value that can be achieved: " << knapsack(capacity, items) << std::endl;
    return 0;
}
