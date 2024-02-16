/*

It's your birthday, and you wish to distribute candies in your class. There are x students in the class. You go to the candy store, where you are presented with n candy packets. Each packet costs the same. Hence, you want to buy at least x candies with as few packets as possible. 

Formally, given n candy packets, you need to choose m adjacent packets such that you get at least x candies. Out of all possible contiguous (adjacent) sequences of packets, your task is to print the minimum value of m. If no such value of m exists, output -1.

Note: Elements in a subsequence are called contiguous (adjacent)  iff the elements taken in order are consecutive in the original sequence.

You can not consider the first and the last packet to be adjacent to each other. 

Input:
You are required to solve multiple such tasks. The first line contains t, the number of tasks. This is followed by t tasks, each of two lines. The first line (of each task) has two spaced integers, x and n. The second line (of each task) consists of n strings denoting the name of the candy. Two candy names are separated by a single space. The number of letters in the spelling of the candy represents the number of candies in each packet. It is given that the number of letters in the name of a candy does not exceed 20.

*/

// Code Passes All Test Cases.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int x, n;
        scanf("%d %d", &x, &n);
        
        int arr[10000];
        for(int i = 0; i < n; i++)
        {
            char str[20];
            scanf("%s", str);
            int len = strlen(str);
            arr[i] = len;
        }
        
        int m = n+1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= n - i; j++)
            {
                int sum = 0, k = 0;
                for(k = i; k <= i+j-1; k++)
                {
                    sum += arr[k];
                }
                
                if(sum == x && m > j)
                {
                    m = j;
                }
                else if(sum >= x && m > j)
                {
                    m = j;
                }
            }
        }
        
        (m != n+1)&&printf("%d\n", m)||printf("-1\n");
    }
    
    return 0;
}