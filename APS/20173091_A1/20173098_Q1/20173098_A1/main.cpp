//
//  main.cpp
//  20173098_A1
//
//  Created by Ram Pratap Bachina on 06/09/21.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int current_pos=0;

string addFunc(string first,string second){
    string output;
    if (first.length() > second.length()){
        swap(first, second);
    }
    int siz_of_str1 = first.length();
    int siz_of_str2 = second.length();
    int diff = siz_of_str2 - siz_of_str1;

    int carry = 0;
    for (int i=siz_of_str1-1; i>=0; i--)
    {
        int sum = ((first[i]-'0') +
                   (second[i+diff]-'0') +
                   carry);
        output.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=siz_of_str2-siz_of_str1-1; i>=0; i--)
    {
        int sum = ((second[i]-'0')+carry);
        output.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry){
        output.push_back(carry+'0');
    }
    reverse(output.begin(), output.end());
    return output;
}

string readLine(string input,int pos){
    string result;
    auto inp_str_len = input.length();
    for (int i=pos;i<inp_str_len;i++){
        if(input[i]=='+' || input[i]=='-' || input[i]=='x'){
            current_pos=i+1;
            break;
        }
        else if (i==inp_str_len-1){
            current_pos=i+1;
            result.push_back(input[i]);
            break;
        }
        result.push_back(input[i]);
    }
    return result;
}



string addMulFunc(string first,string second){
    int result[3000]={0};
    int tempj,extra;
    string res_string;
    int i;
    int first_arr[1000];
    int siz_of_str1 = first.length();
    int siz_of_str2 = second.length();
    int second_arr[1000];
    for(i = siz_of_str1-1,tempj=0;i>=0;i--,tempj++)
    {
        first_arr[tempj] = first[i]-'0'; //12* converts each str in 12 to int eg str(2) to int(2) and str(1) to int(1)
    }
    for(i = siz_of_str2-1,tempj=0;i>=0;i--,tempj++)
        {
            second_arr[tempj] = second[i]-'0';
        }
    for(i = 0;i < siz_of_str2;i++)
        {
            for(tempj = 0;tempj < siz_of_str1;tempj++)
            {
                result[i+tempj] += second_arr[i]*first_arr[tempj];
            }
        }
    for(i = 0;i < siz_of_str1+siz_of_str2;i++)
        {
            extra = result[i]/10;
            result[i] = result[i]%10;
            result[i+1] = result[i+1] + extra;
        }
    for(i = siz_of_str1+siz_of_str2; i>= 0;i--)
    {
        if(result[i] > 0)
            break;
    }
    for(;i >= 0;i--)
        {
            res_string.push_back(result[i]+'0');
        }
    return res_string;
}

int stringToInt(string st1){
    int result;
    stringstream mystream(st1);
    mystream >> result;
    return result;
}

