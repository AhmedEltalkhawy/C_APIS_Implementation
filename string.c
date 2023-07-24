#include <stdio.h>
void print_string (char* arr)
{
    int i ;
    for(i=0 ; arr[i] ; ++i)
    {
        printf("%c", arr[i]) ;
    }
    puts("") ;
}

int stringlen (char* str)
{
    int i ;
    for(i=0 ; str[i] != '\0' ; ++i) ;
    return i ;
}
void reverse_string(char* str)
{
    int i = strlen(str) , j ;
    char temp ;
    for(j=0 ; j < (i/2) ; ++j)
    {
        temp = str[i-j-1] ;
        str[i-j-1] = str[j] ;
        str[j] = temp ;
    }
}


int stringcompare (char* str1, char* str2)
{
    int i ;
    if(stringlen(str1)!= stringlen(str2))
        return 0 ;
    for(i=0 ; str1[i] ; ++i)
    {
        if (str1[i] != str2[i])
            return 0 ;
    }
    return 1 ;
}
int faster_stringcompare (char* str1, char* str2)
{
    int i ;
    //it can be && but we need to do the checking after the loop
    for(i=0 ; str1[i] || str2[i] ; ++i)
    {
        if (str1[i] != str2[i])
            return 0 ;
    }
    return 1 ;
}
void string_Upper_to_Lower(char* str)
{
    int i ;
    for(i=0 ; str[i] != 0 ; ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A') ;
    }
}
void stringcancotante (char* str1,char* str2, char* out, int maxsize)
{
    int index1 = 0, index2 = 0, res= 0 ;
    int size = stringlen(str1) +stringlen(str2) ;
    if(size>maxsize)
        size = maxsize ;
    while(str1[index1] &&(res <size))
        out[res++] = str1[index1++] ;
    while(str2[index2] &&(res <size))
        out[res++] = str2[index2++] ;
    out[res] = 0 ;
}

void string_scan(char* str, int maxsize)
{
    int i = 0 ;
    do
    {
        scanf("%c",&str[i]) ;
    }
    while(str[i++] != '\n' &&  i < maxsize) ;
    str[i-1] = 0 ;
}
void better_string_scan(char* str)
{
    int i = 0 ;
    fflush(stdin) ;
    scanf("%c",&str[i]) ;
    while(str[i] != '\n')
    {
        scanf("%c",&str[++i]) ;
    }
    str[i] = 0 ;

}

void Float_To_String(char* str, float fnum)
{
    int inum = (int)fnum, i = 0, icounter =-1, fcounter = -1,itemp, inum2,itemp2  ;
    float frac = fnum - inum, ftemp ;
    ftemp = frac ;
    itemp = inum ;
    char reminder, freminder ;
    while(itemp>0)
    {
        ++icounter ;
        itemp /= 10 ;
    }
    i = icounter+1 ;
    while(icounter>=0)
    {
        reminder = inum %10 ;
        str[icounter] = (reminder + '0') ;
        inum /= 10 ;
        --icounter ;
    }
    str[i++] = '.' ;
    while(0 != ftemp)
    {
        frac = (frac*10) ;
        inum2 =(int) frac ;
        ftemp = frac -inum2 ;
    }
    itemp2 = inum2 ;
    while(itemp2>0)
    {
        ++fcounter ;
        itemp2 /= 10 ;
    }
    while(fcounter>=0)
    {
        freminder = inum2 %10 ;
        str[i+fcounter] = freminder + '0' ;
        inum2 /= 10 ;
        --fcounter ;
    }
    str[++i] = 0 ;

}
/*********session10*****************/
void Int_To_String(char* str, int num)
{
    int inum = num, i = 0,  icounter =-1,itemp ;
    itemp = inum ;
    char reminder ;
    if(itemp== 0)
        ++icounter ;
    while(itemp>0)
    {
        ++icounter ;
        itemp /= 10 ;
    }

    i = icounter+1 ;
    while(icounter>=0)
    {
        reminder = inum %10 ;
        str[icounter] = (reminder + '0') ;
        inum /= 10 ;
        --icounter ;
    }
    str[i] = '\0' ;
}

