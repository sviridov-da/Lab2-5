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

	typename list<T>::iterator binary_search(const T& value)
	{
		typename list<T>::iterator result = lower_bound(data.begin(), data.end(), value, [](const T& el1, const T& el2) {return el1 <= el2;  });
		if (*result == value)
			return result;
		return data.end();
	}

	typename list<T>::iterator linear_search(const T& value)
	{
		return find(data.begin(), data.end(), value);
	}

public:
	data_storage() : data() {}
	~data_storage()
	{
		
	}
	typename list<T>::iterator get_begin() { return data.begin(); }
	typename list<T>::iterator get_end() { return data.end(); }
	void Add(T value) { data.push_back(value); }
	void Delete(typename list<T>::iterator element) { data.erase(element); }
	void Change(typename list<T>::iterator element) { cin >> *element; }
	void sort()
	{
		data.sort();
	}
	typename list<T>::iterator search(const T& value, string type = "lin")
	{
		if (type == "lin")
			return linear_search(value);
		else
			return binary_search(value);
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


