#include <iostream>

using namespace std;

class Nums{
    private:
        int a, b, c;

    public:
        int d, e;
        void setInt(int a, int b, int c);
        void sum(){
            cout << "sum: "<< a+b+c+d+e<<endl;
        }
};

void Nums :: setInt(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
};


int main() 
{
    Nums n;
    n.setInt(10, 20, 30);
    n.d = 40;
    n.e = 50;
    n.sum();
    return 0;
}