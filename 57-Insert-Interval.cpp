class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> list;

        for (auto& in : intervals) {
            if (in[1] < newInterval[0]) {
                // Current interval ends before the new interval starts, so add it directly
                list.push_back(in);
            } else if (newInterval[1] < in[0]) {
                // New interval ends before the current interval starts, so add newInterval and update newInterval to current interval
                list.push_back(newInterval);
                newInterval = in;
            } else {
                // Overlapping intervals, merge them
                newInterval[0] = min(newInterval[0], in[0]);
                newInterval[1] = max(newInterval[1], in[1]);
            }
        }

        // Add the last newInterval (which is either merged or just remaining)
        list.push_back(newInterval);

        return list;
        
    }
};