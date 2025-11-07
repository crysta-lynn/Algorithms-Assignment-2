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

Node* minimumValueNode(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

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

Node* insertNode(Node* root, int newData) {
    if(root == nullptr) {
        return new Node(newData);
    }

    if(newData < root->data) {
        root->left = insertNode(root->left, newData);
    }
    else if(newData > root->data) {
        root->right = insertNode(root->right, newData);
    }

    return root;
}

void userInsert(Node* root) {
    int insertValue;

    std::cout << "What node value would you like to insert?";
    std::cin >> insertValue;

    insertNode(root, insertValue);

}

Node* deleteNode(Node* root, int deleteValue) { //will clean up this function if I can find time on friday; if you are seeing this message, I did not have time..
    if (root == nullptr) {
        return nullptr;
    }

    if (deleteValue < root->data) {
        root->left = deleteNode(root->left, deleteValue);
        return root;
    }

    else if (deleteValue > root->data) {
        root->right = deleteNode(root->right, deleteValue);
        return root;
    }


    
    if (!root->left && !root->right) {
        delete root;
        return nullptr;
    }

    else if (!root->left) {
        Node* rootReplacement = root->right;
        delete root;
        return rootReplacement;
    }
    else if (!root->right) {
        Node* rootReplacement = root->left;
        delete root;
        return rootReplacement;
    }

    Node* rootReplacement = minimumValueNode(root->right);
    root->data = rootReplacement->data;
    root->right=deleteNode(root->right, rootReplacement->data);

    return root;
}

Node* userDelete(Node* root) {
    int deleteValue;
    std::cout << "what value would you like to delete from the tree? ";
    std::cin >> deleteValue;

    return deleteNode(root, deleteValue);
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

        insertNode(root, newData);
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

Node* menu(Node* root) {
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
                root = userDelete(root);
                break;
            case 0:
                return root;
            default:
                std::cout << "invalid command, choose another\n";
        
        }

        printMenu();

    }
}

int main() {

    Node* root = createTree();
    root = menu(root);

    return 0;
}