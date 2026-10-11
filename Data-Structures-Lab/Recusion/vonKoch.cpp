#include <iostream>
using namespace std;

class Recursive{
    public:
        Recursive(){}

        int binomialcoefficient(int n,int k){
            if(k==0 || k == n){
                return 1;
            }
            int res = binomialcoefficient(n-1, k-1) + binomialcoefficient(n-1,k);
            return res;
        }

        int cube(int i, int count){
            if(count >= 3){
                return  i;
            }
         else{
            return  i * cube(i, count+1);
         }

        }

         

        void Checkcharinstring__OMMIT(char* stringentered, int stringlength, int curr, char charachter){
            if(curr == stringlength){
                return;
            }
            if(stringentered[curr] == charachter){
                stringentered[curr] = ' ';
            }
            Checkcharinstring__OMMIT(stringentered, stringlength,curr+1,charachter);
        };

    

         bool CheckCHARinSTRING(char* stringentered, int stringlength, int curr, char charachter,bool resval){
            if(curr == stringlength ){
                return resval;
            }
            if( stringentered[curr] == charachter){
                resval = true;
                return resval;
            }
           return CheckCHARinSTRING(stringentered, stringlength,curr+1,charachter,resval);
        }

        ~Recursive(){}
};




int main(){
    Recursive RecursiveClass;
    // int value = RecursiveClass.binomialcoefficient(6,1);
    // cout<<value<<endl;
    // int valuetoenter = 3;
    
    // int cubevalue = RecursiveClass.cube(valuetoenter,1);
    // cout<<"value : "<<cubevalue<<endl;

    char chararr[9]= "hello wo";
    bool isLpresent = RecursiveClass.CheckCHARinSTRING(chararr,9,0,'l',false);
    cout<<isLpresent<<endl;
    cout<<chararr<<endl;
    RecursiveClass.Checkcharinstring__OMMIT(chararr,9,0,'l');
    cout<<chararr<<endl;
    RecursiveClass.Checkcharinstring__OMMIT(chararr,9,0,'l');
    isLpresent = RecursiveClass.CheckCHARinSTRING(chararr,9,0,'l',false);
    cout<<isLpresent<<endl;
    
    return 0;
}