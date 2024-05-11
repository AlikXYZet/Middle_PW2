#include <iostream>
#include <cmath>

using namespace std;

class Array
{
public:

	// �����������
	Array()
	{
		// ��������� �������� ���.�������
		cout << "\n������� ���������� ���������: n = ";
		cin >> n;
		cout << "������� ���������� ���������: m = ";
		cin >> m;

		// �������� � ���������� ���.�������
		A = new int* [n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new int[m];
			for (int ii = 0; ii < m; ii++)
			{
				A[i][ii] = rand() % 10;	// ��������: 0-9
			}
		}

		// ���������� ���.������
		string inInfo;
		cout << "������� ����� (En): Info = ";
		cin >> inInfo;
		Info = new string(inInfo);

		int inNumber;
		cout << "������� ����� (int): Number = ";
		cin >> inNumber;
		Number = new int(inNumber);
	};

	// ����������
	~Array()
	{
		// ������������ ������
		FDelete();
	}

	// ���������� ����������� (�� ������ ����������)
	Array(Array& other)
	{
		*this = other;
	}

	// ���������� ����������
	Array& operator=(Array& other)
	{
		if (&other == this)
			return *this;

		// ������������ ������
		FDelete();

		// ��������� ������� �������
		n = other.n;
		m = other.m;

		// �������� � ���������� ���.�������
		A = new int* [n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new int[m];
			for (int ii = 0; ii < m; ii++)
			{
				A[i][ii] = other.A[i][ii];
			}
		}

		// ���������� ���.������
		Info = new string(*(other.Info));
		Number = new int(*(other.Number));

		return *this;
	}

	// ����� � �������
	friend ostream& operator << (ostream& out, Array& Arr);

private:

	// ������ �������
	int n;
	int m;
	int** A;

	// ���.������
	string* Info;
	int* Number;

	// �-� ������������ ������
	void FDelete()
	{
		// �������� ���.�������
		for (int i = 0; i < n; i++)
		{
			delete[] A[i];
		}
		delete[] A;

		// �������� ���.������
		delete Info;
		delete Number;
	}
};

ostream& operator << (ostream& out, Array& Arr)
{
	// ����� ���.�������
	cout << '\n';
	for (int i = 0; i < Arr.n; i++)
	{
		for (int ii = 0; ii < Arr.m; ii++)
		{
			cout << Arr.A[i][ii] << "  ";
		}
		cout << '\n';
	}

	// ����� ���.������
	cout << "Info = " << *Arr.Info << '\n';
	cout << "Number = " << *Arr.Number << '\n';

	return out;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "\n������������� A1:";
	Array A1;
	cout << "\nA1:" << A1;

	cout << "\n������������� A2:";
	Array A2;
	cout << "\nA2:" << A2;

	A2 = A1;
	cout << "\nA2 = A1:" << A2;

	cout << "\n������������� A3:";
	Array A3(A1);
	cout << "\nA3(A1):" << A3;

	cout << "\nA3 = A3:";
	A3 = A3;
	cout << "\nA3:" << A3;

}