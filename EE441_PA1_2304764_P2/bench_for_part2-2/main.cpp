#include <iostream>

#include <chrono>

void benchmark(void (*func)(int))
{
    int const AMOUNT = 20;
    int const REPEAT = 10;
    double results[AMOUNT];
    for (int i = 0 ; i < AMOUNT ; ++i) {
        auto start = std::chrono::steady_clock::now();
        for (int j = 0 ; j < REPEAT ; ++j) {
            func(i+1);
        }
        auto finish = std::chrono::steady_clock::now();
        results[i] = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count() / REPEAT;
    }

    std::cout << std::endl << std::endl;
    std::cout << "n\ttime (ns)\n";
    for (int i = 0 ; i < AMOUNT ; ++i) {
        std::cout << i+1 << '\t' << results[i] << '\n';
    }
    std::cout << std::endl;
}
using namespace std;
void print_backwards(char const * string) {
   if(*string == '\0')
   return;
   else {
      print_backwards(string+1); //recursion part
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



// backward print function
void wrapper_print_backwards(int n)
{
    char * str = new char[n+1];
    for (int i = 0 ; i < n ; ++i) {
        str[i] = 'a' + i;
    }
    str[n] = '\0';

    print_backwards(str);

    delete[] str;
}

void wrapper_nth_prime(int n)
{
    volatile int temp = nth_prime(n);
}

int main()
{

    benchmark(wrapper_print_backwards);
    benchmark(wrapper_nth_prime);
}


