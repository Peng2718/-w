#pragma once
#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
using namespace std;
class word {
private:
	vector<string> WordList;
	vector<string> Review;
	vector<string> Translate;
public:
	bool check();
	void Load();
	void Load2();
	void Add();
	void Show();
	void ShowR();
	void RandomWord();
	void RandomWord2();
	void Count(int& is_goon);
	bool isSame(string s);
	string RandomWordW();
};
int GetRandom(int beg,int end);
#endif // !WORD_H
