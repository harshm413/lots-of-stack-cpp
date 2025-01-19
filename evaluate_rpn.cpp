#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int b = st.top(); st.pop(); // Second operand
                int a = st.top(); st.pop(); // First operand

                // Perform the operation
                int result = applyOperation(a, b, token);
                st.push(result);
            } else {
                // Convert the string to an integer and push onto the stack
                st.push(stoi(token));
            }
        }

        // The final result will be on top of the stack
        return st.top();
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int applyOperation(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b; // Integer division
        throw invalid_argument("Invalid operator");
    }
};

int main() {
    Solution solution;

    vector<string> tokens = {"2", "1", "+", "3", "*"}; // Example: (2 + 1) * 3
    cout << "Result: " << solution.evalRPN(tokens) << endl; // Output: 9

    vector<string> tokens2 = {"4", "13", "5", "/", "+"}; // Example: 4 + (13 / 5)
    cout << "Result: " << solution.evalRPN(tokens2) << endl; // Output: 6

    vector<string> tokens3 = {"10", "6", "9", "3", "/", "*", "-", "+"}; // Complex RPN
    cout << "Result: " << solution.evalRPN(tokens3) << endl; // Example output

    return 0;
}
