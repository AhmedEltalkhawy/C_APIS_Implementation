void selectionsort(int* arr , int size)
{
    int i , j  , max  , temp ,last_i = size-1 ; ;
    for(i=0 ; i < size ; ++i)
    {
        max = 0 ;
        for(j=0 ; j < size -i ; ++j )
        {
            if(arr[max]< arr[j])
            {
                max = j ;
            }
        }
       /* temp = arr[max] ;
        arr[max] = arr[size-1-i] ;
        arr[size-i-1] = temp ;*/
        //or
        if(max!= last_i) // if max element is exist in last place i do not need to swap it
        {
            temp = arr[max] ;
            arr[max] = arr[last_i] ;
            arr[last_i] = temp ;
        }
        --last_i ;

    }

}
void selectionsortfrombiggertolower(int* arr , int size)
{
    int i , j  , min  , temp ;
    for(i=0 ; i < size ; ++i)
    {
        min = 0 ;
        for(j=0 ; j < size -i ; ++j )
        {
            if(arr[min]> arr[j])
            {
                min = j ;
            }
        }
        temp = arr[min] ;
        arr[min] = arr[size-1-i] ;
        arr[size-i-1] = temp ;

    }

}

void bubblesort (int*arr , int size)
{
    int i , j , temp , flag = 1 , count= 0 ;
    for(i=0 ; (i < size) && (flag == 1) ; ++i)
    {
        flag=0 ;
        for(j=0 ; j < size - i - 1  ; ++j )
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
                flag = 1 ; // if any swap does not occauar mean that array is sorted so terminate main loop
            }
         ++count ; // to calcualte  the no of iteration or can multiply i * j

        }
        /*if(flag==0)
            break ;*/

    }
    printf("%d\n" , count) ;
}

void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}
int Binary_Search (int*arr , int size , int element)
{
    int first , last , middle ;
    first = 0 ;
    last = size - 1 ;
    while(first <=last)
    {
        middle = (first+last) / 2 ;
        if(arr[middle] == element)
            return middle ;
        else if (arr[middle] > element)
        {
            last=middle -1 ;
        }
        else
        {
            first = middle + 1 ;

        }


    }
    return -1 ;
}
void counting_sort (int* arr, int size)
{
    // O(n+k) but take a space O(k)
    int i, j,  max = arr[0], min = arr[0], count_size, *count  ;
    for(i=0 ; i < size ; ++i)
    {
        if(max < arr[i])
            max = arr[i] ;
        if(min > arr[i])
            min = arr[i] ;
    }
    count_size = max - min + 1;
    count = calloc(count_size, sizeof(int)) ;
    if(count)
    {
        for(i=0 ; i < size ; ++i)
        {
            count[arr[i]-min]++ ;
        }
        i= 0 ;
        for(j=0 ; j < count_size ; ++j )
        {
            while(count[j])
            {
               arr[i++] = j + min ;
                --count[j] ;
            }
        }

    }
    else
    {
        // call another sort techinque
    }


}
