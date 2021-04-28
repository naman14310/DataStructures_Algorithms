#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<pair<int,int>>> mp;
    int V;
    vector<int> dist;

    public:

        graph(int v){
            int V = v;
            for(int i=0; i<v; i++){
                dist.push_back(INT_MAX-1);
            }
        }

        void addEdge(int u, int v, int d){
            mp[u].push_back({v,d});            
            mp[v].push_back({u,d}); //comment out in case of directed edges
        }

        int minSpanningTree(){

            set<pair<int,int>> s;
            vector<bool> vis(V, false);
            //vector<int> parent(V, -1);
            int sum = 0;
            dist[0] = 0;

            s.insert({dist[0], 0});

            while(!s.empty()){
                auto p = *(s.begin());
                s.erase(s.begin());
                int vt_dist = p.first;
                sum += vt_dist; 
                //cout<<endl<<"sum : "<<sum;
                int vt = p.second;
                vis[vt] = true;

                for(auto nbr : mp[vt]){

                    int nbr_vt = nbr.first;
                    int nbr_dist = nbr.second;

                    if(vis[nbr_vt]) continue;

                    if(nbr_dist < dist[nbr_vt]){

                        auto relaxPair = s.find({dist[nbr_vt], nbr_vt});
                        if(relaxPair!=s.end()){
                            s.erase(relaxPair);
                        }

                        dist[nbr_vt] = nbr_dist;
                        s.insert({dist[nbr_vt], nbr_vt});

                    }
                }

            }

            return sum;

        }


};

int main(){
    graph g(6);

    //cout<<"CSHJVSHVHSV";

    g.addEdge(0,1,4);
    g.addEdge(1,2,6);
    g.addEdge(0,2,6);
    g.addEdge(4,5,7);
    g.addEdge(5,3,3);
    g.addEdge(1,4,4);
    g.addEdge(4,3,2);
    g.addEdge(3,2,1);
    g.addEdge(1,3,3);

    int ans = g.minSpanningTree();
    cout<<endl<<endl<<"MST val : ";
    cout<< ans <<endl<<endl;

    return 0;
}
