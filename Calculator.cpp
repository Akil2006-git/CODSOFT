#include <iostream>
using namespace std;
float add(float a, float b){
        return a+b;
}
float subtract(float a, float b){
        return a-b;
}
float multiply(float a, float b){
        return a*b;
}
float divide(float a, float b){
       return a/b;
}
int main(){
      float x,y;
      char op;
      cout<<"Enter the first number:";
      cin>>x;
      cout<<"Enter the second number:";
      cin>>y;
      cout<<"Enter the operation (+,-,*,/):";
      cin>>op;

      switch(op){

       case '+':
        cout<<"Result :"<<add(x,y);
       break;
       case '-':
        cout<<"Result :"<<subtract(x,y);
       break;
       case '*':
        cout<<"Result :"<<multiply(x,y);
       break;
       case '/':
           if(y!=0){
            cout<<"Result :"<<divide(x,y);
           }
           else{
            cout<<"Invalid output";
           }
        break;

       default:
       cout<<"INVALID OPERATION";

}

}
