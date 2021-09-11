//
//  lfuDoublyLLMap.cpp
//  DataStructures
//
//  Created by Ram Pratap Bachina on 10/09/21.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
struct node {
    int freq;
    string key, val;
    node *left, *right;
    node(int freq, string key, string val, node* left, node* right)
    {
        this->freq = freq;
        this->key = key;
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node* head = NULL;
unordered_map<int, node*> frequencyNodeMap;
unordered_map<string, node*> keyNodeMap;
int maxSizeOfCache;
void putNode(node* oldNode, node* newNode)
{
    node* nextNode = oldNode->right;
    oldNode->right = newNode;
    newNode->left = oldNode;
    newNode->right = nextNode;
    if (nextNode)
        nextNode->left = newNode;
}void evictNode(node* head)
{
    node* nodeToBeEvicted = head;
    int freq = nodeToBeEvicted->freq;
    if (frequencyNodeMap[freq] == nodeToBeEvicted) {
        frequencyNodeMap.erase(freq);
    }
    keyNodeMap.erase(head->key);
    node* nextNode = head->right;
    if (nextNode) {
        nextNode->left = NULL;
    }
    cout << "A key is being evicted" << endl;
    cout << "key-->" << head->key << " val-->" << head->val << endl;
    head = head->right;
}void insertNewNode(node* newNode, string key)
{
    if (head == NULL || head->freq != 1) {
        node* nextNode;
        if (head == NULL) {
            nextNode = NULL;
        }
        else {
            nextNode = head;
        }
        head = newNode;
        newNode->left = NULL;
        newNode->right = nextNode;
        if (nextNode) {
            nextNode->left = newNode;
        }
        frequencyNodeMap[1] = newNode;
        keyNodeMap[key] = newNode;
        return;
    }if (keyNodeMap.size() == maxSizeOfCache) {
        evictNode(head);
    }
    node* lastNodeWithSingleFrequency = frequencyNodeMap[1];
    putNode(lastNodeWithSingleFrequency, newNode);
    frequencyNodeMap[1] = newNode;
    keyNodeMap[key] = newNode;
}
void detachNode(node* nodeToBeDetached)
{
    if (nodeToBeDetached->left) {
        nodeToBeDetached->left->right = nodeToBeDetached->right;
    }
    else {
        head = head->right;
    }
    nodeToBeDetached->left = NULL;
    nodeToBeDetached->right = NULL;
}
void updatePosOfExistingNode(node* existingNode)
{
    existingNode->freq++;
    int freq = existingNode->freq;
    node* nodeWithSameFreq = frequencyNodeMap[freq];
    node* nodeWithPrevFreq = frequencyNodeMap[freq - 1];
    if (nodeWithSameFreq) {
        detachNode(existingNode);
        putNode(nodeWithSameFreq, existingNode);
        frequencyNodeMap[freq] = existingNode;
    }
    else {
        if (nodeWithPrevFreq != existingNode) {
            detachNode(existingNode);
            putNode(nodeWithPrevFreq, existingNode);
        }
        frequencyNodeMap[freq] = existingNode;
    }
}
int main()
{
    cin >> maxSizeOfCache;
    string command, key, val;
    while (true) {
        cin >> command;
        cin >> key;
        if (command == "set") {
            cin >> val;
            if (keyNodeMap.find(key) == keyNodeMap.end()) { //newKey
                node* newNode = new node(1, key, val, NULL, NULL);
                insertNewNode(newNode, key);
            }
            else { //oldKey
                node* existingNode = keyNodeMap[key];
                existingNode->val = val;
                updatePosOfExistingNode(existingNode);
            }
        }
        else if (command == "get") {
            node* existingNode = keyNodeMap[key];
            if (!existingNode) {
                cout << "key not present in cache" << endl;
            }
            else {
                updatePosOfExistingNode(existingNode);
            }
        }
        else {
            break;
        }
    }
}
