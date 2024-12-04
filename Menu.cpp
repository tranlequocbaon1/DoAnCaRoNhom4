#include "header.h"
#include "language.h"
#include<iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Draw.h"


using namespace std;

void drawcaro() {
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
	clearScreen();
	DrawBg_xp();
	SetConsoleTextAttribute(hConsole, (15 << 4) | 12);
	DrawCaro(38,1);
}


void displayMenu(int selected) {
	if (isEnglish) {
		const string options[] = { "NEW GAME", "HELP","ABOUT","LOAD GAME","SETTING","EXIT" };
		const int numOptions = sizeof(options) / sizeof(options[0]);
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord = { 51, 9 }; // Vị trí muốn vẽ
		WORD originalAttributes; // Lưu trữ thuộc tính màu ban đầu
		DWORD charsRead;

		// Lấy thuộc tính màu nền và chữ tại vị trí (51, 9)
		ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);

		for (int i = 0; i < numOptions; i++) {

			if (i == selected) {
				// Mục đang chọn với màu chữ đỏ
				SetConsoleOutputCP(CP_UTF8);

				if (options[i] == "NEW GAME") {
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 9); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 9 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 9); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(50, 10); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					GotoXY(55, 10); cout << options[i];
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(63, 10); cout << u8"      █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					GotoXY(70, 10); cout << u8"█" << endl;
					coord = { 51, 11 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 11); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 11 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 11); 	cout << u8"▀";

					coord = { 51, 12 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);

				}
				else if (options[i] == "HELP") {
					coord = { 51, 12 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 12); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 12 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 12); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(50, 13); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					GotoXY(55, 13); cout << options[i];
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(59, 13); cout << u8"          █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					GotoXY(70, 13); cout << u8"█" << endl;
					coord = { 51, 14 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 14); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 14 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 14); 	cout << u8"▀";
					coord = { 51, 15 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				}
				else if (options[i] == "ABOUT") {
					coord = { 51, 15 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 15); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69,15 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 15); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);

					GotoXY(50, 16); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					GotoXY(55, 16); cout << options[i];
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(60, 16); cout << u8"         █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					GotoXY(70, 16); cout << u8"█" << endl;
					coord = { 51, 17 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 17); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 17 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 17); 	cout << u8"▀";
					coord = { 51, 18 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);

				}
				else if (options[i] == "LOAD GAME") {
					coord = { 51, 18 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 18); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 18 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 18); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);

					GotoXY(50, 19); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					GotoXY(55, 19); cout << options[i];
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(64, 19); cout << u8"     █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					GotoXY(70, 19); cout << u8"█" << endl;
					coord = { 51, 20 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 20); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 20 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 20); 	cout << u8"▀";
					coord = { 51, 21 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);


				}
				else if (options[i] == "SETTING") {
					coord = { 51, 21 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 21); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 21 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 21); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(50, 22); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					GotoXY(55, 22); cout << options[i];
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(62, 22); cout << u8"       █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					GotoXY(70, 22); cout << u8"█" << endl;
					coord = { 51, 23 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);

					GotoXY(51, 23); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 23 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 23); 	cout << u8"▀";

					coord = { 51, 24 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				}
				else if (options[i] == "EXIT") {
					coord = { 51, 24 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);

					GotoXY(51, 24); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 24 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 24); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(50, 25); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					GotoXY(55, 25); cout << options[i];
					SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					GotoXY(59, 25); cout << u8"          █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					GotoXY(70, 25); cout << u8"█" << endl;
					coord = { 69, 26 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					GotoXY(69, 26); 	cout << u8"▀";
					coord = { 51, 27 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					GotoXY(51, 26); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";

				}
			}
			else {
				// Mục không chọn với màu mặc định (trắng)
				// Màu mặc định
				if (options[i] == "NEW GAME") {
					coord = { 51, 9 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					GotoXY(51, 9); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 9 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 9); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);

					GotoXY(50, 10); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					GotoXY(55, 10); cout << options[i];
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(63, 10); cout << u8"      █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					GotoXY(70, 10); cout << u8"█" << endl;
					coord = { 51, 11 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					GotoXY(51, 11); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 11 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 11); 	cout << u8"▀";
					coord = { 51, 12 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				}
				else if (options[i] == "HELP") {
					GotoXY(51, 12); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 12 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 12); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(50, 13); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					GotoXY(55, 13); cout << options[i];
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(59, 13); cout << u8"          █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					GotoXY(70, 13); cout << u8"█" << endl;
					coord = { 51, 14 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					GotoXY(51, 14); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 14 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 14); 	cout << u8"▀";
					coord = { 51, 15 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				}
				else if (options[i] == "ABOUT") {
					GotoXY(51, 15); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

					coord = { 69, 15 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 15); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(50, 16); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					GotoXY(55, 16); cout << options[i];
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(60, 16); cout << u8"         █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					GotoXY(70, 16); cout << u8"█" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
					GotoXY(51, 17); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";

					coord = { 69, 17 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 17); 	cout << u8"▀";
					coord = { 51, 18 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				}
				else if (options[i] == "LOAD GAME") {
					GotoXY(51, 18); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 18 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 18); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);

					GotoXY(50, 19); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					GotoXY(55, 19); cout << options[i];
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(64, 19); cout << u8"     █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					GotoXY(70, 19); cout << u8"█" << endl;
					coord = { 51, 20 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					GotoXY(51, 20); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 20 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 20); 	cout << u8"▀";
					coord = { 51, 21 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				}
				else if (options[i] == "SETTING") {
					GotoXY(51, 21); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 21 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 21); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(50, 22); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					GotoXY(55, 22); cout << options[i];
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(62, 22); cout << u8"       █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					GotoXY(70, 22); cout << u8"█" << endl;
					coord = { 51, 23 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);

					GotoXY(51, 23); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					coord = { 69, 23 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 23); 	cout << u8"▀";
					coord = { 51, 24 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				}
				else if (options[i] == "EXIT") {
					GotoXY(51, 24); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					coord = { 69, 24 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 24); cout << u8"▄";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(50, 25); cout << u8"█    ";
					SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					GotoXY(55, 25); cout << options[i];
					SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					GotoXY(59, 25); cout << u8"          █" << endl;
					SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					GotoXY(70, 25); cout << u8"█" << endl;
					coord = { 69, 26 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					GotoXY(69, 26); 	cout << u8"▀";
					coord = { 51, 27 };
					ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					GotoXY(51, 26); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				}
			}
		}
	}
	 else
	 {
		 const string options[] = { "GAME MOI", "TRO GIUP","THONG TIN","TAI GAME","CAI DAT","THOAT" };
		 const int numOptions = sizeof(options) / sizeof(options[0]);
		 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		 COORD coord = { 51, 9 }; // Vị trí muốn vẽ
		 WORD originalAttributes; // Lưu trữ thuộc tính màu ban đầu
		 DWORD charsRead;

		 // Lấy thuộc tính màu nền và chữ tại vị trí (51, 9)
		 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);

		 for (int i = 0; i < numOptions; i++) {

			 if (i == selected) {
				 // Mục đang chọn với màu chữ đỏ
				 SetConsoleOutputCP(CP_UTF8);

				 if (options[i] == "GAME MOI") {
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 9); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 9 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 9); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(50, 10); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					 GotoXY(55, 10); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(63, 10); cout << u8"      █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					 GotoXY(70, 10); cout << u8"█" << endl;
					 coord = { 51, 11 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 11); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 11 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 11); 	cout << u8"▀";

					 coord = { 51, 12 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);

				 }
				 else if (options[i] == "TRO GIUP") {
					 coord = { 51, 12 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 12); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 12 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 12); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(50, 13); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					 GotoXY(55, 13); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(63, 13); cout << u8"      █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					 GotoXY(70, 13); cout << u8"█" << endl;
					 coord = { 51, 14 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 14); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 14 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 14); 	cout << u8"▀";
					 coord = { 51, 15 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				 }
				 else if (options[i] == "THONG TIN") {
					 coord = { 51, 15 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 15); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69,15 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 15); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);

					 GotoXY(50, 16); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					 GotoXY(55, 16); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(64, 16); cout << u8"     █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					 GotoXY(70, 16); cout << u8"█" << endl;
					 coord = { 51, 17 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 17); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 17 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 17); 	cout << u8"▀";
					 coord = { 51, 18 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);

				 }
				 else if (options[i] == "TAI GAME") {
					 coord = { 51, 18 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 18); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 18 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 18); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);

					 GotoXY(50, 19); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					 GotoXY(55, 19); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(63, 19); cout << u8"      █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					 GotoXY(70, 19); cout << u8"█" << endl;
					 coord = { 51, 20 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 20); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 20 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 20); 	cout << u8"▀";
					 coord = { 51, 21 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);


				 }
				 else if (options[i] == "CAI DAT") {
					 coord = { 51, 21 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 21); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 21 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 21); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(50, 22); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					 GotoXY(55, 22); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(62, 22); cout << u8"       █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					 GotoXY(70, 22); cout << u8"█" << endl;
					 coord = { 51, 23 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);

					 GotoXY(51, 23); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 23 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 23); 	cout << u8"▀";

					 coord = { 51, 24 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				 }
				 else if (options[i] == "THOAT") {
					 coord = { 51, 24 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);

					 GotoXY(51, 24); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 24 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 24); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(50, 25); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
					 GotoXY(55, 25); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
					 GotoXY(60, 25); cout << u8"         █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
					 GotoXY(70, 25); cout << u8"█" << endl;
					 coord = { 69, 26 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 2);
					 GotoXY(69, 26); 	cout << u8"▀";
					 coord = { 51, 27 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 10);
					 GotoXY(51, 26); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";

				 }
			 }
			 else {
				 // Mục không chọn với màu mặc định (trắng)
				 // Màu mặc định
				 if (options[i] == "GAME MOI") {
					 coord = { 51, 9 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					 GotoXY(51, 9); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 9 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 9); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);

					 GotoXY(50, 10); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					 GotoXY(55, 10); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(63, 10); cout << u8"      █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					 GotoXY(70, 10); cout << u8"█" << endl;
					 coord = { 51, 11 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					 GotoXY(51, 11); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 11 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 11); 	cout << u8"▀";
					 coord = { 51, 12 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				 }
				 else if (options[i] == "TRO GIUP") {
					 GotoXY(51, 12); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 12 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 12); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(50, 13); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					 GotoXY(55, 13); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(63, 13); cout << u8"      █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					 GotoXY(70, 13); cout << u8"█" << endl;
					 coord = { 51, 14 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					 GotoXY(51, 14); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 14 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 14); 	cout << u8"▀";
					 coord = { 51, 15 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				 }
				 else if (options[i] == "THONG TIN") {
					 GotoXY(51, 15); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

					 coord = { 69, 15 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 15); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(50, 16); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					 GotoXY(55, 16); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(64, 16); cout << u8"     █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					 GotoXY(70, 16); cout << u8"█" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
					 GotoXY(51, 17); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";

					 coord = { 69, 17 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 17); 	cout << u8"▀";
					 coord = { 51, 18 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				 }
				 else if (options[i] == "TAI GAME") {
					 GotoXY(51, 18); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 18 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 18); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);

					 GotoXY(50, 19); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					 GotoXY(55, 19); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(63, 19); cout << u8"      █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					 GotoXY(70, 19); cout << u8"█" << endl;
					 coord = { 51, 20 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					 GotoXY(51, 20); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 20 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 20); 	cout << u8"▀";
					 coord = { 51, 21 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				 }
				 else if (options[i] == "CAI DAT") {
					 GotoXY(51, 21); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 21 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 21); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(50, 22); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					 GotoXY(55, 22); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(62, 22); cout << u8"       █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					 GotoXY(70, 22); cout << u8"█" << endl;
					 coord = { 51, 23 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);

					 GotoXY(51, 23); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
					 coord = { 69, 23 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 23); 	cout << u8"▀";
					 coord = { 51, 24 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
				 }
				 else if (options[i] == "THOAT") {
					 GotoXY(51, 24); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
					 coord = { 69, 24 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 24); cout << u8"▄";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(50, 25); cout << u8"█    ";
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
					 GotoXY(55, 25); cout << options[i];
					 SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
					 GotoXY(60, 25); cout << u8"         █" << endl;
					 SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
					 GotoXY(70, 25); cout << u8"█" << endl;
					 coord = { 69, 26 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 9);
					 GotoXY(69, 26); 	cout << u8"▀";
					 coord = { 51, 27 };
					 ReadConsoleOutputAttribute(hConsole, &originalAttributes, 1, coord, &charsRead);
					 SetConsoleTextAttribute(hConsole, (originalAttributes & 0xF0) | 11);
					 GotoXY(51, 26); 	cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				 }
			 }
		 }

		 }
	



	std::cout << endl;

	

}
