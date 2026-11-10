//iNSERTION AT GIVEN POSITION
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int val,p;
cin>>val>>p;
for(int i=n;i>p;i--){
    arr[i]=arr[i-1];
}
arr[p]=val;
n++;
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}
//At Last
//++;
//arr[n-1]=val;
/*Deletion at given pos
cin>>p;
for(int i=p;i<n-1;i++){
    arr[i]=arr[i+1];
}
n--;*/