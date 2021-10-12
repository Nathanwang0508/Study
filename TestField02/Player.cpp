#include<iostream>
#include<string>

using namespace std;
class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}
	String(const String& other)
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size);
		m_Buffer[m_Size] = 0;
		m_Buffer[1] = 'O';
	}
	~String()
	{
	delete[] m_Buffer;
	std::cout << "buffer deleted!" << std::endl;
	}
	friend ostream& operator<<(ostream& stream, const String& string);
};
ostream& operator<<(ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}
int main()
{
	{
		String string("NATHAN");
		String string02(string);
		std::cout << string << std::endl;
		std::cout << string02 << std::endl;
	}
	std::cin.get();
}