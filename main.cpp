#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(nullptr));

	int masA = 3, masB = 4, masC = 5;
	int*** cr, **ir, *jr;

	////���������� 
	int*** arr = new int**[masA];

	for (cr = arr; cr < arr + masA; cr++)
	{
		*cr = new int*[masB];
		for (ir = *cr; ir < *cr + masB; ir++)
			*ir = new int[masC];
	}
	//////////////////////////////////////// ���������� � �����

	for (cr = arr; cr < arr + masA; cr++)
	{
		for (ir = *cr; ir < *cr + masB; ir++)
		{
			for (jr = *ir; jr < *ir + masC; jr++)
			{
				*jr = rand() % 30;
				cout << *jr << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}
	//////////////////////////////////// �������
	for (cr = arr; cr < arr + masA; cr++)     // ���� ���������� � ������ while ��� ������������ ��. ������� ��� �����
	{
		for (ir = *cr; ir < *cr + masB; ir++)
		{
			delete[] * ir;
			*ir = nullptr;
		}
	}

	for (cr = arr; cr < arr + masA; cr++)
	{
		for (ir = *cr; ir < *cr + masB; ir++)
		{
			delete[] * ir;
		}
		delete[] * cr;
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}