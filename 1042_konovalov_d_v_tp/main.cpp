#include "queue.h"
#include "time.h"
#include <iostream>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	
	int flag = 1, c;
	///////////////////////////////////////////////////////������� �1
	int h, m, s;
	Time st;
	Time ex;
	
	//system("cls");
	while (flag == 1)
	{
		cout << "������� �1 - ������� ��������: " << endl;
		cout << "1 - ���� �������" << endl;
		cout << "2 - ����� �������" << endl;
		cout << "3 - ���������� �������� ++" << endl;
		cout << "4 - ����������� �������� ++" << endl;
		cout << "5 - ���������� �������� --" << endl;
		cout << "6 - ����������� �������� --" << endl;
		cout << "0 - ������� �� ������ ������� ������" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1:
			system("cls");
			cout << "������� �����: ";
			cin >> h >> m >> s;
			st.changeTime(h, m, s);
			st.print();
			cout << "\n";
			break;
		case 2:
			system("cls");
			st.print();
			cout << "\n";
			break;
		case 3:
			system("cls");
			ex = ++st;
			ex.print();
			cout << "�������� ������ �������!" << endl;
			cout << "\n";
			break;
		case 4: 

			system("cls");
			ex = st++;
			ex.print();
			cout << "�������� ������ �������!" << endl;
			cout << "\n";

			break;
		case 5: 
			system("cls");
			ex = --st;
			ex.print();
			cout << "�������� ������ �������!" << endl;
			cout << "\n";

			break;
		case 6: 
			system("cls");
			ex = st--;
			ex.print();
			cout << "�������� ������ �������!" << endl;
			cout << "\n";
			break;
		case 0: 
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}
	/////////////////////////////////////////////////////////������� �2
	system("cls");
	srand(std::time(nullptr));
	int nQ;
	cout << "������� �2 - �������� ��������" << endl;
	cout << "������ ���������� ��������" << endl;
	cin >> nQ;
	parQueue* tempQ = new parQueue[nQ];
	for (int i = 0; i < nQ; i++) {
		int size;
		cout << "������ ������ ������� " << i + 1 << ":" << endl;
		cin >> size;
		for (int j = 0; j < size; j++) {
			tempQ[i] += (10 + rand() % 10);
		}
	}
	int numF; double numS;
	cout << "������� �2 - �������� ���������\n" << endl;
	flag = 1;

	for (int i = 0; i < nQ; i++) {
		cout << "������� " << i + 1 << ": ";

		tempQ[i].print();
	}

	while (flag == 1)
	{
		cout << "��������, ����� �������� ��������:" << endl;
		cout << "1 - �������� +" << endl;
		cout << "2 - ��������� -" << endl;
		cout << "3 - �������� +=" << endl;
		cout << "4 - ��������� -=" << endl;
		cout << "5 - ��������� *" << endl;
		cout << "6 - ������� /" << endl;
		cout << "7 - ���������� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - ��������
			system("cls");
			cout << "������� ������ �������� ��������" << endl;
			cin >> numF >> numS;
			
			tempQ[numF - 1] = tempQ[numF - 1] + tempQ[int(numS) - 1];

			cout << "���������: ";
			tempQ[numF - 1].print();
			break;
		case 2: //2 - ���������
			system("cls");
			cout << "������� ������ �������� ��������" << endl;
			cin >> numF >> numS;


			tempQ[numF - 1] = tempQ[numF - 1] - tempQ[int(numS) - 1];

			cout << "���������: ";
			tempQ[numF - 1].print();
			break;
		case 3: //3 - ����������
			system("cls");
			cout << "������� ����� �������" << endl;
			cin >> numF;
			cout << "������� �����: " << endl;
			
			cin >> numS;
			tempQ[numF - 1] += numS;
			tempQ[numF - 1].print();
			break;
		case 4: //4 - ����������
			system("cls");
			cout << "������� ����� �������" << endl;
			cin >> numF;
			numS = tempQ[numF - 1].get_first();
			tempQ[numF - 1] -= numS;
			tempQ[numF - 1].print();
			break;
		case 5: //5 - ���������
			system("cls");
			cout << "������� ������ �������� ��������" << endl;
			cin >> numF >> numS;

			tempQ[numF - 1] = tempQ[numF - 1] * tempQ[int(numS) - 1];

			cout << "���������: ";
			tempQ[numF - 1].print();
			break;
		case 6: //6 - �������
			system("cls");
			cout << "������� ����� �������" << endl;
			cin >> numF;
			cout << "������� ��������: " << endl;

			cin >> numS;

			tempQ[numF - 1] = tempQ[numF - 1] / numS;

			cout << "���������: ";
			tempQ[numF - 1].print();
			break;
		case 7:
			for (int i = 0; i < nQ; i++) {
				cout << "������� " << i + 1 << ": ";
				tempQ[i].print();
			}
			break;
		case 0: //0 - �����
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}
	return 0;
}