#include <stdio.h>


int grid[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

char valid = 'Y';

int main()
{
    int n, i, j;
    int d, l, r, c;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &d, &l, &r, &c);
        if(d == 0)
        {
            if((l+c-1) < 11)
            {
                for(j = 0; j < l; j++)
                {
                    if(grid[r-1][c+j-1] == 0) grid[r-1][c+j-1] = 1;
                    else valid = 'N';
                }
            }
            else valid = 'N'; 
        }
        else{
            if((l+r-1) < 11)
            {
                for(j = 0; j < l; j++)
                {
                    if(grid[r+j-1][c-1] == 0) grid[r+j-1][c-1] = 1;
                    else valid = 'N';
                }
            }
            else valid = 'N';
        }
    }

    printf("%c\n", valid);

    return 0;
}