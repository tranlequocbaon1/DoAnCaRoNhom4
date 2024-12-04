#include "header.h"
#include "language.h"
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

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY(34, 9); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	GotoXY(32, 10); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY(30, 11); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY(50, 11);
	if (isEnglish)
		std::cout << u8"'A'    : MOVE LEFT";
	else
		std::cout << u8"'A'    : DI CHUYỂN LÊN";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY(30, 12); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY(50, 12);
	if (isEnglish) std::cout << u8"'D'    : MOVE RIGHT";
	else std::cout << u8"'D'    : DI CHUYỂN PHẢI";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY(30, 13); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY(50, 13);
	if (isEnglish) std::cout << u8"'W'    : MOVE UP";
	else std::cout << u8"'W'    : DI CHUYỂN LÊN";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY(30, 14); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY(50, 14);
	if (isEnglish) std::cout << u8"'S'    : MOVE DOWN";
	else std::cout << u8"'S'    : DI CHUYỂN XUỐNG";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY(30, 15); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY(50, 15);
	if (isEnglish) std::cout << u8"'ENTER': MARK";
	else std::cout << u8"'ENTER': CHỌN";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY(30, 16); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY(45, 16);
	if (isEnglish) std::cout << u8"Press (Q) to return Menu";
	else std::cout << u8"Nhấn (Q) để trở về Menu";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY(32, 17); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY(34, 18); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 6);
	GotoXY(84, 9); std::cout << u8"█" << "\n";
	GotoXY(86, 10); std::cout << u8"█" << "\n";
	GotoXY(88, 11); std::cout << u8"█" << "\n";
	GotoXY(88, 12); std::cout << u8"█" << "\n";
	GotoXY(88, 13); std::cout << u8"█" << "\n";
	GotoXY(88, 14); std::cout << u8"█" << "\n";
	GotoXY(88, 15); std::cout << u8"█" << "\n";
	GotoXY(88, 16); std::cout << u8"█" << "\n";
	GotoXY(86, 17); std::cout << u8"█" << "\n";
	GotoXY(84, 18); std::cout << u8"█" << "\n";

	// Chờ người dùng nhấn 'Q' để quay lại menu
	while (true) {
		char key = _getch(); // Nhận đầu vào từ bàn phím
		if (key == 'q' || key == 'Q') {
			break; // Quay về menu
		}
	}
}


