#include <iostream>
#include <map>
#include <string>
#include <list>
#include <Windows.h>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

const std::map<int, std::string>& crimes =
{
std::pair<int, std::string>(1, "���������� ��������"),
std::pair<int, std::string>(2, "������ �� �������"),
std::pair<int, std::string>(3, "�������� � ������������ �����"),
std::pair<int, std::string>(4, "����������� �������"),
std::pair<int, std::string>(5, "����������� �������� �����")
};

class Crime
{
	std::string crime;
	std::string place;
public:
	const std::string& get_crime()const
	{
		return crime;
	}
	const std::string& get_place()const
	{
		return crime;
	}
	Crime(){}
	Crime(const std::string& crime, const std::string& place)
	{
		this->crime = crime;
		this->place = place;
	}
	~Crime()
	{

	}
	std::ostream& print(std::ostream& os)const
	{
		return os << crime << ", " << place;
	}
	std::istream& scan(std::istream& is)
	{
		is.ignore(); //���������� 1 ������ �� ������ �����(� ������ ������ "\n").
		std::getline(is, crime, ',');
		std::getline(is, place);
		return is;
	}
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return obj.print(os);
}
std::istream& operator>>(std::istream& is, Crime& obj)
{
	return obj.scan(is);
}

void print(const std::map<std::string, std::list<Crime>>& base);

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::list<Crime>> base =
	{
		std::pair<std::string, std::list<Crime>>("m777ko", std::list<Crime>{Crime("���������� ��������", "����� ������"),Crime("������ �� �������", "����� �����������")}),
		std::pair<std::string, std::list<Crime>>("b510ma", std::list<Crime>{Crime("�������� � ������������ �����", "�� �������")}),
		std::pair<std::string, std::list<Crime>>("a213bb", std::list<Crime>{Crime("����������� �������", "������� �������")})
	};
	/*for (std::list<Crime>::iterator it = base["m777ko"].begin(); it != base["m777ko"].end(); ++it)
	{
		cout << *it << endl;
	}*/

	std::string licence_plate;
	Crime crime;
	cout << "������� ����� ����������: "; cin >> licence_plate;
	cout << "������� ��������������: "; cin >> crime;
	base[licence_plate].push_back(crime);

	print(base);
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n";
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			cout << *l_it << endl;
		}
	}
}