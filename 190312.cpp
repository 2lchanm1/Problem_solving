#include <stdio.h>
#include <vector>

using namespace std;

int h; //높이
int m; //가로
int n; //세로
vector <vector<int> >info(100,vector<int>(100));
vector <vector<int> >temp;
int count;
int dir_r[4]={0,0,-1,1};
int dir_c[4]={-1,1,0,0};

int is_changed=0;//좀비가 변화 되었는지 

bool is_finished();

void show(vector<vector<int> > arr){
   for(int i=0;i<n*h;i++){
    for(int j=0;j<m;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}


int main() {
  //input
  scanf("%d %d %d",&m,&n,&h);
  for(int i=0;i<n*h;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&info[i][j]);
    }
  }
  //show(info);
  //전염 
  int inc;
  temp=info;
  do{
   
   if(is_finished())//모두 전염 되었다면 
      break;

   temp=info;
   inc=-1;
   for(int i=0;i<n*h;i++){ 
    if(i%n==0)inc++;//현재 높이 
    for(int j=0;j<m;j++){
      if(info[i][j]==1){

        //같은 층 상하좌우
        for(int k=0;k<4;k++){
          int next_r=i+dir_r[k];
          int next_c=j+dir_c[k];
          //범위 
          if(next_r<(inc*n)||next_r>=((inc+1)*n)) continue;
          if(next_c==-1||next_c==m) continue;
          
          if(info[next_r][next_c]==0) {
            temp[next_r][next_c]=1;
            is_changed=1; //변화 되었음. 
          }
        }
        
        //다른 층 위 아래 
        if(inc-1>=0){
          //아래 
          if(info[i-n][j]==0){
            temp[i-n][j]=1;
            is_changed=1;
          }
        }

        if(inc+1<h){
          //위에
          if(info[i+n][j]==0){
            temp[i+n][j]=1;
            is_changed=1;
          }
        }
      }
    }
  }
   count++;
   info=temp; 
   //show(temp);
    
   //바뀐것이 없다면 ...종료 
    if(is_changed==0){
      count=-1;
      break;
    }
  
    is_changed=0;
  }while(1);

  printf("%d",count);
}

bool is_finished()
{
  for(int i=0;i<n*h;i++){
    for(int j=0;j<m;j++){
      if(info[i][j]==0) return 0; 
    }
  }
  return 1; //모두 전염 되었음. 
}