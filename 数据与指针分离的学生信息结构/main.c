#include "list.h"

int main() {
    List* list = ListInit();
    int cnt = 0;
    scanf("%d", &cnt);
    getchar();
    while (cnt--) 
        AddNode(list);

    Sort(list);
    printf("output list:\n");
    ShowList(list);

    Reverse(list);
    printf("output reverse list:\n");
    ShowList(list);

    DestoryData(list);
    return 0;
}
