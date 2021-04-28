#include<bits/stdc++.h>
using namespace std;

class graph{

    unordered_map<int, vector<int>> mp;
    int V;
    vector<pair<int,int>> info;    //  p.first = parent  &&  p.second = rank

    public:

        graph(int v){
            V = v;
            for(int i=0; i<v; i++){
                info.push_back({-1,0});
            }
        }

        void addEdge(int u, int v){
            mp[u].push_back(v);
            int curr_parent_v = info[v].first;
            int curr_rank_u = info[u].second;
            int curr_rank_v = info[v].second;
            info[u] = {v,curr_rank_u};
            info[v] = {curr_parent_v, curr_rank_v+1};
        }

        int dsu_find(int node){

            if(info[node].first==-1)
                return node;

            else return info[node].first = dsu_find(info[node].first);
        }

        void dsu_union(int u, int v){

            int abs_u = dsu_find(u);
            int abs_v = dsu_find(v);

            if(info[u].second < info[v].second){
                info[u].first = abs_v;
            }
            else if(info[u].second > info[v].second){
                info[v].first = abs_u;
            }
            else{
                info[u].first = abs_v;
                info[u].second += 1; 
            } 

        }

};

int main(){



}