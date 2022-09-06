#include <iostream>
using namespace std;
 
void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int& n, int valye);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int valye;
	cout << "Введите добавляемое число:"; cin >> valye;
	arr=push_back(arr, n, valye);
	Print(arr, n);

	delete[]arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// через
		*(arr + i) = rand() % 100;
	}

}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int* arr,  int& n, int valye)
{

	// 1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем исходный массив в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) после того как все данные скопированны из исходного массива 
	// он больше не нужен и его надо удалить
	delete[]arr;

	//4) Подменяем адрес исходного массива в указателе "arr"
	arr = buffer;

	// И только после этого можно написать вот так:
	arr[n] = valye;
	// поскольку только сейчас в массиве аrr ,появился еще один элемент,
	// в который можно сохранить значение
	n++;
	// 6)После того как мы добавили в массив элемент,колличество элементов массива увеличивается.
	return arr;
}