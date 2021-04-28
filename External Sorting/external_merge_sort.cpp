#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define CHUNK_SIZE 100000
long long FILE_SIZE; 

template <class T>
class priorityQueue{

    vector<T> heap;

    public:

        void heapify(long long i){
            long long l = 2*i + 1;
            long long r = 2*i + 2;
            long long mini = -1;
            if(l<heap.size() && heap[l].first<heap[i].first) mini = l; 
            else mini = i;
            if(r<heap.size() && heap[r].first<heap[mini].first) mini = r;
            if(mini!=i){
                swap(heap[i], heap[mini]);
                heapify(mini);
            }
        }

        long long parent(long long index){
            if(index%2==0) return (index/2)-1;
            else return (index/2);
        }

        void getBalanced(){
            long long index = heap.size()-1;
            //cout<<"Index : "<<index<<endl;
            long long pindex = parent(index);        
            //cout<<"Parent : "<<pindex<<endl;         
            while(pindex >= 0 && heap[pindex].first > heap[index].first){
                //cout<<"IN WHILE"<<endl;
                swap(heap[pindex], heap[index]);
                index = pindex;
                pindex = parent(index);
            }
        }

        void insert(T item){
            heap.push_back(item);
            getBalanced();
        }

        T getMin(){
            long long minimum = heap[0].first;
            int chunkId = heap[0].second;
            swap(heap[0], heap[heap.size()-1]);
            heap.pop_back();
            heapify(0);
            return {minimum,chunkId};
        }

        void printHeap(){
            cout<<endl<<"Heap : "; 
            for(auto i : heap)
                cout << i.first << " ";
            cout<<endl;
        }

};

void merge(long long arr[], long long left, long long mid, long long right){
    long long l[mid-left+1], r[right-mid];
    for(long long i=0; i<right-mid; i++){r[i] = arr[mid+1+i];}
    for(long long i=0; i<mid-left+1; i++){l[i] = arr[i+left];}
    long long i=0, j=0, k=left; 

    while (i<(mid-left+1) && j<(right-mid)){ 
        if (l[i] <= r[j]){ 
            arr[k] = l[i]; 
            i = i+1; 
        }else { 
            arr[k] = r[j]; 
            j = j+1; 
        } 
        k = k+1; 
    } 
  
    while(i<(mid-left+1)){ 
        arr[k] = l[i]; 
        i = i+1; 
        k = k+1; 
    } 

    while(j<(right-mid)){ 
        arr[k] = r[j]; 
        j = j+1; 
        k = k+1; 
    } 

}

void printArray(long long arr[], int size) 
{ 
    for (int i=0; i<size; i++) cout <<arr[i]<<" "; 
    cout<<endl; 
} 

void mergeSort(long long arr[], long long start, long long end){
    if(start>=end) return;
    long long mid = start + (end-start)/2;
    mergeSort(arr,start,mid);mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

long long getFileSize(string ipFile){
    ifstream file(ipFile);
    string data = "";
    long long count = 0;
    while(getline(file, data,',')) count++;
    return count;
}

vector<long long> sortChunk(vector<long long> nums){
    int CZ = nums.size();
    //cout<<"CZ : "<<CZ<<endl;
    long long arr[CZ];
	copy(nums.begin(), nums.end(), arr);
    //for(int i=0; i<CZ; i++) cout<<arr[i]<<" ";
    //cout<<endl;
    mergeSort(arr, 0, CZ-1);
    vector<long long> sorted_nums;
    for(int i=0; i<CZ; i++) sorted_nums.push_back(arr[i]);
    //sorted_nums.assign(arr.begin(), end(arr));
    //cout<<endl;
    //for(auto i : sorted_nums) cout<<i<<" ";
    //cout<<endl;
    return sorted_nums;
}

int execute(string ipFile, string opFile){

    FILE_SIZE = getFileSize(ipFile);
    //cout<<endl<<FILE_SIZE<<endl;

    int NO_OF_CHUNKS = FILE_SIZE/CHUNK_SIZE;
    if(FILE_SIZE % CHUNK_SIZE != 0) NO_OF_CHUNKS += 1;
    //cout<<endl<<NO_OF_CHUNKS<<endl;
    vector<long long> nums;
    ifstream file(ipFile);
    string data = "";
    int count = 0;
    int fnptr = 1;
    while(getline(file, data,','))
    {
        long long num = stoll(data, nullptr, 10); //cout << temp << endl;
        nums.push_back(num);
        count++;
        if(count == CHUNK_SIZE){
            string chunkFile = "temp" + to_string(fnptr);
            vector<long long> sorted_nums = sortChunk(nums);

            FILE* cf = fopen(chunkFile.c_str(), "w");
            for(auto number : sorted_nums){
                fprintf(cf, "%lld ", number);
            }
            fclose(cf);

            fnptr++;
            count = 0;
            nums.clear();
        }
    }

    if(nums.size()>0){

        string chunkFile = "temp" + to_string(fnptr);
        vector<long long> sorted_nums = sortChunk(nums);

        FILE* cf = fopen(chunkFile.c_str(), "w");
        for(long long number=0; number<sorted_nums.size(); number++){
            fprintf(cf, "%lld ", sorted_nums[number]);
        }
        fclose(cf);

        fnptr++;
        count = 0;
        nums.clear();
    }

    fnptr--;
    //cout<<fnptr;
    return fnptr;

}

void mergeAllChunks(string opFile, int k){

    priorityQueue<pair<long long, int>> q;
    pair<long long, int> arr[k];
    int fc = 0;

    FILE* optf = fopen(opFile.c_str(), "w");

    if(optf){
        FILE* chunkFiles[k];
        for(int i=0; i<k; i++){
            string fn = "temp" + to_string(i+1);
            chunkFiles[i] = fopen(fn.c_str(), "r");
        }

        for(int i=0; i<k; i++){
            if(fscanf(chunkFiles[i], "%lld ", &arr[i].first) != EOF)
                arr[i].second = i;
            else break;
        }

        for(int i=0; i<k; i++){
            q.insert(arr[i]);
        }
        int ct = 1;
        while(fc!=k){
            auto item = q.getMin();
            long long num = item.first;
            int chunkId = item.second;
            if(ct==FILE_SIZE)
            fprintf(optf, "%lld", num);
            else{
                 fprintf(optf, "%lld,", num);
            }
            ct++;

            pair<long long, int> newItem;
            if(fscanf(chunkFiles[chunkId], "%lld ", &newItem.first)==1){
                newItem.second = chunkId;
                q.insert(newItem);
            }
            else fc += 1;
        }

        for(int i=0; i<k; i++){ 
            fclose(chunkFiles[i]);
            remove(("temp" + to_string(i+1)).c_str());
        }
        fclose(optf);
    }
    else{
        cout<<endl<<"Output file not opened!"<<endl;
    }

}

int main(int argc, char *argv[]){

    clock_t start, end; 
    start = clock(); 

    if(argc<3) cout<<"Please provide porper input"<<endl;
    else{
        string ipFile = argv[1];
        string opFile = argv[2];
        int k = execute(ipFile, opFile);
        mergeAllChunks(opFile, k);
    }

    end = clock();  
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    //cout<<"====> Time taken by program is : "<<fixed<<time_taken<<setprecision(5); 
    //cout<<" sec "<<endl<<endl; 
    return 0;
}