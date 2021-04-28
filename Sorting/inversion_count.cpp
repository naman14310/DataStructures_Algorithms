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

int invCount = 0;

vector<int> merge(vector<int> a, vector<int> b){

    int lena = a.size();
    int lenb = b.size();

    vector<int> res;

    int i=0, j=0, k=0;

    while(i<lena && j<lenb){

        if(a[i]<=b[j]){
            res.push_back(a[i]);
            i++;
        }
        else{
            res.push_back(b[i]);
            invCount+= lena-i;
            j++;
        }
    }

    while(i<lena){
        res.push_back(a[i]);
        i++;
    }

    while(j<lenb){
        res.push_back(b[j]);
        j++;
    }

    return res;
} 

void mergeSort(vector<int> arr){
    int len = arr.size();

    if(len<2) return ;

    int mid = len/2;

    vector<int> left, right;

    for(int i=0; i<mid; i++){
        left.push_back(arr[i]);
    }

    for(int i=mid; i<len; i++){
        right.push_back(arr[i]);
    }

    mergeSort(left);
    mergeSort(right);
    auto v = merge(left, right);
}
 
int main() 
{   vector<int> v = { 1, 20, 6, 4, 5 };
    mergeSort(v);
    cout<<"invCount : " <<invCount<<endl;
    return 0;
}