class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Sort the array first
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the base number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;
            int sum = -1 * nums[i];

            while (left < right) {
                int s = nums[left] + nums[right];
                
                if (s == sum) {
                    // 1. Record the valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // 2. Skip duplicates SAFELY (left looks forward, right looks backward)
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // 3. Move both pointers inward to continue the search
                    left++;
                    right--;
                } 
                else if (s < sum) {
                    left++; // Need a larger sum
                } 
                else {
                    right--; // Need a smaller sum
                }
            }
        }

        return result;
    }
};