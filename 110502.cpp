/* 2019.01.31
백준 [110502번]  카드 구매하기
*/
#include<stdio.h>

int n;//카드 갯수
int pack[1001];
int most_price[1001];

int cal_most(int num)
{
  if(most_price[num]!=0) return most_price[num];
  if(num==1) {
    most_price[num]=pack[num];
  }
  else{
    int most=pack[num];
    int i=1;
    while(i<num){
      if(most<cal_most(i)+pack[num-i]){
        most=cal_most(i)+pack[num-i];
      }
      i++;
    }
    most_price[num]=most;
  }
  return most_price[num];
}

int main()
{
  int result;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&pack[i]);
  }
  result=cal_most(n);
  printf("%d",result);
}
