// Jazveer Kaler
// 03/20/24
// Binary Search Tree
// Credit to Tejas for node files and Taaha for debugging
/* Used some random sources:
    https://en.wikipedia.org/wiki/Binary_search_tree
    https://www.geeksforgeeks.org/binary-search-tree-data-structure/
    https://www.youtube.com/watch?v=Gt2yBZAhsGM
 */

#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include <fstream>

void addNode(Node*& node, int value);
void deleteNode(Node*& node, int value);
bool search(Node* node, int value);
void print(Node* node, int count);
Node* findMin(Node* node);

using namespace std;

int main() {
    Node* root = nullptr;
    
    //input commands for while loop
    bool running = true;
    char command[50];
    char input[50];
    
    //for add function
    char method;
    int addingNums;
    
    //for delete/search function
    int value;
    int temp;
    
    cout << "Welcome to Binary Search Tree!" << endl;
    
    while(running == true) {
        cout << "Please enter a command: ADD, DELETE, SEARCH, PRINT, QUIT" << endl;
        cin.get(command, 50);
        cin.get();
        
        //ADD
        if(strcmp(command, "ADD") == 0){
            cout << "Would you like to enter values manually (m) or from a file (f)?" << endl;
            cin >> method;
            cin.get();
            
            //by console
            if(method == 'm'){
                cout << "How many numbers do you want to add?" << endl;
                cin >> addingNums;
                cin.get();
                cout << "Enter the numbers: " << endl;
                for (int i = 0; i < addingNums; i++){
                    cin >> temp;
                    cin.get();
                    addNode(root, temp);
                }
            }
            
            //by file
            else if(method == 'f'){
                vector<int> numbers;
                fstream file;
                file.open("numbers.txt");
                int number;
                while(file >> number){
                    numbers.push_back(number);
                }
                vector <int> ::iterator iter = numbers.begin();
                for (iter = numbers.begin(); iter < numbers.end(); iter++){
                    addNode(root, *iter);
                }
            }
        }
        
        //DELETE
        else if(strcmp(command, "DELETE") == 0){
            cout << "Enter the value you want to delete:" << endl;
            cin >> value;
            cin.get();
            deleteNode(root, value);
        }
        
        //SEARCH
        else if(strcmp(command, "SEARCH") == 0){
            cout << "Enter the value you want to search for:" << endl;
            cin >> value;
            cin.get();
            if(search(root, value) == true){
                cout << "Value exists." << endl;
            }
            else if(search(root, value) == false){
                cout << "Value does not exist." << endl;
            }
        }
        else if(strcmp(command, "QUIT") == 0){
            cout << "Exiting the program..." << endl;
            running = false;
        }
        else if(strcmp(command, "PRINT") == 0){
            cout << "Printing..." << endl;
            print(root, 0);
        }
    }
    
    return 0;
}

void addNode(Node*& node, int value) {
    if (node == nullptr) // end of tree
        node = new Node(value);
    
    //sorts based on if value is smaller than or greater than node data
    else if (value < node-> data)
        addNode(node->left, value);
    
    else if (value > node-> data)
        addNode(node->right, value);
}

void deleteNode(Node*& node, int value) {
    if (node == nullptr)
        return;
    
    //trying to find value
    if (value < node->data)
        deleteNode(node->left, value);
    
    else if (value > node->data)
        deleteNode(node->right, value);
    
    
    else {
        
        //no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } 
        
        //only right child
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } 
        
        //only left child
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } 
        
        //two children
        else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            deleteNode(node->right, temp->data);
        }
    }
}

bool search(Node* node, int value) {
    if (node == nullptr)
        return false;
    
    if (node->data == value)
        return true;
    
    if (value < node->data)
        return search(node->left, value);
    
    else
        return search(node->right, value);
}

/*
 bool search(Node* node, int data) {
    if (node == nullptr) {
        return false;
    }
    if (node->getData() == data) {
        return true;
    } else if (data < node->getData()) {
        return search(node->getLeft(), data);
    } else {
        return search(node->getRight(), data);
    }
}
 */


void print(Node* node, int count) {
    if(node == NULL){
        cout << "The tree is empty." << endl;
        return;
    }
    else if(node->right != NULL){
        print(node->right, count + 1);
    }

    for(int i = 0; i < count; i++){
        cout << '\t';
    }
    cout << node->data << endl;

    if(node->left != NULL){
        print(node->left, count + 1);
    }
}

/*
 void print(Node* node, int count) {
     if (node == nullptr) {
         return;
     }
     print(node->getRight(), count + 1);
     for (int i = 0; i < count; i++) {
         cout << '\t';
     }
     cout << node->getData() << endl;
     print(node->getLeft(), count + 1);
 }
 */


Node* findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}
