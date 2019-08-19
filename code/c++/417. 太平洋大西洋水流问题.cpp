class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> out;
        int row = matrix.size();
        if ( 0 == row ) return out;
        int col = matrix[0].size();

        // 能流动到“太平洋"的陆地
        vector<vector<int>> dp1(row, vector<bool>(col, false));
        // 能流动到“大西洋"的陆地
        vector<vector<int>> dp2(row, vector<bool>(col, false));
        
        //从第一个行/最后一行出发寻找连同节点
        for (int j = 0; j < col; j++) {
            dfs(0,j,INT_MIN,matrix,dp1);
            dfs(row-1,j,INT_MIN,matrix,dp2);
        }
        //从第一个列/最后一列出发寻找连同节点
        for (int i = 0; i < row; i++) {
             dfs(i,0,INT_MIN,matrix,dp2);
             dfs(i,cos-1,INT_MIN,matrix,dp2);
        }

        vector<int> temp(2);
        for (int i=0;i < row, i++)
        {
            for (int j=0; j < col;j++)
            {   
                //请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
                if (dp1[i][j] == true && dp2[i][j] ==true)
                {
                    temp[0] = i;
                    temp[1] = j;
                    out.push_back(temp);


                }
            }
        }
        return out;
        
    }
    
    void dfs(int row,int col, int height, vector<vector<int>>& matrix,vector<vector<bool>>& visited)
   {
        if ( row < 0 || row >= matrix.size() ||
             col < 0 || col >= matrix[0].size() 
           ) 
        {
            return ; //农村包围城市，农村就边界
        }
      
         if (visited[row][col] == true) 
         {
             return ;//已经dfs遍历过
         }
        if (height > matrix[row][col])
        {
            return ;//不是升序，此路不通
        }  
      
        visited[row][col]  =true;//能走到这里说明 当前层次遍历完毕
        
        //每个点扩散四周，每个点被四周扩散时候，只要满足一个就可以连通，减少扩散层次。
        dfs(row+1,col, matrix[row][col],matrix,visited);
        dfs(row-1,col, matrix[row][col],matrix,visited);
        dfs(row,col+1, matrix[row][col],matrix,visited);
        dfs(row,col-1, matrix[row][col],matrix,visited);
   }
};