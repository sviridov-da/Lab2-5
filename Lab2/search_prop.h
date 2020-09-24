#pragma once
#include <string>
#include "computer_model.h"
using namespace std;

class search_prop
{
private:
public:
	string processor_type;
	unsigned short int ram_size;
	unsigned short int hard_disk_space;
	unsigned short int video_card_memory;
	search_prop(string processor_type, unsigned short int ram_size,
		unsigned short int hard_disk_space, unsigned short int video_card_memory) :
		processor_type(processor_type), ram_size(ram_size), hard_disk_space(hard_disk_space),
		video_card_memory(video_card_memory) {}
	search_prop() :
		processor_type(""), ram_size(0), hard_disk_space(0),
		video_card_memory(0) {}

	void fill_from_file(istream& current_stream)
	{
		current_stream >> processor_type;
		current_stream >> ram_size;
		current_stream >> hard_disk_space;
		current_stream >> video_card_memory;
	}

	void fill_from_console(istream& current_stream)
	{
		cout << "Enter processor type: ";
		current_stream >> this->processor_type;
		cout << "Enter RAM size: ";
		current_stream >> this->ram_size;
		cout << "Enter hard disk space: ";
		current_stream >> this->hard_disk_space;
		cout << "Enter videocard memory: ";
		current_stream >> this->video_card_memory;

	}

	friend  istream& operator>>(istream& is, search_prop& prop)
	{
		if (typeid(is) == typeid(ifstream))
		{
			prop.fill_from_file(is);
		}
		else
		{
			prop.fill_from_console(is);
		}
		return is;
		/*cout << "Processor type: ";
		is >> prop.processor_type;
		cout << "RAM size: ";
		is >> prop.ram_size;
		cout << "Hard disk spaCE: ";
		is >> prop.hard_disk_space;
		cout << "Videocard memory: ";
		is >> prop.video_card_memory;
		return is;*/
	}

};

