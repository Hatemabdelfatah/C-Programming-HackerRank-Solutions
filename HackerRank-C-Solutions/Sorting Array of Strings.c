#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}


int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = 0, count_b = 0;
    int char_count_a[26] = {0}, char_count_b[26] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        if (!char_count_a[a[i] - 'a']) {
            char_count_a[a[i] - 'a'] = 1;
            count_a++;
        }
    }

    for (int i = 0; b[i] != '\0'; i++) {
        if (!char_count_b[b[i] - 'a']) {
            char_count_b[b[i] - 'a'] = 1;
            count_b++;
        }
    }

    if (count_a == count_b) {
        return strcmp(a, b);
    }

    return count_a - count_b;
}
int sort_by_length(const char* a, const char* b) {
    if(strlen(a)>strlen(b))
    {
        return 1;
    }
    else if (strlen(a)<strlen(b))
    {
        return 0;
    }
    else
    {
        return strcmp(a,b);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int retval = 0;
    for(int i = 0; i < len-1; i++)
    {
        for(int j = 0; j < len-1-i ; j++)
        {
            retval = cmp_func(arr[j],arr[j+1]);
            if(retval>0)
            {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}