Given a number X between 0 to 1000000006 find smallest positive integer Y such that the products of digits of Y modulo 1000000007 is X.

Input Format

A single integer - X

Output Format

A single integer - Y

Input Constraint

0 <= X <= 1000000006

Problem Setter: Practo Tech Team

SAMPLE INPUT 
16
SAMPLE OUTPUT 
28
Explanation
If x is 16 then y is 28 as (2*8)%1000000007 = 16
***************************************************************************************************************************************************
#include <stdio.h>
 
int main()
{
    long long int x,y=0,k=0,i=0,j=1;
    char str[1000];
    scanf("%lld",&x);
    if(x==0) {printf("10"); return 0;}
    if(x==1) {printf("1"); return 0;}
    long long int temp=x;
    for(i=9;i>1 && x>0;i--){
    	while(x%i==0){
    		x=x/i;
    		str[k++]=i+'0';
    	}
    }
    while(x>1){
    	
    	
    	x=temp+1000000007*j;
    	k=0;
    	for(i=9;i>1 && x>0;i--){
    		while(x%i==0){
    			x=x/i;
    			str[k++]=i+'0';
    		}
    	}
    	j++;
    }
    
    k--;
    while(k>=0){
    	printf("%c",str[k--]);
    }
    return 0;
}
