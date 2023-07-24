
#include "linkedlists.h"

node_t*list_CreateNode(int data)
{
    node_t*new_node=(node_t*)malloc(sizeof(node_t));
    new_node->data=data;
    new_node->next=0;
    return new_node;

}


void list_AddNodeToLast(node_t**phead,int data)
{
    node_t *new_node=list_CreateNode(data);
    if(*phead==0)
    {
       *phead=new_node;
        return;
    }

    node_t*current=*phead;
    while(current->next!=0)
    {
        current=current->next;
    }
    current->next=new_node;

}
void list_print(node_t*head)
{
    node_t*current=head;
    while(current!=0)
    {
        printf("%d  ",current->data);
        current=current->next;
    }
    printf("\n");
}

int list_RemoveByData(node_t**phead,int oldData)
{
    if((*phead)->data==oldData)
    {
        node_t*temp=*phead;
        *phead=(*phead)->next;
        free(temp);
        return 1;
    }
    node_t*current=*phead;
    while(current->next->data!=oldData)
    {
        current=current->next;
        if(current->next==0)
        {
            return 0;
        }
    }
    node_t *temp=current->next;
    current->next=current->next->next;
    free(temp);
    return 1;

}
void removelast (node_t ** head )
{
    node_t * temp = *head ;
    while(temp->next->next != 0)
    {
        temp = temp->next ;
    }
    node_t *temp2 = temp ;
    temp->next = temp->next->next ;
    free(temp2->next->next) ;

}
