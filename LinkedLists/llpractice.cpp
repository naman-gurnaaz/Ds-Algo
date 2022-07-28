#include<iostream>
#include "nodeclass.cpp"

using namespace std;


void print(Node *head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* takeInput(){ // -1 is terminator and the loops are iterative. The functions uses no tail.
    int data;                   //this function is not very efficient and time complexity is very high. O(n^2).
    cin>> data;
    Node *head = nullptr;
    while(data != -1){
        Node *newNode = new Node(data);

        if(head == nullptr){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;                    
}

Node* takeInputBetter(){
    int data;                   //this function is not very efficient and time complexity is very high. O(n^2).
    cin>> data;
    Node *head = nullptr;
    Node *tail = nullptr;
    while(data != -1){
        Node *newNode = new Node(data);

        if(head == nullptr){
            head = newNode;
            tail= newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);

    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;
    int count = 0;
    while(temp->next!= nullptr && count <  i-1){
        temp = temp->next;
        count++;
    }
    if(temp != nullptr){
        newNode -> next = temp->next;
        temp -> next = newNode;
    }
    return head;
}

Node* deleteNode(Node *head, int i){
    if(i == 0){
        Node *temp = head->next;
        delete head;
        return temp;
    }
    Node *temp = head;
    int count = 0;
    while(temp->next!= nullptr && count <  i-1){
        temp = temp->next;
        count++;
    }
    if(temp != nullptr){
        Node *a = temp->next;
        Node *b = a -> next;
        delete a;
        temp->next = b;
    }
    return head;

}

int lengthLLIterative(Node *head){
    int count =0;
    Node *temp = head;

    while(temp!=nullptr){
        temp = temp-> next;
        count++;
    }
    return count;
}

int lengthLLRecursive(Node *head){
    if(head == nullptr){
        return 0;
    }
    else{
        return lengthLLRecursive(head->next)+1;
    }
}

Node* insertNodeRecursively(Node *head, int i, int data){
    if(head == nullptr){
        return nullptr;
    }
    if(i==0){
        Node *temp = head;
        Node *newNode = new Node(data);
        newNode -> next = temp;
        head = newNode;
        return head;
    }
    Node *smallHead = insertNodeRecursively(head->next, i-1, data);
    head -> next =smallHead;
    return head;
}

Node* deleteNodeRecursively(Node *head, int i){
    if(head == nullptr){
        return nullptr;
    }
    if (i==0){
        Node* temp = head -> next;
        delete head;
        return temp;
    }
    Node *smallHead = deleteNodeRecursively(head-> next, i-1);
    head->next = smallHead;
    return head;
    
}

void printIthNode(Node *head, int i){
    if(head == nullptr){
        return;
    }
    int count =0;
    Node *temp = head;
    while (temp!=nullptr){
        if(count ==i){
            cout << temp -> data << endl;
        }
        temp = temp->next;
        count ++;
    }
    
}

void printReverseLL(Node* head){
    if(head ==nullptr){
        return;
    }

    printReverseLL(head->next);

    cout << head->data<<endl;
}

int findNode(Node *head, int n){
    if(head == nullptr){
        return -1;
    }
    int count = 0;
    Node *temp = head;
    while(temp != nullptr){
        if(temp -> data == n){
            return count;
        }
        count++;
        temp =temp->next;
    }
    return -1;
}

Node* appendLastToFirst(Node* head){
    Node* temp = head;
    while(temp->next->next!= nullptr){
        temp = temp->next;
    }

    Node* b = temp->next;
    b->next = head;
    head = b;
    temp->next = nullptr;

    return head;
}

Node* midOfLL(Node* head){
    if(head == nullptr){
        return nullptr;
    }
    Node *slow = head;
    Node *fast = head->next;

    while(fast -> next != nullptr && fast -> next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge2SortedLL(Node *h1, Node*h2){
    Node *fhead = nullptr;
    Node *ftail = nullptr;

    if(h1->data <= h2->data){
        fhead = h1;
        ftail = h1;
        h1 = h1->next;
    }
    else{
        fhead = h2;
        ftail = h2;
        h2 = h2->next;
    }

    while(h1 != nullptr && h2 != nullptr){
        if(h1->data <= h2->data){
            ftail->next = h1;
            h1 = h1->next;
            ftail = ftail->next;
        }
        else{
            ftail->next = h2;
            h2 = h2->next;
            ftail = ftail->next;
        }
    }

    if(h1==nullptr){
        ftail->next = h2;
    }
    if(h2==nullptr){
        ftail->next = h1;
    }

    return fhead;

}

Node* mergeSortLL(Node *head){

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node *m = midOfLL(head);
    Node *mid = m->next;
    m->next = nullptr;

    Node *half1 = mergeSortLL(mid);
    Node *half2 = mergeSortLL(head);

    Node *newHead = merge2SortedLL(half1, half2);

    return newHead;
   
}

Node* reverseLLRecursive(Node* head){                    //O(n^2) time complexity
    if(head == nullptr||head->next == nullptr){
        return head;       
    }

    Node *smallAns = reverseLLRecursive(head->next);
    Node *temp = smallAns;
    while(temp->next !=nullptr){
        temp = temp->next;
    }
    temp -> next = head;
    head -> next = nullptr;

    return smallAns;
}


Pair reverseLL2(Node *head){              // O(n) TIME COMPLEXITY
    if(head == nullptr||head->next == nullptr){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL2(head->next);
    smallAns.tail->next = head;
    head->next = nullptr;

    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;

}

Node* reverseLL2_Node(Node *head){
    return reverseLL2(head).head;
}

Node* reverseLL3(Node *head){             //O(n) time complexity
    if(head == nullptr||head->next == nullptr){
        return head;
    }

    Node *smallAns = reverseLL3(head->next);
    Node *tail = head->next;
    tail->next=head;
    head->next=nullptr;

    return smallAns;
}

Node* reverseLLIterative(Node *head){

    Node* prev = nullptr;
    Node* current = head;
    Node* temp = head;

    while(current!=nullptr){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}

//Practice questions:


int findNodeRecursive(Node *head, int i){
    if (head == nullptr||head->next==nullptr){
        return -1;
    }
    if(head->data==i){
        return 0;
    }

    int x = 1 + findNodeRecursive(head->next, i);

    return x;
    
}


Node* evenAfterOdd(Node* head){

    if (head==nullptr || head->next == nullptr){
        return head;
    }
    

    Node* temp = head;
    Node* oddH = nullptr;
    Node* evenH = nullptr;
    Node* oddT = nullptr;
    Node* evenT = nullptr;

    while(temp != nullptr){

        if(temp->data%2 == 0){
            if(evenH == nullptr){
                evenH = temp;
                evenT = evenH;
            }
            else{
                evenT->next = temp;
                evenT = evenT->next;
            }
        }

        if(temp->data%2 != 0){
            if(oddH == nullptr){
                oddH = temp;
                oddT = oddH;
            }
            else{
                oddT->next = temp;
                oddT = oddT->next;
            }
        }

        temp = temp->next;
    }

    if(oddH == nullptr){
        return evenH;
    }
    else{
        if(evenH != nullptr){
            oddT->next = evenH;
            evenT->next = nullptr;
            return oddH;
        }
        else{
            return oddH;
        }
    }

}

Node* removeDuplicate(Node* head){
    Node *temp = head;
    Node *p = nullptr; 

    while (temp!=nullptr&&temp->next!=nullptr){
    
        if(temp->data == temp->next->data){
            p = temp->next->next;
            delete temp->next;
            temp->next = p;
        }else{
            temp = temp->next;
        }

    }
    return head;
}


bool isPallindrome(Node* head){
    if(head==nullptr){
        return false;
    }
    if(head->next == nullptr){
        return true;
    }

    Node *temp = head;
    Node *mid = midOfLL(temp);
    Node *half = reverseLL3(mid->next);

    if(mid->data==mid->next->data){
        mid->next = nullptr;

        while(temp != nullptr && half != nullptr){
            if(temp->data == half->data){
                temp = temp->next;
                half = half->next;
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        while(temp != mid && half!=nullptr){
            if(temp->data == half->data){
                temp = temp->next;
                half = half->next;
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}


Node* appendNNodes(Node *head, int n){
    int length = lengthLLRecursive(head);

    if(n>length||n==0){
        return head;
    }

    int x = length - n, i =0;
    Node *temp = head;

    while(i < x-1 && temp->next!=nullptr){
        temp = temp -> next;
        i++;
    }

    Node *newHead = temp->next;
    temp->next = nullptr;
    Node *last = newHead->next;
    while(last->next!=nullptr){
        last = last->next;
    }
    last->next = head;

    return newHead;
}

Node* unionOf2LL(Node *head1, Node *head2){    //shorter soln will be to call mergesort and
    if(head1 == nullptr){                            // and remove duplicates together.
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }

    Node *temp1 = head1;
    Node *temp2 = head2;

    Node *last = head1;

    while(last->next!= nullptr){
        last = last->next;
    }

    while(temp1!= nullptr){
        
        while(temp2 != nullptr){

            if(temp1->data != temp2->data){
                if(last->next == nullptr){
                    last->next = temp2;
                    temp2 = temp2->next;
                    last = last->next;
                }
                last->next = temp2;
            }
            else{
                temp2=temp2->next;
            }
        }
        
        temp1= temp1->next;

    }

    return head1;
}


int main(){

    Node *head1 = takeInputBetter();
    cout << endl;
    Node *head2 = takeInputBetter();

    head1 = unionOf2LL(head1, head2);
    print(head1);
}
