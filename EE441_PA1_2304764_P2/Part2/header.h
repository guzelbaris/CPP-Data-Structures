#include <iostream>

using namespace std;
// backward print function
void recursive_print_backwards(char const * string);

// nth prime number
int nth_prime(int n);

void recursive_print_backwards(char const * string) {
   if(*string == '\0')
   return;
   else {
      recursive_print_backwards(string+1); //recursion part
      cout<<*string;
   }
}
int nth_prime(int n){
 int check,c=0;

  for(int i=2;i<=1000;i++)
  {
    check=0;
    for(int j=2;j<=i/2;j++)
    {
        if(i%j==0)
        {
          check=1;
           break;
        }
    }

  if(check==0)
    c++;
      if(c==n)
     {
         return i;
      break;
     }
 }

}
