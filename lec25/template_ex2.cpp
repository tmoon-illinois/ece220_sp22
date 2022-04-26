#include <iostream>

template <typename T>
T Mul(T a, T b){
    return a*b;
}

template <typename T>
void myswap(T &a, T &b){
    T temp;
    temp = a;// temp.operator=(a);
    a = b;// a.operator=(b);
    b = temp;
}

using namespace std;
class Point{
    private:
        int x,y;
    public:
        Point(int _x = 0, int _y = 0){ x = _x; y = _y;}
        void ShowPosition() const {cout<<x<<", "<<y<<endl;}
        Point operator*(Point &p){
            Point temp(x*p.x, y*p.y);
            return temp;
        }
};


int main(){
    Point p1(1,2), p2(2,3);

    myswap(p1, p2);
    p1.ShowPosition();
    p2.ShowPosition();

    int a = 2, b = 10;
    myswap(a,b);
    cout<<a<<","<<b<<endl;

}
