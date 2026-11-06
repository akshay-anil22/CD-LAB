#include <stdio.h>

#define MAX 20
#define MAX_SYMBOLS 10

int n, m;

/* epsilon transitions */
int eTrans[MAX][MAX];

/* normal transitions
   trans[symbol][from][to]
*/
int trans[MAX_SYMBOLS][MAX][MAX];

/* epsilon closure */
int closure[MAX][MAX];

int visited[MAX];


/* Find epsilon closure of a state */
void eClosure(int state)
{
    int i;

    if (visited[state])
        return;

    visited[state] = 1;

    for (i = 0; i < n; i++)
    {
        if (eTrans[state][i])
            eClosure(i);
    }
}


int main()
{
    int i, j, k, p, q;

    /* Number of states */
    printf("Enter number of states: ");
    scanf("%d", &n);

    /* Number of input symbols */
    printf("Enter number of input symbols: ");
    scanf("%d", &m);


    /* Initialize epsilon transitions */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            eTrans[i][j] = 0;


    /* Initialize normal transitions */
    for (k = 0; k < m; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                trans[k][i][j] = 0;


    /* Input epsilon transition matrix */
    printf("\nEnter epsilon transition matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &eTrans[i][j]);


    /* Input transition matrix for each symbol */
    for (k = 0; k < m; k++)
    {
        printf("\nEnter transition matrix for symbol %d:\n", k);

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &trans[k][i][j]);
    }


    /* Find epsilon closure of every state */
    printf("\nEpsilon Closures:\n");

    for (i = 0; i < n; i++)
    {
        /* Reset visited */
        for (j = 0; j < n; j++)
            visited[j] = 0;

        /* Find closure */
        eClosure(i);

        printf("E-closure(q%d) = { ", i);

        for (j = 0; j < n; j++)
        {
            closure[i][j] = visited[j];

            if (visited[j])
                printf("q%d ", j);
        }

        printf("}\n");
    }


    /* Construct NFA without epsilon */
    printf("\nNFA without epsilon transitions:\n");

    for (k = 0; k < m; k++)
    {
        printf("\nFor input symbol %d:\n", k);

        for (i = 0; i < n; i++)
        {
            int result[MAX] = {0};

            /*
              Step 1:
              Take epsilon closure of state i
            */
            for (j = 0; j < n; j++)
            {
                if (closure[i][j])
                {
                    /*
                      Step 2:
                      From every state in the closure,
                      follow the input symbol
                    */
                    for (p = 0; p < n; p++)
                    {
                        if (trans[k][j][p])
                        {
                            /*
                              Step 3:
                              Take epsilon closure
                              of the destination
                            */
                            for (q = 0; q < n; q++)
                            {
                                if (closure[p][q])
                                    result[q] = 1;
                            }
                        }
                    }
                }
            }

            printf("q%d -> { ", i);

            for (j = 0; j < n; j++)
            {
                if (result[j])
                    printf("q%d ", j);
            }

            printf("}\n");
        }
    }

    return 0;
}