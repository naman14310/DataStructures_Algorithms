#include<bits/stdc++.h>
using namespace std; 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define deb(x) cout<<#x<<" "<<x<<endl
#define in(x) cin>>x
#define fo(i,n) for(int i=0; i<n; i++)
#define endl "\n"
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void merge(int arr[], int left, int mid, int right){

    int n1 = mid-left+1, n2 = right-mid;
    int l[mid-left+1], r[right-mid];

    for(int i=0; i<n1; i++){
        l[i] = arr[i+left];
    }

    for(int i=0; i<n2; i++){
        r[i] = arr[mid+1+i];
    }

    int i = 0; // Initial index of first subarray 
    int j = 0; // Initial index of second subarray 
    int k = left; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (l[i] <= r[j]) { 
            arr[k] = l[i]; 
            i++; 
        } 
        else { 
            arr[k] = r[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = l[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = r[j]; 
        j++; 
        k++; 
    } 


}

void mergeSort(int arr[], int start, int end){
    if(start<end){
        int mid = start + (end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
 
int main() 
{

    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 

    mergeSort(arr, 0, arr_size - 1); 

    printf("SOrted array is \n"); 
    printArray(arr, arr_size); 
  
    return 0;
}