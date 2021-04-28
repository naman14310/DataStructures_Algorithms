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

//*****************LOWER BOUND*******************

int findCeil(vector<int> v, int n, int item){

    if(n==1){
        if(v[0]>=item) return 0;
        return -1;
    }

    int start = 0;
    int end = n-1;
    int res = INT_MAX;
    int pos = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(v[mid]==item) return mid;

        else if(v[mid]>item){
            
            res = v[mid];
            pos = mid;
            end = mid-1;
        }

        else{
            start = mid+1;
        }
    }

    return pos;
} 
 
int main() 
{      
    OJ;
    int n, item;
    cin>>n>>item;
    vector<int> v;

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    cout<<findCeil(v,n,item);


    return 0;
}