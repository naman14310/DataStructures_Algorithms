#include<bits/stdc++.h>
#define pci pair<char,int>
using namespace std;


//representing weighted graph (nodes are represnted by characters)
class graph{

    int V;
    map<char, list<pci>> mp;

public:

    graph(int V){
        this->V = V;
    }

    void addEdge(char x, char y, bool bidirec, int weight){

        mp[x].push_back({y,weight});
        if(bidirec) mp[y].push_back({x,weight});
    }

    void printGraph(){

        for(auto p : mp){
            cout<<"Node "<<p.first<<" : ";
            for(auto nbr : p.second){
                cout<<"("<<nbr.first<<", "<<nbr.second<<") ";
            }
            cout<<endl;
        }

    }

};

int main(){

    int n = 4;
    graph g(n);

    g.addEdge('A', 'B', false, 10);
    g.addEdge('B', 'C', true, 5);
    g.addEdge('A', 'C', false, 6);
    g.addEdge('A', 'D', true, 15);
    g.addEdge('C', 'D', true, 3);
    g.addEdge('B', 'D', false, 2);

    g.printGraph();

    return 0;
}