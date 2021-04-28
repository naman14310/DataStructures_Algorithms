#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<int>> mp;
    int V;
    vector<vector<int>> paths;
    public:

        graph(int n){
            V=n;
        }

        void addEdge(int u, int v, bool bidirec = false){
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

          void printAllPaths(){
            int count = 1;
            cout<<endl;
            for(auto path : paths){
                cout<<"Path "<<count++<<" : ";
                for(int i : path){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
        }

        void dfs_helper(vector<bool> & visited, vector<int> & route, int src, int des){

            visited[src] = true;
            route.push_back(src);

            if(src==des){
                paths.push_back(route);
                /*cout<<"route : ";
                for(int i : route){
                    cout<<i<<" ";
                }
                cout<<endl;*/
            }
            else{
                 for(int nbr : mp[src]){
                    if(!visited[nbr])
                    dfs_helper(visited, route, nbr, des);
                 }
            }

            route.pop_back();
            visited[src] = false;
        }

        void dfs(){
            vector<bool> visited (V, false);
            vector<int> route;
            int src = 2, des = 3; 

            dfs_helper(visited, route, src, des);
            printAllPaths();
        }

};



int main(){
    graph g(4);

    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 

   // g.printGraph();

    g.dfs();
    cout<<endl;
}