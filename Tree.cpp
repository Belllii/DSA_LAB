#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class BST {
private:
    Node* root;
    // Insert
    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }
    // Search
    bool search(Node* root, int key) {
        if (root == NULL)
            return false;
        if (root->data == key)
            return true;
        else if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // Find Minimum
    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }
    // Find Maximum
    Node* findMax(Node* root) {
        while (root && root->right != NULL)
            root = root->right;
        return root;
    }
    // Delete
    Node* deleteNode(Node* root, int key) {
        if (root == NULL)
            return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // Case 2: One child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Traversals
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    // Height
    int height(Node* root) {
        if (root == NULL)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }

    void searchValue(int key) {
        if (search(root, key))
            cout << "Found\n";
        else
            cout << "Not Found\n";
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        postorder(root);
        cout << endl;
    }

    void showMin() {
        Node* temp = findMin(root);
        if (temp)
            cout << "Minimum: " << temp->data << endl;
    }

    void showMax() {
        Node* temp = findMax(root);
        if (temp)
            cout << "Maximum: " << temp->data << endl;
    }

    void showHeight() {
        cout << "Height: " << height(root) << endl;
    }
};

// Main function
int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.displayInorder();

    cout << "Preorder: ";
    tree.displayPreorder();

    cout << "Postorder: ";
    tree.displayPostorder();

    tree.searchValue(40);

    tree.showMin();
    tree.showMax();

    tree.showHeight();

    cout << "Deleting 30...\n";
    tree.deleteValue(30);

    cout << "Inorder after deletion: ";
    tree.displayInorder();

    return 0;
}
