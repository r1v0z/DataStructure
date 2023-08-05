#include "./head/LoopDlinkList.h"

int main(void)
{
    DLinkList list = InitList();
    DLinkList* Plist = &list;

    HeadInsertList(Plist, 1);
    HeadInsertList(Plist, 2);
    HeadInsertList(Plist, 3);
    HeadInsertList(Plist, 4);
    HeadInsertList(Plist, 5);
    PrintList(list);


    TailInsertList(Plist, 6);
    TailInsertList(Plist, 7);
    TailInsertList(Plist, 8);
    TailInsertList(Plist, 9);
    TailInsertList(Plist, 10);
    PrintList(list);

    HeadDeleteList(Plist);
    TailDeleteList(Plist);
    PrintList(list);

    InsertList(Plist, 1, 100);
    InsertList(Plist, 4, 200);
    InsertList(Plist, 11, 300);
    PrintList(list);

    DeleteList(Plist, 11);
    DeleteList(Plist, 1);
    DeleteList(Plist, 4);
    PrintList(list);
    DNode* node = GetElem(list, 8);
    if (node != NULL)
        printf("node->data: %d\n", node->data);
    else
        printf("node is NULL\n");
    node = GetElem(list, 3000);
    if (node != NULL)
        printf("node->data: %d\n", node->data);
    else
        printf("node is NULL\n");

    DestroyList(Plist);

    return EXIT_SUCCESS;
}