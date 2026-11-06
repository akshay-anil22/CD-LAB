#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define MAX_SYMBOLS 10

int visited[MAX];
int trans[MAX][MAX_SYMBOLS][MAX];
int epsilon;
int n, s;

void eClosure(int state)
{
    if (visited[state])
    {
        return;
    }

    printf("q%d ", state);
    visited[state] = 1;

    for (int i = 0; i < n; i++)
    {
        if (trans[state][epsilon][i])
        {
            eClosure(i);
        }
    }
}

void main()
{
    printf("enter no of states\n");
    scanf("%d", &n);

    printf("enter no of i/p symbols\n");
    scanf("%d", &s);

    epsilon = s - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < n; k++)
            {
                trans[i][j][k] = 0;
            }
        }
    }
    int m, from, symbol, to;
    printf("enter no of transitions\n");
    scanf("%d", &m);

    printf("enter transitions \n");

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &from, &symbol, &to);
        trans[from][symbol][to] = 1;
    }

    printf("E-closure\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[j] = 0;
        }
        printf("e-closure(q%d)-->{ ", i);
        eClosure(i);

        printf("}\n");
    }
}
