#include "Word.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string.h>
#include <thread>
#include <conio.h>
#include <chrono>
#include <functional>
using namespace std;
int Time = -1;
string pev;
string cur;
string w;
bool word::isSame(string s) {
	for (auto& w : Review) {
		if (w==s) {
			return true;
		}
	}
	return false;
}
void word::Load2() {
	ifstream file("WordList.txt");
	if (!file.is_open()) {
		cerr << "can not open file" << endl;
		return;
	}
	string line;
	int i = 0;
	while (getline(file, line)) {
		WordList.resize(i + 1);
		WordList[i] = line;
		i++;
	}
	file.close();
}
void word::Count(int& is_goon) {
	while (1) {
		if (is_goon == 1) {
			if (Time >= 0) {
				Time--;
				this_thread::sleep_for(chrono::seconds(1));
				if (Time == 0) {
					w = RandomWordW();
					if (w != "\0") {
						if (!isSame(w)) {
							Review.push_back(w);
						}
					}
					else {
						break;
					}
					Time = 3;
				}
			}
		}
		else {
			break;
		}
	}
	return;
}
bool word::check() {
	if (WordList.empty())
		return true;
}
int GetRandom(int beg, int end) {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	mt19937 engine(seed);
	uniform_int_distribution<int> int_dist(beg, end);
	return int_dist(engine);
}
void word::Load() {
	ifstream file("WordList.txt");
	if (!file.is_open()) {
		cerr << "can not open file" << endl;
		return;
	}
	string line;
	int i = 0;
	while (getline(file, line)) {
		WordList.resize(i + 1);
		WordList[i] = line;
		i++;
	}
	file.close();

	ifstream file2("translate.txt");
	if (!file2.is_open()) {
		cerr << "can not open file" << endl;
		return;
	}
	string line2;
	int j = 0;
	while (getline(file2, line2)) {
		Translate.resize(j + 1);
		Translate[j] = line2;
		j++;
	}
	file2.close();
}
void word::Add() {
	string Word;
	cin >> Word;
	WordList.push_back(Word);
	ofstream file("WordList.txt");
	if (!file.is_open()) {
		cerr << "can not open file" << endl;
		return;
	}
	for (auto& w : WordList) {
		file << w;
		file << endl;
	}
	file.close();
}
void word::Show() {
	for (auto& w : WordList) {
		cout << w << endl;
	}
}
void word::ShowR() {
	for (auto& w : Review) {
		cout << w << endl;
	}
}
void word::RandomWord2() {
	if (WordList.size() == 0) {
		cout << "你完成了测试" << endl;
		cout << "按a退出" << endl;
		return;
	}
	int index = GetRandom(0, WordList.size() - 1);
	auto it1 = WordList.begin();
	for (int i = 0; i < index; i++) {
		it1++;
	}
	string s1;
	s1 = WordList[index];
	cout << s1 << endl;
	WordList.erase(it1);
}
void word::RandomWord() {
	if (WordList.size() == 0) {
		cout << "你完成了测试" << endl;
		cout << "按a退出" << endl;
		return;
	}
	int index = GetRandom(0, WordList.size() - 1);
	auto it1 = WordList.begin();
	for (int i = 0; i < index; i++) {
		it1++;
	}
	auto it2 = Translate.begin();
	for (int i = 0; i < index; i++) {
		it2++;
	}
	string s1, s2;
	s1 = WordList[index];
	s2 = Translate[index];
	cout << s1 << endl;
	cur = s2;
	WordList.erase(it1);
	Translate.erase(it2);
}
string word::RandomWordW() {
	if (WordList.size() == 0) {
		cout << "你完成了测试" << endl;
		cout << "按a退出" << endl;
		return "\0";
	}
	int index = GetRandom(0, WordList.size() - 1);
	auto it1 = WordList.begin();
	for (int i = 0; i < index; i++) {
		it1++;
	}
	auto it2 = Translate.begin();
	for (int i = 0; i < index; i++) {
		it2++;
	}
	string s1 = WordList[index];
	pev = cur;
	string s2 = Translate[index];
	cur = s2;
	cout << pev << endl;
	cout << s1 << endl;
	WordList.erase(it1);
	Translate.erase(it2);
	return s1;
}




//废弃代码
//bool is_click() {
//	if (_kbhit()) {
//		if (_getch() == ' ')
//			return true;
//	}
//	else {
//		return false;
//	}
//}
//bool is_back() {
//	if (_kbhit()) {
//		if (_getch() == 'a')
//			return true;
//	}
//	else {
//		return false;
//	}
//}