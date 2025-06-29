#include<iostream>
using namespace std;
 
int main()
{
  int number, i, a, x;
  
  for (a = 1; a <= 9; a++)
    {
        for (i = 1; i <= 9; i++){ 
          x = a * i;
          cout << a << " * " << i << " = " << x << endl;
        }
     }
  return 0;
}
