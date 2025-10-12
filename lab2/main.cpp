#include <iostream>
#include <cmath>
#include <bitset>
int main()
{
  setlocale(LC_ALL, "RU");
  unsigned short i; //корректность ввода
  short A;
  std::cout << "Номер бита = "; std::cin >> i;
  if (i<0 || i>15)
  {
    std::cout <<"Не корректный ввод номера бита." << std::endl;
    return 1;
  }
  std::cout << "Число =  "; std::cin >> A;
  std:: bitset<8> b2 = A;
  std:: cout << "A in binary = 0b" << b2.to_string() << std:: endl;
  i = 1 << i;
  b2 = i;
  std:: cout << "i bit in binary = 0b" <<b2.to_string() << std::endl;
  /*
  A = !(i & A)? (A * A) & ~i : A = 125 & 0b10101010;  //, вместо всей конструкции if else
  */
  bool iA = & A;
  std:: cout <<"Значение  бита: " << (short)iA << std::endl;
 /*
 Для первого сравнения в пункте 1, вытащить значение i бита в отдельную переменную.
 */
  if (iA == 0) // не  (i и A) // if (!(i & A)), (!iA)
  {
    std:: cout << "A^2 = " << A *  A << std::endl;
    A *= A;
    A = A & ~i; //заменяем i бит на ноль2
  }
  else
  {
    A = 125 & 0b1010101010101010;
  }
  b2 = A;
  std::cout << "Ответ:" << A << std::endl; std:: cout << "Ответ in binary = 0b" << b2.to_string() << std::endl;
  return 0;
}