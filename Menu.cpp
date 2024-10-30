#include "header.h"
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

	SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
	cout << u8R"(     
                              ╔═█████████    ╔═█████████     ╔═█████████     ╔═█████████	
                             ╔╝██           ╔╝██═════╗ ██    ║ ██    ║ ██   ╔╝██    ╚╗ ██
                             ║ ██           ║ ██     ║ ██    ║ ██    ║ ██   ║ ██     ║ ██
                             ║ ██           ║ ███████████    ║ █████████    ║ ██     ║ ██
                             ║ ██           ║ ██═════╗ ██    ║ ██════╗ ██   ║ ██     ║ ██
                             ║ ██           ║ ██     ║ ██    ║ ██    ║ ██   ║ ██     ║ ██
                             ╚╦ █████████   ║ ██     ║ ██    ║ ██    ║ ██   ╚╦ █████████ 
                              ╚════════╝    ╚══╝     ╚══╝    ╚═╝     ╚═╝     ╚══════╝
)" << endl;
	GotoXY(0, 10);
	DrawHeart();
}


void displayMenu(int selected) {
	const string options[] = { "Bat dau tro choi", "Huong dan","About","Load game","Setting","Thoat" };
	const int numOptions = sizeof(options) / sizeof(options[0]);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
	SetConsoleOutputCP(CP_UTF8);

	cout << u8"                                              ┌────────────────────────┐" << endl;
	for (int i = 0; i < numOptions; i++) {

		if (i == selected) {
			// Mục đang chọn với màu chữ đỏ
			SetConsoleTextAttribute(hConsole, (15 << 4) | 5);
			SetConsoleOutputCP(CP_UTF8);

			cout << u8"                                              │   >> " << options[i];
			if (options[i] == "Bat dau tro choi") cout << u8"  │ " << "\n";
			else if (options[i] == "Huong dan") cout << u8"         │ " << "\n";
			else if (options[i] == "About") cout << u8"             │ " << "\n";
			else if (options[i] == "Load game") cout << u8"         │ " << "\n";
			else if (options[i] == "Setting") cout << u8"           │ " << "\n";
			else if (options[i] == "Thoat") cout << u8"             │ " << "\n";
		}
		else {
			// Mục không chọn với màu mặc định (trắng)
			SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
			// Màu mặc định
			cout << u8"                                              │      " << options[i];
			if (options[i] == "Bat dau tro choi") cout << u8"  │ " << "\n";
			else if (options[i] == "Huong dan") cout << u8"         │ " << "\n";
			else if (options[i] == "About") cout << u8"             │ " << "\n";
			else if (options[i] == "Load game") cout << u8"         │ " << "\n";
			else if (options[i] == "Setting") cout << u8"           │ " << "\n";
			else if (options[i] == "Thoat") cout << u8"             │ " << "\n";
		}
	}
	cout << u8"                                              └────────────────────────┘" << endl;


	std::cout << endl;
}

