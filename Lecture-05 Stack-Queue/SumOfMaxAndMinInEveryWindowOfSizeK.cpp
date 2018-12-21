#include <iostream>
#include <queue>
using namespace std;
int sumOfMinMaxInWindow(int arr[] , int n , int k) 
{ 
    int sum = 0; 
    deque<int> small, big; 
    
    for (int i = 0; i < k; i++) 
    { 
        while ( (!small.empty()) && arr[small.back()] >= arr[i]) 
            small.pop_back(); 
        while ( (!big.empty()) && arr[big.back()] <= arr[i]) 
            big.pop_back(); 
        big.push_back(i); 
        small.push_back(i); 
    } 
 
    for (int i=k;i < n; i++) 
    { 
    	cout<<arr[small.front()]<<" "<<arr[big.front()]<<endl;
        sum += arr[small.front()] + arr[big.front()]; 
        while ( !small.empty() && small.front() <= i - k) 
            small.pop_front(); 
        while ( !big.empty() && big.front() <= i - k) 
            big.pop_front();  
        while ( (!small.empty()) && arr[small.back()] >= arr[i]) 
            small.pop_back(); 
        while ( (!big.empty()) && arr[big.back()] <= arr[i]) 
            big.pop_back(); 
        big.push_back(i); 
        small.push_back(i); 
    } 
    sum += arr[small.front()] + arr[big.front()]; 
    return sum; 
} 
int main(int argc, char const *argv[])
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ; 
    int n = 7; 
    int k = 4; 
    cout << sumOfMinMaxInWindow(arr, n, k) ; 
    return 0; 	
}
