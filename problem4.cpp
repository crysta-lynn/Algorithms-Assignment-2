#include <iostream>

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int data)
    :data{data}
    ,left{nullptr}
    ,right{nullptr}
    {}
};

Node* insert(Node* root, int newData) {
    if(root == nullptr) {
        return new Node(newData);
    }

    if(newData < root->data) {
        root->left = insert(root->left, newData);
    }
    else if(newData > root->data) {
        root->right = insert(root->right, newData);
    }

    return root;
}

Node* createTree() {
    int initialTreeSize;
    int newData;

    std::cout << "To create a binary search tree, tell me how many nodes this tree will have: ";
    std::cin >> initialTreeSize;
    std::cout << std::endl;

    std::cout << "what is the first node value: ";
    std::cin >> newData;
    std::cout << std::endl;

    Node* root = new Node(newData);

    for(int i = 0; i < initialTreeSize; i += 1) {
        std::cout << "Tell me what the next node value is: ";
        std::cin >> newData;
        std::cout << std::endl;

        insert(root, newData);
    }

    return root;
}

int main() {

    createTree();
    
}