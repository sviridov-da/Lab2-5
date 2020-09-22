/*Вариант 5. Модель компьютера характеризуется кодом и названием марки компьютера, типом
процессора, частотой работы процессора, объемом оперативной памяти, объемом
жесткого диска, объемом памяти видеокарты, стоимостью компьютера и
количеством экземпляров. Поиск по типу процессора, объему ОЗУ, памяти
видеокарты и объему жесткого диска.*/
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "search_prop.h"
using namespace std;

class computer_model
{

public:
	int code;
	string brand_name;
	string processor_type;
	unsigned short int ram_size;
	unsigned short int hard_disk_space;
	unsigned short int video_card_memory;
	float computer_cost;
	unsigned short int count_of_computers;

	computer_model(int code, string brand_name, string processor_type,
					unsigned short int ram_size, unsigned short int hard_disk_space,
					unsigned short int video_card_memory, float computer_cost, 
					unsigned short int count_of_computers) :
					code(code), brand_name(brand_name), processor_type(processor_type),
					ram_size(ram_size), hard_disk_space(hard_disk_space), video_card_memory(video_card_memory),
					computer_cost(computer_cost), count_of_computers(count_of_computers){}

	computer_model() :code(0), brand_name(""), processor_type(""),
					ram_size(0), hard_disk_space(0), video_card_memory(0),
					computer_cost(0), count_of_computers(0) {}

	

	void print_to_console(ostream& current_stream)
	{
		current_stream << "********\n"
			<< "Computer code: " << this->code << '\n'
			<< "Brand name: " << this->brand_name << '\n'
			<< "Processor type: " << this->processor_type << '\n'
			<< "RAM size: " << this->ram_size << '\n'
			<< "Hard disk space: " << this->hard_disk_space << '\n'
			<< "Videocard memory: " << this->video_card_memory << '\n'
			<< "Cost: " << this->computer_cost << '\n'
			<< "Count: " << this->count_of_computers << '\n';
	}

	void print_to_file(ostream& current_stream)
	{
		current_stream
			<< this->code << '\n'
			<< this->brand_name << '\n'
			<< this->processor_type << '\n'
			<< this->ram_size << '\n'
			<< this->hard_disk_space << '\n'
			<< this->video_card_memory << '\n'
			<< this->computer_cost << '\n'
			<< this->count_of_computers << '\n';
	}


	friend ostream& operator<<(ostream& current_stream, computer_model computer)
	{
		if (typeid(current_stream) == typeid(ofstream))
		{
			computer.print_to_file(current_stream);
		}
		else
		{
			computer.print_to_console(current_stream);
		}
		return current_stream;
	}

	void fill_from_console(istream& current_stream)
	{
		cout << "Enter code: ";
		current_stream >> this->code;
		cout << "Enter brand: ";
		current_stream >> this->brand_name;
		cout << "Enter processor type: ";
		current_stream >> this->processor_type;
		cout << "Enter RAM size: ";
		current_stream >> this->ram_size;
		cout << "Enter hard disk space: ";
		current_stream >> this->hard_disk_space;
		cout << "Enter videocard memory: ";
		current_stream >> this->video_card_memory;
		cout << "Enter cost: ";
		current_stream >> this->computer_cost;
		cout << "Enter count: ";
		current_stream >> this->count_of_computers;
	}
	void fill_from_file(istream& current_stream)
	{
		current_stream >> this->code;
		current_stream >> this->brand_name;
		current_stream >> this->processor_type;
		current_stream >> this->ram_size;
		current_stream >> this->hard_disk_space;
		current_stream >> this->video_card_memory;
		current_stream >> this->computer_cost;
		current_stream >> this->count_of_computers;
	}

	friend istream& operator>>(istream& current_stream, computer_model& computer)
	{
		if (typeid(current_stream) == typeid(ifstream))
		{
			computer.fill_from_file(current_stream);
		}
		else
		{
			computer.fill_from_console(current_stream);
		}
		return current_stream;
	}

	friend bool operator==(const computer_model& comp1, const computer_model& comp2)
	{
		return
			comp1.hard_disk_space == comp2.hard_disk_space &&
			comp1.processor_type == comp2.processor_type &&
			comp1.ram_size == comp2.ram_size &&
			comp1.video_card_memory == comp2.video_card_memory;	
	}

	friend bool operator!=(const computer_model& comp1, const computer_model& comp2)
	{
		return !(comp1 == comp2);
	}

	friend bool operator>(const computer_model& comp1, const computer_model& comp2)
	{
		if (comp1==comp2) return false;
		else
		{
			if (comp1.processor_type != comp2.processor_type)
				return comp1.processor_type > comp2.processor_type;
			if (comp1.ram_size != comp2.ram_size)
				return comp1.ram_size > comp2.ram_size;
			if (comp1.video_card_memory != comp2.video_card_memory)
				return comp1.video_card_memory > comp2.video_card_memory;
			if (comp1.hard_disk_space != comp2.hard_disk_space)
				return comp1.hard_disk_space > comp2.hard_disk_space;
		}
	}

	friend bool operator>=(const computer_model& comp1, const computer_model& comp2)
	{
		return comp1 > comp2 || comp1 == comp2;
	}

	friend bool operator<=(const computer_model& comp1, const computer_model& comp2)
	{
		return !(comp1 > comp2);
	}

	friend bool operator<(const computer_model& comp1, const computer_model& comp2)
	{
		return !(comp1 >= comp2);
	}

	
};

