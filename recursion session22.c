
int fact_r (int n)
{
    if(n==1)
        return 1 ;
    else
        return n*fact_r(n-1) ;
}

int fabonchi (int n)
{
    int temp , i , index1 = 0 , sum = 1 ;
    if(n== 1 || n== 0)
        return n ;
    for(i= 2 ; i <=n ; ++i)
    {
        temp = sum ;
        sum += index1 ;
        index1 = temp ;
    }
    /*int n0 = 0 , n1= 1 ;  n2 , i ;
    for(i=2 ; i <= n ; ++i)
    {
        n2 = n0 + n1 ;
        n0 = n1 ;
        n1 = n2
    }*/
   return sum  ;
}
int fabonchi_r(int n)
{
    if(n== 0 || n==1)
        return n ;
    else
        return fabonchi(n-1) + fabonchi(n-2) ;
}

