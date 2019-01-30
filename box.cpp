/* 2019.01.29 [DAY10]
 BACKJOON 9455번
 */

#include<stdio.h>
#include<vector>

using namespace std;

int t;//tset case 갯수
int n;
int m;
vector<vector<int> >box(100,vector<int>(100,0));
vector<vector<int> >result(100,vector<int>(100,0));
int length;
vector<int> count;

int cal_len(int row,int col)
{
  int len=0;
  for(int i=row+1;i<n;i++){
    if(box[i][col]==0) len++;
    else {
      len+=result[i][col];
      break;
    }
  }
  result[row][col]=len;
  //printf("[%d %d] %d\n",row,col,len);
  return len;
}


int main()
{
  scanf("%d",&t);
  while(t--){

    length=0;
    box=vector<vector<int> >(100,vector<int>(100,0));
    result=vector<vector<int> >(100,vector<int>(100,0));

    //******input *******
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        scanf("%d",&box[i][j]);
      }
    }


    for(int i=n-1;i>=0;i--){
    for(int j=0;j<m;j++){
      if(box[i][j]==1){
         length+=cal_len(i,j);
      }
    }
    }
    count.push_back(length);
  }

  for(int i=0;i<count.size();i++){
    printf("%d\n",count[i]);
  }
}
