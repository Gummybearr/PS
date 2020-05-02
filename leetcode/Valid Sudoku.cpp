class Solution {
public:
    bool hcheck(vector<vector<char>>& board, int r){
        int arr[10] = {0,};
        for(int i = 0;i<9;i++){
            if(board[r][i]=='.') continue;
            arr[board[r][i]-'0']++;
            if(arr[board[r][i]-'0']>1) return false;
        }
        return true;
    }
    
    bool ccheck(vector<vector<char>>& board, int c){
        int arr[10] = {0,};
        for(int i = 0;i<9;i++){
            if(board[i][c]=='.') continue;
            arr[board[i][c]-'0']++;
            if(arr[board[i][c]-'0']>1) return false;
        }
        return true;
    }
    bool scheck(vector<vector<char>>& board, int s){
        int arr[10] = {0,};
        int hstart = s/3;
        int cstart = s%3;
        for(int i = hstart*3;i<hstart*3+3;i++){
            for(int j = 3*cstart;j<3*cstart+3;j++){
                if(board[i][j]=='.') continue;
                arr[board[i][j]-'0']++;
                if(arr[board[i][j]-'0']>1) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i= 0;i<9;i++){
            if(!hcheck(board, i) || !ccheck(board, i) || !scheck(board, i)) return false;
        }
        return true;
    }
};