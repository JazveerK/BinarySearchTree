#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val);
    ~Node(); // Destructor for proper memory deallocation
};

#endif // NODE_H
