#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int n;
    scanf("%d",&n);
    
        if(n <= 9){
        switch (n) {
        case 1:
            printf("one \n");
            break;
        case 2:
            printf("two \n");
            break;
        case 3:
            printf("three \n");
            break;
        case 4:
            printf("four \n");
            break;
        case 5:
            printf("five \n");
            break;
        case 6:
            printf("six \n");
            break;
        case 7:
            printf("seven \n");
            break;
        case 8:
            printf("eight \n");
            break;
        case 9:
            printf("nine \n");
            break;
        default:
            break;
            
        }         
        }
        else{
            printf("Greater than 9");
        }
}
