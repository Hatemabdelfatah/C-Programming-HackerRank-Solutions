#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    double ptr[n];
    double p = 0;
    for(int i = 0; i < n; i++)
    {
        double u = (tr[i].a + tr[i].b + tr[i].c);
        p = (u / 2);
        ptr[i] =  sqrt((p*(p - tr[i].a)*(p - tr[i].b)*(p - tr[i].c)));
    }
    
    char flag = 0;
    for(int i = 0; i < n-1; i++)
    {
        flag = 0;
        for(int j = 0; j < n-1-i; j++)
        {
            if(ptr[j] > ptr[j+1])
            {
                double temp1 = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp1;
                
                triangle temp = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = temp;
                flag = 1;
            }
        }
        if(0 == flag)
        {
            break;
        }
    }
    
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}