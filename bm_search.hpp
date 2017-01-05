#ifndef ___BM_SEARCH_HPP
#define ___BM_SEARCH_HPP

#include <iostream>
#include <string>
#include <vector>



// skip�֐��̐����ɗ��p
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


// BM�@
// �ƍ��񐔂�Ԃ�
int bmSearch(const std::string& text, const std::string& keyword);

extern std::vector<HashTable> skip_table;
void generateSkipTable(const std::string& keyword);

// �X�L�b�v���鐔��Ԃ�
int skip(const char& c);

std::ostream& operator<<(std::ostream& os, const HashTable& x);

#endif
