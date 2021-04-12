#include <iostream>
#include "node.cpp"
using namespace std;

Node * reverseLLiteratively(Node *head){

    if(head == nullptr|| head -> next == nullptr){
        return head;
    }

    Node *current = head;
    Node *n;
    Node *prev = nullptr;

    while(current != nullptr) {
        n = current -> next;
        current -> next = prev;
        prev = current;
        current = n;
    }
    return prev;
}

Node * reverseLLrecursively_3(Node *head){

    //O(n) time complexity

    if(head == nullptr || head -> next == nullptr){
        return head;
    }

    Node *revH = reverseLLrecursively_3(head -> next);

    Node *tail = head -> next;

    tail -> next = head;
    head -> next = nullptr;

    return revH;
}

class Pair {

    public:
        Node *head;
        Node *tail;
};

Pair reverseLL_2(Node *head){

    //O(n) time complexity

    if(head == nullptr || head -> next == nullptr){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head -> next);
    smallAns.tail -> next = head;
    head -> next = nullptr;

    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;

    return ans;
}

Node * reverseLLbetter(Node *head){
    return reverseLL_2(head).head;
}

Node * insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count = 0;
    
    if (i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }

    Node * temp = head;
    while(temp != nullptr && count < i-1){
        temp = temp -> next;
        count++;
    }

    if (temp != nullptr){
        Node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    return head;
}

Node * deleteNode(Node *head, int i){
    int count = 0;
    Node *temp = head;

    if(i == 0) {
        Node *c = temp -> next;
        delete head;
        head = c;
        return head;
    }

    while(temp != nullptr && count < i-1){
        temp = temp -> next;
        count++;
    }

    if(temp != nullptr) {
        Node *a = temp -> next;
        Node *b = a -> next;
        temp -> next = b;
        delete a;
    }
    return head;
}

Node * insertNodeRecursively( Node* head, int i, int data) {
    if(head == nullptr) {
        return head;
    }

    if(i == 0){
        Node *newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }

    Node *a = insertNodeRecursively(head -> next, i-1, data);
    head -> next  = a;
    return head;
}

Node * deleteNodeRecursively(Node *head, int i){

    if(head == nullptr){
        return nullptr;
    }

    Node *temp = head;
    if(i == 0){
        Node *c = temp -> next;
        delete head;
        head = c;
        return head;
    }

    Node *x = deleteNodeRecursively(head -> next, i-1);
    head -> next = x;
    return head;
}

int LLlenght(Node *head){
    if (head == nullptr){
        return 0;
    }
    return 1 + LLlenght(head -> next);
}

void returnMidNode(Node *head){

    if(head == nullptr){
        return;
    } 

    Node *slow = head;
    Node *fast = head -> next;

    while (slow != nullptr){

        if((fast == nullptr) || (fast -> next == nullptr)){
            cout << '\n' << slow -> data << endl; 
        }
        slow = slow -> next;
        fast = fast -> next -> next;
    }
}

void returnIthNode(Node *head, int i){
    if(head == nullptr){
        return;
    }

    if(i == 0){
        cout << head -> data << endl;
    }

    Node *temp = head;
    int count = 0;

    while(temp != nullptr && count < i){
        temp = temp -> next;
        count++;
    }
    
    if(temp != nullptr){
        cout << temp -> data << endl;
    }

}

Node * merge2SortedLL(Node *head1, Node *head2){
    Node *finalHead = nullptr;
    Node *finalTail = nullptr;

    if((head1 -> data) < (head2 -> data)){
        finalHead = head1;
        finalTail = head1;
        head1 = head1 -> next;
        
    }else{
        finalHead = head2;
        finalTail = head2;
        head2 = head2 -> next;
    }

   while(head1 != nullptr && head2 != nullptr){
       if(head1 -> data < head2 -> data){
           finalTail -> next = head1;
           head1 = head1 -> next;
           finalTail = finalTail -> next;
        }else{
            finalTail -> next = head2;
            head2 = head2 -> next;
            finalTail = finalTail -> next;
        }
    }

    if(head1 == nullptr) {
        finalTail -> next = head2;
        head2 = head2 -> next;
        finalTail = finalTail -> next;
    }

    if(head2 == nullptr) {
        finalTail -> next = head1;
        head2 = head1 -> next;
        finalTail = finalTail -> next;
    }

    return finalHead;
}

Node * SortLLrecursively(Node *head){
    Node *slow = head;
    Node *fast = head -> next;
    Node *mid;

    while (slow != nullptr){

        slow = slow -> next;
        fast = fast -> next -> next;

        if((fast == nullptr) || (fast -> next == nullptr)){
            mid = slow->next;
            slow -> next = nullptr;
        }
    }

    
    Node *left = SortLLrecursively(head);
    Node *right = SortLLrecursively(mid);

    Node *fhead = merge2SortedLL(left, right);

    return fhead;
}

Node * reverseLLrecursively(Node *head){

    //O(n^2) time complexity

    if(head == nullptr || head -> next == nullptr){
        return head;
    }

    Node *revH = reverseLLrecursively(head -> next);

    Node *temp = revH;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }

    temp -> next = head;
    head -> next = nullptr;

    return revH;
}

Node * takeInput() {

    int data;
    cin >> data;
    Node *head = nullptr;
    Node *tail = nullptr;

    while(data != -1){
        Node *newNode = new Node(data);
        if(head == nullptr) {
        head = newNode;
        tail = newNode;
        }else {
            tail -> next = newNode;
            tail = tail -> next; 
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {

    Node *temp = head;

    while( temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {

    Node* head1 = takeInput();
    Node *head2 = reverseLLiteratively(head1);
    print(head2);
}