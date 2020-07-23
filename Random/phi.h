#pragma once

namespace Phi
{
	class String
	{
	public:
		String();
		String(const char* string);
		String(const String& OldString);
		const unsigned int size();
		void reverse();
		const char& front();
		const char& back();
		bool empty();
		// Operator overloads
		char& operator[](unsigned int index);
		void operator=(const String& OldString);
		friend std::ostream& operator<<(std::ostream& stream, const Phi::String& string);
		~String();
	private:
		char* _buffer;
		unsigned int _size;
	};
};