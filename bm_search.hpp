#ifndef ___BM_SEARCH_HPP
#define ___BM_SEARCH_HPP

#include <iostream>
#include <string>

// BM法
// 照合回数を返す
int bmSearch(const std::string& text, const std::string& keyword);

// スキップ関数
// スキップする数を返す
int skip(const char& c);

#endif
