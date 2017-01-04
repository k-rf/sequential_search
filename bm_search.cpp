#include "bm_search.hpp"

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// BM�@
// �ƍ��񐔂�Ԃ�
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

// ============================================================================
// �X�L�b�v�֐�
// �X�L�b�v���鐔��Ԃ�
// ============================================================================
int skip(const char& c)
{

