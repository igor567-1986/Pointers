#include <iostream>
using namespace std;

//#define part_1
 
void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int& n, int valye);
int* push_front(int* arr, int& n, int valye);
int* insert(int* arr, int& n, int valye,int index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n,int index);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int valye, index;
#ifdef part_1
	cout << "Введите добавляемое число в конец массива:"; cin >> valye;
	arr = push_back(arr, n, valye);
	Print(arr, n);
	cout << "Введите добавляемое число в начало массива:"; cin >> valye;
	arr = push_front(arr, n, valye);
	Print(arr, n);
	cout << "Введите добавляемое число и индекс  по которому он будет расположен в массиве он не должен быть выше" << n - 1 << ":"; cin >> valye; cout << "\t"; cin >> index;
	do
		if (index > n - 1)
		{
			cout << "Ошибка индекс введен не верно ,введите его заново"; cin >> index;
		}
	while (index > n - 1);
	arr = insert(arr, n, valye, index);
	Print(arr, n);
#endif // 
	arr = pop_back( arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);
	delete[]arr;
	cout << "Введите индекс по каторому надо удалить число в массиве он не должен быть выше" << n - 1 << ":"; cin >> index;
	do
		if (index > n - 1)
		{
			cout << "Ошибка индекс введен не верно ,введите его заново"; cin >> index;
		}
	while (index > n - 1);
	arr = erase(arr, n,index);
	Print(arr, n);
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// через арифметику указателей и оператор разименование
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
int* push_front(int* arr, int& n, int valye)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = valye;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int valye,int index)
{
    int* buffer = new int[n + 1];
    n++;
	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else if (i == index)buffer[i] = valye;
		else buffer[i] = arr[i-1];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];

	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[n - 1];

	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int* arr, int& n,int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1 ; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else buffer[i] = arr[i+1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}