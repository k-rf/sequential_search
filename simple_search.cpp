#include "simple_search.hpp"

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// Simple Search
// Æ‡‰ñ”‚ğ•Ô‚·D
// ============================================================================
int simpleSearch(const string& text, const string& keyword)
{
	int m = text.length();
	int n = keyword.length();

	int check_times = 0;

	for(int i = 0; i < m - n + 1; i++)
	{
		for(int j = 0; j < n; j++)
		{
			++check_times;
			if(text[i + j] == keyword[j]);
			else break;
		}
	}

	return check_times;
}
