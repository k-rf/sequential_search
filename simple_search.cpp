#include "simple_search.h"

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// Simple Search
// 照合回数を返す．
// ============================================================================
int simpleSearch(const string& text, const string& keyword)
{
	int m = text.length();
	int n = keyword.length();

	int check_times = 0;
	int match_count = 0;

	for(int i = 0; i < m - n + 1; i++)
	{
		for(int j = 0; j < n; j++)
		{
			++check_times;
			if(text[i + j] == keyword[j]);
			else break;

			if(j == n - 1) { match_count++; }
		}
	}

	//cout << "\rmatch count of simple search : " << match_count;

	return check_times;
}
