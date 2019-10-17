/*
name:Red and Black
思路：上下左右dfs，注意每一轮x,y不能变，走过的就标记为#，不再走

*/
#include <iostream>
#include <cstring>
using namespace std;
char g[25][25];
int res,X,Y;
int dx[4] = {0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y){
	if(g[y][x]=='#'|| x<1||x>X||y<1||y>Y)return;
	res++;
	g[y][x] = '#';
	int xx,yy;
	for(int k=0;k<4;k++){
		xx=x+dx[k];
		yy=y+dy[k];
		dfs(xx,yy);
	}
	/*dfs(x,y+1);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x-1,y);*/
	
}

int main(int argc, char const *argv[])
{	int x,y,man_x,man_y;//6,9;i==y,j==x,g[i][j]=g[y][x]
	while(cin>>x>>y){
		if(x==0&&y==0)break;
		X=x,Y=y;
		memset(g,0,sizeof(g));
		for(int i=1;i<=y;i++)
			for(int j=1;j<=x;j++){
				cin >> g[i][j];
				if(g[i][j]=='@'){
					//g[i][j]=='.';
					man_x=j;man_y=i;
				}

			}
	res=0;
	//cout <<man_x<<man_y<<endl;
	dfs(man_x,man_y);
	cout <<res<<endl;

	}
	return 0;
			
}
