
#include <iostream>
using namespace std;
class Queue {
public:
    int *arr;
    int f, r, size;
    Queue(int s) {
        size = s;
        arr = new int[size];
        f = 0;
        r = -1;
    }
    void enqueue(int x) {
        if (r == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++r] = x;
    }
    void dequeue() {
        if (f > r) {
            cout << "Queue Underflow\n";
            return;
        }
        f++;
    }
    void peek() {
        if (f > r) {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[f] << endl;
    }
    void dis() {
        if (f > r) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue st(5);

    st.enqueue(10);
    st.enqueue(3);
    st.enqueue(1);
    st.dis();   // 10 3 1
    st.dequeue();
    st.dis();   // 3 1
    st.peek();  // 3

    return 0;
}


/*#include <iostream>
using namespace std;
class Stack{
public:
    int *arr;
  int top;
  Stack(){
  top=-1;
  }
   void push(int x){
       arr[++top]=x;
   }
   void pop(){
       if(top==-1) return;
      top--;
   }
   void peek(){
   cout<<arr[top]<<endl;
   }
   void dis(){
       for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
       }
       cout<<endl;
   }
};
int main() {
     Stack st;
     st.push(10);
     st.push(3);
     st.push(1);
     st.dis();
     st.peek();
     st.pop();
     st.dis();
    return 0;
}*/

