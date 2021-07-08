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
int main () {
    string Operator;
    getline(cin,Operator);
    SosialDistancingInfix(Operator);
}
  
