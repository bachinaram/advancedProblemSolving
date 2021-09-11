////
////  doublyLinkedList.cpp
////  DataStructures
////
////  Created by Ram Pratap Bachina on 09/09/21.
////
//
//#include<map>
//#include <iostream>
//
//using namespace std;
//
//class node{
//public:
//    int my_key;
//    int my_value;
//    node *prev_element,*next_element;
//    
//    node(int a,int b){
//        my_key=a;
//        my_value=b;
//        prev_element=NULL;
//        next_element=NULL;
//    }
//};
//
//class dll{
//    node *prev,*next;
//public:
//    dll(){
//        prev=NULL;
//        next=NULL;
//    }
//    
//    void deletelastElement(){
//        if(next == NULL) {
//            return;
//        }
//        if(prev == next) {
//            delete next;
//            prev = next = NULL;
//        }
//        else {
//            node *ref = next;
//            next = next->prev_element;
//            next->next_element = NULL;
//            delete ref;
//        }
//    }
//    void moveAccessNodeToHead(node *new_node){
//        if(new_node==prev){
//            return;
//        }
//        if(new_node == next){
//            next = next->prev_element;
//            next->next_element = NULL;
//        }
//        else{
//            new_node->prev_element->next_element = new_node->next_element;
//            new_node->next_element->prev_element = new_node->prev_element;
//        }
//        new_node->next_element = prev;
//        new_node->prev_element = NULL;
//        prev->prev_element = new_node;
//        prev = new_node;
//    }
//    node* retunLastElement() {
//        return next;
//    }
//    
//    node* addHeadNode(int a1,int b1){
//        node* new_node = new node(a1,b1);
//        //if no nodes exists making new node as only element
//        if(prev==NULL && next==NULL){
//            prev=new_node;
//            next=new_node;
//        }
//        else{
//            new_node->prev_element=prev; //
//            prev->prev_element=new_node;
//            prev=new_node;
//        }
//        return new_node;
//    }
//};
//
//class LRUCache{
//  int capacity, size;
//  dll *pageList;
//  map<int, node*> pageMap;
//  public:
//    LRUCache(int capacity) {
//      this->capacity = capacity;
//      size = 0;
//        pageList = new dll();
//        pageMap = map<int, node*>();
//    }
//
//    int get(int key) {
//        if(pageMap.find(key)==pageMap.end()) {
//          return -1;
//        }
//        int val = pageMap[key]->my_value;
//        pageList->moveAccessNodeToHead(pageMap[key]);
//        return val;
//    }
//
//    void put(int key, int value){
//        if(pageMap.find(key)!=pageMap.end()){
//            pageMap[key]->my_value = value;
//            pageList->moveAccessNodeToHead(pageMap[key]);
//            return;
//        }
//        if(size == capacity){
//            int k = pageList->retunLastElement()->my_key;
//            pageMap.erase(k);
//            pageList->deletelastElement();
//            size--;
//        }
//        node *page = pageList->addHeadNode(key, value);
//        size++;
//        pageMap[key] = page;
//    }
//    LRUCache(){
//        map<int, node*>::iterator i1;
//        for(i1=pageMap.begin();i1!=pageMap.end();i1++) {
//            delete i1->second;
//        }
//      delete pageList;
//    }
//};
//
//int main(){
//    cout << "Press a for LRU"<<endl;
//    cout << "Press b for LFU"<<endl;
//    char prog;
//    cin >> prog;
//    if(prog == 'a'){
//        int user_type_input,size_of_table;
//        cout << "Type 1: construction of cache" <<endl;
//        cin >> user_type_input;
//        cin >> size_of_table;
//        LRUCache cache(size_of_table);
//        
//        while(true){
//            cout << "Type 2: get" <<endl;
//            cout << "Type 3: set" <<endl;
//            cin >> user_type_input;
//            if (user_type_input == 2){
//                int value_in_list;
//                cin>>value_in_list;
//                cout<<cache.get(value_in_list)<<endl;
//            }
//            else if (user_type_input == 3){
//                int my_key,my_value;
//                cin >> my_key>> my_value;
//                cache.put(my_key,my_value);
//            }
//            else{
//                cout<<"Enter correct value for the type"<<endl;
//                break;
//            }
//        }
//    }
//    else if (prog == 'b'){
//        cout <<"second program"<<endl;
//    }
//    else{
//        cout<<"Please press only a or b characters for LRU and LFU selection"<<endl;
//    }
//    /*LRUCache cache(2);    // cache capacity 2
//    cache.put(2,2);
//    cout << cache.get(2) << endl;
//    cout << cache.get(1) << endl;
//    cache.put(1,1);
//    cache.put(1,5);
//    cout << cache.get(1) << endl;
//    cout << cache.get(2) << endl;
//    cache.put(8,8);
//    cout << cache.get(1) << endl;
//    cout << cache.get(8) << endl;*/
//    return 0;
//}
