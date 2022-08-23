#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;//Вывод значения переменной "а" на экран
	cout << &a << endl;// Взятие адреса данной переменной "а" прямо при выводе
	cout << pa << endl;// Вывод адреса переменной "а" храняшегося в указателе ра 
	cout << *pa << endl;//Разименования указателя "ра" и вывод на экран значения по адресу

	int* pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
#endif // POINTERS_BASICS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}