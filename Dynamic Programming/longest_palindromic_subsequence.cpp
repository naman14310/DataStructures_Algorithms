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

int solve(string s){
    int n = s.length();

    int T[n][n] ;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                T[i][j]=1;
            }
            else{
                T[i][j] = 0;
            }

        }
    }

    for(int j=1; j<n; j++){
        for(int i=j-1; i>=0; i--){
            if(s[i]==s[j]){
                T[i][j] = T[i+1][j-1]+2;
            }
            else{
                T[i][j] = max(T[i][j-1], T[i+1][j]);
            }
        }
    }

    return T[0][n-1];
}

 
int main() 
{
    cout<<solve("BBABCBCAB");
    return 0;
}