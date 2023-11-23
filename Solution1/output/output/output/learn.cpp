#include <cctype>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int n, x, y;
char ss[20], ans[100], k;
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%s", &ss);
    if (isalpha(ss[0]))
    {
      k = ss[0];
      scanf("%d%d", &x, &y);
    }
    else
    {
      x = atoi(ss);
      scanf("%d", &y);
    }
    if (k == 'a')
      sprintf(ans, "%d+%d=%d", x, y, x + y);
    else if (k == 'b')
      sprintf(ans, "%d-%d=%d", x, y, x - y);
    else
      sprintf(ans, "%d*%d=%d", x, y, x * y);
    printf("%s\n%d\n", ans, strlen(ans));
  }
  return 0;
}