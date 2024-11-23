#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,count,t = 5,f = 1;
    scanf("%d", &n);
      for(int i = n-1; i >= 1-n  ; i--)
    {
        for(int j = n-1; j >= 1-n; j--)
        {
            if(abs(i) <= abs(j))
            {
                printf("%d ", abs(j)+1);
            }
            else if(abs(i) > abs(j))
            {
                printf("%d ", abs(i)+1);
            }
        }
        printf("\n");   
    }
      
    return 0;
}
