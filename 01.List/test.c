#include "./head/LinkedList.h"

int main(void)
{
    LinkNode* node = NULL;
    LinkList list = InitList();
    HeadInsertList(list, 17);
    HeadInsertList(list, 42);
    HeadInsertList(list, 32);
    HeadInsertList(list, 46);
    HeadInsertList(list, 5);
    TailInsertList(list, 17);
    TailInsertList(list, 17);
    PrintList(list);
    DestroyList(&list);

    if(list == NULL)
        printf("list is NULL\n");
    else
        printf("list is Not NULL\n");
    return EXIT_SUCCESS;
}