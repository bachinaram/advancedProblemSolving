//
//  main.cpp
//  20173098_A2
//
//  Created by Ram Pratap Bachina on 09/09/21.
//
#include <unordered_map>
#include <map>
#include <iostream>
#include <string>
using namespace std;

class LFUNode {
  public:
    string myKey, myValue;
    int times;
    LFUNode *lfu_begining, *lfu_ending;
    LFUNode(string k1, string v1, int t){
        myKey=k1;
        myValue=v1;
        times=t;
        lfu_begining=NULL;
        lfu_ending=NULL;
    }
};

LFUNode* Lfuhead = NULL;
int LFUSize;
unordered_map<int, LFUNode*> frequencyNodeMap;
unordered_map<string, LFUNode*> keyNodeMap;

void addLFU(LFUNode* oldNode, LFUNode* newNode)
{
    LFUNode* nextNode = oldNode->lfu_ending;
    oldNode->lfu_ending = newNode;
    newNode->lfu_begining = oldNode;
    newNode->lfu_ending = nextNode;
    if (nextNode){
        nextNode->lfu_begining = newNode;
    }
}

void evictNode(LFUNode* Lfuhead)
{
    LFUNode* nodeToBeEvicted = Lfuhead;
    int times = nodeToBeEvicted->times;
    if (frequencyNodeMap[times] == nodeToBeEvicted) {
        frequencyNodeMap.erase(times);
    }
    keyNodeMap.erase(Lfuhead->myKey);
    LFUNode* nextNode = Lfuhead->lfu_ending;
    if (nextNode) {
        nextNode->lfu_begining = NULL;
    }
    cout << "A key is being evicted" << endl;
    cout << "key-->" << Lfuhead->myKey << " val-->" << Lfuhead->myValue << endl;
    Lfuhead = Lfuhead->lfu_ending;
}

void insertNewNode(LFUNode* newNode, string key)
{
    if (Lfuhead == NULL || Lfuhead->times != 1) {
        LFUNode* nextNode = nullptr;
        if (nextNode == NULL) {
            nextNode = NULL;
        }
        else {
            nextNode = nextNode;
        }
        nextNode = newNode;
        newNode->lfu_begining = NULL;
        newNode->lfu_ending = nextNode;
        if (nextNode) {
            nextNode->lfu_begining = newNode;
        }
        frequencyNodeMap[1] = newNode;
        keyNodeMap[key] = newNode;
        return;
    }
    
    if (keyNodeMap.size() == LFUSize) {
            evictNode(Lfuhead);
        }
        LFUNode* lastNodeWithSingleFrequency = frequencyNodeMap[1];
        addLFU(lastNodeWithSingleFrequency, newNode);
        frequencyNodeMap[1] = newNode;
        keyNodeMap[key] = newNode;
}
void detachNode(LFUNode* nodeToBeDetached)
{
    if(nodeToBeDetached->lfu_begining){
        nodeToBeDetached->lfu_begining->lfu_ending = nodeToBeDetached->lfu_ending;
    }
    else{
        Lfuhead = Lfuhead->lfu_ending;
    }
    nodeToBeDetached->lfu_begining = NULL;
    nodeToBeDetached->lfu_ending = NULL;
}
void updatePosOfExistingNode(LFUNode* existingNode)
{
    existingNode->times++;
    int times = existingNode->times;
    LFUNode* nodeWithSameFreq = frequencyNodeMap[times];
    LFUNode* nodeWithPrevFreq = frequencyNodeMap[times - 1];
    if (nodeWithSameFreq){
        detachNode(existingNode);
        addLFU(nodeWithSameFreq, existingNode);
        frequencyNodeMap[times] = existingNode;
    }
    else{
        if(nodeWithPrevFreq != existingNode){
            detachNode(existingNode);
            addLFU(nodeWithPrevFreq, existingNode);
        }
        frequencyNodeMap[times] = existingNode;
    }

}
    
//-----

class LRUNode {
  public:
  int key, value;
    LRUNode *node_begining, *node_ending;
    LRUNode(int k2, int v2){
        key=k2;
        value=v2;
        node_begining=NULL;
        node_ending=NULL;
    }
};

class LRUList {
    LRUNode *headDLL;
    LRUNode *tailDLL;
  
  bool isEmpty() {
      return tailDLL == NULL;
  }

  public:
    LRUList(){
        headDLL=NULL;
        tailDLL=NULL;
    }
    void remove_rear_page() {
        if(isEmpty()) {
            return;
        }
        if(headDLL == tailDLL) {
            delete tailDLL;
            headDLL = tailDLL = NULL;
        }
        else {
            LRUNode *temp = tailDLL;
            tailDLL = tailDLL->node_begining;
            tailDLL->node_ending = NULL;
            delete temp;
        }
    }
    
