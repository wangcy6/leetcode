class Solution {
private:
 
 	int m_less; //全局变量，整个函数可见，代替指针传参

public:

    int coinChange(vector<int>& coins, int amount) 
	{
		m_less =INT_MAX; 
		 
		sort(coins.begin(),coins.end(),greater<int>());
		
		//递归从上到下传递参数，不需要返回值
		coinChange(0,coins,amount,0);
		//数字在前面是个技巧，刚才没检查出来 if( m_less=INT_MAX) 
		if (INT_MAX == m_less){
		    return -1;
		}
		return m_less;
     
    }

    void coinChange(int index,vector<int>&coins,int amount,int total){

          if (amount <0){
             return ;//组合失败
         }
         if (amount == 0){
             //组合成功
             m_less =min(m_less,total);
             cout<<m_less<<endl;
         }
        
         if(index >=coins.size())
         {
             return; //组合失败，
         }
		
		
         int maxValue =amount/coins[index];//最多可以使用多个硬币
		
          //递归情况下如果不考虑n的变化，造成死循环。i >0情况下，for不执行
		 //index 不会发生变化。
         for(int i=maxValue;i >=0 && (total+i) <m_less;i--)
         {
           int left =amount-i*coins[index];
           int sum =total+i;
           coinChange(index+1,coins,left,sum);
         }
    }
};