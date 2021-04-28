#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<pair<int,int>>> mp;
    int V;
    unordered_map<int, int> dist;

    public:
        graph(int v){
            V=v;
            for(int i=0; i<V; i++){
                dist[i] = INT_MAX;
            }
        }

        void addEdge(int u, int v, int dist){
            u--;v--;
            mp[u].push_back({v,dist});
            mp[v].push_back({u,dist}); //comment out in case of directed edges
        }

        void dijkstra(int src){
            src--;
            dist[src] = 0;

            set<pair<int, int>> s;
            s.insert({0, src});

            while(!s.empty()){

                auto p = *(s.begin());
                s.erase(s.begin());
                int curr_vt = p.second;
                int distance = p.second;
         

                for(auto nbr : mp[curr_vt]){
                    if(distance + nbr.second < dist[nbr.first]){
                        auto relaxPair = s.find({dist[nbr.first], nbr.first});
                        if(relaxPair!=s.end()){
                            s.erase(relaxPair);
                        }
                        
                        dist[nbr.first] = distance + nbr.second;
                        s.insert({dist[nbr.first], nbr.first});
                    }
                }
            }

            printDist(src);
        }

        void printDist(int src){
            cout<<endl<<"Source Node : "<<src+1<<endl;
            for(auto nbr : dist){
                cout<<endl<<"nbr : "<<nbr.first+1<<" distance : "<<nbr.second<<endl;
            }
            cout<<endl;
        }



};

int main(){

    graph g(6);

    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,4);
    g.addEdge(2,5,7);
    g.addEdge(2,4,2);
    g.addEdge(3,5,5);
    g.addEdge(3,4,3);
    g.addEdge(5,4,4);
    g.addEdge(5,6,7);
    g.addEdge(4,6,6);

    g.dijkstra(1);


}