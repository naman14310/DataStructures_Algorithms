#include <iostream>
using namespace std;

template <class T>

class deque{

    T *arr;
    int f, rear;
    int capacity;
    int filled;

    public:

        deque(){
          //  cout<<"Hello ! I'm default constructor ..."<<endl;
            arr = new T[8];
            f = -1;
            rear  = -1;
            capacity = 8;
            filled = 0;
        }

        deque(int n, T x){
           // cout<<"Hello ! I'm parameterized constructor ..."<<endl;
            arr = new T[n];
            capacity = n;
            f = 0;
            rear  = n-1;
            filled = n;

            for(int i=0; i<n; i++) arr[i]=x;
        }

        bool isFull() 
        { 
            if( f == (rear+1)%capacity) return true;
            return false; 
        } 

        bool empty() 
        { 
            return (f == -1); 
        } 

        void push_back(T item){
            if(isFull()){
            
           // cout<<"full..."<<endl;
            T* tempArr = new T[2*capacity]; 
            
            int j=0;
            for (int i = f; i !=rear; i=(i+1)%capacity) { 
                tempArr[j] = arr[i]; 
                j++;
            } 

            tempArr[j] = arr[rear];
            f = 0; rear = j;
            delete[] arr; 
            capacity *= 2; 
            arr = tempArr;
            rear=(rear+1)%capacity;
            }

            else if(empty()){
         //       cout<<"empty.."<<endl;
                f = 0; 
                rear = 0; 
            }

            else{
                rear=(rear+1)%capacity;
            }
            
            arr[rear] = item;
       //     cout<<"element "<<item<<" pushed at index "<<rear<<endl;
            filled++;
        }

        void push_front(T item){
            if(isFull()){
            
      //      cout<<"full..."<<endl;
            T* tempArr = new T[2*capacity]; 
            int j=0;
            for (int i = f; i !=rear; i=(i+1)%capacity) { 
                tempArr[j] = arr[i];
                j++; 
            } 

            tempArr[j] = arr[rear];
            f = 0; rear = j;
  
            delete[] arr; 
            capacity *= 2; 
            arr = tempArr;
            
            if(f>0) f--;
            else{
                f = capacity-1;
            }

            }

            else if(empty()){
         //       cout<<"empty.."<<endl;
                f = 0; 
                rear = 0; 
            }

            else{
                if(f>0) f--;
                else{
                f = capacity-1;
                }
            }
            
            arr[f] = item;
            filled++;

        }

        void pop_front(){
            /*if(empty()){
         //       cout<<"Queue is empty !"<<endl;
            }*/
            if(f == rear){
                f = -1;
                rear = -1;
          //      cout<<"Queue become empty !"<<endl;
            }
            else{
                f = (f+1)%capacity;
          //      cout<<"front shifted right !"<<endl;
            }
            filled--;
        }

        void pop_back(){
           /* if(empty()){
           //     cout<<"Queue is empty !"<<endl;
            }*/
            if(f == rear){
                f = -1;
                rear = -1;
          //      cout<<"Queue become empty !"<<endl;
            }
            else{
                if(rear>0) rear--;
                else rear=capacity-1;
                //rear = (rear-1)%capacity;
          //      cout<<"rear shifted left !"<<endl;
            }
            filled--;
        }

        T front(){
            /*if(empty()){
                cout<<"Queue is empty!"<<endl<<endl;
                T t;
                return t;
            }*/
           // else{
                return arr[f];
           // }    
        }

        T back(){
            /*if(empty()){
                cout<<"Queue is empty!"<<endl<<endl;
                return;
            }*/
          //  else{
                return arr[rear];
          //  }    
        }

        void resize(int n, int x){
     
            T* tempArr = new T[n]; 

            if(empty()){
                for(int i=0; i<n; i++){
                    tempArr[i] = x;
                }
            }
            else{

                int j=0;
                for (int i = f; i!=rear && j<n; i=(i+1)%capacity) { 
                    tempArr[j] = arr[i]; 
                    j++;
                } 
                if(filled<=n) tempArr[j++] = arr[rear];

                while(j<n){
                    tempArr[j++] = x;
                }
            }

            rear = n-1; 
            f = 0; 
            delete[] arr; 
            capacity = n; 
            arr = tempArr;
            filled = n;
        //    cout<<"filled : "<<filled<<endl;
        }

        int size(){
            return filled;
        }

        void clear(){
            
            delete[] arr; 
            T* tempArr = new T[8];
            f = -1;
            rear = -1;
            capacity = 8;
            arr = tempArr;
            filled = 0;
        //    cout<<"Queue cleared..."<<endl<<endl;
        }

        T operator[](int index){

                return arr[(f+index)%capacity];
        } 

        void printAll(){
            if(empty()) {
                cout<<"Queue is empty , kya traverse krun ?"<<endl<<endl; 
                return;
            }
         //   cout<<"traverse..."<<endl;
            for(int i=f; i!=rear; i=(i+1)%capacity ) cout<<arr[i]<<" ";
            cout<<arr[rear];
            cout<<endl<<endl;
        }

};

int main(){

     clock_t time_req; 
    time_req = clock(); 

    deque<int> a(3,8);

    cout<<a.size();

    a.printAll();
    a.resize(10,4);

    a.printAll();

    cout<<endl;
    time_req = clock()- time_req; 
    cout << "Processor time taken :"
        << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl; 

    return 0;
}