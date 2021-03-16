// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include"template.h"
#include"Point.h"
#include"Case.h"

#include <iostream>

using namespace std;

#define stop __asm nop

// Point
std::ostream& operator<<(std::ostream& os, const Point& place)	// распечатать координаты
{
	os << "\nКоординаты:\n"
		<< "x = " << place.m_x
		<< "\n"
		<< "y = " << place.m_y;
	return os;
};

// Point перегрузка для  Point*
std::ostream& operator<<(std::ostream& os, const Point* place)
{
	os << "\nКоординаты:\n"
		<< "x = " << place->m_x
		<< "\n"
		<< "y = " << place->m_y;
	return os;
}

// функция условия для list  remove_if
bool NegPoint(const Point& object) 
{
	return ( object.m_x < 0 && object.m_y < 0 );
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	
	queue<int, list<int>> myQueue;
	myQueue.push(4);
	myQueue.push(6);
	PrintAdapter(myQueue);
	stop;


	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
	vector<int> vInt = { 1, 2, 3, 4, 5 };
	stack<int, std::vector<int>> st(vector<int>(vInt.rbegin(), vInt.rend()));	// создаем новый вектор, реверсивный  vector<int>(vInt.rbegin(), vInt.rend())

	PrintAdapter(st);
	stop;

	stack<int, std::vector<int>> st2(vInt);
	PrintAdapter(st2);
	stop;



	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	
	{
		queue<Point, deque<Point>> q1;
		q1.push(Point(5, 5));
		q1.push(Point(1, 1));
		q1.push(Point(8, 8));
		Point& fr = q1.front();
		Point& bk = q1.back();
		PrintAdapter(q1);

		fr = Point(2, 2);
		bk = Point(4, 4);
		PrintAdapter(q1);

		while ( !q1.empty() )
		{
			q1.pop();
		};

		PrintAdapter(q1);
	}

	queue<Point*, deque<Point*>> q1;
	q1.push(new Point(5, 5));
	q1.push(new Point(1, 1));
	q1.push(new Point(8, 8));
	Point* fr = q1.front();
	Point* bk = q1.back();
	*fr = Point(9, 9);
	*q1.back() = Point(10, 10);

	//PrintAdapter(q1);

	while ( !q1.empty() )
	{
		delete q1.front();
		q1.pop();
	}


	stop;

	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?
	const char* ar[] = { "Bool", "is", "also", "important" };
	priority_queue<const char*, std::vector<const char*>, Case> pr(ar, (ar + sizeof(ar) / sizeof(ar[0])));

	PrintAdapter(pr);		// не упорядочены	// для сравнения используются адреса  и сравнивается видом  "return x < y"
							// создали предикат Case, который сравнивает первые символы строки, таким образом сортируется
	
	stop;




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

	set<Point> mySet = { Point(1,1),Point(3,3),Point(12,12),Point(6,6),Point(10,10) };

	PrintAll(mySet);
	stop;

	set<Point>::iterator it = mySet.begin();
	//*it = Point(22, 22);					// ! set предназначен только для чтения

	set<int> mySet2 = { 1,2,3,4,5 };			// 1, 2, 3, 4, 5
	mySet2.insert(2);							// 1, 2, 3, 4, 5		// дубли игнорируются
	PrintAll(mySet2);

	set<int> mySet3 = { 5,4,3,2,1 };			// 1, 2, 3, 4, 5		// упорядочивается
	PrintAll(mySet3);

	int arr5[] = { 1, 2, 3, 6, 7 };
	mySet3.insert(arr5, arr5 + 5);				// 1, 2, 3, 4, 5, 6, 7		// дубли игнорируются
	PrintAll(mySet3);	

	//set<int, greater<int>> mySet4(arr5, arr5 + ( sizeof(arr5) / sizeof(arr5[ 0 ])));
	set<int, greater<int>> mySet4(arr5, arr5 + 5 );			// используем другой компаратор
	PrintAll(mySet4);

	stop;


	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset 
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	pair<const char*, int> pr1("Иванова", 20000);

	map<const char*, int , Case> mp;
	// 3 способа заполнения
	mp.insert(pr1);
	mp.insert(pair<const char*, int>("Сидоров", 15000));
	mp[ "Петров" ] = 40000;

	PrintMap(mp);
	stop;
	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	const char* temp1 = "Иванова";
	const char* temp2 = "Петрова";
	//changeKeyName(mp, "Иванова","Петрова");		// не работает 
	changeKeyName(mp, temp1, temp2);

	stop;



	//д) Сформируйте любым способом вектор с элементами типа string.
	//Создайте (и распечатайте для проверки) map<string, int>, который будет
	//содержать упорядоченные по алфавиту строки и
	//количество повторений каждой строки в векторе
	// Пример:  map -> ключ/значение ->  "Green"  2

	vector<string> vString = { "Green", "Yellow", "Blue", "Pink", "Black","Green" };
	map<string, int> mp2;
	vector<string>::iterator iter1 = vString.begin(), iter2 = vString.end();		// итераторы
	while ( iter1 != iter2 )
	{
		mp2[ *iter1 ]++;			// если нет в Map объекта, создает "Green" - значение 0....."Yellow" = 0 ....."Blue" 0
									//  и возвращает адрес на значение, далее мы делаем ++
									//  и Pair становится  -  "Green"  1
									// после нахождения второй похожей строки Pair становится  -  "Green" = 2
		++iter1;
	}
	PrintAll(mp2);
	stop;


	//е) 
	//задан массив:
	const char* words[] = {"Abba", "Alfa", "Beta", "Beauty"};
	//создайте map, в котором каждой букве будет соответствовать совокупность 
	//лексиграфически упорядоченных слов, начинающихся с этой буквы.
	//Подсказка: не стоит хранить дубли одной и той же строки
	
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
		//...
	map<char, set<string>> mp3;
	for ( size_t i = 0; i < sizeof(words) / sizeof(words[0]); i++ )
	{
		mp3[ words[ i ][ 0 ] ].insert(words[ i ]);	//T& operator[]( const Key& key );
													// Возвращает ссылку на значение, которое сопоставлено с ключом, эквивалентным ключу, 
													// выполняя вставку, если такой ключ еще не существует.
													// и insert  добавляет значение в .second
	}
	
	PrintAll(mp3);


	//ж)
	//создайте структуру данных, которая будет хранить информацию о студенческих группах.
	//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
	//фамилии могут дублироваться
	//Сами группы тоже должны быть упорядочены по номеру
	//
	//номера 
	const char* words2[] = { "Ivanov", "Petrov", "Ivanov", "Petrov", "Grechkin", "Holol", "Abdulov", "Bregin" };
	map<size_t, multiset<string>> mp4;

	for ( size_t i = 1; i < (sizeof(words2) / sizeof(words2[ 0 ]) + 1); i++ )
	{
		mp3[ i ].insert(words2[ i ]);				//T& operator[]( const Key& key );
													// Возвращает ссылку на значение, которое сопоставлено с ключом, эквивалентным ключу, 
													// выполняя вставку, если такой ключ еще не существует.
													// и insert  добавляет значение в .second
	}
	PrintAll(mp4);
	stop;

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	std::pair <std::string, std::string> p1 = make_pair("attitude", "отношение");
	std::pair <std::string, std::string> p2 = make_pair("attitude", "позиция");
	std::pair <std::string, std::string> p3 = make_pair("order", "порядок");
	std::pair <std::string, std::string> p4 = make_pair("order", "заказ");
	std::pair <std::string, std::string> p5 = make_pair("order", "приказ");
	std::pair <std::string, std::string> p6 = make_pair("denote", "означать");
	std::pair <std::string, std::string> p7 = make_pair("denote", "указывать");

	std::multimap<std::string, std::string> mMap;
	mMap.insert(p1);
	mMap.insert(p2);
	mMap.insert(p3);
	mMap.insert(p4);
	mMap.insert(p5);
	mMap.insert(p6);
	mMap.insert(p7);

	PrintAll(mMap);
	string word = "order";
	myTranslater(mMap, word);
   

  stop

	return 0;
}

