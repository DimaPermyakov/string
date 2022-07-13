// Copyright 2022 Dmitriy <dimapermyakov55@gmail.com>
#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>

class String {
public:
	/// ����������
	~String();

	/// ����������� �� ���������
	String();

	/// ����������� �����������
	/// <param name="rhs">������, ������� �������� </param>
	String(const String& rhs);
	explicit String(const size_t& StrSize);
	/// ���������������� �����������
	/// <param name="data">������, ������� ��������� ��������� � �����������
	/// ������ </param>
	explicit String(const char* data);

	/// �������� ������������
	/// <param name="data">������, ������� �������� </param>
	/// <returns>���������� ������ �� ����</returns>
	String& operator=(const String& rhs);
	/// �������� +=
	/// <param name="rhs">������, ������� ����� ����� ����� '+=' </param>
	/// <returns>���������� ������ �� ����</returns>
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);

	/// �������� *=
	/// <returns>���������� ������ �� ����</returns>
	String& operator*=(unsigned int m);

	/// �������� ==
	/// <param name="rhs">������, ������� ����� ����� ����� '==' </param>
	/// <returns>���������� �������� ��������� ���� �����</returns>
	bool operator==(const String& rhs) const;
	bool operator==(const char* rhs) const;

	/// �������� &lt;
	/// <param name="rhs">������, ������� ����� ����� ����� "&lt;" </param>
	/// <returns>���������� �������� ��������� ���� �����</returns>
	bool operator<(const String& rhs) const;

	/// ������� ������ ���������
	/// <param name="substr">���������, ������� ���������� ����� </param>
	/// <returns>���������� ������� substr. ���� ��������� �� �������, ��
	/// ���������� -1</returns>
	size_t Find(const String& substr) const;
	size_t Find(const char* substr) const;

	/// ������� ������ ��������, �������� ��� ������� oldSymbol �� newSymbol.
	/// <param name="oldSymbol">������, ������� ��������� �������� </param>
	/// <param name="newSymbol">������, �� ������� ��������� �������� </param>
	void Replace(char oldSymbol, char newSymbol);

	/// ������� ���������� ����� ������
	/// <returns>���������� ����� ������</returns>
	size_t Size() const;

	/// ������� ��� ����������� ����� �� ������
	bool Empty() const;

	/// �������� []
	/// <example>
	/// <code>
	/// String str = "some string";
	/// char symbol = str[2]; // symbol == 'm'
	/// </code>
	/// </example>
	/// <param name="index"> ������ ������� </param>
	/// <returns> �������� ������� � ������ � �������� index</returns>
	char operator[](size_t index) const;

	/// �������� []
	/// <example>
	/// <code>
	/// String str = "some string";
	/// str[0] = 'S'; // ������ ���������� str ����� "Some string"
	/// </code>
	/// </example>
	/// <param name="index"> ������ ������� </param>
	/// <returns> ������ �� ������ � ������ � �������� index</returns>
	char& operator[](size_t index);

	/// ������ ������
	/// <example>
	/// <code>
	/// String str = "___some string___";
	/// str.RTrim('_'); // ������ ���������� str ����� "___some string"
	/// </code>
	/// </example>
	/// <param name="symbol"> �������� ��������, ������ �������� </param>
	void RTrim(char symbol);

	/// ������ ������
	/// <example>
	/// <code>
	/// String str = "___some string___";
	/// str.LTrim('_'); // ������ ���������� str ����� "some string___"
	/// </code>
	/// </example>
	/// <param name="symbol"> �������� ��������, ������ �������� </param>
	void LTrim(char symbol);

	void swap(String& oth);

	friend std::ostream& operator<<(std::ostream&, const String&);

private:
	char* Data{};
};

/// �������� +
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c ����� "HelloWorld"
/// </code>
/// </example>
/// <returns>���������� ������ ������ a + b</returns>
String operator+(const String& a, const String& b);
String operator+(const String& a, const char* b);

/// �������� +
/// <example>
/// <code>
/// String a = "A";
/// String c = a * 5; // c ����� "AAAAA"
/// </code>
/// </example>
String operator*(const String& a, unsigned int b);

/// �������� !=
bool operator!=(const String& a, const String& b);
bool operator!=(const String& a, const char* b);
bool operator!=(const char* str1, const String& rhs);

/// �������� &gt;
bool operator>(const String& a, const String& b);

/// �������� ������
/// <param name="out">����� ���� ������� ������ </param>
/// <param name="str">������, ������� ������� </param>
/// <returns>���������� ������ �� �����</returns>
std::ostream& operator<<(std::ostream& out, const String& str);

bool operator==(const char* str1, const String& rhs);

#endif  // INCLUDE_STRING_HPP_
