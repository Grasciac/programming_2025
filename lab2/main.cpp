#include <iostream>
#include <cmath>
#include <bitset>
int main()
{
  setlocale(LC_ALL, "RU");
  unsigned short i; 
  short A;
  std::cout << "Номер бита = "; std::cin >> i;
  std::cout << "Число =  "; std::cin >> A;
  std:: bitset<8> b2 = A;
  std:: cout << "A in binary = " << b2.to_string() << std:: endl;
  i = 1 << i;
  b2 = i;
  std:: cout << "i bit in binary = " <<b2.to_string() << std::endl;
  /*
  A = !(i & A)? (A * A) & ~i : A = 125 & 0b10101010;  //, вместо всей конструкции if else
  */
  if (!(i & A)) // не  (i и A) 
  {
    std:: cout << A *  A << std::endl;
    A *= A;
    A = A & ~i; //заменяем i бит на ноль2
  }
  else
  {
    A = 125 & 0b10101010;
  }
  b2 = A;
  std::cout << "Ответ:" << A << std::endl; std:: cout << "Ответ in binary = " << b2.to_string() << std::endl;
  return 0;
}