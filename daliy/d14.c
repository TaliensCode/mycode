/* 20:30 2015-03-23 Monday */
#include <stdio.h>
int main()
{
    int n = 0,c = 0;
    int i = 0;
    long int tn = 0,sn = 0;

    printf("Input n and c:");
    scanf("%d%d",&n,&c);

    i = 1;
    while ( i <= c ) 
    {
        tn = tn + n;
        sn = sn + tn;
        n = n * 10;
        ++i;
    }
    printf("a + aa + ...=%ld\n",sn);

    return 0;
}
