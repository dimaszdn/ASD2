#include <iostream>

#include<vector>
#include<string>

void result(int sum, int target, const std::vector<int>& subset)
{
    if (sum == target)
    {
        std::cout << "Subset " << "{ ";
        for (const auto& number : subset)
            std::cout << number << " ";
        std::cout << "}" << " sums to " << std::to_string(target) << "\n";
    }
    else
        std::cout << "There is no such set!" << "\n";
}

int main()
{
    std::vector<int> nums = {6, 7, 9, 4, 12, 13, 1};
    size_t N = nums.size();
    int target = 14;

    int sum;
    std::vector<int> subset;
    for (int i = 0; i < (1 << N); ++i)
    {
        sum = 0;
        subset.clear();
        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
            {
                sum += nums[j];
                subset.push_back(nums[j]);
            }
        }
        if (sum == target)
            break;
    }

    result(sum, target, subset);

    return 0;
}