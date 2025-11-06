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

void inorder(Node* root){
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    
    std::cout << root->data << std::endl;

    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << std::endl;

    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    
    std::cout << root->data << std::endl;
}

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

    for(int i = 1; i < initialTreeSize; i += 1) {
        std::cout << "Tell me what the next node value is: ";
        std::cin >> newData;
        std::cout << std::endl;

        insert(root, newData);
    }

    return root;
}

void printMenu() {
    std::cout   << "What would you like to do?\n"
                << "Inorder traversal (1)\t"
                << "Preorder traversal (2)\t"
                << "Postorder traversal (3)\t"
                << "Search (4)\t"
                << "Exit (0)\n";
}

void menu(Node* root) {
    int command;

    printMenu();

    while(std::cin >> command) {

        switch(command) {
            case 1:
                inorder(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                std::cout << "oops, this function does not exist yet, please choose another one\n";
                break;
            case 0:
                return;
            default:
                std::cout << "invalid command, choose another\n";
        
        }

        printMenu();

    }
}

int main() {

    Node* root = createTree();
    menu(root);

    return 0;
}