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

int countNodes(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return 0;
    }
    return 1+countNodes(root->left) + countNodes(root->right);
}


void inOrder(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return;
    }
    cout << root ->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}


BinaryTreeNode<int> * buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE){
    if(inS > inE){
        return nullptr;
    }
    int rootData = pre[preS];

    int rootIndex = -1;
    for(int i = inS; i<=inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    //left sub-tree
    int lInS = inS;
    int lInE = rootIndex-1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;

    //right sub tree
    int rPreS = lPreE+1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);

    return root;
}

BinaryTreeNode<int> * buildTree(int* in, int* pre, int size){
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

int height(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return 0;
    }

    return 1+ max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root){
    if(root == nullptr){
        return 0;
    }

    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}

pair<int, int> heightDiameter(BinaryTreeNode <int> *root)
{
    if(root == nullptr){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftans = heightDiameter(root->left);
    pair<int, int> rightans = heightDiameter(root->right);
    int ld = leftans.second;
    int rd = rightans.second;
    int lh = leftans.first;
    int rh = rightans.first;

    int height = 1 + max(lh, rh); 
    int diameter = max(lh+rh, max(ld,rd));

    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;

    return ans;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    BinaryTreeNode<int> *root= takeInputLevelWise();
    printBinaryTree(root);
    pair<int, int> n = heightDiameter(root);
    cout << n.first <<"   " << n.second << endl;
}
