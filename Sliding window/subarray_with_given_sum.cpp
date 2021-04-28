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

pair<int,int> solve(int arr[], int sum, int len){
   
   int start = 0, tempSum = arr[0];

   for(int end=1; end<=len; end++){

       while(tempSum > sum && start<end){
                tempSum -= arr[start];
                start++;
       }

       if(tempSum==sum){
           return {start,end-1};
       }

       if(end<len){
           tempSum+=arr[end];
       }
   }

   return{0,0};
   
}
 
 
int main() 
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    int sum = 15;

    pair<int, int> p = solve(arr, sum, 6);
    cout<< p.first<<" "<<p.second;
    return 0;
}