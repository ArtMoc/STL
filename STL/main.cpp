#include <iostream>
#include <array>
#include <vector>
#include<deque>
#include <forward_list>
#include<list>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_LIST_1
//#define STL_LIST_2
//#define FORWARD_LIST

template<typename T>
void print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY


#ifdef STL_VECTOR
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232, };
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //���� ������ � �������
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << " byte" << endl;

	int* data = vec.data();
	vec.push_back(55);
	data = vec.data();
	vec.push_back(89);

	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			//cout << *(data + i) << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
		//subscript - ��������������
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}

	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //���� ������ � �������
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << " byte" << endl;


	/*vector<vector<int>> vec2;
	cout << "Size:     " << vec2.size() << endl;
	cout << "Capacity: " << vec2.capacity() << endl; //���� ������ � �������
	cout << "MaxSize:  " << vec2.max_size() << endl;
	cout << sizeof(vec2) << " byte" << endl;*/


	int index;
	int value;
	int count;
	cout << "������� ������ ������������ ��������:\t";cin >> index;
	cout << "������� ���������� ����������:\t\t";cin >> count;
	cout << "������� �������� ������������ ��������:\t";cin >> value;
	//                      insert(position, count, value)
	if (index < vec.size())vec.insert(vec.begin() + index, count, value);
	else cout << "Error: out of range" << endl;
	print(vec);

	std::vector<int>powers = { 1024,2048,4096,8192,16384 };

	//vec.insert(vec.begin() + 4, powers.begin(), powers.end());
	vec.insert(vec.begin() + 8, { 256, 384, 512, 768 });
	for (int i : vec)cout << i << tab;cout << endl;

	/*vec.insert(vec.begin() + 4, vec.begin()+15, vec.begin()+17);
	for (int i:vec)cout << i << tab;cout << endl;*/

	cout << "������� ������ ���������� ��������:\t";cin >> index;
	cout << "������� ���������� ��������:\t\t";cin >> count;
	vec.erase(vec.begin() + index, vec.begin() + index + count);
	print(vec);

	cout << "\n--------------------------------------------\n";
	vec.swap(powers);
	print(vec);
	print(powers);

#endif // STL_VECTOR


#ifdef STL_DEQUE
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout << endl;

	std::deque<int> d_powers = { 256,512,768 };
	//deque.push_back(*(d_powers.begin() + 1));
	for (int i : deque)cout << i << tab;cout << endl;
	for (int i : d_powers)cout << i << tab;cout << endl;
#endif // STL_DEQUE

#ifdef STL_LIST_1
	std::list<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;
	int index;
	int value;
	int count;
	do
	{
		cout << "������� ������ ������������ ��������: "; cin >> index;
		if (index > list.size())cout << "������� ������ ��������\n";
	} while (index > list.size());
	cout << "������� ���������� ����������: "; cin >> count;
	cout << "������� ����������� ��������: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)position++;
	list.insert(position, count, value);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST_1

#ifdef STL_LIST_2
	std::list<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;
	int index;
	do
	{
		cout << "������� ������ ���������� ��������: "; cin >> index;
		if (index >= list.size())cout << "������� ������ ��������\n";
	} while (index >= list.size());
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)position++;
	list.erase(position);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST_2



#ifdef FORWARD_LIST
	std::forward_list<int> list = { 3,5,8,13,21 };
	list.push_front(123);
	/*std::forward_list<int>::iterator it = list.begin();
	for(int i = 0; i < list.)*/
	//list.insert_after(list.end(), 1024);
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	list.reverse();
	list.push_front(1024);
	list.reverse();
	for (int i : list)cout << i << tab; cout << endl;

	std::list<int> list2;

	cout << "Forward_List max size:\t" << list.max_size() << endl;
	cout << "List max size:\t\t" << list2.max_size() << endl;
#endif // FORWARD_LIST


}