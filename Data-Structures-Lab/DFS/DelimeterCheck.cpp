#include <iostream>
#include <stack>
using namespace std;
//delimiter matching 

bool delimetermatch(string delstring){
    stack<char>* delstack = new stack<char>();   
    for(int i= 0; i< delstring.length(); i++){
              char curr = delstring[i];
              if(curr == '(' || curr == '[' || curr == '{'){
                delstack->push(curr);
              }
              else if(curr == ')' || curr == ']' || curr == '}'){
                if(delstack->top() == '(' && curr == ')') delstack->pop();
               else  if(delstack->top() == '[' && curr == ']') delstack->pop();
               else  if(delstack->top() == '{' && curr == '}') delstack->pop();
              }
               else {
            return false;      
          } 
    }
   if(delstack->empty()) return true;
   else return false;
}


int main(){
    string delemiter = "(({[[()]]}))()";
    bool check = delimetermatch(delemiter);
    cout<<check<<endl;
    return 0;
}