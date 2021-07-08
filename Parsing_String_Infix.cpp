#include <bits/stdc++.h>
using namespace std;

void PPKM_DARURAT(string Operator){    
    for (int p=0; p<Operator.length(); p++) {   
        if(p==0 && Operator[p] == '-' && Operator[p+1]!= '('){
            cout << Operator[p];
        }
        if(Operator[p] == '('){
            if(Operator[p] == '(' && isdigit(Operator[p-1]) && (Operator[p-1]) != '-' && (Operator[p-1]) != ' '){
                cout << "* ";
            }    
        }
        if((Operator[p]=='-') && (Operator[p-1]=='+' || Operator[p-1]=='*' || Operator[p-1]=='/' || Operator[p-1]=='%')){
            if(!isdigit(Operator[p]=='-') && (Operator[p-1]=='+' || Operator[p-1]=='*' || Operator[p-1]=='/' ||Operator[p-1]=='%')){
                cout << "-1 * ";
            }
            else if(isdigit(Operator[p]=='-') && (Operator[p-1]=='+' || Operator[p-1]=='*' || Operator[p-1]=='/' || Operator[p-1]=='%')){
                cout << Operator[p] << " ";
            }
            else if(isdigit(Operator[p-1])){
                cout << Operator[p] << " ";
            }
        }
  
        else if(Operator[p]=='-'){
            
            if (isdigit (Operator[p-1]) && Operator[p+1] == '(') {
                cout << Operator[p] << " ";
            }
            else if (!isdigit(Operator[p-1]) && Operator[p+1] == '('){
                  cout << "-1 * ";
            }
            else if (!isdigit(Operator[p-1]) && Operator[p+1] == ')'){
                  cout << Operator[p] << " ";
            }
            else if (Operator[p-1] == ' ' && Operator[p+1] == ' '){
                  cout << Operator[p] << " ";
            }
            else if (isdigit(Operator[p-1])){
                  cout << Operator[p] << " ";
            }
           }
        else if (Operator [p] == ' '){
           }
        else if (isdigit(Operator[p])){
            if(isdigit(Operator[p+1])){
                  cout << Operator [p];
            }
            else if (!isdigit(Operator[p+1])){
                  cout << Operator[p] << " ";
            }
        }
        else
               cout << Operator[p] << " ";
    }
};

int main (){
    string Operator;
    getline(cin, Operator);
    PPKM_DARURAT(Operator);
}
