#pragma once
//using namespace std;
#include <functional>
typedef struct Unit //элемент очереди
{
	double data = 0.0; //значение
	Unit* prev = 0; //указатель на предыдущи элемент
} Unit;

class parQueue
{
private:
	Unit* last = 0; //указатель на "конец" очереди

protected:
	int size; //размер очереди

public:
	parQueue(); //конструктор без параметров
	~parQueue(); //деструктор

	/*–азмер каждой очереди вводитс€ пользователем с клавиатуры,
	а значени€ задаютс€ случайным образом от 10 до 20.*/

	Unit* get_last(); //объ€вление функции вз€ти€ конца очереди
	int get_first();
	void print(); //вывод на консоль очереди
	bool isEmpty(); //проверка на заполненность

	parQueue operator + (parQueue&); // \/сложени€ двух экземпл€ров класса
	parQueue operator -= (double); // \/как метод дл€ извлечени€ элемента из очереди
	parQueue operator * (parQueue&); // \/поэлементного умножени€ экземпл€ров класса друг на друга
	parQueue operator / (double); // \/деление очереди на пользовательское число

	friend void operator +=(parQueue&, double); // \/добавлени€ элемента в очередь
	friend parQueue operator -(parQueue&, parQueue&); //дл€ вычитани€ экземпл€ров класса друг из друга

};