#ifndef ___BM_SEARCH_H
#define ___BM_SEARCH_H

#include <iostream>
#include <string>
#include <vector>



// skip関数の生成に利用
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


// BM法
// 照合回数を返す
int bmSearch(const std::string& text, const std::string& keyword);

// 生成したテーブルを返す
// 注意：テーブルの最後にkey:'?'，value:keyword.length()を格納している．
std::vector<SkipTable> generateSkipTable(const std::string& keyword);

// スキップする数を返す
int skip(const char& c, const std::vector<SkipTable>& st);

std::ostream& operator<<(std::ostream& os, const SkipTable& x);

#endif
