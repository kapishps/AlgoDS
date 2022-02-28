class Solution {
public:
    vector<pair<int,int>> d{{-1,0}, {0,-1}, {1,0}, {0,1}};
    
    
    void dfs(int x, int y, vector<vector<char>>& grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1'){
            return;
        }
        
        grid[x][y] = '2';
        for(auto i: d){
            dfs(x+i.first, y+i.second, grid);
        }
    }
    
    int numIslands(vector<vector<char>> grid) {
        int cnt = 0;
        
        for(int i =0; i< grid.size(); i++){
            for(int j =0; j< grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
        
    }
};