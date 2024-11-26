#include "header.h"
#include <windows.h>
#include<iostream>;
#include <conio.h>
#include "sound.h"
#include "Draw.h"

void about() {
	clearScreen();
	DrawBg_Xanh();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15<<4));

	drawAbout(39, 1);
	SetConsoleTextAttribute(hConsole, 2 | (15<<4));
	SetConsoleOutputCP(CP_UTF8);

	std::cout << u8"                               ┌────────────────────────────────────────────┐" << "\n";
	std::cout << u8"                               │    Teacher_Instructors:Trương Toàn Thịnh   │" << "\n";
	std::cout << u8"                               │ GROUP 04:                                  │" << "\n";
	std::cout << u8"                               │   +Đỗ Ngọc Gia Bảo - Leader(24120263)      │" << "\n";
	std::cout << u8"                               │   +Huỳnh Thanh Tú          (24120235)      │" << "\n";
	std::cout << u8"                               │   +Trần Lê Quốc Bảo        (24120268)      │" << "\n";
	std::cout << u8"                               │   +Nguyễn Văn Toàn         (24120232)      │" << "\n";
	std::cout << u8"                               │   +Trần Thiên An           (24120255)      │" << "\n";
	std::cout << u8"                               │ Press Q to return Menu                     │" << "\n";
	std::cout << u8"                               └────────────────────────────────────────────┘" << "\n";

	// Chờ người dùng nhấn 'Q' để quay lại menu
	while (true) {
		char key = _getch(); // Nhận đầu vào từ bàn phím
		if (key == 'q' || key == 'Q') {
			click();
			return;
			// Quay về menu
		}
	}
}

