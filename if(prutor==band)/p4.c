/*
The problem setter was out of Alice-Bob stories. This time he decided to keep it simple and straight:

You are given an integer n. You have to form a matching of n pairs {x, y} using the numbers [1,2,3,...2n]. The pairs should satisfy the following properties: 

1. Each number in the range [1,2,3,...,2n] should be used exactly once. Let the pairs be (a1, b1), (a2, b2), ….. (an, bn). Then, ai < bi for each of the pairs, i.e. the first element of the pair should be less than the second element and,
2. If we define an array A formed by the sums of the elements in each pair: A = [a1+b1, a2+b2, …. , an + bn], then A should be strictly increasing and the adjacent elements should differ by 1

In other words, the sums of each of the n pairs should be n distinct and consecutive elements

Your task is to determine whether it is possible to form such a matching of n pairs. If it is possible, print the n pairs. 
Else if it is not possible, print n pairs such that these pairs satisfy the first property, these pairs are sorted in the increasing order of their first elements, and all the pairs have the same sum. Note that in this case, these pairs need not satisfy the second property mentioned above. 

INPUT
A single integer n (1<= n <= 100)

OUTPUT
If such a pairing is possible, print YES followed by n lines - each line containing one of the n pairs.
Else, print NO followed by n lines - each line containing one of the n pairs as described in the question. 
*/

//Passes all test cases. 

#include <stdio.h>

int main()
{
    
    int n;
    scanf("%d", &n);
    
    if(!(n&1))
    {
        printf("NO\n");
        
        for(int i = 1; i <= n; i++)
        {
            printf("%d %d\n", i, 2*n-i+1);
        }
    }
    else
    {
        printf("YES\n");
        
        for(int j = 1; j <= (n+1)/2; j++)
        {
            printf("%d %d\n", (2*j - 1), (n + (n+1)/2)-j+1);
        }
        
        for(int k = 1; k <= n/2; k++)
        {
            printf("%d %d\n", (2*k), 2*n - k+1);
        }
    }
    
    return 0;
}

// Yes there are more than 1 solution to this problem :(