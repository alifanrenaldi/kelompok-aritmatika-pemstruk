/* Kelompok Aritmatika

Saddam Surya Mardiansyah  - 2017051014
Alifan Renaldi            - 2017051044
Kurniawan Dwi Yuliyanto   - 2057051010
*/


#include <bits/stdc++.h>
using namespace std;
void PPKM_infixpostfix(string Operator){
    
    int a;
    a = Operator.length();
    
    for (int p=0; p<a(); p++) {   
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

int main () 
{
    string Operator;
    getline(cin,Operator);
    PPKM_infixpostfix(Operator);
}
