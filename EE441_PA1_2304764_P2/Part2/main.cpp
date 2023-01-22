#include <iostream>
#include "header.h"

using namespace std;

int main()
{
   double d;
   //char str[] = "First try of the function";
   //cout<<"Original String: "<<str<<endl;
   //cout<<"Reversed String: ";
   //recursive_print_backwards(str);
   d=nth_prime(15);
   cout<<d;
   return 0;
}
