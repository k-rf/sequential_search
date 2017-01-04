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