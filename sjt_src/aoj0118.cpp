/*
题意：就是DFS找划分区域
*/
#include <bits/stdc++.h>
using namespace std;
char g[200][200];
// row,col =y,x  
int X,Y,res;
int dx[4] = {1,-1,0,0}, dy[4] ={0,0,1,-1};

void dfs(int row,int col){
	char t = g[row][col] ; 
	g[row][col] = 'x';
	int x,y;
	for(int k=0;k<4;k++){
		x = col + dx[k];
		y = row + dy[k];
		if(x>=0&&y>=0&&x<X&&y<Y&&g[y][x]==t)
			dfs(y,x);
	}


}


int main(int argc, char const *argv[])
{	int row,col;
	while(cin >> row >>col){
		if(row==0&&col==0)break;
		X= col ,Y=row;
		memset(g,0,sizeof(g));
		res=0;
		for(int r=0;r<row;++r){
				cin >> g[r];
		}
		for(int r=0;r<row;++r){
			for(int c=0;c<col;++c){
				if(g[r][c] != 'x'){
					++res;
					dfs(r,c);
				}
			}
		}
		
		cout << res <<endl;

	}
	return 0;
}