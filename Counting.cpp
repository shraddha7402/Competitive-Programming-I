
#include <cstring>
#include <cstdio>
int dp[1001][111];
int main()
{
memset(dp, 0, sizeof(dp));
dp[1][0] = 2;dp[2][0] = 5;dp[3][0] = 13;
for (int i = 4; i < 1001; ++ i) {
for (int j = 0; j < 110; ++ j)
dp[i][j] = dp[i-1][j]+dp[i-1][j]+dp[i-2][j]+dp[i-3][j];
for (int j = 0; j < 110; ++ j)
if (dp[i][j] > 9999) {
dp[i][j+1] += dp[i][j]/10000;
dp[i][j+0] %= 10000;
}
}
int n, end;
while (~scanf("%d",&n)) {
end = 110;
while (!dp[n][end] && end) -- end;
printf("%d",dp[n][end --]);
while (end >= 0)
printf("%04d",dp[n][end --]);
puts("");
}
return 0;
}
