class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1; // or throw an exception, depending on the requirements
        if (nums.size() == 1) return nums[0];

        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            if (nums[left] <= nums[mid] && nums[mid] <= nums[right]) {
                return nums[left]; // no need to update ans, we can return directly
            }
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid; // no need to update ans, we can simply move the right pointer
            }
        }
        return nums[left]; // at this point, left and right pointers meet
    }
};