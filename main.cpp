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
		
	// テストコード
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