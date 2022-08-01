/*Problem Statement:

While playing an RPG game, you were assigned to complete one of the hardest quests in this game. There are n monsters you’ll need to defeat in this quest. Each monster i is described with two integer numbers – poweri and bonusi. To defeat this monster, you’ll need at least poweri experience points. If you try fighting this monster without having enough experience points, you lose immediately. You will also gain bonusi experience points if you defeat this monster. You can defeat monsters in any order.

The quest turned out to be very hard – you try to defeat the monsters but keep losing repeatedly. Your friend told you that this quest is impossible to complete. Knowing that, you’re interested, what is the maximum possible number of monsters you can defeat?

Input:

The first line contains an integer, n, denoting the number of monsters. The next line contains an integer, e, denoting your initial experience.
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, poweri, which represents power of the corresponding monster.
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, bonusi, which represents bonus for defeating the corresponding monster.
*/

//using the ll concepts for merging and comparing.


#include <iostream>
using namespace std;

class Monster{
    public:
    int power;
    int bonus;
    Monster* next;

    Monster(int p, int b){
        power = p;
        bonus = b;
        next = nullptr;
    }
};

Monster* takeIp(int p[], int b[], int n){
    
    Monster* head =nullptr; 
    Monster* tail = nullptr;

    for(int i =0; i< n; i++){
        Monster* newNode = new Monster(p[i], b[i]);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    return head;
}

Monster* merge2ll(Monster* h1, Monster*h2){
    Monster *fhead = nullptr;
    Monster *ftail = nullptr;

    if(h1->power<= h2->power){
        fhead = h1;
        ftail = h1;
        h1 = h1->next;
    }
    else{
        fhead = h2;
        ftail = h2;
        h2 = h2->next;
    }

    while(h1!=nullptr && h2!=nullptr){
        if(h1->power<= h2->power){
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

    if(h1 == nullptr){
        ftail->next = h2;
    }
    if(h2 == nullptr){
        ftail->next = h1;
    }
    return fhead;
}

Monster* mergeSort(Monster* head){
    if(head == nullptr||head->next == nullptr){
        return head;
    }
    Monster* slow = head;
    Monster* fast = head->next;

    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    Monster *mid = slow->next;
    slow->next = nullptr;

    Monster *half1 = mergeSort(mid);
    Monster *half2 = mergeSort(head);

    Monster *newHead = merge2ll(half1, half2);

    return newHead;
}

int defeatMonster(Monster* head, int exp, int n){
    int count=0;
    Monster *newHead = mergeSort(head);
    for(int i =0; i< n; i++){
        if(exp >= newHead->power && newHead!= nullptr){
            count++;
            exp = exp + newHead->bonus;
            newHead = newHead->next;
        }
        else{
            break;
        }
    }
    
    return count;

}

int main(){

    int n, e;
    cin >> n >> e;
    int p[n], b[n];
    for(int i =0; i< n; i++){
        cin >> p[i];
    }
    for(int i =0; i< n; i++){
        cin >> b[i];
    }

    Monster *head = takeIp(p, b, n);
    int x = defeatMonster(head, e, n);
    cout<< x << endl;

}

