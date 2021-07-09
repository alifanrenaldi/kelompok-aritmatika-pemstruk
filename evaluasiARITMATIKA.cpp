#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x){
    if(x == '+' || x == '-' ||      
       x == '*' || x == '/' ||
       x == '%'){
        return true;
    }else{
        return false;
    }
}

int putFirst(string x){
    if(x == "+" || x == "-"){
        return 1;
    }
    if(x == "*" || x == "/" || 
       x == "%"){
        return 2;
    }
    return 0;
}

bool large(string x, string y){
    int xValue, yValue;
    xValue = putFirst(x);
    yValue = putFirst(y);
    return xValue <= yValue;
}

double run (double x, double y, string n){
    if(n == "+"){
        return x+y;
    }
    else if(n == "-"){
        return x-y;
    }
    else if(n == "*"){
        return x*y;
    }
    else if(n == "/"){
        return x/y;
    }
    else if(n == "%"){
        return (int) x % (int) y;
    }
    return 0;
}

vector <string> infix;
vector <string> postfix;
string temp;
vector <string>::iterator itr;
vector <string>::iterator it;
vector <string>::iterator iter;

void input(){
    string str;
    char dam;
    while(cin.get(dam)){
        if(dam == '\n'){
            break;
        }
        if(dam != ' '){
            str.push_back(dam);
        }
    }
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(str[i] == '(' || str[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(str.substr(i, 1));
        }
        if(isdigit(str[i]) || (str[i] == '-' && i == 0 && isdigit(str[i+1]))){
            temp.push_back(str[i]);
            continue;
        }
        if(isOperator(str[i])){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            if((str[i] == '-' && isOperator(str[i-1])) || 
               (str[i] == '-' && i == 0 && str[i+1] == '(') || 
               (str[i] == '-' && str[i-1] == '(')){
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(str.substr(i, 1));
            }
        }
    }
    if(temp.length() != 0){
        infix.push_back(temp);
        temp.clear();
    }
}

void toPostfix(){
    stack <string> lipan;
    int i = 0;
    for(itr = infix.begin(); itr != infix.end() ; itr++, i++){
        if(isdigit(infix[i].back())){
            postfix.push_back(infix[i]);
            continue;
        }
        if(infix[i] == "("){
            lipan.push(infix[i]);
            continue;
        }
        if(infix[i] == ")"){
            while(!lipan.empty() && (lipan.top() != "(")){
                string toPush = lipan.top();
                postfix.push_back(toPush);
                lipan.pop();
            }
            lipan.pop();
            continue;
        }
        if(isOperator(infix[i][0])){
            if(lipan.empty() || lipan.top() == "("){
                lipan.push(infix[i]);
            }
            else{
                while(!lipan.empty() && (lipan.top() != "(") && 
                      large(infix[i], lipan.top())){
                    string toPush = lipan.top();
                    postfix.push_back(toPush);
                    lipan.pop();
                }
                lipan.push(infix[i] );
            }
            continue;
        }
    }
    while(!lipan.empty()){
        string toPush = lipan.top();
        postfix.push_back(toPush);
        lipan.pop();
    }
}
void result(){
    stack <string> lipan;
    int i = 0;
    double res;
    for(iter = postfix.begin(); iter != postfix.end() ; iter++, i++){
        if(isdigit(postfix[i].back())){
            lipan.push(postfix[i]);
        }
        else{
            double A = strtod((lipan.top()).c_str(), NULL);
            lipan.pop();
            double B = strtod((lipan.top()).c_str(), NULL);
            lipan.pop();
            res = run(B, A, postfix[i]);
            lipan.push(to_string(res));
        }
    }
    res = strtod((lipan.top()).c_str(), NULL);
    cout << res << endl;
}

int main(){
    input();
    toPostfix();
    result();
}
