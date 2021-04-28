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

void multiply(int** mat1,  int** mat2,  int** res, int  N) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
}

/*function matrix_power_final(A, x):
  result = I_n
  while x > 0:
    if x % 2 == 1:
      result = result * A
    A = A * A
    x = x / 2
  return result
 */
 
int main() 
{
    vector<vector<int>> a
  
    multiply(mat1, mat2, res); 
  
    cout << "Result matrix is \n"; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        cout << res[i][j] << " "; 
        cout << "\n"; 
    } 
    return 0;
}