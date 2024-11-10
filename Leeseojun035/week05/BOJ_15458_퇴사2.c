#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1500000
int DP[MAXSIZE] ={0,};

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int T,P;
        scanf("%d %d",&T,&P);
    if(i==0) DP[T-1] = P;

    else if(i+T-1<=n)
  {
    if(DP[i+T-1]<DP[i-1]+P)
    DP[i+T-1] = DP[i-1]+P;

  }
  if(DP[i]<DP[i-1]){
        DP[i] = DP[i-1];

  }

}
printf("%d",DP[n-1]);

    return 0;
}
