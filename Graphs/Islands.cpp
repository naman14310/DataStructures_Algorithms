#include<bits/stdc++.h>
using namespace std;

const int row = 4;
const int col = 5;

bool isValid(int x, int y){
    if(x>=0 && x<row && y>=0 && y<col)
        return true;
    
    return false;
}

void bfs(int arr[][5], pair<int, int> src){

    int offset_x[] = {1, 0, 0, -1};
    int offset_y[] = {0, 1, -1, 0};

    queue<pair<int, int>> q;
    q.push(src);
    
  //  int b = 0;

    while(!q.empty()){
        pair<int, int> cell = q.front();
        arr[cell.first][cell.second] = 2;
      //  cout<<"x : "<<cell.first<<" y : "<<cell.second<<endl;
        q.pop();

        for(int i=0; i<4; i++){
            pair<int, int> newCell = {cell.first+offset_x[i], cell.second+offset_y[i]};
          //  cout<<"FIND -> nbrx : "<<newCell.first<<" nbry : "<<newCell.second<<endl<<endl;

            bool valid = isValid(newCell.first, newCell.second);
          //  cout<<"Kya ye valid he : "<< valid<<endl; 

            bool visitkrliyakya = arr[newCell.first][newCell.second]==false;
          //  cout<<"Visit kiya kya : "<<visitkrliyakya<<endl;

            if(valid && arr[newCell.first][newCell.second]==1){
               // cout<<"Pushed -> nbrx : "<<newCell.first<<" nbry : "<<newCell.second<<endl<<endl;
                q.push(newCell);
            }
        }

      //  b++;
       // if(b==10) break;
    }

  //  cout<<endl<<"Island changes.."<<endl;

}


int solve(int arr[][5]){

  
    int count=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]==1){
                pair<int, int> src = {i,j};
                bfs(arr, src);
                count++;
            }
        }
    }
    return count;
}

int main(){

    int arr[4][5] = { 
                      {1,1,1,1,0},
                      {1,1,0,1,0},
                      {1,1,0,0,0},
                      {0,0,0,0,1}
                    };

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<solve(arr)<<endl;

   /*   for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

}