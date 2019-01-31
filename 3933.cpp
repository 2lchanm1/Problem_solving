/*  2019.01.31
   백준 [3933번] 라그랑주의 네제곱수*/

#include<stdio.h>
#include<math.h>

long num[255];
long pow_v[256];

int max(int n)
{
  int i=0;
  while(1)
  {
    if(pow_v[i]>n) break;
    i++;
  }
  return i-1;
}

int main()
{
    //input
    int n=0;
    while(scanf("%d",&num[n])){
      if(num[n]==0) break;
      n++; //
    }
    //n==총 test case 갯수
    pow_v[0]=0;
    for(int i=1;i<=255;i++){
      pow_v[i]=i*i;
      //printf("pow_v[%d] %d\n",i,pow_v[i]);
    }



    int p=0;

    while(p<n){
      long sum=0;
      int count=0;
      int i=0,j=0,k=0,m=0;
      int pow_max=max(num[p]);

      for( i=0;i<=pow_max;i++){
        for(j=i;j<=pow_max;j++){
          for(k=j;k<=pow_max;k++){
            for(m=k;m<=pow_max;m++){
              sum=pow_v[i]+pow_v[j]+pow_v[k]+pow_v[m];
              //printf("%ld %ld %ld %ld\n",pow_v[i],pow_v[j],pow_v[k],pow_v[m]);
              //printf("sum %ld\n",sum);
              if(sum==num[p]){
                sum=0;
                //printf("%ld %ld %ld %ld\n",pow_v[i],pow_v[j],pow_v[k],pow_v[m]);
                count++;
              }
              else if(sum>num[p]){
                break;
              }
            }
          }
      }
    }
    printf("%d\n",count);
    p++;
  }
}
