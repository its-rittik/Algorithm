#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data ;
    node *nxt ;
};

class Linklist{
    public:

    node* head;
    Linklist(){
        head = NULL;
    }

    node* createnode(int value){
        node* newnode = new node;
        newnode -> data = value ;
        newnode -> nxt = NULL;
        return newnode;
    }

    void addnode(int value){
        node* newnode = createnode(value);
        if(head == NULL) head = newnode;
        else{
            node* temp = head ;

            while(temp -> nxt != NULL) temp = temp -> nxt;
            temp -> nxt = newnode ;
        }
    }

    void print(){
        node* temp = head;

        if(head == NULL) cout<<"Linklist is empty!!!\n";
        else{
            while(temp!= NULL) {
                cout<<temp -> data<<" ";
                temp = temp -> nxt; 
            }
        }
        cout<<endl;
    }

    void insert_after_position(int value , int position){
        node* toAdd = createnode(value);
        if(head == NULL) cout<<"Linklist is empty!!!\n";
        else if(position ==0 ){
            toAdd -> nxt = head;
            head = toAdd;
        }
        else{
            node* previous = head;
            for(int i = 0 ; i < position -1 ; i++){
                previous = previous -> nxt ;
            }
            toAdd -> nxt = previous -> nxt;
            previous -> nxt = toAdd;
        }
    }

    void deleting(int position){
        if(head == NULL){
            cout<<"Linklist is empty!!!\n";
            return;
        }
        else if(position = 0 ){
            head = head -> nxt;
            return;
        }
        else{
            node* previous = head;
            for(int i = 0 ; i < position-1 ; i++) previous = previous -> nxt;
            previous -> nxt = previous -> nxt -> nxt;
        }
    }

    void reversee(node* temp){
        if(temp == NULL) return ;
        reversee(temp -> nxt);
        cout<< temp -> data <<" "; 
    }

    void sizee(){
        node* temp = head ;
        int count = 0 ;

        while(temp != NULL){
            count++;
            temp = temp -> nxt ;
        }

        cout<<"Size of the link list: "<<count<<endl;
    }
};

int main(){
    Linklist l;
    l.addnode(5);
    l.addnode(7);
    l.addnode(8);
    l.addnode(10);

    cout<<"Print all the nodes: ";
    l.print();
    
    l.insert_after_position(6 , 1);
    cout<<"Insert after position 1: ";
    l.print();

    l.deleting(1);
    cout<<"Delete the node at postion 1: ";
    l.print();

    cout<<"Reverse the list: ";
    l.reversee(l.head);
    cout<<endl;

    
    l.sizee();

    return 0 ;
}