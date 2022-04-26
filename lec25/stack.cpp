#include <iostream>
using namespace std;

class Point{
    private:
        int x,y;
    public:
        Point(){x=0;y=0;}
        Point(int _x, int _y){x=_x;y=_y;}
        void show(){cout<<x<<","<<y<<endl;}
        Point operator*(const Point &p){
            Point temp(x * p.x, y * p.y);
            return temp;
        }
        void set(int _x, int _y){x=_x; y=_y;}
};
template <typename T>
class MyStack{
    private:
        int TOS;//index for the top element
        int size;
        T *data;// array in heap
    public:
        MyStack(int _size = 4){size = _size; TOS = -1; data = new T[size];};
        ~MyStack(){delete []data;};
        bool empty(){
            if(TOS==-1) return true;
            else return false;
        };
        bool full(){
            if(TOS == size-1) return true;
            else return false;
        }
        void push(const T &value){
            if(full()){
                cout<<"overflow"<<endl;
                return;
            }
            TOS++;
            data[TOS] = value;
        }
        T top(){ return data[TOS];}
        void pop(){
            if(empty()){
                cout<<"underflow"<<endl;
                return;
            }
            TOS--;
        }
};

int main(){
    MyStack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');

    cout<<s1.top()<<endl;
    
    
    MyStack<int> s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);

    cout<<s2.top()<<endl;
}




