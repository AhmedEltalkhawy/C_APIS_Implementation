
int mergearray (int* arr1 , int size1 , int* arr2 , int size2 , int* arr3 , int size3)
{
    int size , index1=0 , index2=0 , res= 0 ;
    size = size1 + size2 -1 ;
    if(size > size3)
        size = size3 ;
    while(index1 <size1 && index2 <size2 && res<size)
    {
        if(index1==index2)
            arr3[res++]= arr1[index1++] ;
        else
            arr3[res++] =arr2[index2++] ;
    }
    while(index1 <size1 && res < size)
        arr3[res++] = arr1[index1++] ;
    while(index2 <size2 && res < size)
        arr3[res++] = arr2[index2++] ;
    return size ;
}

int another_mergearray (int* arr1 , int size1 , int* arr2 , int size2 , int* arr3 , int size3)
{
    //only for equal size
    int size = size1 + size2 -1 , i ,j = 0;
    if(size > size3)
        size = size3 ;
    for(i=0 ; i <size ; ++i)
    {
        arr3[i] = arr1[j] ;
        arr3[++i] =arr2[j++] ;
    }
    return size ;
}
void printarray (int *arr , int size)
{
    int i ;
    for (i=0 ; i <size ; ++i)
    {
        printf("%d ",arr[i]) ;
    }
    printf("\n") ;

}
int array_scan (int * arr , int size )
{
    int no_element , testsize ,i ;
    printf("enter the number of element smaller than  %d\n" , size) ;
    scanf("%d",&no_element) ;
    testsize = no_element ;
    printf("enter the sorted element of array\n") ;
    if(no_element > size)
    {
        testsize = size ;
    }
    for(i=0 ; i < testsize ;++i)
    {
        scanf("%d",&arr[i]) ;
    }
    return i ;
}
void cir_shift_array (int* arr , int size)
{
    int i = size-1 , temp = arr[i] ;
    for(i = size -1 ; i>0 ; --i)
    {
        arr[i] = arr[i-1] ;
    }
    arr[0] = temp ;
}
void cir_shift_array_no (int* arr , int size , int no)
{
    int i ;
    for(i=0; i< no ; ++i)
        cir_shift_array(arr , size) ;
}
void better_cir_shift_array_no (int* arr , int size , int no)
{
    int arr1[1000] , i , j=0 , temp =no ;
    for(i=size-1 ; temp >0 ; --i , --temp)
    {
        arr1[j++] = arr[i] ;
    }
    for(i=size-1 ; i > 0 ; ++i)
    {
        arr[i] = arr[i-1] ;
    }

}

