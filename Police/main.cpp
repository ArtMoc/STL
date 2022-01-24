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
std::pair<int, std::string>(1, "Превышение скорости"),
std::pair<int, std::string>(2, "Проезд на красный"),
std::pair<int, std::string>(3, "Парковка в неположенном месте"),
std::pair<int, std::string>(4, "Оскорбление офицера"),
std::pair<int, std::string>(5, "Пересечение сплошной линии")
};

class Crime
{
	int crime_id;
	std::string place;
public:
	int get_crime()const
	{
		return crime_id;
	}
	const std::string& get_place()const
	{
		return place;
	}
	Crime(){}
	Crime(int crime_id, const std::string& place)
	{
		this->crime_id = crime_id;
		this->place = place;
	}
	~Crime()
	{

	}
	std::ostream& print(std::ostream& os)const
	{
		return os << crimes.at(crime_id) << ", " << place;
	}
	std::istream& scan(std::istream& is)
	{
		is.ignore(); //Игнорирует 1 символ из буфера ввода(в данном случае "\n").
		//std::getline(is, crime_id, ',');
		cin >> crime_id;
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
		std::pair<std::string, std::list<Crime>>("m777ko", std::list<Crime>{Crime(1, "улица Ленина"),Crime(2, "улица Октябрьская")}),
		std::pair<std::string, std::list<Crime>>("b510ma", std::list<Crime>{Crime(3, "ТЦ Экватор")}),
		std::pair<std::string, std::list<Crime>>("a213bb", std::list<Crime>{Crime(4, "Красная площадь")})
	};

	/*for (std::list<Crime>::iterator it = base["m777ko"].begin(); it != base["m777ko"].end(); ++it)
	{
		cout << *it << endl;
	}*/

	std::string licence_plate;
	Crime crime;
	cout << "Введите номер автомобиля: "; cin >> licence_plate;
	cout << "Введите правонарушение: "; cin >> crime;
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