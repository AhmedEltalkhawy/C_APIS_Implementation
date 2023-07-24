typedef struct node {

int data;
struct node* next;

}node_t;


node_t*list_CreateNode(int data);
void list_AddNodeToLast(node_t**phead,int data);

int list_RemoveByData(node_t**phead,int oldData);


void list_print(node_t*head);
void removelast (node_t ** head ) ;
