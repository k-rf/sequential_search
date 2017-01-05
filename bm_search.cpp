#include "sequential_search.hpp"
#include "bm_search.hpp"

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// BM法
// 照合回数を返す
// ============================================================================
int bmSearch(const string& text, const string& keyword)
{
	int m = text.length();
	int n = keyword.length();

	int check_pos = n - 1;
	int check_times = 0;

	for(int i = check_pos; i < m; i += skip(text[i]))
	{
		for(int j = n - 1; j >= 0; j--)
		{
			++check_times;
			if(text[i + j - n + 1] == keyword[j]);
			else break;
		}
	}

	return check_times;
}


vector<HashTable> skip_table;

void generateSkipTable(const string& keyword)
{
	skip_table.push_back(HashTable(*(keyword.rbegin() + 1), 1));

	for(string::const_reverse_iterator rsitr = keyword.rbegin() + 2; 
		rsitr != keyword.rend(); rsitr++)
	{
		vector<HashTable>::iterator end = skip_table.end();
		for(int i = 0; i < skip_table.size(); i++)
		{
			if(*rsitr == skip_table[i].getKey()) { break; }
			else
			{
				if(skip_table.size() - i == 1)
				{
					skip_table.emplace_back(HashTable(*rsitr, static_cast<int>(rsitr - keyword.rbegin())));
				}
			}
		}
	}
}

// ============================================================================
// スキップする数を返す
// ============================================================================
int skip(const char& c)
{
	if(skip_table.size() == 0) { return 1; }
	
	for(vector<HashTable>::iterator itr = skip_table.begin();
		itr != skip_table.end(); itr++)
	{
		if(c == itr->getKey()) { return itr->getValue(); }
	}
	return key_length;
}


ostream& operator<<(ostream& os, const HashTable& x)
{
	return os << "key: " << x.getKey() << " value: " << x.getValue();
}

