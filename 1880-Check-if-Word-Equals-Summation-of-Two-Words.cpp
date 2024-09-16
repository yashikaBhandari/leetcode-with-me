class Solution {
public:
int stringToValue(const string& word) {
    int value = 0;
    for (char c : word) {
        value = value * 10 + (c - 'a');  // Convert each character to its letter value
    }
    return value;
}
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstvalue=stringToValue(firstWord);
        int secondvalue=stringToValue(secondWord);
        int targetvalue=stringToValue(targetWord);

        return (firstvalue + secondvalue) == targetvalue;
    }
};