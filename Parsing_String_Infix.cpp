/* Kelompok Aritmatika

Saddam Surya Mardiansyah - 2017051014
*/


#include <bits/stdc++.h>
using namespace std;
void SosialDistancingInfix(string Operator){
    
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
