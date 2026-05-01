#include<iostream>
using namespace std;
long long factiorel (int );
int main (){
int n ; 
cin>>n ;
cout<<factiorel(n);
}
long long factiorel (int n){
if (n == 0 )
    return 1;
return n *factiorel(n-1);
}