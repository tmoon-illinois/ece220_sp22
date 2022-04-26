#include <iostream>

template <typename T>
T Mul(T a, T b){
    return a*b;
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

    p1.ShowPosition();
    p2.ShowPosition();

    Point p3;
    p3 = Mul(p1, p2);// return p1*p2; --> return p1.operator*(p2);
    p3.ShowPosition();
}
