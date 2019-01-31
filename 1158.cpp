/*  2019.01.31
   백준 [1158번] 조세퍼스 문제 */

#include<stdio.h>
#include<vector>

using namespace std;

int n;
int m;
vector<int> num;

int main()
{
  //inout
  scanf("%d %d",&n,&m);

  //initial
  for(int i=1;i<=n;i++){
    num.push_back(i);
  }


  int start=1;
  printf("<");
  for(int i=1;i<=n;i++){
    int p=(start+m)-1;
    while(p>num.size()) p-=num.size();
    p--;
    int temp=num.at(p);
    //result.push_back(temp);
    if(i==n) printf("%d",temp);
    else printf("%d, ",temp);
    num.erase(num.begin()+p);
    start=p+1;
  }
  printf(">");


}
