#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value) {
        data = value;
        prev = next = NULL;
    }};
class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }// Insert at Beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        if (head != NULL) {
            head->prev = newNode;
            newNode->next = head;
        }head = newNode;
    }// Insert at End
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;}
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }        temp->next = newNode;
        newNode->prev = temp;
    }// Insert After
    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Value not found\n";
            return;}
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;
if (temp->next != NULL) {
            temp->next->prev = newNode;
        }temp->next = newNode;
    }// Insert Before
    void insertBefore(int key, int value) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;}
        Node* temp = head;
        if (head->data == key) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;}
        while (temp != NULL && temp->data != key) {
            temp = temp->next;}
        if (temp == NULL) {
            cout << "Value not found\n";
            return;}
        Node* newNode = new Node(value);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }    // Delete Beginning
    void deleteBeginning() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }delete temp;
    }// Delete End
    void deleteEnd() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            head = NULL;
        }delete temp;
    }// Delete Specific Value
    void deleteValue(int key) {
        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;}
if (temp == NULL) {
            cout << "Value not found\n";
            return;}
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;}
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }delete temp;
    }// Delete BEFORE
    void deleteBefore(int key) {
        if (head == NULL || head->next == NULL) {
            cout << "Not enough elements\n";
            return;        }
        Node* temp = head
        while (temp != NULL && temp->data != key) {
            temp = temp->next;}
        if (temp == NULL || temp->prev == NULL) {
            cout << "No node exists before this value\n";
            return;}
        Node* del = temp->prev;
        if (del->prev == NULL) {
            head = temp;
            temp->prev = NULL;
        } else {
            del->prev->next = temp;
            temp->prev = del->prev;
        }delete del;
    }// Delete AFTER
    void deleteAfter(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;}
        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;}
if (temp == NULL || temp->next == NULL) {
            cout << "No node exists after this value\n";
            return;}
        Node* del = temp->next;
        temp->next = del->next;
        if (del->next != NULL) {
            del->next->prev = temp;
        }delete del;
    }// Display Forward
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }cout << endl;
    }// Display Backward
    void displayBackward() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }cout << endl;
    }};
int main() {
    DoublyLinkedList dll;
    dll.insertBeginning(10);
    dll.insertBeginning(5);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.displayForward();
    dll.displayBackward();
    dll.insertAfter(20, 25);
    dll.displayForward();
    dll.insertBefore(20, 15);
    dll.displayForward();
    dll.deleteBeginning();
    dll.displayForward();
    dll.deleteEnd();
    dll.displayForward();
    dll.deleteValue(25);
    dll.displayForward();
    dll.deleteBefore(20);
    dll.displayForward();
    dll.deleteAfter(10);
    dll.displayForward();
    return 0;
}
