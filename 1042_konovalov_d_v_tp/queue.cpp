#include <iostream>
#include "queue.h"
using namespace std;

parQueue::parQueue() //конструктор - инициализируем размер и последний элементы
{
	size = 0;
	last = nullptr;
}

parQueue::~parQueue() //деструктор
{
	if (last != nullptr) {
		while (size > 0) //пока размер больше нуля
		{
			Unit* temp = last; //временной переменной присваиваем значение последнего
			last = temp->prev; //последняя становится "предыдущей"
			temp = nullptr;
			size--; //уменьшаем размер
		}
	}
	
}

Unit* parQueue::get_last()
{
	return last;
}

int parQueue::get_first()
{
	Unit* temp = this->last;
	double arr;
	int cnt = 0;

	if (this->size > 0) {

		while (temp->prev != 0) {
			temp = temp->prev;
		}
		arr = temp->data;

		return arr;
	}
	else if (temp == nullptr) {
		cout << "Очередь пуста" << endl;
		return 0;
	}
	
	
}

parQueue parQueue::operator -=(double el)
{
	parQueue tmp = *this;
	parQueue tmp1;
	double* buff = new double[this->size];

	int cnt = 0;
	if (tmp.last == nullptr) {
		cout << "Очередь пуста" << endl;
		return *this;
	}
	if (tmp.last->prev == nullptr && tmp.last->data == el) {
		last = nullptr;
		size--;
		return *this;
	}
	else {

		while (tmp.last != nullptr) {

				buff[cnt] = tmp.last->data;
				cnt++;

				tmp.last = tmp.last->prev;
			
		}
		for (int i = cnt - 2; i >= 0; i--) {
			tmp1 += buff[i];
		}

		*this = tmp1;

		return *this;
	}
	
}

void operator +=(parQueue& q, double el)
{
	Unit* new_unit = new Unit; //выделяем память под новый элемент
	new_unit->prev = q.last; //указатель нового элемента указывает на последний в очереди
	q.last = new_unit; //теперь новый элемент стал последним
	q.last->data = el; //присваиваем данные
	q.size++;
}

parQueue operator -(parQueue& q, parQueue& q1)
{
	parQueue th;
	double* buff1 = new double[q.size];
	double* buff2 = new double[q1.size];
	Unit* el_queue1 = q.last;
	Unit* el_queue2 = q1.last;

	parQueue temp;

	if (el_queue1 == nullptr || el_queue2 == nullptr) {
		cout << "Очередь пуста" << endl;
		return q;
	}

	for (int i = q1.size - 1; i >= 0; i--)
	{
		buff2[i] = el_queue2->data;
		el_queue2 = el_queue2->prev;
	}

	for (int i = q.size - 1; i >= 0; i--)
	{
		buff1[i] = el_queue1->data;
		el_queue1 = el_queue1->prev;
	}

	for (int i = 0; i < q.size; i++)
	{
		for (int j = 0; j < q1.size; j++)
		{
			if (buff1[i] == buff2[j]) {
				buff1[i] = 0;
				break;
			}
		}
	}



	for (int i = 0; i < q.size; i++)
	{
		if (buff1[i] != 0) th += buff1[i];
	}

	delete[] buff1;
	delete[] buff2;

	if (th.size == 0) {
		return q;
	}

	return th;
}

void parQueue::print()
{
	if (this->size != 0 || last != nullptr) {
		Unit* tmp = last;

		while (tmp->prev != nullptr)
		{
			cout << tmp->data << " --> "; //выводим значения (с конца), пока указатель на следующий элемент не будет нулевым
			tmp = tmp->prev;
		}
		cout << tmp->data << endl; //вывели последний элемент
	}
	else {
		cout << "Очередь пуста" << endl;
	}

}

parQueue parQueue::operator + (parQueue& q)
{
	parQueue th;

	double* buff1 = new double[q.size];
	double* buff2 = new double[this->size];
	Unit* el_queue1 = q.last;
	Unit* el_queue2 = this->last;

	if (el_queue1 == nullptr || el_queue2 == nullptr) {
		cout << "Очередь пуста" << endl;
		return q;
	}

	for (int i = q.size - 1; i >= 0; i--)
	{
		buff1[i] = el_queue1->data;
		el_queue1 = el_queue1->prev;
	}


	for (int i = this->size - 1; i >= 0; i--)
	{
		buff2[i] = el_queue2->data;
		el_queue2 = el_queue2->prev;
	}

	for (int i = 0; i < q.size; i++)
	{
		th += (buff1[i]);
	}

	for (int i = 0; i < this->size; i++)
	{
		th += (buff2[i]);
	}

	delete[] buff1;
	delete[] buff2;

	return th;

}

parQueue parQueue::operator * (parQueue& q) {
	parQueue th;

	double* buff1 = new double[q.size];
	double* buff2 = new double[this->size];
	Unit* el_queue1 = q.last;
	Unit* el_queue2 = this->last;

	if (el_queue1 == nullptr || el_queue2 == nullptr) {
		cout << "Очередь пуста" << endl;
		return q;
	}

	if (q.size == this->size) {
		for (int i = q.size - 1; i >= 0; i--)
		{
			buff1[i] = el_queue1->data;
			el_queue1 = el_queue1->prev;
			buff2[i] = el_queue2->data;
			el_queue2 = el_queue2->prev;
		}

		for (int i = 0; i < q.size; i++)
		{
			th += (buff1[i] * buff2[i]);
		}

		delete[] buff1;
		delete[] buff2;

		return th;
	}
	else {
		cout << "Выберете очереди с одинаковой размерностью" << endl;
		return *this;
	}
}

parQueue parQueue::operator / (double el) {
	parQueue th;


	double* buff2 = new double[this->size];

	Unit* el_queue2 = this->last;

	if (el_queue2 == nullptr) {
		cout << "Очередь пуста" << endl;
		return *this;
	}

	for (int i = this->size - 1; i >= 0; i--)
	{
		buff2[i] = el_queue2->data;
		el_queue2 = el_queue2->prev;
	}

	for (int i = 0; i < this->size; i++)
	{
		th += (double (buff2[i]) / double (el));
	}

	delete[] buff2;

	return th;

}

bool parQueue::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}