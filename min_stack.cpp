#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; // Main stack to store elements
    stack<int> minStack;  // Auxiliary stack to store the minimum values

public:
    MinStack() {}

    void push(int x) {
        mainStack.push(x);
        // If minStack is empty or x is smaller than or equal to the current minimum
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            // If the top of mainStack equals the top of minStack, pop from minStack as well
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Minimum value: " << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << "Top value: " << minStack.top() << endl;       // Output: 0
    cout << "Minimum value: " << minStack.getMin() << endl; // Output: -2

    return 0;
}
