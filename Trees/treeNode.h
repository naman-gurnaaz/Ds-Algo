#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class TreeNode{

    public:
    T data;
    vector<TreeNode<T>*> children;

    //constructor
    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode(){
        for(int i = 0; i<children.size(); i++){
            delete children[i];
        }
    }
};