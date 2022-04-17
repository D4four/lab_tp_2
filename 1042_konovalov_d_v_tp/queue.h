#pragma once
//using namespace std;
#include <functional>
typedef struct Unit //������� �������
{
	double data = 0.0; //��������
	Unit* prev = 0; //��������� �� ��������� �������
} Unit;

class parQueue
{
private:
	Unit* last = 0; //��������� �� "�����" �������

protected:
	int size; //������ �������

public:
	parQueue(); //����������� ��� ����������
	~parQueue(); //����������

	/*������ ������ ������� �������� ������������� � ����������,
	� �������� �������� ��������� ������� �� 10 �� 20.*/

	Unit* get_last(); //���������� ������� ������ ����� �������
	int get_first();
	void print(); //����� �� ������� �������
	bool isEmpty(); //�������� �� �������������

	parQueue operator + (parQueue&); // \/�������� ���� ����������� ������
	parQueue operator -= (double); // \/��� ����� ��� ���������� �������� �� �������
	parQueue operator * (parQueue&); // \/������������� ��������� ����������� ������ ���� �� �����
	parQueue operator / (double); // \/������� ������� �� ���������������� �����

	friend void operator +=(parQueue&, double); // \/���������� �������� � �������
	friend parQueue operator -(parQueue&, parQueue&); //��� ��������� ����������� ������ ���� �� �����

};