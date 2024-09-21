class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
    // Step 1: Count the frequency of each number
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Step 2: Sort the array based on the frequency and value
    sort(nums.begin(), nums.end(), [&freq](int a, int b) {
        // If frequencies are different, sort by frequency in increasing order
        if (freq[a] != freq[b]) {
            return freq[a] < freq[b];
        }
        // If frequencies are the same, sort by value in decreasing order
        return a > b;
    });
    
    return nums;
}

};