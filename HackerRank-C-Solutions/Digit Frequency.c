#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char s[1000],a[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int j,c = 0;
    scanf("%[^\n]", s);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < strlen(s); j++)
        {
            if(a[i] == s[j])
            {
                c++;
            }
            else{}
        }
        printf("%d ",c);
        c = 0;   
    }
    return 0;
}
