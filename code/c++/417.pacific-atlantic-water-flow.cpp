class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
         vector<vector<int>> result;
         int rows = matrix.size();
         if ( rows  == 0) return result;//不要忘记边界检查 错误1 
         int cols =matrix[0].size();
         if (0 == cols ) return result;
         vector<int> temp(2);
        
        for (int i=0; i < rows; i++ )
        {
            for (int j=0;j < cols; j++)
            {     
		        //第一个节点默认是通过的
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
	 //错误2 自己col-1 写成 cols-1 ，（i,j）坐标和 行，列大小明明有冲突
     //cout<< row <<":"<<cols<<":"<<pre <<":"<<isBoth <<endl;
      matrix[row][col] = pre;//错误3 破坏当前节点数据，后面其他节点无法在使用该节点
      return isBoth;
          
          
    }
	int dfs(vector<vector<int>>& matrix,int row,int col,int pre)
    {
      
      if (row < 0 || col < 0) return 1; //边界检查-遇到太平洋
      if (row >=matrix.size() || col >= matrix[0].size() ) return 2; //边界检查-遇到大西洋
     
      //当前节点判断逻辑  
      if (matrix[row][col] > pre)  return 0;  //不能流动 返回0
      pre =matrix[row][col];
      
      //依赖四个节点必须完全遍历完毕，而不是只要其从一个可以通过就可以 
      matrix[row][col]=INT_MAX;  
      int isBoth =  dfs(matrix,row,col-1,pre) |  
                     dfs(matrix,row,col+1,pre) | 
                     dfs(matrix,row+1,col,pre) | 
                     dfs(matrix,row-1,col,pre) ;
	 //错误1 自己col-1 写成 cols-1 ，（i,j）坐标和 行，列大小明明有冲突
     //cout<< row <<":"<<cols<<":"<<pre <<":"<<isBoth <<endl;
      matrix[row][col] = pre;//破坏当前节点数据，后面其他节点无法在使用该节点
      return isBoth;
          
          
    }
};