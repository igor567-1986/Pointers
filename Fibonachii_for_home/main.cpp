#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите предел для чисел ряда фибоначчи:"; cin >> n;
	if (n == 0)cout << "0";
	else cout << "0"<< "\t" ;
	for (int i =0, fib1 = 0, fib2 = 1; fib2 < n;)
	{
		cout << fib2 << "\t";
		i = fib1 + fib2;
		fib1 = fib2;
		fib2 = i;
	}
	cout << endl;
	cout << "Введите сколько цифр из ряда фибоначчи надо вывести:"; cin >> n;
	cout << "0" << "\t";
	for (int i = 0, fib1 = 0, fib2 = 1,fib3=0; i < n-1;i++)
	{
		cout << fib2 << "\t";
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
	}
	int n;
	cout << "Введите колличество членов ряда:"; cin >> n;
	for (int i = 0, a = 0, b = 1, c = a + b; i < n; i++, c = (a + b) + (b + c))
	{
		cout << a << "\t";
	}
	cout << endl;
}