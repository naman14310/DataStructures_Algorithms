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
            u--;v--;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        bool bfs(vector<int> & color, int src){
            queue<int> q;
            q.push(src);
            color[src] = 1;
            while(!q.empty()){
                int vt = q.front();
                q.pop();
                for(int nbr : mp[vt]){

                   int nbr_color = 1 - color[vt];
                
                   if(color[nbr]==color[vt]) return false;

                   else if(color[nbr]==-1){
                       q.push(nbr);
                       color[nbr] = nbr_color;
                   } 
                }
            }
            return true;
        }

        bool isBipartite(){
            vector<int> color;

            for(int i=1; i<=V; i++){
                color.push_back(-1);
            }

            for(int i=0; i<V; i++){
                if(color[i]==-1){
                    bool flag = bfs(color, i);
                    if(!flag) return false;
                }
            }
            return true;
        }



};

int main(){

    graph g(5);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);

    if(g.isBipartite()) cout<<endl<<"YES"<<endl;
    else cout<<endl<<"NO"<<endl;
}