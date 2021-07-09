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
