#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,f = 10,remain,sum = 0;
    scanf("%d", &n);
    while(n != 0)
    {
        remain = n % f;
        n /= 10;
        sum += remain;
    }
    printf("%d",sum);
    
    return 0;
}
