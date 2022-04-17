#include "queue.h"
#include "time.h"
#include <iostream>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	
	int flag = 1, c;
	///////////////////////////////////////////////////////ЗАДАНИЕ №1
	int h, m, s;
	Time st;
	Time ex;
	
	//system("cls");
	while (flag == 1)
	{
		cout << "Задание №1 - Унарные операции: " << endl;
		cout << "1 - Ввод времени" << endl;
		cout << "2 - Вывод времени" << endl;
		cout << "3 - Префиксный оператор ++" << endl;
		cout << "4 - Постфиксный оператор ++" << endl;
		cout << "5 - Префиксный оператор --" << endl;
		cout << "6 - Постфиксный оператор --" << endl;
		cout << "0 - Переход ко втрому заданию работы" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1:
			system("cls");
			cout << "Введите время: ";
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
			cout << "Операция прошла успешно!" << endl;
			cout << "\n";
			break;
		case 4: 

			system("cls");
			ex = st++;
			ex.print();
			cout << "Операция прошла успешно!" << endl;
			cout << "\n";

			break;
		case 5: 
			system("cls");
			ex = --st;
			ex.print();
			cout << "Операция прошла успешно!" << endl;
			cout << "\n";

			break;
		case 6: 
			system("cls");
			ex = st--;
			ex.print();
			cout << "Операция прошла успешно!" << endl;
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
	/////////////////////////////////////////////////////////ЗАДАНИЕ №2
	system("cls");
	srand(std::time(nullptr));
	int nQ;
	cout << "ЗАДАНИЕ №2 - Бинарные операции" << endl;
	cout << "Ведите количество очередей" << endl;
	cin >> nQ;
	parQueue* tempQ = new parQueue[nQ];
	for (int i = 0; i < nQ; i++) {
		int size;
		cout << "Ведите размер очереди " << i + 1 << ":" << endl;
		cin >> size;
		for (int j = 0; j < size; j++) {
			tempQ[i] += (10 + rand() % 10);
		}
	}
	int numF; double numS;
	cout << "Задание №2 - Бинарные операторы\n" << endl;
	flag = 1;

	for (int i = 0; i < nQ; i++) {
		cout << "Очередь " << i + 1 << ": ";

		tempQ[i].print();
	}

	while (flag == 1)
	{
		cout << "Выберите, какие операции провести:" << endl;
		cout << "1 - Сложение +" << endl;
		cout << "2 - Вычитание -" << endl;
		cout << "3 - Сложение +=" << endl;
		cout << "4 - Вычитание -=" << endl;
		cout << "5 - Умножение *" << endl;
		cout << "6 - Деление /" << endl;
		cout << "7 - Посмотреть очередь" << endl;
		cout << "0 - Выход" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - Сложение
			system("cls");
			cout << "Введите номера очередей очередей" << endl;
			cin >> numF >> numS;
			
			tempQ[numF - 1] = tempQ[numF - 1] + tempQ[int(numS) - 1];

			cout << "Результат: ";
			tempQ[numF - 1].print();
			break;
		case 2: //2 - Вычитание
			system("cls");
			cout << "Введите номера очередей очередей" << endl;
			cin >> numF >> numS;


			tempQ[numF - 1] = tempQ[numF - 1] - tempQ[int(numS) - 1];

			cout << "Результат: ";
			tempQ[numF - 1].print();
			break;
		case 3: //3 - Добавление
			system("cls");
			cout << "Введите номер очереди" << endl;
			cin >> numF;
			cout << "Введите число: " << endl;
			
			cin >> numS;
			tempQ[numF - 1] += numS;
			tempQ[numF - 1].print();
			break;
		case 4: //4 - Извлечение
			system("cls");
			cout << "Введите номер очереди" << endl;
			cin >> numF;
			numS = tempQ[numF - 1].get_first();
			tempQ[numF - 1] -= numS;
			tempQ[numF - 1].print();
			break;
		case 5: //5 - Умножение
			system("cls");
			cout << "Введите номера очередей очередей" << endl;
			cin >> numF >> numS;

			tempQ[numF - 1] = tempQ[numF - 1] * tempQ[int(numS) - 1];

			cout << "Результат: ";
			tempQ[numF - 1].print();
			break;
		case 6: //6 - Деление
			system("cls");
			cout << "Введите номер очереди" << endl;
			cin >> numF;
			cout << "Введите делитель: " << endl;

			cin >> numS;

			tempQ[numF - 1] = tempQ[numF - 1] / numS;

			cout << "Результат: ";
			tempQ[numF - 1].print();
			break;
		case 7:
			for (int i = 0; i < nQ; i++) {
				cout << "Очередь " << i + 1 << ": ";
				tempQ[i].print();
			}
			break;
		case 0: //0 - Выход
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