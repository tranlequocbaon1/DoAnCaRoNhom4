#include"Header.h"
#include <conio.h>
#include <iostream>
#include "Sound.h"
#include <string>
#include <Windows.h>
#include <iomanip>
#include"Draw.h"

using namespace std;

void displaysetting(int selected) {
    const string options[] = { "SFX" }; // Chỉ có một mục
    const int numOptions = sizeof(options) / sizeof(options[0]);
    SetConsoleOutputCP(CP_UTF8); // Hỗ trợ Unicode
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    clearScreen();
    DrawBg_Hong();
    drawSetting(32, 1);

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4)); // Màu xanh và nền trắng
    GotoXY(46, 12);
    cout << u8"┌────────────────────────┐";

    for (int i = 0; i < numOptions; i++) {
        GotoXY(46, 13 + i);
        if (i == selected) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
            cout << u8"│   >> " << options[i] << setw(10)
                << (isSFXEnabled ? " (On)" : " (Off)") << u8"     │";
        }
        else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
            cout << u8"│      " << options[i] << setw(10)
                << (isSFXEnabled ? " (On)" : " (Off)") << u8"     │";
        }
    }

    GotoXY(46, 13 + numOptions);
    cout << u8"└────────────────────────┘";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
}


void Setting() {
	int choice = 0;
	char key;
	while (true) {

		displaysetting(choice);
		key = _getch(); // Nhận đầu vào từ bàn phím mà không cần nhấn Enter

		if (key == 'Q' || key == 'q')
		{
			click();
			return;

		}
		else if (key == 13) {
			click();
			switch (choice) {
				//thuc hien hanh dong
			case 0:

				toggleSFX();
				GotoXY(72, 4);

				break;
			}
		}
	}
}