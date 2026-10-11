#include <iostream> 
using namespace std;

class destination{
    private:
        string nameCustomer;
        string StoreName;
        int ETA;// time in minutes;
    public:
        destination(string Nc, string SN, int ETA):nameCustomer(Nc), StoreName(SN),ETA(ETA){}
        void get_nameCustomer(){ return this->nameCustomer;}
        void get_StoreName(){ return this->get_StoreName;}
        void get_ETA(){return this->ETA;}

        destination(const destination& other){
            this->ETA = other.ETA;
            this->nameCustomer  = other.nameCustomer;
            this->get_StoreName = other.StoreName;
        }

        destination& operator =(const destination& other){
            if(this != &other){
                this->ETA = other.ETA;
                this->nameCustomer  = other.nameCustomer;
                this->get_StoreName = other.StoreName;
            }
            return this;
        }

        ~destination(){}

};

class QuickSort{
    private :
        int* arr;
        int size_arr;
    public :
        QuickSort(int arr[],int size_arr): size_arr(size_arr){
            this->arr = new int[size];
            this->arr = arr;
        }
        void swap(int a&, int &b){
            int temp = a;
            a = b;
            b = temp;
        }

        int Partition(int left, int right){}

        void Sort(int left, int right){
            if(left < right){
                int pivot = this->Partition(left, right);
                this->Sort(left, pivot-1);
                this->Sort(pivot+1, right);

            }
        }



        ~QuickSort(){
            delete[] this->arr;
        }


}




int main(){
    



    return  0;
}