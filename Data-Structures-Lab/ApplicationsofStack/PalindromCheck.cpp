#include <iostream>
#include <stack>
using namespace std;

class Node{
    public:
    char ch;
    Node* next;
    Node(char ch){
        this->ch = ch;
        this->next = nullptr;
    }
    Node(const Node& other){
        this->ch = other.ch;
        this->next = other.next;
    }
    Node& operator =(const Node& other){
        if(this != &other){
            this->ch = other.ch;
            this->next = other.next;
        }
        return *this;
    }
    ~Node(){}
};
class Stack{
    public:
    Node* top;
    Stack(){
        this->top = nullptr;
    }
    char Top(){
        return this->top->ch;
    }
    void pop(){
        Node* temp =  this->top;
        this->top = this->top->next;
        temp->next = nullptr;
        delete temp;
    }
    void push(char value){
        Node* newnode = new Node(value);
        newnode->next = this->top;
        this->top = newnode;
    }
    bool empty(){
        return (this->top == nullptr);
    }

    ~Stack(){}
};


bool checkpalindrome(string word){
    Stack* stckfor = new Stack();
    Stack* stckback = new Stack();
    bool ispalindrome = true;
        // push the word on to the stack forward 
        for(int i = 0; i< word.length(); i++){
            stckfor->push(word[i]);
        }
      
        for(int i = word.length()-1; i >=0; i--){
            stckback->push(word[i]);
        }
        while(!stckback->empty() && !stckfor->empty()){
          if(stckfor->Top() == stckback->Top()) {
            stckfor->pop();
            stckback->pop();
            
          }
            else{
                  ispalindrome = false;
                  break;
            }
        
        }
        if(stckback->empty() && stckfor->empty() && ispalindrome) return true;
        delete stckback;
        delete stckfor;
        return false;
};


char digitToSymbol(int digit) {
    if (digit < 10)
        return '0' + digit;
    else
        return 'A' + (digit - 10);
}

// Convert a decimal number to a given base (2–27)
string convertBase(int num, int base) {
    if (num == 0) return "0";

    stack<char> remStack;
    
    while (num > 0) {
        int remainder = num % base;
        remStack.push(digitToSymbol(remainder));
        num /= base;
    }

    // Build final string from stack
    string result = "";
    while (!remStack.empty()) {
        result += remStack.top();
        remStack.pop();
    }

    return result;
}


int main(){
    bool word_1 = checkpalindrome("hashir");
    bool word_2 = checkpalindrome("pop");
    cout<<"word 1 : "<< word_1<<endl;
    cout<<"word 2 : "<<word_2<<endl;

    int num, base;
    
    cout << "Enter decimal number: ";
    cin >> num;

    cout << "Enter base (2–27): ";
    cin >> base;

    if (base < 2 || base > 27) {
        cout << "Invalid base!" << endl;
        return 0;
    }

    string converted = convertBase(num, base);
    cout << "Converted: " << converted << endl;
    return 0;
    
}