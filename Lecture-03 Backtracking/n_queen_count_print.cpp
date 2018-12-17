#include<iostream>
using namespace std;

bool canPlace(int board[][10],int n,int x,int y){

	//Column
	for(int k=0;k<x;k++){
		if(board[k][y]==1){
			return false;
		}
	}
	//Left Diag
	int i=x,j=y;
	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;j--;
	}

	//Right Diag
	i=x,j=y;
	while(i>=0 and j<n){
		if(board[i][j]==1){
			return false;
		}
		i--; j++;
	}
	return true;
}


int NQueen(int n,int board[][10],int i){
	//Base Case
	if(i==n){
		//Print the board
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return 1;
	}
	//Rec Case
	//Try to place queen at every column/position in the current row
	int cnt = 0;
	for(int j=0;j<n;j++){
		if(canPlace(board,n,i,j)){
			board[i][j] = 1;
			int aageKaCount = NQueen(n,board,i+1);
			cnt += aageKaCount;
			board[i][j] = 0;
		}
	}
	return cnt;
}

int main(){

	int board[10][10] = {0};
	int n;
	cin>>n;

	cout<<NQueen(n,board,0);

	return 0;
}