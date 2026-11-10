#include <iostream>
using namespace std;
class Queue{
public:
    int arr[100];
    int f,r,si;
     Queue(int s){
         si=s;
         r=-1;
        f=0;
     }
     void enq(int x){
         if(r+1>=si){
            deq();
         }
         else
        arr[++r]=x;

        float s=0.0;
        for(int i=f;i<=r;i++){
          s+=arr[i];
        }
        cout<<s/(r-f+1)<<endl;
     }
     void deq(){
        f++;
     }
     int peek(){
        return arr[f];
     }
     int s(){
         return r-f+1;
     }
     void dis(){
        for(int i=f;i<=r;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
};
int main() {
    Queue ob(3);
     ob.enq(1);
      ob.enq(10);
       ob.enq(3);
        ob.enq(5);
    return 0;
}

/*A1
#include <iostream>
using namespace std;
class Queue{
public:
    int arr[100];
    int f,r;
     Queue(){
         r=-1;
        f=0;
     }
     void enq(int x){
        arr[++r]=x;
     }
     void deq(){
        f++;
     }
     int peek(){
        return arr[f];
     }
     int s(){
         return r-f+1;
     }
     void dis(){
        for(int i=f;i<=r;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
};
int main() {
    Queue ob;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
       ob.enq(i);
    }
    while (ob.s() > 1) {
        // Step 1: delete first
        ob.deq();

        // Step 2: move next to rear
        int temp = ob.peek();
        ob.deq();
        ob.enq(temp);
    }
ob.dis();
    return 0;
}*/

