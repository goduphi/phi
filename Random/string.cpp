#include <iostream>
#include "phi.h"

Phi::String::String() : _size{ 0 }
{
	std::cout << "Creating string of size " << this->_size << std::endl;
	this->_buffer = nullptr;
}
Phi::String::String(const char* string)
{
	std::cout << "Creating string..." << std::endl;
	this->_size = strlen(string);
	// Reserve a space for the null terminator '\0'
	this->_buffer = new char[this->_size + 1];
	memset(this->_buffer, 0, _size + 1);
	memcpy(this->_buffer, string, this->_size);
}
Phi::String::String(const Phi::String& OldString)
	: _size{ OldString._size }
{
	std::cout << "Copying string..." << std::endl;
	this->_buffer = new char[this->_size + 1];
	memset(this->_buffer, 0, _size + 1);
	memcpy(this->_buffer, OldString._buffer, this->_size);
}
const unsigned int Phi::String::size()
{
	return this->_size;
}
void Phi::String::reverse()
{
	int l = 0, r = this->_size - 1;
	while (l < r)
	{
		std::swap(this->_buffer[l], this->_buffer[r]);
		l++;
		r--;
	}
}
const char& Phi::String::front()
{
	return this->_buffer[0];
}
const char& Phi::String::back()
{
	return this->_buffer[this->_size - 1];
}
bool Phi::String::empty()
{
	return this->_size > 0;
}
// Operator overloads
char& Phi::String::operator[](unsigned int index)
{
	if (index < 0 || index > this->_size - 1)
		throw "Index out of bounds";
	return this->_buffer[index];
}
void Phi::String::operator=(const Phi::String& OldString)
{
	this->_size = OldString._size;
	this->_buffer = new char[this->_size + 1];
	memset(this->_buffer, 0, _size + 1);
	memcpy(this->_buffer, OldString._buffer, this->_size);
}
std::ostream& Phi::operator<<(std::ostream& stream, const Phi::String& string)
{
	stream << string._buffer;
	return stream;
}
Phi::String::~String()
{
	std::cout << "Destroying string..." << std::endl;
	delete[] this->_buffer;
}