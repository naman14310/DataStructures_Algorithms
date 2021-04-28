#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<int>> mp, rev;
    int V;
    stack<int> s; 
    public:

        graph(int v){
            V = v;
        }

        void addEdge(int u, int v){
            mp[u].push_back(v);
        }

        void dfs1(vector<bool> &vis, int src){

            vis[src] = true;
       //     cout<<src<<" ";
            for(int nbr : mp[src]){
                if(!vis[nbr]){
                    dfs1(vis, nbr);
                }
            }
            s.push(src);
        }

        void transpose(){
            for(auto v : mp){
                for(int nbr : v.second){
                    rev[nbr].push_back(v.first);
                }
            }
        }

        void dfs2(vector<bool> &vis, int src){

            vis[src] = true;
            cout<<src<<" ";
            for(int nbr : rev[src]){
                if(!vis[nbr]){
                    dfs2(vis, nbr);
                }
            }
        }

        void kosaraju(){
            vector<bool> vis1 (V, false);
            vector<bool> vis2 (V, false);
            vector<vector<int>> res;
      
            for(int i=0; i<V; i++){
                if(!vis1[i])
                dfs1(vis1, i);
            }

            transpose();

            int components = 0;
            while(!s.empty()){
                int src = s.top();
                s.pop();
                if(!vis2[src]){
                    dfs2(vis2,src);
                    components++;
                    cout<<endl;
                }
            }

            cout<<"No of Stringly Connected Components are : "<<components<<endl;
        }

};

int main(){
    graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,7);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(6,7);

    g.kosaraju();

} 