string difference(string first,string second){
    int siz_of_str1 = first.length();
    int siz_of_str2 = second.length();
    int carry = 0;
    string result;
    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());
    for (int i = 0; i < siz_of_str2; i++){
        int subtraction =((first[i] - '0') - (second[i] - '0') - carry);
        if (subtraction < 0) {
            subtraction = subtraction + 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        result.push_back(subtraction + '0');
    }
    for (int i = siz_of_str2; i < siz_of_str1; i++) {
        int subtraction = ((first[i] - '0') - carry);
        if (subtraction < 0) {
            subtraction = subtraction + 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        result.push_back(subtraction + '0');
        }
    reverse(result.begin(), result.end());
    return result;
}
//--
int gcd(long long int f, long long int s) {
    if (f < s) {
        f = s;
        s = f;
    }
    if (f % s == 0){
        return s;
    }
    else{
        f = f%s;
    }
    return gcd(s, f);
}


int mod_large(string first, long long int my_second_number) {
    int remainder,existing,res;
    int secondRemainder = 1000000 % my_second_number;
    string reverseSix;
    int siz_of_str1 = first.length();
    if (siz_of_str1 <= 6) {
        existing = stringToInt(first);
        res = existing % my_second_number;
        return res;
    }
    reverseSix = first.substr(siz_of_str1-6, 6);
    first = first.substr(0, siz_of_str1-6);
    remainder = stringToInt(reverseSix);
    int modulusRemainder = remainder % my_second_number;
    return (mod_large(first, my_second_number)*secondRemainder+modulusRemainder)%my_second_number;
}

int gcd_of_two_numbers(string first, string second) {
    int result1;
    long long int my_second_number = stoll(second, nullptr, 10);
    long long int gcd_out = mod_large(first, my_second_number);
    if (gcd_out == 0){
        return my_second_number;
    }
    result1= gcd(my_second_number, gcd_out);
    return result1;
}



//---------


int crossWithEverythingInArray(int eachofI, int output[], int outputS)
{
    int carry = 0;
    for (int i=0; i<outputS; i++)
    {
        int prod = output[i] * eachofI + carry;
        output[i] = prod % 10;
        carry  = prod/10;
    }
    while(carry)
    {
        output[outputS] = carry%10;
        carry = carry/10;
        outputS++;
    }
    return outputS;
}

void factorial(long long int userinput)
{
    int outputLen = 1;
    int output[3000];
    output[0] = 1;
    for (int i=2; i<=userinput; i++){
        outputLen = crossWithEverythingInArray(i, output, outputLen);
    }
    for (int temp=outputLen-1; temp>=0; temp--){
        cout << output[temp];
    }
    
}

//==
string exponent_fun(int base,int exponent){
    string result;
    int initial_output = 0;
    int output[3000];
    int ref_var = base;
     
    // Initialize result
    while (ref_var != 0) {
        output[initial_output++] = ref_var % 10;
        ref_var = ref_var / 10;
    }
    for (int i = 2; i <= exponent; i++){
        initial_output = crossWithEverythingInArray(base, output, initial_output);
    }
    for (int i = initial_output - 1; i >= 0; i--){
        result+=to_string(output[i]);
    }
    return result;
}

int main() {
    int operation;
    cout << "Press 1 for Exponentiation \nPress 2 for GCD \nPress 3 for Factorial"<<endl;
    cout << "Press 4 for Calculator" << endl;
    cin >> operation;
    cout << "you have opted for option "<< operation <<endl;
    
    if(operation>=1 and operation<=4){
        if(operation == 4){
            cin.ignore();
            string inp_str;
            getline(cin,inp_str);
            string result;
            
            string top_str,next_str,result_str;
            
            char math_symbol;
            auto inp_str_len = inp_str.length();
            for (int i=0;i<inp_str_len;i++){
                if(inp_str[i]=='+' || inp_str[i]=='-' || inp_str[i]=='*'){
                    current_pos=i+1;
                    break;
                }
            top_str.push_back(inp_str[i]);
            math_symbol=inp_str[i];
            }
            while(inp_str.length() > current_pos){
                if(inp_str[current_pos-1] == '+'){
                    next_str=readLine(inp_str,current_pos);
                    top_str=addFunc(top_str, next_str);
                    result_str=top_str;
                }
                else if(inp_str[current_pos-1] == 'x'){
                    next_str=readLine(inp_str,current_pos);
                    top_str=addMulFunc(top_str, next_str);
                    result_str=top_str;
                }
                else if(inp_str[current_pos-1] == '-'){
                    next_str=readLine(inp_str,current_pos);
                    top_str=difference(top_str, next_str);
                    result_str=top_str;
                }
                else{
                    cout << "your input has operators other than + - x"<<endl;
                    break;
                }
            }
            cout <<result_str<<endl;
        }
        else if (operation == 1){
            int base_x,exponent_n;
            cin >> base_x >> exponent_n;
            if(base_x == 0){
                cout << "0" <<endl;
            }
            else if(exponent_n == 0){
                cout << "1" <<endl;
            }
            else{
                string final_exp_out;
                final_exp_out=exponent_fun(base_x,exponent_n);
                cout << final_exp_out<<endl;
                
            }
        }
        else if (operation == 2){
            string first_str,second_str,result_gcd;
            cin >> first_str >>second_str;
            cout << gcd_of_two_numbers(first_str,second_str)<<endl;
        }
        else if (operation == 3){
            long long int fact;
            cin >> fact;
            factorial(fact);
        }
        else{
            cout << "Invalid option" <<endl;
        }
        return 0;
    }
}
 
