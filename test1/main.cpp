#include <iostream> //#include <cmath> математический модуль, если вдруг в иострим нет вдруг их
//#include <limits> 
int main() {
	/*
	Some
	some
	some
	*/
	
	system ("chcp 1251 > null");
	
	std::cout << "All is okay!\n" << std::endl; /* \n пропускает строку
	*/
	std::cout << "Hello world!!\n" <<std::endl;

	/*int x;
	int y;
	std::cin >> x >>y;
	std::cout << "x = " << x << "\n" << "y = " << y << std::endl << "x + y = " << x+y;
	*/
	//std:: cout << numeric_limits <int>::max() << std::endl; для вычисления максимума инта, используется директива #include <limits>
	// Арифметические операции
	//+, -, *, /, %(ост от деления), ++, -
	// float f = 10.(float) / 3(int)
	// int x = 10;
	// int y = 3;
	// float f = (x*1.f)(вещественным тогда будет) / y
	// i+=1(как в питоне), i++ постфикный инкремент, i-- декремент, ++i префиксный инкремент 
	// int q = 3.345f неявное приведение тип,, int w = (int)3.345f явное приведение типа, c-style cast, int e = static_cast<int(целевой тип)>(3.345f)-(приводит один тип к другому) явное приведение типа c++ style(шаблон)
	// Битовый сдвиг:
	int x2 = 0b011; // = 3
	std:: cout << (x2 << 1) << std::endl; // >> - вправо на сдвиг по биту, << - влево  на сдвиг по биту
	
	// битовое & и
	int a = 0b0010;
	int b = 0b1110;
	// 0b0010
	std:: cout << (a ) << std::endl;

	// битовое | (или)
	// 0b1110
	//битовая инверсия ~ std:: cout << ~b << std::endl; b = 0b0001
	//битовый xor (^) (a^b) = 0b1100 - исключающее или
	

	int f = 11;
	bool isEvan = f % 2;

	//логические операторы 
	//==, !=, !(логическое отрицание), <, >, <=, >=
	// && логическое И
	// Тернанрный 
	// std:: cout<<(f % 2 == 0? "Even" : "Odd" );

	return 0;
}