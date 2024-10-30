#include "header.h"
#include <windows.h>
#include<iostream>;
#include <conio.h>
#include "sound.h"

void about() {
	clearScreen();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15<<4));

	clearScreen();
	std::cout << u8R"(
                           ╔═█████████     ╔═█████████    ╔═█████████	 ╔═██ 	  ╔═██   ╔═██████████
                          ╔╝██═════╗ ██    ║ ██    ║ ██  ╔╝██    ╚╗ ██   ║ ██     ║ ██   ╚═══╗ ██
                          ║ ██     ║ ██    ╠═██════╣ ██  ║ ██     ║ ██   ║ ██     ║ ██       ║ ██ 
                          ║ ███████████    ║ █████████   ║ ██     ║ ██   ║ ██     ║ ██       ║ ██
                          ║ ██═════╗ ██    ║ ██    ║ ██  ║ ██     ║ ██   ║ ██     ║ ██       ║ ██
                          ║ ██     ║ ██    ║ ██    ║ ██  ║ ██     ║ ██   ║ ██     ║ ██       ║ ██
                          ║ ██     ║ ██    ║ █████████   ╚╦ █████████    ╚╦ █████████        ║ ██ 
                          ╚═╝      ╚═╝     ╚══════╝       ╚══════╝        ╚════════╝         ╚═╝ 
)" << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15<<4));
	SetConsoleOutputCP(CP_UTF8);
	std::cout << u8"                               ┌────────────────────────────────────────────┐" << "\n";
	std::cout << u8"                               │    Teacher_Instructors:Truong Toan Thinh   │" << "\n";
	std::cout << u8"                               │ GROUP 04:                                  │" << "\n";
	std::cout << u8"                               │   +Do Ngoc Gia Bao - Leader(24120263)      │" << "\n";
	std::cout << u8"                               │   +Huynh Thanh Tu          (24120235)      │" << "\n";
	std::cout << u8"                               │   +Tran Le Quoc Bao        (24120268)      │" << "\n";
	std::cout << u8"                               │   +Nguyen Van Toan         (24120232)      │" << "\n";
	std::cout << u8"                               │   +Tran Thien An           (24120255)      │" << "\n";
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

