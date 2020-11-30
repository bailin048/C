#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
int main()
{
    char* c[] = { "enter","new","point","first" };
    char** cp[] = { c + 3,c + 2,c + 1,c };
    char*** cpp = cp;
    printf("%s\n", **++cpp);
    printf("%s\n", *--*++cpp+3);
    printf("%s\n", *cpp[-2]+3);
    printf("%s\n", cpp[-1][-1]+1);
    return 0;
}