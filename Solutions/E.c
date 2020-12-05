#include <stdio.h>

typedef struct list
{
    int yo, pos;
    struct *next;
} List;

List *run(List *list)
{
    List *tmp = list;
    while(tmp->next != NULL)
        tmp = tmp->next;
    return tmp;

}
void zerofy()
{
    tester = (int*)realloc(tester, N);
    for(int i = 0; i < N; i++)
        tester[i] = 0;
}

void count_parties_sup(int s)
{
    List *tmp = list[s-1]->next;
    tester[s-1] = 1;

    while(tmp != NULL)
    {
        tester[tmp->pos - 1] = 1;
        tmp = tmp->next;
    }
}

void count_parties_inf()
{
    List *tmp = list[i-1]->next;
    tester[s-1] = 1;

    while(tmp != NULL)
    {
        tester[tmp->pos - 1] = 1;
        tmp = tmp->next;
    }    
}

int N, M;
int yo, superior;
int inf, sup;
List *list;
int *freq, *tester;
int count;

int main()
{
    scanf("%d %d", &N, &M);

    list = (List*)calloc(N, sizeof(List));
    freq = (int*)calloc(N, sizeof(int));
    tester = (int*)calloc(N, sizeof(int));

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &yo, &superior);
        List *tmp = run(list[superior-1]);
        tmp->next = (List*)calloc(1, sizeof(List));
        tmp->next->yo = yo;
        tmp->next->pos = i+1;
    }

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &superior, &inf, &sup);
        zerofy();
        count_parties(superior);
        
    }

    return 0;
}