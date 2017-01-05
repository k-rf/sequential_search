#ifndef ___BM_SEARCH_HPP
#define ___BM_SEARCH_HPP

#include <iostream>
#include <string>
#include <vector>



// skip関数の生成に利用
class HashTable
{
	char key;
	int value;

public:
	HashTable(char _key = '\0', int _value = 1)
		: key(_key), value(_value) {}

	char getKey() const { return key; }
	int getValue() const { return value; }

	void setKey(char _key) { key = _key; }
	void setValue(int _value) { value = _value; }

	friend std::ostream& operator<<(std::ostream& os, const HashTable& x);
};


// BM法
// 照合回数を返す
int bmSearch(const std::string& text, const std::string& keyword);

extern std::vector<HashTable> skip_table;
void generateSkipTable(const std::string& keyword);

// スキップする数を返す
int skip(const char& c);

std::ostream& operator<<(std::ostream& os, const HashTable& x);

#endif
