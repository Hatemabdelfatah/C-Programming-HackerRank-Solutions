#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) 
{
    
    int max_and,max_or,max_xor;
    int s=0,a = 1,b = 2,count = 0;
    int temp = n>k? n : k;
    int temp2 = temp;
    for(int i = 1; i < temp; i++){
        s += i;
    }
    int arr_and[s],arr_or[s],arr_xor[s];
    for(int i = 1; i < temp2; i++)
    {
        for(int j = 1; j < temp; j++){
            arr_and[count] = a & b;
            arr_or[count] = a | b;
            arr_xor[count] = a ^ b;
            b++;
            count++;
        }
        a++;
        b = a+1;
        temp--;
    }
    max_and = 0;
    max_or = 0;
    max_xor = 0;
    for(int i = 0; i < s; i++){
        if((arr_and[i] > max_and) && (arr_and[i] < k)){
            max_and = arr_and[i];
        }
        else{}
        if((arr_or[i] > max_or) && (arr_or[i] < k)){
            max_or = arr_or[i];
        }
        else{}
        if((arr_xor[i] > max_xor) && (arr_xor[i] < k)){
            max_xor = arr_xor[i];
        }
        else{}
    }
    printf("%d\n%d\n%d",max_and,max_or,max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
