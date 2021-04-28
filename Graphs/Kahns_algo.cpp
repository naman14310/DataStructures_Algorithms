#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<int>> mp;
    int V;
    vector<int> indg;
    vector<int> ans;

    public:
        
        graph(int v){
            V=v;
            for(int i=0; i<v; i++)
                indg.push_back(0);
        }

        void addEdge(int u, int v){
            mp[u].push_back(v);
            indg[v]++;
        }

        int topoSort(){

            queue<int> q;

            for(int i=0; i<V; i++){
                if(indg[i]==0)
                    q.push(i);
            }

            int count = 0;

            while(!q.empty()){
                
                int vt = q.front();
                q.pop();
                ans.push_back(vt);
                count++;

                for(int nbr : mp[vt]){
                    indg[nbr]--;
                    if(indg[nbr]==0)
                        q.push(nbr);
                }
            }

            return count;
        }

        void topological_sort(){
            
            int count = topoSort();

            if(count<V){
                cout<<endl<<"Topological order doesn't exist!"<<endl;
                return;
            }
            else{
                cout<<endl<<"Topological order is : ";

                for(int i=0; i<V; i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
            }

        }


        



};

int main(){
    graph g(6);

    g.addEdge(5,0);
    g.addEdge(5,3);
    g.addEdge(3,2);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,1);
    g.addEdge(3,0);

    g.topological_sort();

}