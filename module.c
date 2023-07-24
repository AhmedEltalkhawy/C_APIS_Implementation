/*************session12***********************/

int max_f (void) ;
int min_f (void) ;
void takenumber(int x ) ;
int globalvar ;
int max_global ;
int min_global ;
void takenumber(int x )
{
// take number here is setter
    globalvar = x  ;
    max_f() ;
    min_f() ;

}
int max_f (void)
{
    static max = 0 ;
    if(max <globalvar)
        max = globalvar ;
    return max ;
}
int min_f (void)
{
    static int min  ;
    static flag = 0 ;
    if (flag == 0)
    {
        min = globalvar ;
        flag = 1 ;
    }
    if (min > globalvar )
          min = globalvar ;
    return min ;
}
int ret_most_arguement (int y)
{

    static int most  ;
    static int flag = 0 ;
    if(flag == 0)
    {
        most = y ;
        flag=1 ;
    }
    else
    {
        if (most < y)
            most = y ;
    }


    return most ;
}
/****


int remove_repeated(int* arr, int size)
{
    int i, j, k, counter = size ;
    for(i=0 ; i< size ; ++i)
    {
        for(j=i+1 ; j < size ; ++j)
        {
            if(arr[i] == arr[j])
            {
                --counter ;
                for(k= j ; k < size - 1  ; ++k)
                {
                    arr[k] = arr[k+1] ;
                }
            }
        }
    }
    printf("counter %d\n",counter) ;
    return counter ;

}*/
/**********************************************************/
