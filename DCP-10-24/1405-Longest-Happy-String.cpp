class Solution {
public:
    typedef pair<int, char> p;

    string longestDiverseString(int a, int b, int c) {
        // priority queue for pairs
        priority_queue<p, vector<p>> pq;

        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";
        while (!pq.empty()) {
            int currcount = pq.top().first;
            char currchar = pq.top().second; // changed to char
            pq.pop();

            // Check if the last two characters in result are the same as currchar
            if (result.length() >= 2 && result[result.length() - 1] == currchar && result[result.length() - 2] == currchar) {
                // If we can't use currchar, we need to use the next highest frequency character
                if (pq.empty()) {
                    break; // Exit if there are no more characters to use
                }
                int nextcount = pq.top().first;
                char nextchar = pq.top().second; // changed to char
                pq.pop();

                result.push_back(nextchar);
                nextcount--; // Decrease the count for nextchar
                if (nextcount > 0) {
                    pq.push({nextcount, nextchar});
                }

                // Push currchar back to the queue as we still need to use it
                pq.push({currcount, currchar});
            } else {
                // If we can use currchar
                result.push_back(currchar);
                currcount--; // Decrease the count for currchar
                if (currcount > 0) {
                    pq.push({currcount, currchar});
                }
            }
        }

        return result;
    }
};
