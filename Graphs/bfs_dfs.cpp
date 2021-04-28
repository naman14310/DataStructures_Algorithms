#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<int>> mp;

    public:

        void addEdge(int u, int v, bool bidirec){
            mp[u].push_back(v);
            if(bidirec){
                mp[v].push_back(u);
            }
        }

        void printGraph(){
            for(auto p : mp){
                cout<<p.first<<" -> ";
                for(int nbr : p.second){
                    cout<<nbr<<" ";
                }
                cout<<endl;
            }
        }

        void dfs_helper(vector<bool> & visited, int src){

            visited[src] = true;
            cout<<src<<" ";
            for(int nbr : mp[src]){
                if(!visited[nbr])
                    dfs_helper(visited, nbr);
            }
        }

        void dfs(){
            vector<bool> visited (mp.size()+1, false);
            int src = 1;

            dfs_helper(visited, src);
        }

        void bfs_helper(vector<bool> & vis, int src){

            queue<int> q;
            q.push(src);
            vis[src] = true;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                for(int nbr : mp[node]){
                    if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                    }
                }
            }
        }

        void bfs(){
            vector<bool> visited (mp.size()+1, false);
            int src = 1;

            bfs_helper(visited, src);
        }

};



int main(){
    graph g;

    g.addEdge(1, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(2, 4, true);
    g.addEdge(2, 5, true);
    g.addEdge(3, 6, true);
    g.addEdge(3, 7, true);
    g.addEdge(4, 8, true);
    g.addEdge(5, 8, true);
    g.addEdge(6, 8, true);
    g.addEdge(7, 8, true);

   // g.printGraph();

    cout<<"bfs : ";  g.bfs();
    cout<<endl;
    cout<<"dfs : "; g.dfs();
    cout<<endl;
}