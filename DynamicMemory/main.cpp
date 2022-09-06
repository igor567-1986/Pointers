#include <iostream>
using namespace std;
 
void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int& n, int valye);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int valye;
	cout << "������� ����������� �����:"; cin >> valye;
	arr=push_back(arr, n, valye);
	Print(arr, n);

	delete[]arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// �����
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

	// 1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1];
	//2) �������� �������� ������ � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) ����� ���� ��� ��� ������ ������������ �� ��������� ������� 
	// �� ������ �� ����� � ��� ���� �������
	delete[]arr;

	//4) ��������� ����� ��������� ������� � ��������� "arr"
	arr = buffer;

	// � ������ ����� ����� ����� �������� ��� ���:
	arr[n] = valye;
	// ��������� ������ ������ � ������� �rr ,�������� ��� ���� �������,
	// � ������� ����� ��������� ��������
	n++;
	// 6)����� ���� ��� �� �������� � ������ �������,����������� ��������� ������� �������������.
	return arr;
}