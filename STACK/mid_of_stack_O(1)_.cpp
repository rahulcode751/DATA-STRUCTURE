#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
class Node{
    public:
    Node *next;
    Node *prev;
    int data;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

Node* dummy = new Node(-1);
Node* head = dummy;
Node* mid = dummy;
int cnt = 0;

void push(int data){
    Node* cur = new Node(data);
    cur->prev = NULL;
    cur->next = head;
    cnt++;
    head->prev = cur;
    head = cur;
    if(cnt == 1){
        mid = cur;
    }
    else if(cnt%2 == 0){
        mid = mid->prev;
    }
}

int pop(){
    if(cnt == 0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    Node* temp = head;
    int x = head->data;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    cnt--;
    if(cnt%2 != 0){  //(cnt&1) = cnt%2 != 0
        mid = mid->next;
    }
    free(temp);
    return x;
}

int middle(){
    if(cnt == 0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return mid->data;
}

void print(){
    if(cnt == 0){
        cout<<"Stack is empty"<<endl;
        return;
    }
        Node* cur = head;
        for(int i=0;i<cnt; i++){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    cout<<"Middle is-> "<<middle()<<endl;
    cout<<endl;

    cout<<"Deleted element is -> "<<pop()<<endl;
    print();
    cout<<"Middle element is -> "<<middle()<<endl;
    cout<<endl;

    cout<<"Deleted element is -> "<<pop()<<endl;
    print();
    cout<<"Middle element is -> "<<middle()<<endl;
    cout<<endl;

    cout<<"Deleted element is -> "<<pop()<<endl;
    print();
    cout<<"Middle element is -> "<<middle()<<endl;
    cout<<endl;

    cout<<"Deleted element is -> "<<pop()<<endl;
    print();
    cout<<"Middle element is -> "<<middle()<<endl;
    cout<<endl;
	return 0;
}



