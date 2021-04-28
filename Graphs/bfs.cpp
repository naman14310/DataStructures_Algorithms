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

        void bfs(){
            bool visited[v];

            for(int i=0; i<=v; i++){
                visited[i] = false;
            }

            for(int i=1; i<=v; i++){
                int src = 1;
                bfs_helper(src, visited);
            }
            
            fill_n(visited, v+1, false);
            cout<<"\nbfs on 1 -> ";bfs_helper(1,visited);

            fill_n(visited, v+1, false);
            cout<<"\nbfs on 2 -> ";bfs_helper(2,visited);

            fill_n(visited, v+1, false);
            cout<<"\nbfs on 3 -> ";bfs_helper(3,visited);

            fill_n(visited, v+1, false);
            cout<<"\nbfs on 4 -> ";bfs_helper(4,visited);
        }

        

        void bfs_helper(int src, bool visited[]){
            

            queue<int> q;
            if(!visited[src])
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                
                int node = q.front();
                cout<< node << " ";
                
                q.pop();
                for(auto nbr : mp[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }

/*            for(int i=0; i<=visited;{
                cout<<"visited["<<i<<"]"<<visited[i];
            }
*/
            return;

        }
}; 
 
int main() 
{   int n=4;
  //  cin>>n;
    graph g(n);
    
    g.addEdge(1,2,true);
    g.addEdge(2,3,true);
    g.addEdge(2,4,false);
    g.addEdge(3,4,false);
    g.addEdge(4,1,true);

    g.display();
    //call bfs
    g.bfs();

    //g.display();

    return 0;
}