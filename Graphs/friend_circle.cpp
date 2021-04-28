#include<bits/stdc++.h>
using namespace std; 

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

        int bfs(){
            bool visited[v];
            int count = 0;
            for(int i=0; i<=v; i++){
                visited[i] = false;
            }

            for(int i=1; i<=v; i++){
                if(!visited[i]){
                    bfs_helper(i, visited);
                    count++;
                }
                
            }

            return count;
            
        }

        void bfs_helper(int src, bool visited[]){
            

            queue<int> q;
            if(!visited[src])
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                
                int node = q.front();
              //  cout<< node << " ";
                
                q.pop();
                for(auto nbr : mp[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            return;
        }
}; 
 
int main() 
{   int n=8;

    graph g(n);
    
    g.addEdge(1,2,false);
    g.addEdge(2,3,false);
    g.addEdge(4,5,false);
    g.addEdge(6,7,false);
    g.addEdge(7,8,false);
    g.addEdge(3,2,false);
    g.addEdge(3,3,false);

    cout<<g.bfs();

    return 0;
}