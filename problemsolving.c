
/* this function to find intersection intervals between  2 intervals*/

int FindIntersectionInterval(int* start , int* end)
{
    int n1 , n2 , n3 , n4 ;
    scanf("%d %d %d %d" , &n1 , &n2 , &n3 , &n4) ;
    if(((n1 > n3)&& (n1> n4))|| ((n3 > n2) && (n4 >n2)))
    {
        return -1 ;
    }
}
