#include<iostream>
#include <queue>
#include "binaryTreeClass.cpp"
using namespace std;



void printBinaryTree(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return;
    }

    cout<< root->data << ": ";

    if(root->left != nullptr){
        cout<<"L"<< root->left->data;
    }

    if(root->right != nullptr){
        cout<<"R"<< root->right->data;
    }

    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}


BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter Data:"<< endl;
    cin >> rootData;
    if(rootData == -1){
        return nullptr;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}


BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<< "Enter Data:";
    cin>> rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter left child of "<< front->data <<endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            q.push(child);
        }
        cout << "Enter right child of "<< front->data <<endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            q.push(child);
        }

    }

    return root;
}

void printLevelWise(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return;
    }
    queue<BinaryTreeNode<int>*> p;
    p.push(root);
    while(!p.empty()){
        BinaryTreeNode<int>* front = p.front();
        cout<< front->data << ": ";
        p.pop();
        if(front->left != nullptr){
            cout<< "L" << front->left->data;
            p.push(front->left);
        }
        if(front->right != nullptr){
            cout<< "R" << front->right->data;
            p.push(front->right);
        }
        cout<< endl;
    }
}



int travelTime(int a[], int size){
    int count = 0;
    int home  = a[0];
    int dest = a[size-1];
    for(int i = 0; i<size; i++){
        if(a[i]<=home){
            home = a[i];
            count++;
        }
    }
    return count;
}

int main(){
    //BinaryTreeNode<int> *root = takeInputLevelWise();
    //printLevelWise(root);

    int n;
    cin >> n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }
    cout << travelTime(arr, n)<< endl;
}
