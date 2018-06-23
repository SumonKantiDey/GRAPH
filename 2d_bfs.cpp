 BFS 2D grid problem
///prob https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int adj[1001][1001];
int dis[1001][1001];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int row,col,start,enda,finish1,finish2;
int r,bomb,edge,place;
bool check(pii p){///check the point is inside the board or not
   int x = p.first;
   int y = p.second;
    if((x >= 0 && x < row) && (y >= 0 && y < col))
    return 1;
    else return 0;
}
int bfs(int x,int y)
{
   pii p1,temp;
   queue<pii>Q;
   Q.push(make_pair(x,y));
   memset(dis,0,sizeof(dis));///initial distance is zero
   while(!Q.empty())
   {
       temp = Q.front();
       Q.pop();
       if(temp.first == finish1 && temp.second == finish2){
          return dis[finish1][finish2];// get the destination
       }
       for(int i=0; i<4; i++){
           int tx = temp.first + fx[i];
           int ty = temp.second + fy[i];
           if(check(make_pair(tx,ty))&& adj[tx][ty] == 0){
               adj[tx][ty] =1;//if i visit the index then filled it by one
               dis[tx][ty] = dis[temp.first][temp.second] + 1;//find the distance
               Q.push(make_pair(tx,ty));
            }
       }
   }
}

int main()
{
    while(cin>>row>>col){
    if(row == 0 && col==0){
        break;
    }
    memset(adj,0,sizeof(adj));
    cin>>edge;
    for(int i=0; i<edge; i++){
        cin>>r>>bomb;
        while(bomb--){
            cin>>place;
            adj[r][place] = 1;
        }
    }
    cin>>start>>enda;
    cin>>finish1>>finish2;
    cout<<bfs(start,enda)<<endl;
    }
  return 0;
}
