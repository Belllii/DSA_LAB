#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = next = NULL;
    }
};

class Playlist {
private:
    Node* current;
public:
    Playlist() {
        current = NULL;
    }
    void ADD(string song) {
        Node* newNode = new Node(song);
        if (current == NULL) {
            current = newNode;
            return;
        }
        // Insert after current
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next =newNode;
        current = newNode; // ***move to new song***
    }
  void NEXT() {
        if (current != NULL && current->next != NULL)
            current = current->next;
    }
    void PREV() {
        if (current != NULL && current->prev != NULL)
            current = current->prev;
    }
    void REMOVE() {
        if (current == NULL) return;
        Node* temp = current;
        // Only one node
        if (current->prev == NULL && current->next == NULL) {
            current = NULL;
        else if (current->next != NULL) {
            // move to next
            if (current->prev != NULL)
                current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
        }
        else {
            // last node → move to prev
            current->prev->next = NULL;
            current = current->prev;
        }

        delete temp;
    }

    // PRINT
    void print() {
        if (current == NULL) {
            cout << "Playlist: Empty\n";
            return;
        }
        // Go to head
        Node* temp = current;
        while (temp->prev != NULL)
            temp = temp->prev;
        cout << "Playlist: ";
        // Traverse forward
        while (temp != NULL) {
            cout << temp->song;
            if (temp->next != NULL) cout << ", ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Currently Playing: " << current->song << endl;
    }
};
int main() {
    Playlist p;
    p.ADD("Track1");
    p.ADD("Track2");
    p.PREV();
    p.ADD("Track3");
    p.NEXT();
    p.REMOVE();
    p.print();
    return 0;
}