/* Application to 2 pointer tech */
int FindMaxConsecutiveValues (int * arr , int size ,int m)
{
    int p1 = 0 , p2 = m - 1 ;
    int last_sum = 0 , max_sum = 0 , current_sum = 0  ;
    int flag = 1 ;
    while (p2 < size )
    {
        if(flag == 1)
        {
            int i ;
            for( i=0 ; i < m ; ++i )
            {
                current_sum += arr[i] ;
            }
            last_sum = current_sum ;
            max_sum  = current_sum ;
            flag = 0 ;
        }
        else
        {

            current_sum = last_sum - arr[p1-1] + arr[p2] ;
            if(current_sum > max_sum)
            {
                max_sum = current_sum ;
            }
            last_sum = current_sum ;
        }
        ++p2 ;
        ++p1 ;
    }
    return max_sum ;
}
/* Example in 2 pointer tech slides mostafa saad */
int FindMaxContigiousSumSubArray (int* arr , int size , int max_sum)
{
    int p1 = 0 , p2 = 0 ;
    int current_sum = 0 , max = 0 ;
    while(p1 < size)
    {
        while ( (p2 < size ) && (current_sum + arr[p2]) <= max_sum )
        {
            current_sum += arr[p2++] ;
        }
        if(max < current_sum)
        {
            max = current_sum ;
        }
        current_sum-=arr[p1++] ;
    }
    return max ;

}
/*cumulative sum problem mostafa saad*/
int SumRange (int start , int end , int * arr )
{
    if(start==0)
    {
        return arr[end] ;
    }
    return arr[end] - arr[start -1] ;
}
void ZeroBased ( int* sumarr , int* arr , int size)
{
    int i ;
    for (i=0 ; i < size ; ++i)
    {
        sumarr[i] = (i==0) ? arr[i] : arr[i] +sumarr[i-1] ;
    }

}
/******************************************************/
/****************session14***************************/
int most_repeated_sorted_array (int* arr, int size)
{
    int i, max = 0, count=1, element ;
    for(i=0 ; i < size -1 ; ++i)
    {
        //size-1 عشان ميخرجش في المقارنة برا array
        if(arr[i] == arr[i+1])
        {
            count++ ;
            if(max < count)
            {
                max = count ;
                element = arr[i] ;
            }
        }
        else
        {
            count = 1 ;
        }


    }
    return element ;

}
int most_repeated_mono_array(int* arr , int size)
{
    // is optimized algorithm O(n) without 2 for loop inside O(n^2)
    int count[10] = {0} , i , max = 0 , element  ;
    //intiliize it to zero to avoid sum to garbge
    //don’t make array static becuase if next call sum old value
    for(i=0 ; i < size ; ++i)
    {
        count[arr[i]]++ ;
    }
    for(i=0 ; i < 10 ; ++i)
    {
        if(count[i] > max)
        {
            max = count[i] ;
            element = i ;
        }

    }
    return element ;

}
int most_repeatednum_by_min_max_element(int* arr , int size)
{
    int i , max= 0 , min=arr[0] , arrsize , max_count =0 , element ;
    for(i=0 ; i< size ; ++i)
    {
        if(max < arr[i])
        {
            max = arr[i] ;
        }
        if(min > arr[i])
        {
            min = arr[i] ;
        }
    }
    arrsize = max - min ;
    int* parr = (int*) calloc(arrsize+1 , sizeof(int)) ;
    for(i= 0 ; i < size ; ++i)
    {
        parr[arr[i] - min] ++ ;
    }
    for(i=0 ; i <= arrsize ; ++i)
    {
        if(parr[i] > max_count)
        {
            max_count = parr[i] ;
            element = i + min ;

        }

    }
    printf("%d\n" , max_count) ;
    return element ;
}
/*************************************************************************************/
// task1 in sheet 5
// try to  make it in O(n)
int except_number_in_array (int* arr , int size)
{
    int frequencyarray[11] = {0} , i ;
    for(i=0 ; i < size ; ++i)
    {
        frequencyarray[arr[i]] ++ ;
    }
    for(i=0 ; i < 11 ; ++i)
    {
        if(frequencyarray[i] ==0)
            return i ;
    }
}

/*int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10} ;
    int size = sizeof(arr) / sizeof(arr[0]) ;
    printf("%d" , except_number_in_array(arr , size)) ;


    return 0 ;
}*/
// task2 in sheet 5
// try to  make it in O(n)

int except_repeated_number_in_array (int* arr , int size)
{
    int frequencyarray[11] = {0} , i ;
    for(i=0 ; i < size ; ++i)
    {
        frequencyarray[arr[i]] ++ ;
    }
    for(i=0 ; i < 11 ; ++i)
    {
        if(frequencyarray[i] ==2)
            return i ;
    }
}


int only_one_repeated_num (int* arr, int size)
{
// task 3 in sheet 5
    int i, max = 0, min = arr[0] ;
    for(i=0 ; i < size ; ++i)
    {
        if(max < arr[i])
            max = arr[i] ;
        if(min > arr[i])
            min = arr[i] ;
    }
    int arraysize = max - min ;
    int* frequencyarray = (int*)calloc(arraysize, sizeof(int)) ;
    if(frequencyarray != (void*)(0))
    {
        for(i =0 ; i < size ; ++i)
        {
            frequencyarray[arr[i]-min] ++ ;
        }
        for(i=0 ; i < arraysize ; ++i )
        {
            if(frequencyarray[i] == 1)
            {
                free(frequencyarray) ;
                break ;
            }

        }

    }
    else
    {
        printf("null pointer") ;
    }
    return i+1 ;

}
// task 8 in sheet 3
int* returnacopyofarray_until_given_number(int* arr , int size , int givennum , int*newsize)
{
    int i , j ;
    static int newarr[100] ;
    for(i=0 ; i < size ; ++i)
    {
        if(arr[i]== givennum)
        {
            break ;
        }
    }
    *newsize = i ;
    for(j= 0 ; j <i ; ++j)
    {
        newarr[j] = arr[j] ;
    }
    return newarr ;
}

