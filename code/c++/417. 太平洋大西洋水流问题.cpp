class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> out;
        int row = matrix.size();
        if ( 0 == row ) return out;
        int col = matrix[0].size();
		if (0 == col) return out;

        //能流动到“太平洋"的陆地
        vector<vector<bool>> dp1(row, vector<bool>(col, false));
        //能流动到“大西洋"的陆地
        vector<vector<bool>> dp2(row, vector<bool>(col, false));
        
        //从第一行/最后一行出发寻找连同节点，不变的x坐标
        for (int j = 0; j < col; j++) {
            dfs(0,j,INT_MIN,matrix,dp1);
            dfs(row-1,j,INT_MIN,matrix,dp2);
        }
        //从第一列/最后一列出发寻找连同节点,不变的y坐标
        for (int i = 0; i < row; i++) {
             dfs(i,0,INT_MIN,matrix,dp1);
             dfs(i,col-1,INT_MIN,matrix,dp2);
        }

        vector<int> temp(2);
        for (int i=0;i < row;i++)
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
//超时
class Solution2 {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
         vector<vector<int>> result;
         int rows = matrix.size();
         if ( rows  == 0) return result;//不要忘记边界检查
         int cols =matrix[0].size();
         
         vector<int> temp(2);
        
        for (int i=0; i < rows; i++ )
        {
            for (int j=0;j < cols; j++)
            {
                if ( dfs(matrix,i,j,INT_MAX,rows,cols) ==3)
                {
                    temp[0]=i;
                    temp[1]=j;
                    result.push_back(temp);
                }
            }
        }
        
        return result;
        
    }
    //从中心到周围遍历时候 需考虑死循环，matrix[row][col]=INT_MAX别人来回运动
    int dfs(vector<vector<int>>& matrix,int row,int col,int pre,int rows,int cols)
    {
      
      if (row < 0 || col < 0) return 1; //边界检查-遇到太平洋
      if (row >=rows || col >= cols ) return 2; //边界检查-遇到大西洋
     
      //当前节点判断逻辑  
      if (matrix[row][col] > pre)  return 0;  //不能流动 返回0
      pre =matrix[row][col];
      
      //依赖四个节点必须完全遍历完毕，而不是只要其从一个可以通过就可以 
      matrix[row][col]=INT_MAX;  
      int isBoth =  dfs(matrix,row,col-1,pre,rows,cols) |  
                     dfs(matrix,row,col+1,pre,rows,cols) | 
                     dfs(matrix,row+1,col,pre,rows,cols) | 
                     dfs(matrix,row-1,col,pre,rows,cols) ;
     //cout<< row <<":"<<cols<<":"<<pre <<":"<<isBoth <<endl;
      matrix[row][col] = pre;//破坏当前节点数据，后面其他节点无法在使用该节点
      return isBoth;
          
          
    }
};
/**
//测试结果
超出时间限制
[[1,2,3,4,5,6,7,8,9,10,11,12,13],
[48,49,50,51,52,53,54,55,56,57,58,59,14],
[47,88,89,90,91,92,93,94,95,96,97,60,15],
[46,87,120,121,122,123,124,125,126,127,98,61,16],
[45,86,119,144,145,146,147,148,149,128,99,62,17],
[44,85,118,143,160,161,162,163,150,129,100,63,18],
[43,84,117,142,159,168,169,164,151,130,101,64,19],
[42,83,116,141,158,167,166,165,152,131,102,65,20],
[41,82,115,140,157,156,155,154,153,132,103,66,21],
[40,81,114,139,138,137,136,135,134,133,104,67,22],
[39,80,113,112,111,110,109,108,107,106,105,68,23],
[38,79,78,77,76,75,74,73,72,71,70,69,24],
[37,36,35,34,33,32,31,30,29,28,27,26,25]]

执行用时：112 ms
**/
