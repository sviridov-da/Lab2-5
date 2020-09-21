#pragma once
#include <list>
#include<iostream>
#include <iterator>
#include <fstream>

using namespace std;
template<class T>
class data_storage
{
private:
	list<T> data;

	typename list<T>::iterator binary_search()
	{

	}

	typename list<T>::iterator linear_search()
	{

	}

public:
	data_storage() : data() {}

	void Add(T value) { data.push_back(value); }
	void Delete(typename list<T>::iterator element) { data.erase(element); }
	void Change(typename list<T>::iterator element) { cin >> *element; }
	void sort()
	{
		data.sort();
	}
	typename list<T>::iterator search(string type = "lin")
	{
		if (type == "lin")
			return linear_search();
		else if (type == "bin")
			return binary_search();
	}






	friend ostream& operator<<(ostream& os, const data_storage& data)
	{
		copy(data.data.begin(), data.data.end(), ostream_iterator<T>(os, ""));

		return os;
	}

	friend istream& operator>>(istream& current_stream, data_storage& data)
	{
		if(typeid(current_stream) == typeid(ifstream))
			copy(istream_iterator<T>(current_stream), istream_iterator<T>(), inserter(data.data, data.data.end()));
		else
			data.Add(*istream_iterator<T>(current_stream));
		return current_stream;
	}


};


