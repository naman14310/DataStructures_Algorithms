#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y){
    if(x>=0 && x<4 && y>=0 && y<5) return true;
    return false;
}

int bfs(int arr[][5], pair<int,int> src){

    int count = 1;
    int i = src.first, j=src.second;
    arr[i][j] = 2;

    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};

    queue<pair<int, int>> q;
    q.push(src);

    while(!q.empty()){
        pair<int, int> cell = q.front();
        q.pop();

        for(int nbr=0; nbr<4; nbr++){
           int  xnew = cell.first + dx[nbr];
           int  ynew = cell.second + dy[nbr];
           
           if(isValid(xnew, ynew) && arr[xnew][ynew]==1){
              
               q.push({xnew, ynew});
               arr[xnew][ynew] = 2;
               count++;
               
           }
        }

    }
    return count;
}

int main(){

    int matrix[4][5] = { {1,0,0,0,1},
                       {0,0,1,1,0},
                       {1,0,0,0,0},
                       {1,1,1,1,0},                      
                      };
    int ans = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            if(matrix[i][j]==1){
                 pair<int, int> src = {i,j};
                 int count = bfs(matrix, src);
                 ans = max(ans, count);
            }
           
        }
    }

 /*   cout<<endl<<"**********************"<<endl;
     for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout<<ans<<endl<<endl;

    return 0;
}