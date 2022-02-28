class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int k){
        if(k >= word.size()){
            return true;
        }
        if(x >= board.size() || y >= board[0].size() || board[x][y] != word[k]){
            return false;
        }
        char curr = word[k];
        
        board[x][y] = '#';
        bool ans = dfs(board, word, x +1, y, k+1) || dfs(board, word, x, y+1, k+1)|| dfs(board, word, x-1, y, k+1) || dfs(board, word, x, y-1, k+1);
        board[x][y] = curr;
        return ans;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i< board.size(); i++){
            for(int j =0; j<board[0].size(); j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};