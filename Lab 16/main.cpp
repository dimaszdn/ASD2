#include <iostream>

#include<vector>

struct Item
{
    int weight, cost;
    Item(int weight, int cost) : weight(weight), cost(cost) {}
    friend std::ostream& operator<<(std::ostream& out, Item& item)
    {
        out << item.weight << " " << item.cost << " ";
        return out;
    }
};

void userInput(int& N, int& M, std::vector<Item>& items)
{
    std::cout << "Enter the number of items: ";
    std::cin >> N;
    std::cout << "Enter the capacity of the backpack: ";
    std::cin >> M;

    std::cout << "Enter the weight and cost of the items: " << "\n";
    int count{0};
    int weight, cost;
    while (count < N)
    {
        std::cin >> weight >> cost;
        items.emplace_back(weight, cost);
        ++count;
    }
}

int main()
{
    int N, M; //N-количество предметов, M-вместимость рюкзака
    std::vector<Item> items;
    userInput(N, M, items);

    //таблица хранит максимальные стоимости
    std::vector<std::vector<int>> table(N + 1, std::vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i)
    {
        int weight = items[i - 1].weight;
        int cost = items[i - 1].cost;
        for (int j = 1; j <= M; ++j)
        {
            if (weight <= j)
                table[i][j] = std::max(table[i - 1][j], cost + table[i - 1][j - weight]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    std::cout << "Max cost: " << table[N][M] << "\n";
    return 0;
}