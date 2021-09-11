//
//#include <iostream>
//using namespace std;
//class Node{
//public:
//    int data;
//    Node* next;
//};
//
//void addNodeAtBegin(Node** n,int value){
//    Node* new_head = new Node();
//    new_head->data=value;
//    new_head->next = *n; //n has address of head which has value NULL
//    *n=new_head; //making head value as new_head object
//}
//
//void addNodeAtEnd(Node** n,int value){
//    Node* last_node=new Node();
//    last_node->data=value;
//    last_node->next=NULL;
//    Node* temp=*n;//n has address of head which has LL
//
//    while(temp->next!=NULL){
//        temp=temp->next;
//    }
//    temp->next=last_node;
//}
//
//
//void addNodeMiddle(Node** n,int value){
//    Node* temp = *n;
//    while(temp->next!=NULL){
//        if(temp->data==20){
//            Node* middle_node=new Node();
//            middle_node->data=value;
//            middle_node->next=temp->next;
//            temp->next=middle_node;
//        }
//        temp=temp->next;
//    }
//
//
//
//}
//void displayLL(Node* t){
//    while(t!=NULL){
//        cout<<t->data<<" ";
//        t=t->next;
//    }
//}
//int main(){
//    Node* head=NULL;
//    addNodeAtBegin(&head,10);//created head sent
//    addNodeAtBegin(&head,20);
//    addNodeAtBegin(&head,30);
//    addNodeAtEnd(&head,40);
//    addNodeMiddle(&head,25);
//    displayLL(head);
//}
//
