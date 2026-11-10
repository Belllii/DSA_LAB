#include <iostream>
using namespace std;
// Node class
class Node {
public:
    int id;
    Node* next;
    Node* prev;

    Node(int id) {
        this->id = id;
        next = prev = NULL;
    }
};
// Doubly Linked List (ONLY HEAD)
class DList {
public:
    Node* head;

    DList() {
        head = NULL;
    }

    // Insert at front (O(1))
    void insertFront(int id) {
        Node* newNode = new Node(id);

        if (!head) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end (O(n))
    void insertEnd(int id) {
        Node* newNode = new Node(id);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    // Remove from front (O(1))
    int removeFront() {
        if (!head) return -1;
        Node* temp = head;
        int val = head->id;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return val;
    }

    // Delete specific node (O(n))
    bool deleteValue(int id) {
        if (!head) return false;

        Node* temp = head;

        while (temp) {
            if (temp->id == id) {

                // Case 1: deleting head
                if (temp == head) {
                    head = head->next;
                    if (head) head->prev = NULL;
                }
                // Case 2: middle or last
                else {
                    if (temp->prev)
                        temp->prev->next = temp->next;

                    if (temp->next)
                        temp->next->prev = temp->prev;
                }

                delete temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Print forward
    void print(string msg) {
        cout << msg;
        Node* temp = head;
        while (temp) {
            cout << "Task " << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

// System class
class TaskSystem {
public:
    DList holding;
    DList active;

    void ARRIVE(int id) {
        holding.insertEnd(id);
        holding.print("Holding area: ");
    }

    void URGENT(int id) {
        holding.insertFront(id);
        holding.print("Holding area: ");
    }

    void PROCESS() {
        if (holding.isEmpty()) {
            cout << "Error: Holding area is empty." << endl;
            return;
        }

        int id = holding.removeFront();
        active.insertEnd(id);
        active.print("Active execution sequence: ");
    }

    void CANCEL(int id) {
        if (!active.deleteValue(id)) {
            cout << "Error: Task " << id << " not found." << endl;
        } else {
            active.print("Active execution sequence: ");
        }
    }

    void VIEW_FORWARD() {
        active.print("Active execution sequence: ");
    }
};

int main() {
    TaskSystem t;

    // Sample test
    t.PROCESS();
    t.ARRIVE(10);
    t.ARRIVE(25);
    t.URGENT(99);
    t.PROCESS();
    t.PROCESS();
    t.PROCESS();
    t.CANCEL(10);
    t.VIEW_FORWARD();

    return 0;
}
