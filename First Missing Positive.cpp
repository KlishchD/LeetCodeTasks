class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool flag = 0;
        for (int &i : nums) {
            if (i == 1) {
                flag = 1;
                break;
            }
        }
        if (!flag) return 1;
        
        for (int &i : nums) if (i <= 0 || i > nums.size()) i = 1;
        for (int &i : nums) {
            nums[abs(i) - 1] = -abs(nums[abs(i) - 1]);
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return nums.size() + 1;
    }
};
