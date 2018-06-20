///ref http://www.spoj.com/problems/NAKANJ/
///knight moves using 2D grid
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cctype>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
int xMove[8] = {2, 1, -1, -2, -2, -1,  1,  2 };//knight moves index
int yMove[8] = {1, 2,  2,  1, -1, -2, -2, -1 };//knight moves index
int moves[10][10];
bool check(pii p)///check when we move is it inside the diagram or not
{
    int x = p.first;
    int y =p.second;
    if((x>=0 && x<8) && (y>=0 && y<8))
        return 1;
    else return 0;
}
int bfs(int a1,int b1,int a2,int b2){
    
    pii p1,temp;
    queue<pii>Q;
    p1.first = a1;
    p1.second = b1;
    Q.push(p1);///we can write Q.push(make_pair(a1,b1));
    memset(moves,0,sizeof(moves));///initially all moving index are zero
    while(!Q.empty())
    {
        int m,n;
        temp = Q.front();
        Q.pop();
        if(temp.first == a2 && temp.second == b2){
            return moves[a2][b2];
        }
        for(int i=0; i<8; i++)
        {
            m = temp.first + xMove[i];
            n = temp.second + yMove[i];
            if(check(make_pair(m,n))){
               moves[m][n] = moves[temp.first][temp.second] + 1;
               /**As all moves index are zero suppose i want to go index(1,2) to (3,3) then initially (1,2)= 0  
               when  child index is valid then its increase by one[(3,3) = 1] (3,3) index  is child of (1,1) index
               As i go from (1,1) to (3,3) then push this child index in queue**/
               Q.push(make_pair(m,n));
           }
           else continue;
       }
   }

}
int main()
{
    string s1,s2;
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        int x1,y1,x2,y2;
        y1 = (s1[1] - '0');
        y2 = (s2[1] - '0');
        y1--;//start from 0 to 7 so decrease this vale
        y2--;//strat from 0 to 7 so decrease this vale
        x1 = (s1[0] - 'a');///no need to decrease because maximum difference between (a-h) is 7
        x2 = (s2[0] - 'a');
        cout<<bfs(x1,y1,x2,y2)<<endl;
    }
return 0;
}
