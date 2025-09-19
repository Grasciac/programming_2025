#include <iostream> //#include <cmath> математический модуль, если вдруг в иострим нет вдруг их

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

	int x;
	int y;
	std::cin >> x >>y;
	std::cout << "x = " << x << "\n" << "y = " << y << std::endl << "x + y = " << x+y;
	
	// Арифметические операции
	//+, -, *, /, %(ост от деления), ++, -
	// float f = 10.(float) / 3(int)
	// int x = 10;
	// int y = 3;
	// float f = (x*1.f)(вещественным тогда будет) / y
	// i+=1(как в питоне), i++ постфикный инкремент, i-- декремент, ++i префиксный инкремент 
	// int q = 3.345f неявное приведение тип,, int w = (int)3.345f явное приведение типа, c-style cast, int e = static_cast<int(целевой тип)>(3.345f)-(приводит один тип к другому) явное приведение типа c++ style(шаблон)
	return 0;
}