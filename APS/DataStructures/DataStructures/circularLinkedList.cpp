//#include <iostream>
//using namespace std;
//class Node{
//public:
//    int data;
//    Node* next;
//};
//
//void addNewNodeBegin(Node** n,int value){
//    Node* temp=*n; //n has the address of head which is NULL, so now temp has empty/ll
//    Node* begin = new Node();
//    begin->data=value;
//    if(temp==NULL){
//        begin->next=begin;
//        *n = begin;
//    }
//    else{
//        do{
//            temp=temp->next;
//        }
//        while(temp->next!=begin->next);
//        temp->next=begin;
//        *n=begin;
//    }
//}
////2->3->5->2 now 4->2->3->5->4
//
//void displayCLL(Node* n){
//    Node* temp;
//    temp = n;
//    do{
//        cout<<n->data<<' ';
//        n=n->next;
//    }
//    while(temp!=n->next);
//}
//int main(){
//    Node* head=NULL;
//    //addNewNodeBegin(&head,10);
//    addNewNodeBegin(&head,20);
//    displayCLL(head);
//    
//}
