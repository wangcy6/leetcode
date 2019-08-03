
// CPP program to reverse a string 
#include <stdio.h> 
  
/* function prototype for utility function to 
  reverse a string from begin to end  */
void reverse(char* begin, char* end); 
  
/*Function to reverse words*/
void reverseWords(char* s) 
{ 
    char* start=s;
	char* end =s+strlen(s);
	//step01 trim 
	while(start &&*start == '' )
	{
		start++;
	}
	if (!start)
	{
		return "";
	}
	while(end||*end == '' )
	{
		end --;
	}
	if (!end)
	{
		return "";
	}
	if(start=s ||end =s+strlen(s) )
	{
		
	}else
	{
		strncpy(s,s+start,end-start);
	}
	//02 交换
	while(end>start)
	{
		
	}
	
	
  
} 
  
/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer 
  begin and ending with pointer end  */
void reverse(char* begin, char* end) 
{ 
    char temp; 
    while (begin < end) { 
        temp = *begin; 
        *begin++ = *end; 
        *end-- = temp; 
    } 
} 
 

/* Driver function to test above functions */
int main() 
{ 
    char s[] = "i like this program very much"; 
    char* temp = s; 
    reverseWords(s); 
    printf("%s", s);  
    return 0; 
} 