#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketPairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (bracketPairs.count(c)) {
                // Check the top of the stack
                if (!st.empty() && st.top() == bracketPairs[c]) {
                    st.pop(); // Matching pair found
                } else {
                    return false; // No matching pair
                }
            } else {
                // Push opening brackets onto the stack
                st.push(c);
            }
        }

        // If stack is empty, all brackets were matched
        return st.empty();
    }
};

int main() {
    string s = "{[()]}";  // Example input

    Solution solution;
    bool result = solution.isValid(s);

    cout << "Is the string valid? " << (result ? "Yes" : "No") << endl;

    return 0;
}
