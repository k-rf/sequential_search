// ============================================================================
// 実験：Simple SearchとBM法の照合回数の比較
// 
// 実験概要：
// 　１．テキスト(50文字)とキーワード(10文字)をランダム生成．
// 　２．Simple SearchとBM法を行う．
// 　３．テキストを50文字増加してランダムに生成する．
// 　４．テキストが10,000文字になるまで２．３．を繰り返す．
// 　５．テキストサイズを横軸，照合回数を縦軸とするグラフを作成する．
//
// 注意：スライドでは縦軸を照合時間としていたが，照合時間は計算機に依存するため，
// 　　　計算機に依存することなく照合時間の指標となる照合回数を縦軸に用いた．
// ============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>
#include <vector>

#include "sequential_search.hpp"
#include "simple_search.hpp"
#include "bm_search.hpp"

using namespace std;

void progressBar(int current_value, int max_value, char fill_char)
{
	std::stringstream s;
	s << "||";

	const int bar_length = 40;
	int grid = max_value / bar_length;
	bool update = false;

	for(int i = 1; i <= bar_length; i++)
	{
		if(current_value > i * grid) { s << fill_char; update = true; }
		else { s << " "; }
	}
	s << "||\r";

	if(update) { std::cout << s.str(); update = false; }

}


int text_length = 50;
const int key_length = 10;

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
	
	// テストコード
	//text = "baaaabaaabaaaaaaaaaa";
	//keyword = "aaaaaaaaaa";

	//generateSkipTable(keyword);
	//for(vector<HashTable>::iterator itr = skip_table.begin();
	//	itr != skip_table.end(); itr++)
	//{
	//	cout << *itr << endl;
	//}

	//cout << "text   : " << text << endl;
	//cout << "keyword: " << keyword << endl;
	//cout << "SS " << simpleSearch(text, keyword) << endl;
	//cout << "BM " << bmSearch(text, keyword) << endl;

	for(int i = 0; i < text_length; i++) { text += material[rand(mt)]; }
	for(int i = 0; i < key_length; i++) { keyword += material[rand(mt)]; }
	
	
	generateSkipTable(keyword);
	
	const int max_text_length = 100000;
	while(text_length <= max_text_length)
	{
		simple << setw(6) << text_length << " " << simpleSearch(text, keyword) << endl;
		bm << setw(6) << text_length << " " << bmSearch(text, keyword) << endl;

		text.clear();
		text_length += 50;
		for(int i = 0; i < text_length; i++) { text += material[rand(mt)]; }

		progressBar(text_length, max_text_length, '#');
	}
	cout << endl;

	cout << "end\n\a";
	while(getchar() != 'q');

	return 0;
}