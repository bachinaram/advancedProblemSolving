//
//  main.cpp
//  20173098_Q3
//
//  Created by Ram Pratap Bachina on 11/09/21.
//

#include <iostream>
using namespace std;
int k1=0;
class spArray{
    int rw,cl;
    int** spMatrix1;
    int k;
    
public:
    spArray(int r, int c){
        rw=r;
        cl=c;
        spMatrix1 = new int *[r*c];
        for (int i = 0; i < r*c; i++){
            spMatrix1[i] = new int[3];
        }
        k=0;
    }
    spArray sparse(int r, int c, int inp_arr1[500][500] ){
        k1=0;
        spArray output(r,c);
        output.k=k;
        for(int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (inp_arr1[i][j] != 0)
                {
                    output.spMatrix1[k1][0] = i;
                    output.spMatrix1[k1][1] = j;
                    output.spMatrix1[k1][2] = inp_arr1[i][j];
                    k1++;
                    //cout << i << " "<< j <<" "<<inp_arr1[i][j]<< " "<<k<< endl;
                }
            }
        }
        return output;
    }
    
    void display(){
        for (int i=0; i<k1; i++)
            {
                cout << spMatrix1[i][0] << " " << spMatrix1[i][1] << " " << spMatrix1[i][2] << endl;
            }
    }
    
};




void converToSparse(int r,int c,int orig_matrix[500][500]){
    cout<<"Given Matrix"<<endl;
    cout<<"____________"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << orig_matrix[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}




void matricesAddition(spArray sp2){
    int firstR=0;
    int secondR=0;
    
/*
    while (firstR < l1 && secondR < l2){
        if (a[firstR][0] > b[secondR][0] || (a[firstR][0] == b[secondR][0] && a[firstR][1] > b[secondR][1])){
            cout<<b[secondR][0]<< " ";
            cout<<b[secondR][1]<< " ";
            cout<<b[secondR][2]<< " ";
            secondR++;
        }
        else if (a[firstR][0] < b[secondR][0] || (a[firstR][0] == b[secondR][0] && a[firstR][1] < b[secondR][1])){
            cout<<b[firstR][0]<< " ";
            cout<<b[firstR][1]<< " ";
            cout<<b[firstR][2]<< " ";
            firstR++;
        }
        else{
            int addedval = a[firstR][2] + b[secondR][2];
            if (addedval != 0){
                cout << a[firstR][0]<<" ";
                cout<< a[firstR][1]<<" ";
                cout<< addedval<<" ";
            }
            firstR++;
            secondR++;
        }
    }
    
    while(firstR<l1){
        cout<<a[firstR][0]<< " ";
        cout<<a[firstR][1]<< " ";
        cout<<a[firstR][2]<< " ";
        firstR++;
    }
    
    while(secondR<l2){
        cout<<b[secondR][0]<< " ";
        cout<<b[secondR][1]<< " ";
        cout<<b[secondR][2]<< " ";
        secondR++;
    }*/
}

int main(int argc, const char * argv[]){
    int user_input,inp1_rows,inp1_cols,inp2_rows,inp2_cols;
    cout << "type 1 for addition and multiplication"<<endl;
    cout << "type 2 for transpose operation"<<endl;
    cin >> user_input;
    if(user_input==1){
        cout<<"enter row and col with format inp1 inp2 twice for two matrices"<<endl;
        cin >> inp1_rows >> inp1_cols;
        cin >> inp2_rows >> inp2_cols;
        int inp_arr1[500][500] = {{0,23,0,45,0},{0,0,10,12,0},{0,0,0,0,0},{0,0,0,5,0},{0,15,12,0,0}};
        int inp_arr2[500][500] = {{0,0,0,0,0},{0,0,0,8,0},{0,0,0,0,23},{0,0,0,9,0},{0,20,25,0,0}};
        converToSparse(inp1_rows,inp1_cols,inp_arr1);
        spArray m1(inp1_rows,inp1_cols);
        spArray sp1 = m1.sparse(inp1_rows,inp1_cols,inp_arr1);
        sp1.display();
        converToSparse(inp2_rows,inp2_cols,inp_arr2);
        spArray m2(inp2_rows,inp2_cols);
        spArray sp2 = m2.sparse(inp2_rows,inp2_cols,inp_arr2);
        sp2.display();
        
        if(inp1_rows==inp2_rows && inp1_cols==inp2_cols){
            //sp1.matricesAddition(sp2);
            //matricesAddition(out_sp_matrix1,len_1,out_sp_matrix2,len_2);
        }
        else{
            cout<<"matrix dimension are not same hence we cannot add them"<<endl;
        }
        
        if(inp1_cols == inp2_rows){
            //matricesMultiplication(out_sp_matrix1,out_sp_matrix2);
        }
        else{
            cout<<"both matrices dimension are accurate hence cannot perform multiply"<<endl;
        }
    }
    else if (user_input==2){
        cout<<"enter row and col with format inp1 inp2"<<endl;
        cin >> inp1_rows >> inp1_cols;
        int inp_arr1[500][500] = {{0,23,0,45,0},{0,0,10,12,0},{0,0,0,0,0},{0,0,0,5,0},{0,15,12,0,0}};

        spArray m1(inp1_rows,inp1_cols);
        spArray sp = m1.sparse(inp1_rows,inp1_cols,inp_arr1);
        sp.display();

    }
    else{
        cout<<"choose 1 or 2"<<endl;
    }
    return 0;
}


