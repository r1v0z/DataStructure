#include "./head/LinkedList.h"

int main(void)
{
    LinkList list = InitList();
    LinkList* Plist = &list;
    HeadInsertList(Plist, 1);
    HeadInsertList(Plist, 2);
    HeadInsertList(Plist, 3);
    HeadInsertList(Plist, 4);
    HeadInsertList(Plist, 5);
    PrintList(list);

    TailInsertList(list, 6);
    TailInsertList(list, 7);
    TailInsertList(list, 8);
    TailInsertList(list, 9);
    TailInsertList(list, 10);
    PrintList(list);

    HeadDeleteList(Plist);
    PrintList(list);
    TailDeleteList(Plist);
    PrintList(list);

    InsertList(Plist, 3, 10);
    PrintList(list);

    InsertList(Plist, 4, 20);
    PrintList(list);

    InsertList(Plist, 2, 30);
    PrintList(list);

    InsertList(Plist, 5, 40);
    PrintList(list);
    printf("----------------\n");
    DeleteList(Plist, 1);
    DeleteList(Plist, 13);
    DeleteList(Plist, 3);
    PrintList(list);



    DestroyList(Plist);
    // PrintList(list);
    return EXIT_SUCCESS;
}