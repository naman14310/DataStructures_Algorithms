#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<int>> mp;
    int V;

    public:
        graph(int v){
            V=v;
        }

        void addEdge(int u, int v){
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        bool dfs(vector<bool> & vis, int src, vector<bool> & rs, int parent){
            vis[src] = true;
            rs[src] = true;
         //   cout<<"src : "<<src<<" ";
            for(int nbr : mp[src]){
           //     cout<<"nbr : "<<nbr<<endl;
                if(!vis[nbr]){
                  bool cycle = dfs(vis, nbr, rs, src);
                  if(cycle)
                    return true;
                }
                else if(nbr!=parent && rs[nbr]){
                    return true;
                }
            }
        //     cout<<"src out : "<<src<<" ";
            rs[src] = false;
            return false;
        }

        bool cycle_detection(){
            bool containsCycle = false;
            vector<bool> visited (V+1, false);
            vector<bool> recursionStack (V+1, false);
            //loop is used to run code for disconnected graphs as well
            for(int i=1; i<=V; i++){
                int src = i;
                if(!visited[i]){
                    containsCycle = dfs(visited, src, recursionStack, -1);
                    if(containsCycle) break;
                }
            }
          
            return containsCycle;
        }

};

int main(){

    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
//    g.addEdge(4, 0);

    string arr[] = {"NO", "YES"};
    cout<<"Does graph contains cycle : "<< arr[g.cycle_detection()]<<endl;

}
