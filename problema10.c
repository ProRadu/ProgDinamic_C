#include<stdio.h>
#include<stdlib.h>

int minim(int a, int b)
{
    if(a<b)
        return a;
    else return b;
}

int main()
{
    int n, i, j, k, t[20][20], smin[20][20];
    FILE *f=fopen("date.in","r");
    fscanf(f, "%d", &n);
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
            fscanf(f,"%d", &t[i][j]);
    fclose(f);
    for(i=0;i<n;i++)
        smin[i][i]=t[i][i];
    for(k=1;k<n;k++)
    {
        i=k;
        j=0;
        while(i<n)
        {
            smin[i][j] = t[i][j] + minim(smin[i-1][j], smin[i][j+1]);
            i++;
            j++;
        }
    }
    FILE *g=fopen("date.out","w");
    fprintf(g,"Numarul minim de pere este %d\n", smin[n-1][0]);
    fprintf(g,"Traseul cu numarul minim de pere este:\n");
    j=0;
    i=n-1;
    while(i!=j)
    {
        fprintf(g,"t[%d][%d] -> ", i, j);
        if(smin[i-1][j] > smin[i][j+1])
            j++;
        else i--;
    }
    fprintf(g,"t[%d][%d]\n", i, j);
    fclose(g);
    return 0;
}
