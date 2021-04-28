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

int solve(int arr[], int n, int k){

    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0; i<n; i++){
        q.push(arr[i]);

        if(q.size()>k){
            q.pop();
        }
    }

    return q.top();

}
 
int main() 
{   int n = 9, k = 4;
    int arr[] = {1,2,231,65,2,42,56,214,5};
    cout<<solve(arr, n, k)<<endl;
    sort(arr, arr+n, greater<int>());

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}