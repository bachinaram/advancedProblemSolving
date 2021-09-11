////
////  stackUsingLinkedList.cpp
////  DataStructures
////
////  Created by Ram Pratap Bachina on 26/08/21.
////
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//class Node{
//public:
//    int data;
//    Node* next;
//};
//
//Node* top=NULL;
//
//void push(int value){
//    Node* temp=new Node();
//    temp->data=value;
//    temp->next=top;
//    top=temp;
//}
//
//void pop(){
//    Node* mystack = top;
//    top=top->next;  //making second scond node as first node
//    mystack->next=NULL; //destroying connection in the first node
//    free(mystack); //removing first node
//}
//
//void display(){
//    while(top!=NULL){
//        cout<<top->data<<endl;
//        top=top->next;
//    }
//}
//
//int main(){
//    push(15);
//    push(25);
//    push(35);
//    pop();
//    pop();
//    display();
//}
