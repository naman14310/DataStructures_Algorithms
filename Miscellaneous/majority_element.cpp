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

bool isMajority(int arr[], int n, int k){
    int count = 0;

    for(int i=0; i<n; i++){
        if(arr[i]==k){
            count++;
        }
    } 

    if(count>n/2) return true;
    return false;
}

int moore_voting(int arr[], int n){
    int count = 1;
    int element = arr[0];
    
    for(int i=1; i<n; i++){

        if(arr[i]==element){
            count++;
        }
        else{
            count--;
        }

        if(count==0){
            element = arr[i];
            count=1;
        }  
    }
    
    bool check = isMajority(arr,n,element);

    if(check) return element;
    return -1;

}
 
int main() 
{

    int arr[] = {2,1,1,2,1,2,1,1,2};

    cout<<moore_voting(arr,9);
    return 0;
}