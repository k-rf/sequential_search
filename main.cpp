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
#include <random>
#include <iomanip>

#include "simple_search.hpp"

using namespace std;

int main()
{
	ofstream simple;
	simple.open(".\\ss.dat");

	ofstream bm;
	bm.open(".\\bm.dat");

	
	string material("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> rand(0, material.length() - 1);

	string text, keyword;

	int text_length = 50;
	for(int i = 0; i < text_length; i++) { text += material[rand(mt)]; }
	for(int i = 0; i < 10; i++) { keyword += material[rand(mt)]; }
	
	while(text_length <= 100)
	{
		simple << setw(6) << text_length << " " << simpleSearch(text, keyword) << endl;
		
		text = "";
		text_length += 50;
		for(int i = 0; i < text_length; i++) { text += material[rand(mt)]; }
	}

	cout << "\a";

	return 0;
}