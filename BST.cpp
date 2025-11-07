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
    
    std::cout << root->data << ", ";

    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << ", ";

    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    
    std::cout << root->data << ", ";
}

Node* search(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    else if (value > root->data) {
        return search(root->right, value);
    }
    else if (value == root->data) {
        return root;
    }
    return nullptr;
}

bool userSearch(Node* root) {
    int searchValue;

    std::cout << "what number are you searching for: ";
    std::cin >> searchValue;

    Node* result = search(root, searchValue);

    if (result == nullptr) {
        std::cout << "number not found in tree\n";
        return false;
    }
    std::cout << "number found at address: " << result << std::endl;
    return true;

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

void userInsert(Node* root) {
    int insertValue;

    std::cout << "What node value would you like to insert?";
    std::cin >> insertValue;

    insert(root, insertValue);

}

Node* createTree() {
    int initialTreeSize;
    int newData;

    std::cout << "To create a binary search tree, tell me how many nodes this tree will have: ";
    std::cin >> initialTreeSize;

    std::cout << "what is the first node value: ";
    std::cin >> newData;

    Node* root = new Node(newData);

    for(int i = 1; i < initialTreeSize; i += 1) {
        std::cout << "Tell me what the next node value is: ";
        std::cin >> newData;

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
                << "Insert node (5)\t"
                << "Delete node(6)\t"
                << "Exit (0)\n";
}

void menu(Node* root) {
    int command;

    printMenu();

    while(std::cin >> command) {

        switch(command) {
            case 1:
                inorder(root);
                std::cout << std::endl;
                break;
            case 2:
                preorder(root);
                std::cout << std::endl;
                break;
            case 3:
                postorder(root);
                std::cout << std::endl;
                break;
            case 4:
                userSearch(root);
                break;
            case 5:
                userInsert(root);
                break;
            case 6:
                std::cout << "oops, the delete function does not exist yet, please choose another command.\n";
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