void another_Int_To_String (char* str, int num)
{
    int i =0, j, temp, flag = 1 ;
    if(num==0)
    {
        str[i] = '0' ;
        str[++i] = '\0' ;
    }
    else
    {
        if (num < 0 )
        {
            str[i++] = '-' ;
            num *= -1 ;
            flag = 0 ;
        }
        for(  ; num > 0 ; ++i)
        {
            str[i] = (num%10) + '0' ;
            num /= 10 ;
        }
        if(flag)
        {
            for( j= 0; j < (i/2) ; ++j)
            {
                temp = str[i-j-1] ;
                str[i-j-1] = str[j] ;
                str[j] = temp ;
            }
        }
        else
        {
            for( j= 1; j <= (i/2)  ; ++j)
            {
                temp = str[i-j] ;
                str[i-j] = str[j] ;
                str[j] = temp ;
            }
        }


        str[i] = 0 ;

    }
}
int String_To_Int (char* str )
{
    int i , num = 0 ;
    for (i=0 ; str[i] ; ++i)
    {
        num = num*10 + (str[i] - '0') ;
    }
    return num ;
}
void Take_String_print_n_times (char* str, char sperator)
{
    //task 7 in sheet 4
    // this function take a string and print first word n time according to the number in str and do also in second word
    int i, j, counter;
    char first_str [15], second_str [15], first_num =0, second_num =0 ;
    for(i=0 ; str[i] != sperator ; ++i)
    {
        first_str[i] = str[i] ;
    }
    first_str[i++] = 0 ;
    first_num = str[i++] - '0' ;
    ++i ;
    for(j=0 ; str[i] != sperator ; ++i, ++j)
    {
        second_str[j] = str[i] ;
    }
    second_str[j] = 0 ;
    second_num = (str[++i] - '0') ;
    for(counter = 0 ;  counter < first_num ; ++counter)
        print_string(first_str) ;
    for(counter = 0 ;  counter < second_num ; ++counter)
        print_string(second_str) ;

}
int frame (char* str , char*s1 , char* s2 , int* pn1 , int* pn2)
{
    //this function take frame in task 4 sheet 7 and separte it
    int i , j = 0, k = 0 , flag = 0 ;
    *pn1= 0 , *pn2 = 0 ;
    for (i=0 ; str[i] ; ++i)
    {
        if(str[i] == ',')
        {
            ++flag ;
        }
        else
        {
            if (flag==0)
            {
                s1[k++] = str[i] ;
            }
            else if (flag==1)
            {
                // if he enter char neglect
                if(str[i] >= '0' && str[i] <= '9')
                    *pn1 = *pn1*10 + (str[i]-'0') ;
            }
            if (flag==2)
            {
                s2[j++] = str[i] ;
            }
            else if (flag==3)
            {
                if(str[i] >= '0' && str[i] <= '9')
                    *pn2 = *pn2*10 + (str[i]-'0') ;
            }

        }

    }
    s1[k] = 0 ;
    s2[j] = 0 ;
    //if he dont sent 3 ,
    if (flag != 3)
        return 0 ;
    return 1 ;

}
/***************inmain****************/
/*
char str [] = "ahmed,5,mohamed,1a0" ;
   int n1 , n2 ;
   char s1[10] , s2[10] ;
   frame(str,s1 ,s2 ,&n1,&n2) ;
   printf("%s     %d     %s  %d " , s1 , n1 , s2 , n2) ;
*/
/**********************session14*************************/
char most_repeated_char(char* str)
{
    int count[256] ={0} ; // frequency array
    int i , max = 0 ;
    char ch ;
    for(i=0 ; str[i] ; ++i)
    {
        count[str[i]] ++ ;
    }
    for(i= 0 ; i < 256 ; ++i)
    {
        if(count[i] > max )
        {
            max = count[i] ;
            ch = i ;
        }
    }
    return ch ;
}

char first_repeated_char (char* str)
{
    int frequencyarray[256] ={0} , i ;
    for(i=0 ; str[i] ; ++i)
    {
        frequencyarray[str[i]]++ ;
        if(frequencyarray[str[i]] == 2)
        {
            return str[i] ;

        }
    }

}
char* stringcopy_noduplicateelement(char* str)
{
    static char copystr [50] ;
    int frequncyarray[256] ={0} , i , j=0 ;
    for(i=0 ; str[i] ; ++i)
    {
        if(frequncyarray[str[i]]== 0)
        {
            copystr[j++] = str[i] ;
            frequncyarray[str[i]] ++ ;
        }
    }
    return copystr ;
}





