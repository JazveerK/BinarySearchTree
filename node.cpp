#include "node.h"
#include <iostream>
#include <cstring>
using namespace std;


Node::Node(int val){
  data = val;
  left = nullptr;
  right = nullptr;
}

Node::~Node(){
    delete left; 
    delete right;
}
