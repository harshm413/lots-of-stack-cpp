#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts; // To store the count of repetitions
        stack<string> result; // To store the decoded string
        string currentString = ""; // Current string being processed
        int currentCount = 0; // Current repetition count

        for (char c : s) {
            if (isdigit(c)) {
                // If it's a digit, build the current count
                currentCount = currentCount * 10 + (c - '0');
            } else if (c == '[') {
                // Push the current count and the current string onto the stacks
                counts.push(currentCount);
                result.push(currentString);
                // Reset current string and count
                currentString = "";
                currentCount = 0;
            } else if (c == ']') {
                // Pop from the stacks and build the string
                string temp = currentString;
                int repeatCount = counts.top();
                counts.pop();
                currentString = result.top();
                result.pop();
                // Repeat the string and append to the current string
                for (int i = 0; i < repeatCount; i++) {
                    currentString += temp;
                }
            } else {
                // For characters, simply add them to the current string
                currentString += c;
            }
        }

        return currentString;
    }
};

int main() {
    Solution solution;

    string s1 = "3[a]2[bc]";
    cout << "Decoded String: " << solution.decodeString(s1) << endl; // Output: "aaabcbc"

    string s2 = "3[a2[c]]";
    cout << "Decoded String: " << solution.decodeString(s2) << endl; // Output: "accaccacc"

    string s3 = "2[abc]3[cd]ef";
    cout << "Decoded String: " << solution.decodeString(s3) << endl; // Output: "abcabccdcdcdef"

    return 0;
}
