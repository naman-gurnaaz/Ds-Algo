#include <iostream>
#include <queue>
#include "treeNode.h"

TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter Data: "<< endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter the no. of children: ";
    cin >> n;
    for(int i = 0; i<n; i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;

}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter Data: "<< endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter the num of childern of "<< front->data<< endl;
        cin >> numChild;

        for(int i = 0; i<numChild; i++){
            int childData;
            cout << "Enter "<< i << "th child of  "<< front->data <<endl;
            cin>> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}

void printTreeLevelWise(TreeNode<int> *root){
    if(root == nullptr){
        return;
    }

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){

        TreeNode<int> *front = pendingNodes.front();
        cout << front->data<< ": ";
        pendingNodes.pop();
        for(int i = 0; i<front->children.size(); i++){

            pendingNodes.push(front->children[i]);

            if(i == front->children.size() -1){
                cout<< front->children[i]->data;
            }

            else{
                cout<< front->children[i]->data << ", ";
            }

        }
        cout << endl;
    }
    
}

int countNodes(TreeNode <int>*root){
    if(root == nullptr){
        return 0;
    }
    int ans = 1;
    for(int i=0; i<root->children.size(); i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}


int sumOfNodes(TreeNode <int>*root){
    if(root == nullptr){
        return 0;
    }
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}


TreeNode<int>* maxDataNode(TreeNode<int> *root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode<int> *max = root;
    for(int i =0; i<root->children.size(); i++){
        TreeNode<int> *child = maxDataNode(root->children[i]);
        if(max->data < child->data){
            max = child;
        }
    }
    return max;
}

void printTree(TreeNode<int>* root){
    if(root == nullptr){
        return;
    }
    cout << root->data << ":";
    for(int i = 0; i<root->children.size(); i++){
        cout<< root->children[i]->data << ", ";
    }
    cout << endl;
    for(int i = 0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}


int heightOfTree(TreeNode<int> *root){
    if(root == nullptr){
        return 0;
    }
    int maxHeight = 0;
    for(int i = 0; i<root->children.size(); i++){
        int height = heightOfTree(root->children[i]);
        if(height > maxHeight){
            maxHeight = height;
        }
    }
    return maxHeight+1;
}

void printAtLevelK(TreeNode<int> *root, int k){
    if(root == nullptr){
        return;
    }
    if(k == 0){
        cout << root->data << endl;
        return;
    }
    for(int i = 0; i<root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
}


int countLeafNodes(TreeNode<int> *root){
    if(root == nullptr){
        return 0;
    }
    if(root->children.empty()){
        return 1;
    }
    int ans =0;
    for(int i = 0; i<root->children.size(); i++){
        ans += countLeafNodes(root->children[i]);
    }

    return ans;
    
}




//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){

    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << endl;
    printAtLevelK(root, 2);
    delete root;
}