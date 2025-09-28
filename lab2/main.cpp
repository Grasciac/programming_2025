#include <iostream>
#include <cmath>
int main()
{
  setlocale(LC_ALL, "RU");
  unsigned short i;
  signed char A;
  std::cin >> i;
  A = char(i);
  std::cin >> i;
  if (!((signed char)pow(2, i - 1) & A))
  {
    std::cout << (int) A << std::endl;
    return 1;
  }
  else
  {
    

  }
  return 0;
}

