// ============================================================================
// �����FSimple Search��BM�@�̏ƍ��񐔂̔�r
// 
// �����T�v�F
// �@�P�D�e�L�X�g(50����)�ƃL�[���[�h(10����)�������_�������D
// �@�Q�DSimple Search��BM�@���s���D
// �@�R�D�e�L�X�g��50�����������ă����_���ɐ�������D
// �@�S�D�e�L�X�g��10,000�����ɂȂ�܂łQ�D�R�D���J��Ԃ��D
// �@�T�D�e�L�X�g�T�C�Y�������C�ƍ��񐔂��c���Ƃ���O���t���쐬����D
//
// ���ӁF�X���C�h�ł͏c�����ƍ����ԂƂ��Ă������C�ƍ����Ԃ͌v�Z�@�Ɉˑ����邽�߁C
// �@�@�@�v�Z�@�Ɉˑ����邱�ƂȂ��ƍ����Ԃ̎w�W�ƂȂ�ƍ��񐔂��c���ɗp�����D
// ============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>
#include <vector>

#include "simple_search.h"
#include "bm_search.h"
#include "progress_bar.h"

using namespace std;


int text_length = 50;
const int key_length = 10;

int main()
{
	ofstream simple, bm;
	simple.open(".\\ss.dat");
	bm.open(".\\bm.dat");

	
	string material("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> rand(0, material.length() - 1);

	
	string text, keyword;
		
	// �e�X�g�R�[�h
	//text =    "aaabaaa";
	//keyword = "aa";

	//cout << "text   : " << text << endl;
	//cout << "keyword: " << keyword << endl;
	//cout << "SS " << simpleSearch(text, keyword) << endl;
	//cout << "BM " << bmSearch(text, keyword) << endl;

	for(int i = 0; i < text_length; i++) { text += material[rand(mt)]; }
	for(int i = 0; i < key_length; i++) { keyword += material[rand(mt)]; }
	
	
	const int max_text_length = 100000;
	while(text_length <= max_text_length)
	{
		progressBar(text_length, max_text_length, '#');

		simple << setw(6) << text_length << " " << simpleSearch(text, keyword) << endl;
		bm << setw(6) << text_length << " " << bmSearch(text, keyword) << endl;

		text.clear();
		text_length += 50;
		for(int i = 0; i < text_length; i++) { text += material[rand(mt)]; }
	}
	cout << endl;

	cout << "end\n\a";
	while(getchar() != 'q');

	return 0;
}