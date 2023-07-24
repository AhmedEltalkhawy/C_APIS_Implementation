
int searchchar_in_2darray(char (*parr)[5] , int row , int col , char element)
{
    // this function is found element counting and return its location
    int row_index = -1 , col_index = -1 , char_counter = 0 , i , j , char_flag = 0  ;
    for(i=0 ; i < row ; ++i)
    {
        for(j=0 ; j < col ; ++j)
        {
            if(parr[i][j] == element )
            {
                ++char_counter ;
                if(char_flag == 0)
                {
                   row_index = i ;
                   col_index = j ;
                   char_flag = 1 ;
                }
             }
        }
    }
    if(char_counter > 0)
    {
        printf("%c is exist in row %d and column % d and it is repeated %d times \n" , element , row_index , col_index , char_counter) ;
    }
    else
        printarrayofstring("%c  is not exist \n" , element) ;

}


/*int main()
{
   char arr[3][5] = {"ali" , "ayai" , "afie"} ;
   searchchar_in_2darray(arr , 3 , 5 , 'i') ;
    return 0;
}*/

void matrix_is_symmetric (int(*p)[3] , int col)
{
    int i , col1 =0 , col2 = col-1 , sum1 = 0 , sum2 = 0 ;
    for(i=0 ; i < col ; ++i)
    {
       /* printf("%d  %d   %d\n" , i , col1 , p[i][col1]) ;
        printf("%d  %d   %d\n" , i , col2 , p[i][col2]) ;
        ++col1 ;
        --col2 ;*/
        sum1+= p[i][col1++] ;
        sum2 += p[i][col2--] ;

    }
    if(sum1 == sum2)
        printf("yes is syemmtric\n") ;
    else
        printf("NO NOT syemmtric\n") ;
}



