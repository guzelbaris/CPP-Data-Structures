#include <iostream>

using namespace std;

int digit(int a){

    int x_1,x_2,x_3,x_4;
    x_1=a/1000;
    cout<<x_1<<endl;
    x_2=(a%1000)/100;
    cout<<x_2<<endl;
    x_3=((a%1000)%100)/10;
    cout<<x_3<<endl;
    x_4=((a%1000)%100)%10;
    cout<<x_4<<endl;
    cout<<a<<endl;

return a;
}

int main()
{
    int b=5763;

    digit(b);


    return 0;
}
