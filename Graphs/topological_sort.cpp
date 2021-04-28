#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<int>> mp;
    int V;
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

        void topological_sort(vector<bool> & visited, int src, stack<int> & stk){
            visited[src] = true;
            for(int nbr : mp[src]){
                    if(!visited[nbr])
                    topological_sort(visited, nbr, stk);
                 }
            
            stk.push(src);
        }

        void tpSort(){
            vector<bool> visited (V, false);
            stack<int> s;

            for(int i=0; i<V; i++){
                if(!visited[i])  topological_sort(visited, i, s);
            }
            
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }

};



int main(){
    graph g(6);

    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(5, 0); 
    g.addEdge(5, 2); 
    g.addEdge(4, 1); 
    g.addEdge(4, 2);
    g.addEdge(3, 1);

   // g.printGraph();

    g.tpSort();
    cout<<endl;
}