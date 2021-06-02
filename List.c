#include "List.h"
#include <stdlib.h>
void CreateList(List *pl) {
    pl->head = NULL;
    pl->size = 0;
    pl->current=NULL;
    pl->currentpos = 0;
}
void InsertBack(ListEntry e , List *pl){
    int pos = ListSize(pl);
    ListNode *p , *tmp;
    p= (ListNode *)malloc(sizeof(ListNode));
    p->entry=e;
    p->next=NULL;
    tmp=pl->head;
    int i;
    for(i = 0 ; i< pos-1 ; i++){
        tmp = tmp->next;
    }
    pl->current = tmp;
    pl->currentpos=(ListSize(pl)-1);
    pl->size++;
}
void InsertFront(ListEntry e , List *pl){
    ListNode *p;
    p =(ListNode *)malloc(sizeof(ListNode));
    p->entry=e;
    p->next=pl->head;
    pl->head=p;
    pl->currentpos=0;
    pl->current=pl->head;
    pl->size++;
}
void InsertList(int pos , ListEntry e , List *pl){
    ListNode  *p;
    p =(ListNode *)malloc(sizeof(ListNode));
    p->entry=e;
    p->next=NULL;
    if(pos==0){
        p->next=pl->head;
        pl->head=p;
        pl->currentpos=0;
        pl->current=pl->head;
    }
    else{
        if(pos<=pl->currentpos){
            pl->currentpos=0;
            pl->current=pl->head;
        }
        for(;pl->currentpos!=pos-1;pl->currentpos++)
            pl->current=pl->current->next;
        p->next=pl->current->next;
        pl->current->next=p;
    }
    pl->size++;
}
void DeleteList (int pos , ListEntry *pe , List *pl){
    ListNode *tmp;
    if(pos == 0){
        *pe=pl->head->entry;
        pl->current=pl->head->next;
        free(pl->head);
        pl->head=pl->current;
        pl->currentpos=0;
    }
    else{
        if(pos <= pl->currentpos){
            pl->currentpos = 0;
            pl->current = pl->head;
        }
        for(;pl->currentpos != pos-1 ; pl->currentpos++)
            pl->current=pl->current->next;
        *pe = pl->current->next->entry;
        tmp=pl->current->next->next;
        free(pl->current->next);
        pl->current->next=tmp;
    }
    pl->size--;
}
int ListEmpty(List *pl){
    return (pl->size==0);
}
int ListFull(List *pl){
    return 0;
}
int ListSize(List *pl){
    return pl->size;
}
void DestroyList (List *pl){
    ListNode *q;
    while(pl->head){
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->size=0;
}
void TraverseList(List *pl , void(*Visit)(ListEntry)){
    ListNode *p = pl->head;
    while(p){
        (*Visit)(p->entry);
        p=p->next;
    }
}
void RetrieveList(int pos , ListEntry *pe , List *pl){
    if(pos==0)
        *pe = pl->head->entry;
    else{
        if(pos<=pl->currentpos){
            pl->currentpos=0;
            pl->current=pl->head;
        }
        for (;pl->currentpos != pos-1;pl->currentpos++)
            pl->current=pl->current->next;
        *pe=pl->current->next->entry;
    }
}
void ReplaceList(int pos , ListEntry e , List *pl){
    if(pos==0)
        pl->head->entry=e;
    else{
        if(pos<=pl->currentpos){
            pl->currentpos=0;
            pl->current=pl->head;
        }
        for(;pl->currentpos != pos-1 ;pl->currentpos++)
            pl->current=pl->current->next;
        pl->current->next->entry = e;
    }
}




