#pragma once

#include <fstream>
#include <string>
#include <exception>

using namespace std;

template <typename T>
class FileException
{
public:
	void load(T& file, string path);
};

template <typename T>
void FileException<T>::load(T& file, string path)
{
	file.open(path);
	file.exceptions(T::failbit);

	if (!file.is_open())
		throw exception{};
}