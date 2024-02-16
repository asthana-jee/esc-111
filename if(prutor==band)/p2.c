/*

A school trip was organized to the water park. However, before the bus starts, the teacher asks t number of similar programming problems. In a programming problem, the teacher provided a list of n unique numbers as a[1] a[2].....a[n] such that 1<=a[i]<=n. Another list provided by the teacher was b[1] b[2]....b[n] such that initially b[i]=i for all i.

Now we perform some operations.
In one operation, a[i] represents that the number originally at a[i]th index in b is taken to ith index; this is done for 1<=i<=n. After performing this on all the n elements of b, we get our new b.

Lets walk through an example
We start with 
a : 3 6 4 8 2 1 5 7 
b : 1 2 3 4 5 6 7 8
Lets say after some operation we have
a : 3 6 4 8 2 1 5 7 
b : 1 3 4 2 5 7 8 6
Then after one more operation we have, 
b: 4 7 2 6 3 1 5 8.
As a[1]=3 and the number at a[1]th index in b is 4 originally, so 4 comes at the first position and so on.

What are the minimum number of transformations greater than 0 required to return the b in ascending order? If the number of transformations on b required are y, then p=(2^y)mod1000000007

NOTE: 


 Indexing starts from 1 

 Beware of overflow and use long long wherever necessary 

 There is only 1 newline after each output and no trailing newlines.


INPUT :
The first line of the input contains an integer t (1<=t<=10) — the number of tasks.
The first line of each test case description contains an integer n 
The second line of the test case description contains n integers a1,a2,…,an

OUTPUT :
Output t lines, each containing the answer p to the corresponding test case

INPUT CONSTRAINTS:
1<=n<=1000


*/

// Passes All Test Cases.

#include <stdio.h>

#define MOD 1000000007

int check_asc(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return 1;
        }
    }
    
    return 0;
}

int main()
{
    
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n;
        scanf("%d", &n);
        
        int arr[1000];
        
        for(int i = 0; i < n; i++)
        {
            int inp;
            scanf("%d", &inp);
            arr[i] = inp;
        }
        
        int asc_arr[1000];
        
        for(int j = 0; j < n; j++)
        {
            asc_arr[j] = j;
        }
        
        int power = 0;
        
        do
        {
            int new_arr[1000];
            
            for(int k = 0; k < n; k++)
            {
                new_arr[k] = asc_arr[arr[k]-1];
            }
            
            for(int l = 0; l < n; l++)
            {
                asc_arr[l] = new_arr[l];
            }
            
            power++;
        }
        while(check_asc(asc_arr, n));
        
        int p = 1;
        for(int m = 0; m < power; m++)
        {
            p = (p*2)%MOD;
        }
        
        printf("%d\n", p);
        
    }
    
    return 0;
}