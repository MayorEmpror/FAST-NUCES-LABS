#include <iostream>
using namespace std;

int factorial(int i ){
    if(i <= 1) return 1;
    return i * factorial(i-1);
}

// Keeping Catalan just for reference, but it's not used here
int Catalan(int i){
    return factorial(2 * i) / (factorial(i + 1) * factorial(i));
}

void Backtracker(string* arr, string element , int num_zeros, int num_ones,int num_plus, int number_ofchar, int& index ){
    if(num_zeros == number_ofchar && num_ones == number_ofchar && num_plus == number_ofchar){
        arr[index++]  = element;
        return;
    }
    if(num_zeros < number_ofchar){  // strictly less
        Backtracker(arr, element + "0", num_zeros+1, num_ones, num_plus, number_ofchar, index);
    }
    if(num_ones < num_zeros){       // can only add '1' if there are more zeros already
        Backtracker(arr, element + "1", num_zeros, num_ones+1, num_plus, number_ofchar, index);
    }
    if(num_plus < num_ones){        // can only add '+' if there are more ones already
        Backtracker(arr, element + "+", num_zeros, num_ones, num_plus+1, number_ofchar, index);
    }
}

string* ImplementBackTracker(int number_ofchar, int& total){
    // Instead of Catalan, just overshoot and count manually
    total = 10000; // large enough
    string* elements = new string[total];
    int index= 0;
    Backtracker(elements,"",0,0,0,number_ofchar,index);
    total = index; // actual number found
    return elements;
}

int main(){
    int number_ofchar = 3;
    int total = 0;
    string* charachers = ImplementBackTracker(number_ofchar, total);
    cout<<"{";
    for(int i = 0;i<total; i++){
        cout<<charachers[i]<<",";
    }
    cout<<"}"<<endl;
    delete[] charachers;
    return 0;
}
