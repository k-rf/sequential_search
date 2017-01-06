#ifndef ___BM_SEARCH_H
#define ___BM_SEARCH_H

#include <iostream>
#include <string>
#include <vector>



// skip�֐��̐����ɗ��p
class SkipTable
{
	char key;
	int value;

public:
	SkipTable(char _key = '\0', int _value = 1)
		: key(_key), value(_value) {}

	char getKey() const { return key; }
	int getValue() const { return value; }

	void setKey(char _key) { key = _key; }
	void setValue(int _value) { value = _value; }

	friend std::ostream& operator<<(std::ostream& os, const SkipTable& x);
};


// BM�@
// �ƍ��񐔂�Ԃ�
int bmSearch(const std::string& text, const std::string& keyword);

// ���������e�[�u����Ԃ�
// ���ӁF�e�[�u���̍Ō��key:'?'�Cvalue:keyword.length()���i�[���Ă���D
std::vector<SkipTable> generateSkipTable(const std::string& keyword);

// �X�L�b�v���鐔��Ԃ�
int skip(const char& c, const std::vector<SkipTable>& st);

std::ostream& operator<<(std::ostream& os, const SkipTable& x);

#endif
