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

void solve(int n){
    int first, last, flag=0, index = 0, count=0;
    while(n>0){
        if(n&1){
            if(flag==0){
                first = index;
                flag= 1;
            }
            last = index;
            count++;
            
        }
        index++;
        n>>=1;
    } 
    cout<<"count : "<<count<<endl;
    cout<<"first : "<<first<<endl;
    cout<<"last : "<<last<<endl;
}
 
int main() 
{
    solve(6);
    return 0;
}