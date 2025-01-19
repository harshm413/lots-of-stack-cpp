#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;  // Increment for open parenthesis
            } else if (c == ')') {
                balance--;  // Decrement for close parenthesis
            }

            // If balance becomes negative, it means a closing parenthesis is unmatched
            if (balance < 0) {
                return false;
            }
        }

        // Valid if balance is zero
        return balance == 0;
    }
};

/*
Time Complexity:
- Each character is processed once.
- Total time complexity: O(n).

Space Complexity:
- O(1) as we only use a single counter.
*/

int main() {
    string s = "(()())";  // Example input

    Solution solution;
    bool result = solution.isValid(s);

    cout << "Is the string valid? " << (result ? "Yes" : "No") << endl;

    return 0;
}
/*
// Approach: Stack-Based Solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push(c); // Push opening parenthesis
            } else {
                // Pop the stack for closing parenthesis
                if (st.empty() || st.top() != '(') {
                    return false; // Mismatch or unbalanced
                }
                st.pop(); // Valid match
            }
        }

        return st.empty(); // Ensure no unmatched opening parentheses
    }
};


Time Complexity:
- Each character is pushed or popped from the stack exactly once.
- Total time complexity: O(n), where n is the length of the string.

Space Complexity:
- O(n) in the worst case, where the stack contains all opening parentheses.

*/