#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include<string.h>

void print_string (char* arr) ;
void string_Upper_to_Lower(char* str) ;
void stringcancotante (char* str1,char* str2, char* out, int maxsize) ;
void string_scan(char* str) ;
void better_string_scan(char* str) ;
void Float_To_String(char* str, float fnum) ;
void Take_String_print_n_times (char* str, char sperator) ;
int another_mergearray (int* arr1, int size1, int* arr2, int size2, int* arr3, int size3) ;
void frame (char* str, char*s1, char* s2, int* pn1, int* pn2) ;
int another_mergearray (int* arr1, int size1, int* arr2, int size2, int* arr3, int size3) ;
void printarray (int *arr, int size) ;
void another_Int_To_String (char* str, int num) ;
int String_To_Int (char* str) ;
void printarrayofstring (char** arr, int size) ;
int fact_r (int n) ;
int fabonchi_r(int n) ;
int fabonchi (int n) ;





int rec_binarysearch (int* arr, int first, int last, int element)
{
    if(first > last)
        return -1 ;
    int middle = (first+last) / 2 ;
    if(element == arr[middle])
        return middle ;
    else if (arr[middle] > element)
    {
        /*return*/ rec_binarysearch(arr, first, middle -1, element) ;

    }
    else
        /*return*/
        rec_binarysearch(arr, middle + 1, last, element) ;

}

#include "linkedlists.h"

void swap (int* n1, int* n2)
{
    int temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

/**************************************************/
int main()
{
    int arr [] = {2,4,3,9,6,3,1,5} ;
    int* sumarr = (int*) malloc(sizeof(arr)/sizeof(arr[0]) *sizeof(int)) ;
    ZeroBased(sumarr , arr , sizeof(arr)/sizeof(arr[0]) );
    printf("%d" , SumRange(1 , 3 , sumarr)) ;


    return 0;
}


