﻿#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

void firstTask();
void secondTask();
void individualTask();
void additionalTask();

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	while (true)
	{

		cout << "\t\t\t/////      /////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t//////    //////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t///  //////  ///  ///       /// ///    ///  ///      ///\n";
		cout << "\t\t\t///   ////   ///  //////    ///  ///   ///  ///      ///\n";
		cout << "\t\t\t///          ///  //////    ///   ///  ///  ///      ///\n";
		cout << "\t\t\t///          ///  ///       ///    /// ///  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///     //////  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///      /////  ////////////\n";
		cout << "\t\t\t--------------------------------------------------------\n";


		cout << "\t\t\t\t\t|1)Задание 1             |\n\t\t\t\t\t|2)Задание 2             |\n\t\t\t\t\t" <<
			"|3)Индивидуальное задание|\n\t\t\t\t\t|4)Дополнительное задание|\n\t\t\t\t\t---------------" <<
			"-----------\n\t\t\t\t\tВыбор: ";
		int menuChoice; cin >> menuChoice;

		switch (menuChoice)
		{
		case(1): { std::system("cls"); firstTask();      break; }
		case(2): { std::system("cls"); secondTask();     break; }
		case(3): { std::system("cls"); individualTask(); break; }
		case(4): { std::system("cls"); additionalTask(); break; }
		default: {std::cout << "Введено неверное значение..."; _getch(); std::system("cls"); break; }
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region firstGeneralTask

//Создать класс списка IntSetMassive.В данном классе будет храниться список целых чисел
//(однонаправленный список), а также будут определены некоторые операции присущие
//множествам.
//Определить в классе конструкторы(к примеру, инициализация массивом, но оставляет
//	только неповторяющиеся элементы), деструктор, необходимые поля.К примеру, в нем должен
//	быть указатель на первый элемент, а также количество элементов массива.В данном массиве
//	должны быть только неповторяющиеся элементы, так как он имитирует множество.
//	Дополнительно перегрузить следующие операции :
//	 « + » – добавить число во множество(типа object + item, где item – целое число), добавляет
//	только если такого элемента еще нет во множестве;
//	 « + » – объединение множеств(типа object1 + object2), возвращает копию множества,
//	которое является объединением двух множеств - операндов;
//	 « - » – удалить число из множества(типа object - item, где item – целое число)
//	 « - » – пересечение множеств(типа object1 - object2);
//	 «[]» – возвращает элемент по номеру;
//	 int() – приведение к целому, возвращает мощность множества(размер массива).
//	Написать программу тестирования, в которой проверяется использование всех
//	перегруженных операций.

class IntSetMassive
{
public:

	IntSetMassive();
	~IntSetMassive();
	int getSize();
	void pushBack(const int data);
	void PrintMass();
	void deleteMass(const int index);
	void clearAll();
	bool check(const int value);
	int getIndex(const int value);
	void operator+(const int data);
	void operator+(const IntSetMassive& other);
	void operator-(const int data);
	void operator-(const IntSetMassive& other);
	int& operator[](const int index);

private:
	class Mass
	{
	public:
		int data;
		Mass* pNext;
		Mass(int data = 0, Mass* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int SIZE;
	Mass* pHead;
};

IntSetMassive::IntSetMassive()
{
	this->pHead = nullptr;
	this->SIZE = 0;
}

IntSetMassive::~IntSetMassive()
{
	clearAll();
}

int IntSetMassive::getSize()
{
	return SIZE;
}

void IntSetMassive::pushBack(const int data)
{
	if (IntSetMassive::check(data))
		return;
	if (this->pHead == nullptr)
	{
		this->pHead = new Mass(data);
	}
	else
	{
		Mass* pTemp = this->pHead;
		while (pTemp->pNext != nullptr)
		{
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = new Mass(data);
	}
	this->SIZE++;
}

void IntSetMassive::PrintMass()
{
	Mass* pTemp = this->pHead;
	while (pTemp != nullptr)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->pNext;
	}
}

void IntSetMassive::deleteMass(const int index)
{
	int counter = 0;
	Mass* pTemp = this->pHead;

	if (counter == index)
	{
		this->pHead = this->pHead->pNext;
		delete pTemp;
	}

	else
	{

		for (; counter < index - 1; counter++)
		{
			pTemp = pTemp->pNext;
		}

		Mass* pTempForDelete = pTemp->pNext;
		pTemp->pNext = pTempForDelete->pNext;
		delete pTempForDelete;
	}

	this->SIZE--;
}

void IntSetMassive::clearAll()
{

	for (int i = 0; i < getSize(); i++)
	{
		deleteMass(i);
	}

	this->SIZE = 0;
}

void IntSetMassive::operator+(const int data)
{
	IntSetMassive::pushBack(data);
}

void IntSetMassive::operator+(const IntSetMassive& other)
{
	Mass* pTemp = other.pHead;
	while (pTemp != nullptr)
	{
		IntSetMassive::pushBack(pTemp->data);
		pTemp = pTemp->pNext;
	}
}

void IntSetMassive::operator-(const int data)
{
	if (IntSetMassive::check(data))
	{
		deleteMass(getIndex(data));
	}
}

void IntSetMassive::operator-(const IntSetMassive& other)
{
	Mass* pTemp = other.pHead;
	while (pTemp != nullptr)
	{
		if (IntSetMassive::check(pTemp->data))
		{
			cout << pTemp->data << " ";
		}
		pTemp = pTemp->pNext;
	}
}

int& IntSetMassive::operator[](const int index)
{
	Mass* pTemp = this->pHead;

	if (index == 0)
	{
		return pTemp->data;
	}
	else
	{
		int counter = 0;
		while (counter != index)
		{
			pTemp = pTemp->pNext;
			counter++;
		}
		return pTemp->data;
	}
}

int IntSetMassive::getIndex(const int value)
{
	int counter = 0;
	Mass* pTemp = this->pHead;
	while (pTemp->data != value)
	{
		pTemp = pTemp->pNext;
		counter++;
	}
	return counter;
}

bool IntSetMassive::check(const int value)
{
	Mass* pTemp = this->pHead;
	while (pTemp != nullptr)
	{
		if (pTemp->data == value)
		{
			return true;
		}
		pTemp = pTemp->pNext;
	}
	return false;
}


void firstTask()
{
	IntSetMassive it1;

	it1.pushBack(1);
	it1.pushBack(1);
	it1.pushBack(2);
	it1.pushBack(3);
	it1.pushBack(4);

	IntSetMassive it2;

	it2.pushBack(3);
	it2.pushBack(4);
	it2.pushBack(5);
	it2.pushBack(6);
	it2.pushBack(7);

	cout << "1-е множество: ";
	it1.PrintMass();
	cout << "\n2-е множество: ";
	it2.PrintMass();

	cout << "\n\nДобавили число в 1-е множество (17): ";
	it1 + 17;
	it1.PrintMass();
	cout << "\n\nУдалили число из 1-го множества (17): ";
	it1 - 17;
	it1.PrintMass();

	cout << "\n\nПересечение множеств: ";
	it1 - it2;

	cout << "\n\nОбъединение множеств: ";
	it1 + it2;
	it1.PrintMass();

	cout << "\n\nВозвратили элемент по номеру из 1-го множества (2): ";
	cout << it1[2];

	/////////////////////////////////////////////////
	cout << "\n\nВозвратили мощность множества: "; //
	/////////////////////////////////////////////////

	_getch(); system("cls");
}

#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region secondTask

void secondTask()
{

}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region individualTask

void individualTask()
{

}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void additionalTask()
{
	_getch();
}