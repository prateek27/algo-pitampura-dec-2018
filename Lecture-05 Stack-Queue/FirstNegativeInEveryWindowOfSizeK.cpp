#include <iostream>
#include <queue>
using namespace std;

void firstNegative(int arr[], int n, int k) {
	queue<int> qu;
	for(int i=0;i<k;i++) {
		if(arr[i]<0) {
			qu.push(i);
		}
	}
	if(not qu.empty()) {
		cout<<arr[qu.front()]<<" ";
	} else {
		cout<<"0 ";
	}
	for(int i = k; i<n;i++) {
		while((not qu.empty()) and qu.front()<=i-k) {
			qu.pop();
		}
		if(arr[i]<0) {
			qu.push(i);
		}
		if(not qu.empty()) {
			cout<<arr[qu.front()]<<" ";
		} else {
			cout<<"0 ";
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[10] = {5, 6, 3, -2, -1, 8, 7, -4, 9, -7};
	firstNegative(arr, 10, 3);
	return 0;
}
