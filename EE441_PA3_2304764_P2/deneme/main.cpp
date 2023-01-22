#include <iostream>

using namespace std;

void increment_1(int value){
value=value+1;
}
void increment_2(int& value){
value=value+1;
}
void increment_3(int* value){
value=value+1;
}

int main()
{
   int x=10;
   int y=10;
   int z=10;

   x=increment_1(x);
   y=increment_2(y);
   z=increment_3(&z);

   cout<<x<<y<<z;
}
