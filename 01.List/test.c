#include "./head/DLinkList.h"

int main(void)
{
    DList list = InitList();
    DList* PList = &list;

    HeadInsertList(PList, 1);
    HeadInsertList(PList, 2);
    HeadInsertList(PList, 3);
    HeadInsertList(PList, 4);
    HeadInsertList(PList, 5);
    PrintList(list);
    TailInsertList(PList, 6);
    TailInsertList(PList, 7);
    TailInsertList(PList, 8);
    TailInsertList(PList, 9);
    TailInsertList(PList, 10);
    PrintList(list);
    InsertList(PList, 3, 100);

    InsertList(PList, 1, 101);
    InsertList(PList, 12, 201);
    PrintList(list);

    InsertList(PList, 14, 11);
    PrintList(list);

    HeadDeleteList(PList);
    PrintList(list);
    TailDeleteList(PList);
    PrintList(list);

    DeleteList(PList, 1);
    PrintList(list);

    DeleteList(PList, 5);
    PrintList(list);
    DeleteList(PList, 10);
    PrintList(list);

    DNode* node = NULL;
    node = GetNode(list, 5);
    printf("node->data: %d\n", node->data);
    node = GetNode(list, 9);
    printf("node->data: %d\n", node->data);

    node = GetNode(list, 20);
    if(node != NULL)
        printf("node->data: %d\n", node->data);
    else
        printf("node is NULL!\n");


    node = LocateElem(list, 4);
    printf("node->data: %d\n", node->data);
    node = LocateElem(list, 201);
    printf("node->data: %d\n", node->data);
    node = LocateElem(list, 6);
    printf("node->data: %d\n", node->data);   

    PrintList(list);
    int len = Length(list);
    printf("len: %d\n", len);



    DestroyList(PList);
    if (list == NULL)
    {
        printf("list is NULL\n");
    }
    

    return EXIT_SUCCESS;
}