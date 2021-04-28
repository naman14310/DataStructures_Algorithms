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


bool equal(int a[], int b[]){
    for(int i=0; i<256; i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int solve(string s, string word){

    int a[256] = {0};
    int w[256] = {0};
    int count = 0;
    if(word.length()>s.length()) return 0;

    int wlen = word.length();

    int i=0;
    while(i<wlen){
        int ch = s[i];
        
        a[ch]++;
        w[ch]++;
        i++;
    }

    if(equal(a,w)) count++;

    while(i<s.length()){
        int ch = s[i];
        a[ch]++;
        a[s[i-wlen]]--;
        if(equal(a,w)) count++;
        i++;
    }

    return count;
}
 
 
int main() 
{

    cout<<solve("forxxorfxdofr", "for");
    return 0;
}