class Solution {
public:
   
        int findPeakElement(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Compare the middle element with its right neighbor
        if (nums[mid] < nums[mid + 1]) {
            // If the middle element is less than the right neighbor,
            // then there must be a peak on the right side
            left = mid + 1;
        } else {
            // If the middle element is greater than or equal to the right neighbor,
            // then there must be a peak on the left side (including mid)
            right = mid;
        }
    }

    // When left == right, we have found a peak element
    return left;  // or return right; they are the same at this point
}


    
};