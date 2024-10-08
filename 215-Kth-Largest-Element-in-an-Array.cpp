class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /* priority_queue<int> maxHeap;

    // Push all elements into the max-heap
    for (int num : nums) {
        maxHeap.push(num);
    }

    // Pop k-1 elements from the max-heap
    for (int i = 0; i < k - 1; ++i) {
        maxHeap.pop();
    }

    // The top element of the max-heap is the kth largest element
    return maxHeap.top();
    }*/


    // more efficient approach 
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto x: nums){
        pq.push(x);
        if(pq.size()>k)
            pq.pop();
            }
            return pq.top();
    }
};