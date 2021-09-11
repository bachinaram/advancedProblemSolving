////
////  queueUsingLinkedList.cpp
////  DataStructures
////
////  Created by Ram Pratap Bachina on 27/08/21.
////
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//class Node{
//public:
//    int data;
//    Node *next;
//}*front,*rear=NULL;
////10
////10 20
////10 20 30
////we always work on rear in linked list we have to add new node at the end
//
//void push(int value){
//    Node* n=new Node();
//    n->data=value;
//    n->next=NULL;
//    if(front == NULL){
//        front=rear=n;
//    }
//    else{
//        rear->next=n;
//        rear=n;
//    }
//}
//void pop(){
//    if(front == NULL){
//        cout<<"Q is empty"<<endl;
//    }
//    else{
//        Node* m=front;
//        front=front->next;
//        m->next=NULL;
//        free(m);
//    }
//}
//
//void displayQueue(){
//    Node* p=front;
//    while(p->next!=NULL){
//        cout<<p->data<<endl;
//        p=p->next;
//    }
//    cout<<p->data<<endl;
//}
//
//int main(){
//    push(10);
//    push(20);
//    pop();
//    push(40);
//    pop();
//    push(60);
//    push(90);
//    displayQueue();
//}
