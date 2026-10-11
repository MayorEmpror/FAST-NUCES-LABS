#include <iostream>
using namespace std;


IssafeToplace(int board[],int row, int col){
    for(int i = 0; i< row; i++){
        if(board[i] == col || abs(board[i] - col) == abs(i - row)){
            return false;
        }

    }
    }



int main(){

    return 0;
}
