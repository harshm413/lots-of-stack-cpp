#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stack1; // Stack for input
    stack<int> stack2; // Stack for output

    // Helper function to transfer elements from stack1 to stack2
    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        stack1.push(x); // Push directly to the input stack
    }

    int pop() {
        if (stack2.empty()) {
            transfer(); // Transfer elements if output stack is empty
        }
        int topElement = stack2.top();
        stack2.pop(); // Remove the front element
        return topElement;
    }

    int peek() {
        if (stack2.empty()) {
            transfer(); // Transfer elements if output stack is empty
        }
        return stack2.top(); // Return the front element
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Front element: " << queue.peek() << endl; // Output: 1
    cout << "Removed element: " << queue.pop() << endl; // Output: 1
    cout << "Front element: " << queue.peek() << endl; // Output: 2
    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: No

    return 0;
}
