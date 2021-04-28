class Solution {
public:
    
    vector<int> param(int i, int j){
        int l = j, r = j, t = i, d = i;
        
        while(l%3!=0) l--;
        
        while(r%3!=2) r++;
        
        while(t%3!=0) t--;
        
        while(d%3!=2) d++;
        
        vector<int> prm(4,0);
        prm[0] = l; prm[1] = r; prm[2] = t; prm[3] = d;
        return prm;
    }
    
    bool canFill(vector<vector<char>>& board, int row, int col, char ch){
        
        for(int i=0; i<9; i++){
            if(board[row][i]==ch) 
                return false;
        }
        
        for(int i=0; i<9; i++){
            if(board[i][col]==ch) 
                return false;
        }
        
        vector<int> prm = param(row, col);
        int l = prm[0], r = prm[1], t = prm[2], d = prm[3];
        
        for(int i=t; i<=d; i++){
            for(int j=l; j<=r; j++){
                 if(board[i][j]==ch)
                     return false;
            }
        }
        
        return true;
    }

    bool solve(vector<vector<char>>& board, int i, int j){
        
        if(i>8 || j>8) return true;

        if(board[i][j]!='.'){
            if(j==8)
                return solve(board, i+1, 0);
            else
                return solve(board, i, j+1);
        }
        
        for(int num = 1; num<=9; num++){
            
            char ch = num+'0';
            
            if(canFill(board, i, j, ch)){

                board[i][j] = ch;
                
                bool temp = false;
                if(j==8)
                    temp = solve(board, i+1, 0);
                else
                    temp = solve(board, i, j+1);
                
                if(temp) return true;
            }
        }
        
        board[i][j] = '.';
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        bool b = solve(board, 0, 0);
        
    }
};
