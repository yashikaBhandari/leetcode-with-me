class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
// Step 1: Build adjacency list for the graph
        vector<vector<int>> graph(n);  // method i invokes graph[i] methods
        vector<vector<int>> reverseGraph(n); // to track reverse invocations (who calls whom)
        
        for (auto& invocation : invocations) {
            int invoker = invocation[0];
            int invoked = invocation[1];
            graph[invoker].push_back(invoked);
            reverseGraph[invoked].push_back(invoker);
        }
        
        // Step 2: Find all suspicious methods using DFS from method k
        unordered_set<int> suspicious; // Set to store suspicious methods
        dfs(graph, k, suspicious);
        
        // Step 3: Check if any external method (not suspicious) invokes a suspicious method
        for (int i = 0; i < n; i++) {
            if (suspicious.find(i) == suspicious.end()) { // If method i is not suspicious
                for (int invoked : graph[i]) {
                    if (suspicious.find(invoked) != suspicious.end()) {
                        // If a non-suspicious method invokes a suspicious method, return all methods (no removal)
                        vector<int> allMethods(n);
                        for (int j = 0; j < n; j++) allMethods[j] = j;
                        return allMethods;
                    }
                }
            }
        }
        
        // Step 4: Return non-suspicious methods (all that are not suspicious)
        vector<int> remainingMethods;
        for (int i = 0; i < n; i++) {
            if (suspicious.find(i) == suspicious.end()) {
                remainingMethods.push_back(i);
            }
        }
        
        return remainingMethods;
    }

private:
    // DFS to find all methods that are suspicious, starting from method k
    void dfs(vector<vector<int>>& graph, int method, unordered_set<int>& suspicious) {
        if (suspicious.find(method) != suspicious.end()) return; // Already visited
        suspicious.insert(method); // Mark current method as suspicious
        for (int next : graph[method]) {
            dfs(graph, next, suspicious); // Recursively visit all methods invoked by this method
        }
    }
};
