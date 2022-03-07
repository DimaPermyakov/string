// Copyright 2022 Dmitriy <dimapermyakov55@gmail.com>
#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include <cstddef>
#include <iostream>


class String {
public:
	~String();
	String();
	String(const String& rhs);
	String(const char* data);
	size_t Find(const String& substr) const;
	size_t Find(const char* substr) const;
	void Replace(char oldSymbol, char newSymbol);
	size_t Size() const;
	bool Empty() const;
	void RTrim(char symbol);
	void LTrim(char symbol);
	void swap(String& oth);
	String& operator=(const String& rhs);
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	String& operator*=(unsigned int m);
	bool operator==(const String& rhs) const;
	bool operator==(const char* rhs) const;
	bool operator<(const String& rhs) const;
	char operator[](size_t index) const;
	char& operator[](size_t index);
	friend std::ostream& operator<<(std::ostream&, const String&);

private:
	char* Data{};
};
String operator+(const String& a, const String& b);
String operator+(const String& a, const char* b);
String operator*(const String& a, unsigned int b);
bool operator!=(const String& a, const String& b);
bool operator!=(const String& a, const char* b);
bool operator>(const String& a, const String& b);
std::ostream& operator<<(std::ostream& out, const String& str);

bool operator==(const char* str1, const String& rhs);

#endif  // INCLUDE_STRING_HPP_
