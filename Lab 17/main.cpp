#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> binPacking(std::vector<int>& weights, int capacity) {
    std::vector<int> bins;

    std::sort(weights.begin(), weights.end(), std::greater<>());

    for (int weight : weights) {
        bool placed = false;
        for (int& bin : bins) {
            if (bin + weight <= capacity) {
                bin += weight;
                placed = true;
                break;
            }
        }
        if (!placed) {
            bins.push_back(weight);
        }
    }

    return bins;
}

int main()
{
    std::vector<int> weights = {5, 3, 7, 2, 8, 4, 6};
    int capacity = 10;

    std::vector<int> bins = binPacking(weights, capacity);

    std::cout << "Count of boxes: " << bins.size() << "\n";
    std::cout << "Boxes weights: ";
    for (int bin : bins) {
        std::cout << bin << " ";
    }
    std::cout << "\n";

    return 0;
}