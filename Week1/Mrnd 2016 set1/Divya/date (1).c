#include<stdio.h>
int Date(char str[10],int d,int i);
int Month(char str[10],int m,int i);
int Year(char str[10],int y,int i);
void get_date(int f);
void get_month(int k);
void get_year(int h);
void get_value(int r);
void get_value2(int j);
void main()
{
    char str[10];
    int x,y,z;
    gets(str);
    x=Date(str,x,0);
    y=Month(str,y,3);
    z=Year(str,z,6);
    printf("\n");
    get_date(x);
    get_month(y);
    get_year(z);
}
int Date(char str[10],int d,int i)
{
    d=0;
    while(str[i]!='/')
    {
        d=(d*10)+str[i]-'0';
        i++;
    }
    return d;
}
int Month(char str[10],int m,int i)
{
    m=0;
    while(str[i]!='/')
    {
        m=(m*10)+str[i]-'0';
        i++;
    }
    return m;
}
int Year(char str[10],int y,int i)
{
    y=0;
    while(str[i]!='\0')
    {
        y=(y*10)+str[i]-'0';
        i++;
    }
    return y;
}
void get_date(int f)
{
    switch(f)
    {
    case 1:
        printf("first\t");
        break;
    case 2:
        printf("second\t");
        break;
    case 3:
        printf("third\t");
        break;
    case 4:
        printf("fourth\t");
        break;
    case 5:
        printf("fifth\t");
        break;
    case 6:
        printf("sixth\t");
        break;
    case 7:
        printf("seventh\t");
        break;
    case 8:
        printf("eighth\t");
        break;
    case 9:
        printf("ninth\t");
        break;
    case 10:
        printf("tenth\t");
        break;
    case 11:
        printf("eleventh\t");
        break;
    case 12:
        printf("twelfth\t");
        break;
    case 13:
        printf("thirteenth\t");
        break;
    case 14:
        printf("fourteenth\t");
        break;
    case 15:
        printf("fifteenth\t");
        break;
    case 16:
        printf("sixteenth\t");
        break;
    case 17:
        printf("seventeenth\t");
        break;
    case 18:
        printf("eighteenth\t");
        break;
    case 19:
        printf("nineteenth\t");
        break;
    case 20:
        printf("twentieth\t");
        break;
    default:
    {
        if(f>20&&f<29)
        {
            printf("twenty");
            f=f%10;
            get_date(f);
        }
        else if(f==30)
            printf("thirtieth\t");
        else if(f==31)
            printf("fourteenth\t");
        else
            printf("wrong entry\t");
    }
    }
}
void get_year(int h)
{
    int r,s;
    r=h%100;
    h=h/100;
    if(h>0 & h<=9)
    {
get_value(h);
    }
    else if(h==10)
    {
        printf("1 thousand ");
    }
    else if(h>=11 &&h<=19)
    {
        get_value2(h);
    }
    else
    {
        printf("two thousand ");
    }
    if(r>=11&&r<=19)
    {
       get_value2(r);
    }
    else
    {
        s=r/10;
        r=r%10;
        if(s!=0)
            switch(s)
            {
            case 2:
                printf("twenty ");
                break;
            case 3:
                printf("thirty ");
                break;
            case 4:
                printf("forty ");
                break;
            case 5:
                printf("fifty ");
                break;
            case 6:
                printf("sixty ");
                break;
            case 7:
                printf("seventy ");
                break;
            case 8:
                printf("eighty ");
                break;
            case 9:
                printf("ninety ");
                break;
            default:
                printf("");
            }
        get_value(r);
    }
}
void get_value(int r)
{
    switch(r)
    {
    case 1:
        printf("one ");
        break;
    case 2:
        printf("two ");
        break;
    case 3:
        printf("three ");
        break;
    case 4:
        printf("four ");
        break;
    case 5:
        printf("five ");
        break;
    case 6:
        printf("six ");
        break;
    case 7:
        printf("seven ");
        break;
    case 8:
        printf("eight ");
        break;
    case 9:
        printf("nine ");
        break;
    default:
        printf("");
    }
}
void get_value2(int j)
{
     switch(j)
        {
        case 11:
            printf("eleven  ");
            break;
        case 12:
            printf("twelve  ");
            break;
        case 13:
            printf("thirteen  ");
            break;
        case 14:
            printf("fourteen  ");
            break;
        case 15:
            printf("fifteen  ");
            break;
        case 16:
            printf("sixteen  ");
            break;
        case 17:
            printf("seventeen  ");
            break;
        case 18:
            printf("eighteen  ");
            break;
        case 19:
            printf("nineteen  ");
            break;
        default:
            printf("");
        }
}
void get_month(int k)
{
    switch(k)
    {
    case 1:
        printf("January\t");
        break;
    case 2:
        printf("February\t");
        break;
    case 3:
        printf("March\t");
        break;
    case 4:
        printf("April\t");
        break;
    case 5:
        printf("May\t");
        break;
    case 6:
        printf("June\t");
        break;
    case 7:
        printf("July\t");
        break;
    case 8:
        printf("August\t");
        break;
    case 9:
        printf("September\t");
        break;
    case 10:
        printf("October\t");
        break;
    case 11:
        printf("November\t");
        break;
    case 12:
        printf("December\t");
        break;
    default:
        printf("wrong entry\t");
    }
}
