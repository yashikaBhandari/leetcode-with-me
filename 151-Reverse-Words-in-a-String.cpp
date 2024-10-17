class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        int length = s.length();

        // Trim leading spaces
        int start = 0;
        while (start < length && s[start] == ' ') {
            start++;
        }

        // Extract words
        for (int i = start; i < length; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join the words into a single string with a single space separating them
        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};
