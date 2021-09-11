////
////  hackerRankpr1.cpp
////  DataStructures
////
////  Created by Ram Pratap Bachina on 28/08/21.
////
//
//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//
////hackerrank stack equal stacks problem
//
//stack<int> returnStack(vector<int> h){
//    stack<int> temp;
//    for(auto i:h){
//        temp.push(i);
//    }
//    return temp;
//}
//
//int returnInt(vector<int> h){
//    int count=0;
//    for(auto j:h){
//        count=count+j;
//    }
//    return count;
//}
//
//int returnHighest(int a,int b, int c){
//    int result;
//    int max=a;
//    result=1;
//    if(b>max){
//        max=b;
//        result=2;
//    }
//    if(c>max) {
//        max=c;
//        result=3;
//    }
//    return result;
//}
//
//int stackTotal(stack<int> a){
//    stack<int> b = a;
//    int count=0;
//    while(!b.empty()){
//        count = count+b.top();
//        b.pop();
//    }
//    return count;
//}
//
//
//int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
//    stack<int> st1;
//    stack<int> st2;
//    stack<int> st3;
//    st1=returnStack(h1);
//    st2=returnStack(h2);
//    st3=returnStack(h3);
//    int h1_total = returnInt(h1);
//    int h2_total = returnInt(h2);
//    int h3_total = returnInt(h3);
//    bool res =  true;
//    int highest;
//    if(h1_total == h2_total && h2_total == h3_total){
//        res=false;
//    }
//    highest = returnHighest(h1_total,h2_total,h3_total);
//    while(res){
//        if(highest==1){
//            st1.pop();
//            h1_total=stackTotal(st1);
//            highest = returnHighest(h1_total, h2_total,h3_total);
//        }
//        else if (highest==2) {
//            st2.pop();
//            h2_total=stackTotal(st2);
//            highest = returnHighest(h1_total, h2_total,h3_total);
//        }
//        else if (highest==3){
//            st3.pop();
//            h3_total=stackTotal(st3);
//            highest = returnHighest(h1_total, h2_total,h3_total);
//        }
//        if(h1_total == h2_total && h2_total == h3_total){
//            res=false;
//        }
//    }
//    return h1_total;
//}
//
//
//int main(){
//    vector<int> v1;
//    vector<int> v2;
//    vector<int> v3;
//    v1.push_back(1);
//    v1.push_back(1);
//    v1.push_back(1);
//    v1.push_back(2);
//    v1.push_back(3);
//
//    v2.push_back(2);
//    v2.push_back(3);
//    v2.push_back(4);
//
//
//    
//    v3.push_back(1);
//    v3.push_back(4);
//    v3.push_back(1);
//    v3.push_back(1);
//    
//    int output;
//    output = equalStacks(v1,v2,v3);
//    cout<<output;
//}
