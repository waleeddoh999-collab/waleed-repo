#include<iostream>
using namespace std;
long long Max_Number (long long [],int ,int =0);
int main (){
int n ; 
cin>>n ;
long long array[n];
for (int i = 0 ; i < n ; i++)
    cin>>array[i];

cout<<Max_Number(array, n);
}
long long Max_Number (long long arr[],int s , int i){
if (i == s-1)
    return arr[i];
    long long next = Max_Number(arr, s, i+1);
return (arr[i] > next) ? arr[i] : next;
}