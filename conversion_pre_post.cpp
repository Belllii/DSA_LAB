#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Stack {
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPrefix(string infix) {

    // Step 1: Reverse infix
    reverse(infix.begin(), infix.end());

    // Step 2: Swap brackets
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    Stack st;
    string postfix = "";

    // Step 3: Convert to postfix
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Operand
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop();
        }
        else { // operator
            while (!st.isEmpty() &&
                   precedence(st.peek()) > precedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    // Step 4: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Prefix Expression: "
         << infixToPrefix(infix);

    return 0;
}
/*#include <iostream>
#include <string>
using namespace std;

// Manual stack class for characters
class Stack {
    char arr[100];
    int top;
public:
    Stack() { top = -1; }

    void push(char c) {
        if (top >= 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }
    char pop() {
        if (top == -1) {
            return '\0'; // empty
        }
        return arr[top--];
    }
    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};
// Function to return precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else if (op == '^') return 3;
    return 0;
}
// Infix to Postfix Conversion
string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Operand
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        // Left Parenthesis
        else if (ch == '(') {
            st.push(ch);
        }
        // Right Parenthesis
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}*/
