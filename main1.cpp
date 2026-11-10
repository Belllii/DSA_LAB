#include <iostream>
#include <string>
using namespace std;

// ============ STACK FOR INT ============
class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if(top >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if(top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// ============ APPLY OPERATOR ============
int applyOperator(char op, int a, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// ============ PREFIX EVALUATION ============
int evaluatePrefix(const string &expr) {
    Stack st(expr.length());

    // Traverse from right to left
    for (int i = expr.length() - 1; i >= 0; i--) {
        char ch = expr[i];

        if (ch >= '0' && ch <= '9') {  // If digit → push
            st.push(ch - '0');
        } else {  // operator
            int op1 = st.pop();
            int op2 = st.pop();
            st.push(applyOperator(ch, op1, op2));
        }
    }

    return st.pop();
}

// ============ POSTFIX EVALUATION ============
int evaluatePostfix(const string &expr) {
    Stack st(expr.length());

    // Traverse from left to right
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch >= '0' && ch <= '9') {  // If digit → push
            st.push(ch - '0');
        } else {  // operator
            int op2 = st.pop();
            int op1 = st.pop();
            st.push(applyOperator(ch, op1, op2));
        }
    }

    return st.pop();
}

// ============ MAIN ============
int main() {
    string expr;
    cout << "Enter Prefix Expression: ";
    cin >> expr;
    cout << "Prefix Evaluation Result: " << evaluatePrefix(expr) << endl;

    cout << "Enter Postfix Expression: ";
    cin >> expr;
    cout << "Postfix Evaluation Result: " << evaluatePostfix(expr) << endl;

    return 0;
}
