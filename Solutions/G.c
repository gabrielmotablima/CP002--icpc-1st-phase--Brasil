#include <stdio.h>
int cost[100];

int main()
{
    int n, a, ant = 0, flag = -1001;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        cost[i] = a + ant;
        ant += a;
    }

    for(int j = 0; j < n; j++)
    {
        if(cost[j] > flag)
            flag = cost[j];
    }

    if(flag > 0)
        printf("%d", 100+flag);
    else
        printf("100");

    return 0;
}