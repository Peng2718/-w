#include "Word.h"
#include <Windows.h>
#include <thread>
#include <iostream>
#include <conio.h>
#include "system.h"
using namespace std;
bool isRunning = true;
enum Mode
{
	add,test1,test2,show,menu
};

int main() {
	System sys;
	word wordlist;
	Mode mode;
	mode = menu;
	while (isRunning) {
		if (mode == menu) {
			system("cls");
			cout << "请选择方式：" << endl;
			cout << "1:有中文" << endl;
			cout << "2.无中文：" << endl;
			while (1) {
				int is_goon = 0;
				is_goon = _getch();
				if (is_goon=='1') {
					mode = test1;
					break;
				}
				else if (is_goon == '2') {
					mode = test2;
					break;
				}
				else {
					cout << "选择无效" << endl;
				}
			}
		}
		if (mode == test1) {
			wordlist.Load();
			system("cls");
			cout << "按s开始测试" << endl;
			cout << "按a退出" << endl;
			int is_goon = 1;
			thread CountTime(&word::Count, &wordlist,ref(is_goon));
			CountTime.detach();
			while (is_goon) {
				sys.handle(wordlist,is_goon);
			}
			mode = menu;
		}
		if (mode == test2) {
			wordlist.Load2();
			system("cls");
			cout << "按s开始测试" << endl;
			cout << "按a退出" << endl;
			int is_goon = 1;
			while (is_goon) {
				sys.handle2(wordlist, is_goon);
			}
			mode = menu;
		}
	}
	system("cls");
	cout << "仍需复习的单词" << endl;
	wordlist.ShowR();
	cout << endl;
	cout << "加油！继续坚持！每天背单词:" << endl;
	return 0;
}
