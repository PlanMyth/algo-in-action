#include <cassert>
#include <vector>
namespace dp {
class Solution {
   public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return std::max(nums[0], nums[1]);
        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    };
};
}  // namespace name

static void rob_test() {
    dp::Solution s;
    std::vector<int> nums = {1, 2, 3, 1};
    assert(s.rob(nums) == 4);
    nums = {2, 7, 9, 3, 1};
    assert(s.rob(nums) == 12);
}