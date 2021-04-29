#include<stdio.h>

#define min(x,y) ((x) < (y) ? (x) : (y))
#define min3(a,b,c) ((a)< (b) ? min((a),(c)) : min((b),(c)))

int d_levenshtein(char* s, char* t, int n, int m)
{
    int d[n+1][m+1];

    int i;
    int j;
    int l_cost;

    for (i = 0;i <= n;i++)
    {
        d[i][0] = i;
    }
    for(j = 0; j<= m; j++)
    {
        d[0][j] = j;
    }
    for (i = 1;i <= n;i++)
    {
        for(j = 1; j<= m; j++)
        {
            if( s[i-1] == t[j-1] )
            {
                l_cost = 0;
            }
            else
            {
                l_cost = 1;
            }
            d[i][j] = min3(
            d[i-1][j] + 1,                  // delete
            d[i][j-1] + 1,         // insert
            d[i-1][j-1] + l_cost           // substitution
            );
            if( (i > 1) && 
                (j > 1) &&  
                (s[i-1] == t[j-2]) && 
                (s[i-2] == t[j-1])
            ) 
            {
                d[i][j] = min(
                d[i][j],
                d[i-2][j-2] + l_cost   // transposition
                );
            }
        }
    }
    return d[n][m];
}