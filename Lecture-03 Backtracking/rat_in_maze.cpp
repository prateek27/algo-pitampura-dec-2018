#include<iostream>
using namespace std;

int ratInMaze(char maze[][10],int m,int n,int path[][10],int i,int j){
	//Base Case
	if(i==m and j==n){
		path[i][j] = 1;
		for(int x=0;x<=m;x++){
			for(int y=0;y<=n;y++){
				cout<<path[x][y]<<" ";
			}
			cout<<endl;
		}
		path[i][j] = 0;
		cout<<endl;
		return 1;
	}
	if(i>m or j>n or maze[i][j]=='X'){
		return 0;
	}
	int cnt = 0;
	//Rec Case
	path[i][j] = 1;
	cnt += ratInMaze(maze,m,n,path,i,j+1);
	cnt += ratInMaze(maze,m,n,path,i+1,j);
	//Backtracking
	path[i][j] = 0;
	return cnt;
}

int main(){

	char maze[10][10] = {
					   "000X",
					   "0X00",
					   "00X0",
					   "000X",
					   "0X00"
					  };
	int path[10][10]={0};
	int m,n;
	m = 5,n=4;

	cout<<ratInMaze(maze,m-1,n-1,path,0,0);

	return 0;
}