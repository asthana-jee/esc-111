/*
In a mystical land, there are N ancient artifacts scattered throughout various regions. Each artifact possesses a unique mystical power. The power of the i-th artifact is represented by a positive integer A[i].

However, these artifacts are not easy to control. To activate their power, one must offer them the right amount of energy. The energy required to activate the i-th artifact is equal to the sum of its digits. For example, if A[i] = 345, the energy required would be 3 + 4 + 5 = 12.

You are a brave adventurer, and your quest is to activate all the artifacts with the minimum amount of energy. To do this, you have two abilities:
1. You can add 1 to any digit of the number on the artifact, but this requires expending 2 units of energy. If the resulting sum has a carry, then add it to the digit on the left and so on.
2. You can subtract 1 from any digit of the number on the artifact, but this also requires expending 1 unit of energy. You can't subtract 1 if the digit is 0.

If after using your ability, the new number on the artifact requires the same amount of energy(i.e., energy of new number + energy used in ability = energy of original number), you keep the new number only if its absolute value is smaller than the original number.
Consider this example:
Number on artifact 42, this will require 6 units of energy
I decrease the digit 2 by 1, making it 1, expending 1 unit of energy.
The new number is 41 which requires 5 units of energy, and the total energy I would need now is still 6 (5+1).
Alternately, I can decrease the digit 4 by 1, making it 3, expending 1 unit of energy.
The new number is 32, which requires 5 units of energy, and the total energy I would need now is still 6 (5+1).
Since all of 42, 41(after ability), 32(after ability) require a total of 6 units of energy, we will change the number on the artifact to 32 which has the smallest absolute value amongst all 3 of them.

Write a C function that takes the array A[] of N integers as input and outputs the minimum total energy required to activate all the artifacts.
Feel free to make additional functions which you think might aid your solution.

INPUT:
First line contains N (1<=N<=1000), the number of artifacts.
The following N lines contain the number on each artifact. (1<=A[i]<=100000)


OUTPUT:
The output should contain two lines,
First line contains a single number denoting the minimum total energy required to activate all the artifacts.
Second line contains N single-space separated integers which denote the updated numbers on each artifact.
[Do not add an additional newline character after the second line of your output and no trailing whitespaces.]
*/

//Passes 2/2 Visible and 8/10

#include <stdio.h>

void minTotEnergy(int n, int A[]){
    
    int sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    
    printf("%d\n", sum);
}

int sumOfDigits(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num%10;
        num /= 10;
    }
    return sum;
}

int lenOfNum(int num)
{
    int len = 0;
    while(num > 0)
    {
        num /= 10;
        len++;
    }
    
    return len;
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    
    for(int i = 0; i < n; i++)
    {
        int inp;
        scanf("%d", &inp);
        
        arr[i] = inp;
        
    }
    
    int minEnrgy[1000];
    
    for(int j = 0; j < n; j++)
    {
        int num = 1;
        int f = 1;
        while(num <= arr[j])
        {
            if(sumOfDigits(arr[j]) > sumOfDigits(arr[j]+num)+2)
            {
                minEnrgy[j] = sumOfDigits(arr[j]+num) + 2;
                arr[j] += num;
                j++;
            }
            else if(lenOfNum(arr[j]) == lenOfNum(num) && f == 1)
            {
                minEnrgy[j] = sumOfDigits(arr[j]);
                arr[j] -= num;
                f = 0;
            }
            else
            {
                num *= 10;
            }
        }
    }
    
    minTotEnergy(n, minEnrgy);
    
    for(int k = 0; k < n; k++)
    {
        printf("%d ", arr[k]);
    }
    
    return 0;
}




//One of the hidden case my code doesn't pass might be 9989.