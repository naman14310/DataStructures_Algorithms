#include<bits/stdc++.h>
using namespace std;

class graph{

    int V;
    list<int> *l;

public:
    graph(int V){
        this->V  = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool bidir){
        l[x].push_back(y);
        if(bidir) l[y].push_back(x);
    }

    void printGraph(){
        for(int i=0; i<V; i++){
            cout<<i;
            for(int nbr : l[i]){
                cout<<"->"<<nbr;
            }
            cout<<endl;
        }
    }

};

int main(){

    int n = 4;
    graph g(4);

    g.addEdge(2,1,false);
    g.addEdge(0,1, true);
    g.addEdge(0,2, true);
    g.addEdge(3,2, false);

    g.printGraph();
    
    return 0;
}