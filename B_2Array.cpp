#include <iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  for(int i=0;i<n;i++){
      for(int j=0;j<n-1;j++){
          if(arr[j+1]<arr[j]){
              int t=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=t;
          }
      }
  }int c=0;
  for(int i=0;i<n-1;i++){
      c++;
      if(arr[i]!=arr[i+1]){
          cout<<arr[i]<<"Count="<<c;
          c=0;
           continue;
      }

  }
    return 0;
}
//Task_A2
/*#include <iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
 for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i]==arr[j]){
            for(int k=j;k<n-1;k++){
                arr[k]=arr[k+1];
            }
            n--;
        }
    }

 }
 for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }
    return 0;
}*/
