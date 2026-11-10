#include <iostream>
using namespace std;
class Node {
public:
    char ch;
    Node* prev;
    Node* next;
    Node(char c) {
        ch = c;
        prev = next = NULL;
    }
};
class TextEditor {
private:
    Node* cursor; // ONLY pointer
public:
    TextEditor() {
        cursor = NULL;
    }
    // TYPE
    void TYPE(char c) {
        Node* newNode = new Node(c);
        // Empty list
        if (cursor == NULL) {
            cursor = newNode;
            return;
        }
        // Insert before cursor
        newNode->next = cursor;
        newNode->prev = cursor->prev;
        if (cursor->prev != NULL)
            cursor->prev->next = newNode;
        cursor->prev = newNode;
    }

    // Move LEFT
    void LEFT() {
        if (cursor == NULL) {
            // go to last node
            return; // nothing to do (we can't find tail directly)
        }
        if (cursor->prev != NULL)
            cursor = cursor->prev;
    }
    // Move RIGHT
    void RIGHT() {
        if (cursor != NULL)
            cursor = cursor->next;
    }
    // BACKSPACE
    void BACKSPACE() {
        if (cursor == NULL) return;
        Node* toDelete = cursor->prev;
        if (toDelete == NULL) return;
        if (toDelete->prev != NULL)
            toDelete->prev->next = cursor;
        else
            cursor->prev = NULL;
        cursor->prev = toDelete->prev;
        delete toDelete;
    }
    // PRINT
    void print() {
        if (cursor == NULL) {
            cout << "Final Text: ";
            return;
        }
        // Go to head
        Node* temp = cursor;
        while (temp->prev != NULL)
            temp = temp->prev;
        cout << "Final Text: ";
        // Print forward
        Node* iter = temp;
        while (iter != NULL) {
            cout << iter->ch;
            iter = iter->next;
        }
        cout << endl;

        if (cursor == NULL)
            cout << "Cursor is at: END\n";
        else
            cout << "Cursor is at: " << cursor->ch << endl;
    }
};
int main() {
    TextEditor te;
    te.TYPE('H');
    te.TYPE('e');
    te.TYPE('x');
    te.TYPE('l');
    te.LEFT();
    te.BACKSPACE();
    te.RIGHT();
    te.TYPE('l');
    te.TYPE('o');
    te.LEFT();
    te.LEFT();
    te.print();
    return 0;
}
