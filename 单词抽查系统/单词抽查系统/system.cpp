#include "system.h"
#include "Word.h"
#include <chrono>
#include <thread>
#include <conio.h>
using namespace std;
extern int Time;
void System::handle(word& Word,int& is_goon) {
	if (_kbhit()) {
		switch (_getch()) {//这样每次函数就只会要求输入一次
		case 's':
			Word.RandomWord();
			Time = 3;
			break;
		case 'a':
			is_goon = 0;
			break;
		}
	}
}
void System::handle2(word& Word, int& is_goon) {
	if (_kbhit()) {
		switch (_getch()) {
		case 's':
			Word.RandomWord2();
			break;
		case 'a':
			is_goon = 0;
			break;
		}
	}
}




//废弃代码
//if (_getch() == 's') {//_getch()是会停留的，等待下次按下
		//	Word.RandomWord();
		//	return;
		//}
		//if (_getch() == 'a') {
		//	is_goon = 0;
		//	return;
		//}
//void System::Count() {
//	while (1) {
//		if (Time >= 0) {
//			Time--;
//			this_thread::sleep_for(chrono::seconds(1));
//			if (Time == 0) {
//				
//			}
//		}
//	}
//}