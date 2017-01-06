#include "bm_search.h"

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// BM法
// 照合回数を返す
// ============================================================================
int bmSearch(const string& text, const string& keyword)
{
	vector<SkipTable> skip_table = generateSkipTable(keyword);

	int m = text.length();
	int n = keyword.length();

	int check_pos = n - 1;
	int check_times = 0;
	int match_count = 0;

	for(int i = check_pos; i < m; i += skip(text[i], skip_table))
	{
		for(int j = n - 1; j >= 0; j--)
		{
			++check_times;
			if(text[i + j - n + 1] == keyword[j]);
			else break;

			if(j == 0) { match_count++; }
		}
	}
	
	//cout << "\rmatch count of BM search :     " << match_count;

	return check_times;
}


// ============================================================================
// 生成したテーブルを返す
// 注意：テーブルの最後にkey:'?'，value:keyword.length()を格納している．
// ============================================================================
vector<SkipTable> generateSkipTable(const string& keyword)
{
	if(keyword.length() == 0) { return vector<SkipTable>(); }

	vector<SkipTable> st;
	st.push_back(SkipTable(*(keyword.rbegin() + 1), 1));

	for(string::const_reverse_iterator rsitr = keyword.rbegin() + 2;
		rsitr != keyword.rend(); rsitr++)
	{
		vector<SkipTable>::iterator end = st.end();
		for(int i = 0; i < st.size(); i++)
		{
			if(*rsitr == st[i].getKey()) { break; }
			else if(st.size() - i == 1)
			{
				st.emplace_back(SkipTable(*rsitr, static_cast<int>(rsitr - keyword.rbegin())));
			}
		}
	}
	st.emplace_back(SkipTable('?', keyword.length()));
	return st;
}

// ============================================================================
// スキップする数を返す
// ============================================================================
int skip(const char& c, const vector<SkipTable>& st)
{
	if(st.size() == 0) { return 1; }
	
	for(vector<SkipTable>::const_iterator itr = st.begin();
		itr != st.end(); itr++)
	{
		if(c == itr->getKey()) { return itr->getValue(); }
		if(st.end() - itr == 1) { return itr->getValue(); }
	}
}


ostream& operator<<(ostream& os, const SkipTable& x)
{
	return os << "key: " << x.getKey() << " value: " << x.getValue();
}

