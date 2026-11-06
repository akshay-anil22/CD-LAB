#include <stdio.h>

#define MAX 10

int main()
{
  int n, m;
  int trans[MAX][MAX];
  int final[MAX];
  int mark[MAX][MAX] = {0};

  printf("Enter number of states: ");
  scanf("%d", &n);

  printf("Enter number of input symbols: ");
  scanf("%d", &m);

  printf("Enter DFA transition table:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      scanf("%d", &trans[i][j]);
  }

  printf("Enter final states (1 = Final, 0 = Non-final):\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &final[i]);

  // Mark pairs where one is final and the other is non-final
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (final[i] != final[j])
        mark[i][j] = 1;
    }
  }

  // Mark distinguishable pairs
  int changed;

  do
  {
    changed = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (mark[i][j])
          continue;

        for (int k = 0; k < m; k++)
        {
          int p = trans[i][k];
          int q = trans[j][k];

          if (p == q)
            continue;

          int x = p < q ? p : q;
          int y = p < q ? q : p;

          if (mark[x][y])
          {
            mark[i][j] = 1;
            changed = 1;
            break;
          }
        }
      }
    }

  } while (changed);

  printf("\nEquivalent States:\n");

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (mark[i][j] == 0)
        printf("q%d and q%d\n", i, j);
    }
  }

  printf("\nMinimized DFA Groups:\n");

  int visited[MAX] = {0};

  for (int i = 0; i < n; i++)
  {
    if (visited[i])
      continue;

    printf("{ q%d ", i);
    visited[i] = 1;

    for (int j = i + 1; j < n; j++)
    {
      if (mark[i][j] == 0)
      {
        printf("q%d ", j);
        visited[j] = 1;
      }
    }

    printf("}\n");
  }

  return 0;
}