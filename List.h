
#ifndef LIST_LINKED_LIST_H
#define LIST_LINKED_LIST_H
    typedef struct student {
        char *std_name;
        char *std_password;
        int std_degree;
        int std_id;
    }ListEntry;

    typedef struct listnode{
        ListEntry entry ;
        struct listnode *next ;
    }ListNode;
    typedef struct list{
        ListNode  *head , *current ;
        int size , currentpos;
    }List;
    void CreateList(List *);
    void InsertList(int , ListEntry , List *);
    void DeleteList(int , ListEntry* , List *);
    int ListEmpty(List *);
    int ListFull(List *);
    int ListSize(List *);
    void DestroyList(List *);
    void TraverseList(List * , void(*)(ListEntry));
    void RetrieveList(int , ListEntry * , List *);
    void ReplaceList(int , ListEntry  , List *);
    void InsertFront(ListEntry , List*);
    void InsertBack(ListEntry,List *);

#endif //CPT_MAGED_LIST_H
