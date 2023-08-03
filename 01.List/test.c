#include "./head/LoopLinkList.h"

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
    TailInsertList(Plist, 6);
    TailInsertList(Plist, 7);
    TailInsertList(Plist, 8);
    TailInsertList(Plist, 9);
    TailInsertList(Plist, 10);
    PrintList(list);
    InsertList(Plist, 1, 100);
    InsertList(Plist, 12, 200);
    InsertList(Plist, 7, 300);
    PrintList(list);
    HeadDeleteList(Plist);
    HeadDeleteList(Plist);
    PrintList(list);
    TailDeleteList(Plist);
    TailDeleteList(Plist);
    PrintList(list);
    DeleteList(Plist, 1);
    DeleteList(Plist, 3);
    DeleteList(Plist, 7);
    PrintList(list);



    DestroyList(Plist);

    return EXIT_SUCCESS;
}