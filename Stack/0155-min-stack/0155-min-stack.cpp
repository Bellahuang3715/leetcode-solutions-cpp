#include <stack>
#include <iostream>

class MinStack {
private:
    std::stack<int> mainStack;  // Primary stack to store elements
    std::stack<int> minStack;   // Secondary stack to store minimums

public:
    MinStack() {
        // Constructor initializes an empty stack
    }
    
    void push(int val) {
        mainStack.push(val);
        // Push the minimum value onto the minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }
    
    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        throw std::runtime_error("Stack is empty");
    }
    
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        throw std::runtime_error("Stack is empty");
    }
};

int main() {
    MinStack minStack;

    minStack.push(5);
    minStack.push(3);
    minStack.push(7);
    std::cout << "Current Minimum: " << minStack.getMin() << std::endl; // Output: 3

    minStack.pop();
    std::cout << "Current Minimum: " << minStack.getMin() << std::endl; // Output: 3

    minStack.pop();
    std::cout << "Current Minimum: " << minStack.getMin() << std::endl; // Output: 5

    return 0;
}
