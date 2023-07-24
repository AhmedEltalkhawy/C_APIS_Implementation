
#include "struct.h"
#include <stdio.h>





/*void printstack (struct stack *ps)
{
    printf("%d" , (*ps).top) ;
}*/



void struct_scan (struct student * ps)
{
    string_scan( ps->name ,20) ;
    scanf("%d" , &((*ps).age)) ;
    fflush(stdin) ;
    scanf("%c" , &((*ps).age)) ;

}

void struct_print(struct student *ps)
{
    printf("%s  %d  %c\n" , ps->name , ps->age , ps->grade) ;
}

struct student scan ()
{
    struct student s ;
    scanf("%s" , s.name) ;
    scanf("%d" , &s.age) ;
    fflush(stdin) ;
    scanf("%c" , &s.grade) ;
    return s ;
};
void print_array_struct( struct student * ps , int size)
{
    int i = 0 ;
    for(i=0 ; i < size ; ++i)
        struct_print(ps+i) ;

}

