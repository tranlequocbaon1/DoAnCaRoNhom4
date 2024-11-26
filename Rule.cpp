#include "header.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Draw.h"

void showInstructions() {
	clearScreen();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15 << 4));
	clearScreen();
	DrawBg_Cam();
	drawRule(39, 1);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15<<4));
	SetConsoleOutputCP(CP_UTF8);
	std::cout << u8"                                ┌────────────────────────────────────────────┐" << "\n";
	std::cout << u8"                                │              'A'    : MOVE LEFT            │" << "\n";
	std::cout << u8"                                │              'D'    : MOVE RIGHT           │" << "\n";
	std::cout << u8"                                │              'W'    : MOVE UP              │" << "\n";
	std::cout << u8"                                │              'S'    : MOVE DOWN            │" << "\n";
	std::cout << u8"                                │              'ENTER': MARK                 │" << "\n";
	std::cout << u8"                                │            Press Q to return Menu          │" << "\n";
	std::cout << u8"                                └────────────────────────────────────────────┘" << "\n";
	// Chờ người dùng nhấn 'Q' để quay lại menu
	while (true) {
		char key =_getch(); // Nhận đầu vào từ bàn phím
		if (key == 'q' || key == 'Q') {
			break; // Quay về menu
		}
	}
}