  void move_page_to_head(LRUNode *page) {
      if(page==headDLL) {
          return;
      }
      if(page == tailDLL) {
          tailDLL = tailDLL->node_begining;
          tailDLL->node_ending = NULL;
      }
      else {
          page->node_begining->node_ending = page->node_ending;
          page->node_ending->node_begining = page->node_begining;
      }

      page->node_ending = headDLL;
      page->node_begining = NULL;
      headDLL->node_begining = page;
      headDLL = page;
  }


    LRUNode* get_rear_page() {
      return tailDLL;
  }
    
    LRUNode* add_page_to_head(int key, int value) {
        LRUNode *page = new LRUNode(key, value);
        if(!headDLL && !tailDLL) {
            headDLL = tailDLL = page;
        }
        else {
            page->node_ending = headDLL;
            headDLL->node_begining = page;
            headDLL = page;
        }
        return page;
    }
  
};

class LRUCache{
  int capacity, size;
    LRUList *pageList;
  map<int, LRUNode*> pageMap;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
      size = 0;
        pageList = new LRUList();
        pageMap = map<int, LRUNode*>();
    }

    int get(int key) {
        if(pageMap.find(key)==pageMap.end()) {
          return -1;
        }
        int val = pageMap[key]->value;

        // move the page to headDLL
        pageList->move_page_to_head(pageMap[key]);
        return val;
    }

    void put(int key, int value) {
      if(pageMap.find(key)!=pageMap.end()) {
          // if key already present, update value and move page to head
          pageMap[key]->value = value;
          pageList->move_page_to_head(pageMap[key]);
          return;
      }

        if(size == capacity) {
          // remove rear page
          int k = pageList->get_rear_page()->key;
          pageMap.erase(k);
          pageList->remove_rear_page();
          size--;
        }

        // add new page to head to Queue
        LRUNode *page = pageList->add_page_to_head(key, value);
        size++;
        pageMap[key] = page;
    }

    ~LRUCache() {
      map<int, LRUNode*>::iterator i1;
      for(i1=pageMap.begin();i1!=pageMap.end();i1++) {
          delete i1->second;
      }
      delete pageList;
    }
};

int main(int argc, const char * argv[]) {
    cout << "Press a for LRU"<<endl;
    cout << "Press b for LFU"<<endl;
    char prog;
    cin >> prog;
    if(prog == 'a'){
        int user_type_input1,size_of_table;
        cout << "Type 1: construction of cache" <<endl;
        cin >> user_type_input1;
        cin >> size_of_table;
        LRUCache cache(size_of_table);
        while(true){
            cout << "Type 2: get" <<endl;
            cout << "Type 3: set" <<endl;
            cin >> user_type_input1;
            if (user_type_input1 == 2){
                int value_in_list;
                cin>>value_in_list;
                cout<<cache.get(value_in_list)<<endl;
            }
            else if (user_type_input1 == 3){
                int my_key,my_value;
                cin >> my_key>> my_value;
                cache.put(my_key,my_value);
            }
            else{
                cout<<"Enter correct value for the type"<<endl;
                break;
            }
        }
    }
    else if (prog == 'b'){
        cout <<"LFU program"<<endl;
        int user_type_input2;
        cout << "Type 1: construction of cache" <<endl;
        cin >> user_type_input2;
        cin >> LFUSize;
        string k3,v3;
        while(true){
            cout << "Type 2: get" <<endl;
            cout << "Type 3: set" <<endl;
            cin >> user_type_input2;
            if (user_type_input2 == 2){
                cin >> k3;
                LFUNode* existingNode = keyNodeMap[k3];
                if (!existingNode){
                    cout << "-1" << endl;
                }
                else{
                    updatePosOfExistingNode(existingNode);
                }
            }
            else if (user_type_input2 == 3){
                cin >> k3 >> v3;
                if (keyNodeMap.find(k3) == keyNodeMap.end()) { //newKey
                    LFUNode* newNode = new LFUNode(k3, v3, 1);
                    insertNewNode(newNode, k3);
                }
                else{
                    LFUNode* existingNode = keyNodeMap[k3];
                    existingNode->myValue = v3;
                    updatePosOfExistingNode(existingNode);
                }
            }
            else{
                cout<<"Enter correct value for the type"<<endl;
                break;
            }
        }
    }
    else{
        cout<<"Please press only a or b characters for LRU and LFU selection"<<endl;
    }
    /*LRUCache cache(2);    // cache capacity 2
    cache.put(2,2);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cache.put(1,1);
    cache.put(1,5);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    cache.put(8,8);
    cout << cache.get(1) << endl;
    cout << cache.get(8) << endl;*/
    return 0;
}
