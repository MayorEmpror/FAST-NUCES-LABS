#include <iostream>
using namespace std;

int main(){
    float** resultcard = new float*[5];
    for(int i = 0; i < 5; i++){
        resultcard[i] = new float[4];
    }
    //enter marks
  for(int i = 0; i < 5; i++){
    for(int j = 0; j< 4; j++){
         cout<<"enter student "<< i << " marks"<<endl;
         cin>>resultcard[i][j];
    }
  }
//total marks of student
  float* totalcard = new float[5];
    for(int i = 0; i < 5; i++){
    for(int j = 0; j< 4; j++){
      totalcard[i] +=  resultcard[i][j];
    }
  }

  for(int i = 0; i< 5; i++){
      cout<<"marks of student  : "<<i<<" "<<totalcard[i]<<endl;
  }


  //average marks of students 

  float* avg = new float[4];
      for(int i = 0; i < 4; i++){
      avg[i] += totalcard[i]/5;
      cout<<" subject "<<i<<" averge marks"<<avg[i]<<endl;
  }



  //highes marks
  int index_highest = -1;
      for(int i = 0; i < 5; i++){
         if(index_highest < totalcard[i]){
            index_highest = i;
        }else  continue;
  }
  cout<<"student : "<<index_highest<<" is the topper"<<endl;
    return 0;  
}