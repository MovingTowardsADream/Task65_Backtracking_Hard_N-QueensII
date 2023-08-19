#include <iostream>
#include <vector>

class Solution {
public:
    int result = 0;
    bool cont;

    int totalNQueens(int n) {
        std::vector<int> nums = {};
        queens(nums, n);
        return result;
    }

    void queens(std::vector<int>& nums, int n) {
        if (n == nums.size()) {
            result++;
        }
        else {
            for (int i = 0;i < n;i++) {
                if (std::find(nums.begin(), nums.end(), i) != nums.end()) {
                    continue;
                }
                cont = 0;
                for (int j = 0;j < nums.size();j++) {
                    if (i == nums[j] + nums.size() - j || i == nums[j] - nums.size() + j) {
                        cont = 1;
                        break;
                    }
                }
                if (cont)
                    continue;
                nums.push_back(i);
                queens(nums, n);
                nums.pop_back();
            }
        }
    }
};
