void n_swappointer (char**pptr1,char**pptr2 )
{
    char* temp_ptr ;
    temp_ptr = *pptr1 ;
    *pptr1 = *pptr2 ;
    *pptr2 = temp_ptr ;
}
int n_faster_stringcompare (char* str1, char* str2)
{
    int i ;
    //it can be && but we need to do the checking after the loop
    for(i=0 ; str1[i] || str2[i] ; ++i)
    {
        if (str1[i] > str2[i])
            return 1 ;
        else if (str1[i] < str2[i])
            return -1 ;
    }
    return 0 ;
}
void n_bubblesort (char**arr , int size)
{
    int i , j , temp , flag = 1 , count= 0 ;
    for(i=0 ; (i < size)  ; ++i)
    {
        for(j=0 ; j < size - i - 1  ; ++j )
        {
            if(n_faster_stringcompare(arr[j] , arr[j+1]) == 1)
            {
                         ++count ;

               n_swappointer(&arr[j] , &arr[j+1]) ;
            }

        }
        /*if(flag==1)
            break ;*/

    }
    printf("%d\n" , count) ;
}
void printarrayofstring (char** arr , int size)
{
    int i ;
    for(i=0 ; i < size ; ++i)
        print_string(arr[i]) ;
}


/*int main()
{
    char* str [] = {"mohamed" , "yassen" , "fathi" , "ali"} ;
    printarrayofstring(str ,4) ;
    n_bubblesort(str , 4) ;
    printarrayofstring(str ,4) ;



    return 0;
}*/



