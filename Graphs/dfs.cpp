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

class graph{
    unordered_map<int, vector<int>> mp;
    int v;
    public:

        graph(int n){
            v = n;
        }

        void addEdge(int u, int v, bool bidir){
            mp[u].push_back(v);
            if(bidir){
                mp[v].push_back(u);
            }
        }

        void display(){
            cout<<"****GRAPH****"<<endl;
            for(auto p : mp){
                cout << p.first << " -> ";
                for(int nbr : p.second){
                    cout<< nbr <<" ";
                }
                cout<<endl;
            }
        }

        void dfs(){
            bool visited[v];

            for(int i=0; i<=v; i++){
                visited[i] = false;
            }

       //     for(int i=1; i<=v; i++){
                int src = 1;
                dfs_helper(src, visited);
           // }
        }

        

        void dfs_helper(int src, bool visited[]){
            
            
            visited[src] = true;
            
            cout<<src<<" ";

            for(int nbr : mp[src]){
                if(!visited[nbr])
                {
                    dfs_helper(nbr, visited);
                }
            }

            return;

        }
}; 
 
int main() 
{   int n=5;
  //  cin>>n;
    graph g(n);
    
    g.addEdge(1,2,true);
    g.addEdge(2,3,true);
    g.addEdge(2,4,false);
    g.addEdge(3,4,false);
    g.addEdge(5,1,false);

    g.display();
    //call bfs
    g.dfs();

    //g.display();

    return 0;
}