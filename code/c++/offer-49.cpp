/**
要求：把字符串转化成整数
测试用例：正负数和0，空字符，包含其他字符
intou  outout -wrong
1. 123-- 123--1111
2 ""  0-- -1200350024
3 1a33 --0--5933
4 2147483648 --0  -2147483648 (int   2147483648～2147483647)
5 -2147483648  --2147483648 -0
备注：使用raise抛出异常作为非法提示

**/
class Solution {
public:
    int StrToInt(string str) {
        int maxValue = (int)((unsigned)~0 >> 1);
        int minValue = -(int)((unsigned)~0 >> 1) - 1;
     
        int strLen= str.size();
        long long out=0;//忘记初始化
        int index =0;
        if (strLen ==0 ) {return out;}
        int flag =1;
        if(str[index] =='+')
        {
            flag=1; 
            index++;
            
        }else if(str[index] =='-')
        {
            flag =2;
            index++;
        }
             
             
        for (;index<strLen;index++)
        {   
            int temp =str[index]-'0';
            if( temp >0 && temp <9)
            {
                out=out*10+temp;
                if(flag ==1 && out > maxValue || flag ==2 && out< minValue  )
                {
                    out =0;
                    break;
                }
                
            }else
            {   //非数字
                out =0;
                break;
            }
            
        }
        return  flag==1?out:-out;
    }
};