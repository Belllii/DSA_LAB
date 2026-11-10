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
// Doubly Linked List (ONLY HEAD POINTER)
class DoublyList {
public:
    Node* head;
    DoublyList() {
        head = NULL;
    }
    // Insert at end (no tail, so traverse)
    void insertEnd(int id) {
        Node* newNode = new Node(id);

        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    // Insert at front
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
    // Remove from front
    int removeFront() {
        if (!head) return -1;
        int val = head->id;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
        return val;
    }
    // Delete specific patient
    bool deleteValue(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (temp == head) {
                    head = head->next;
                    if (head) head->prev = NULL;
                }
                else {
                    if (temp->next)
                        temp->next->prev = temp->prev;

                    if (temp->prev)
                        temp->prev->next = temp->next;
                }
                delete temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    // Print forward
    void printForward(string msg) {
        cout << msg;
        Node* temp = head;
        while (temp) {
            cout << "Patient " << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Print reverse (find last manually)
    void printReverse(string msg) {
        cout << msg;
        if (!head) {
            cout << endl;
            return;
        }
        Node* temp = head;
        // go to last node
        while (temp->next) {
            temp = temp->next;
        }
        // traverse backward
        while (temp) {
            cout << "Patient " << temp->id << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    bool isEmpty() {
        return head == NULL;
    }
};
// Hospital System
class HospitalSystem {
public:
    DoublyList waitingRoom;
    DoublyList treatmentWard;
    void WALK_IN(int id) {
        waitingRoom.insertEnd(id);
        waitingRoom.printForward("Waiting room: ");
    }
    void AMBULANCE(int id) {
        waitingRoom.insertFront(id);
        waitingRoom.printForward("Waiting room: ");
    }
    void ADMIT() {
        if (waitingRoom.isEmpty()) {
            cout << "Error: Waiting room is empty." << endl;
            return;
        }
        int id = waitingRoom.removeFront();
        treatmentWard.insertEnd(id);
        treatmentWard.printForward("Treatment ward: ");
    }
    void DISCHARGE(int id) {
        if (!treatmentWard.deleteValue(id)) {
            cout << "Error: Patient " << id << " not found." << endl;
        } else {
            treatmentWard.printForward("Treatment ward: ");
        }
    }
    void WARD_STATUS_REVERSE() {
        treatmentWard.printReverse("Reverse treatment ward: ");
    }
};
// Main
int main() {
    HospitalSystem h;

    h.ADMIT();
    h.WALK_IN(101);
    h.WALK_IN(202);
    h.AMBULANCE(999);
    h.ADMIT();
    h.ADMIT();
    h.WALK_IN(303);
    h.ADMIT();
    h.WARD_STATUS_REVERSE();
    h.DISCHARGE(101);
    h.DISCHARGE(500);

    return 0;
}
