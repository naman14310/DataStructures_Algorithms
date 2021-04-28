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


int findElement(vector<int> v, int start, int end, int item){
    
    if(end<0 || start >=v.size()) return -1;
    
    while(start<=end){
        int mid = start + (end-start)/2;

        if(v[mid]==item){
            return mid;
        }

        else if(item>v[mid]) start=mid+1;

        else end = mid-1;

    }

    return -1;
}

int findMin(vector<int> v, int n){
    int pos=0;
    if(n<1) return -1;
    if(n==1) return v[0];
    
    int start = 0, end = n-1, ans=INT_MAX;
    while(start<=end){
        int mid = start + (end-start)/2;
        int left = mid==0?n-1:mid-1;
        int right = (mid+1)%n;
        if(v[mid]<=v[left] && v[mid]<=v[right]){
            
            if(ans>v[mid]){
                ans = v[mid];
                pos = mid;
            }
           
        }

        if(v[mid]<v[0]) end = mid-1;

        else start = mid+1;
    }

    if(ans<INT_MAX) return pos;
    else return pos;
}
 
 
int main() 
{

    OJ;
    int n, item;
    vector<int> v;
    cin>>n>>item;
    
    for(int i=0; i<n; i++){
        int item;
        cin>>item;
        v.push_back(item);
    }
 
    int pos = findMin(v,n);
    if(v[pos]==item) cout<<pos;
    else {
        int left = findElement(v,0,pos-1,item);
        int right = findElement(v,pos+1, n-1, item);
        cout<<max(left,right);
    }
     

    return 0;
}