////
////  stackGetMaxElement.cpp
////  DataStructures
////
////  Created by Ram Pratap Bachina on 27/08/21.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <stack>
//#include <vector>
//using namespace std;
//
//
///*
// * Complete the 'getMax' function below.
// *
// * The function is expected to return an INTEGER_ARRAY.
// * The function accepts STRING_ARRAY operations as parameter.
// */
//
//int str2int(string str){
//    int temp;
//    stringstream ss;
//    ss << str;
//    ss >> temp;
//    return temp;
//}
//
//vector<int> getMax(vector<string> operations) {
//    stack<int> myNumberStack;
//    stack<int> trackStack;
//    
//    vector<int> result;
//    for(auto i:operations){
//        if(i.at(0)=='1'){
//            istringstream iss(i);
//            int key,value;
//            iss >> key >> value;
//            myNumberStack.push(value);
//            if(!trackStack.empty()){
//                if(trackStack.top()<=value){
//                    trackStack.push(value);
//                }
//                else{
//                    trackStack.push(trackStack.top());
//                }
//            }
//            else{
//                trackStack.push(value);
//            }
//        }
//        else if (i.at(0)=='2') {
//            myNumberStack.pop();
//            trackStack.pop();
//        }
//        else if (i.at(0)=='3'){
//            result.push_back(trackStack.top());
//        }
//    }
//    return result;
//
//}
//int main(){
//    vector<string> mystring;
//    int n;
//    cin >> n;
//    
//    for(int i=0;i<n;i++){
//        string line;
//        getline(cin,line);
//        mystring.push_back(line);
//    }
//    vector<int> output;
//    output = getMax(mystring);
//    for(auto j: output){
//        cout<<j<<endl;
//    }
//    return 0;
//}
////
