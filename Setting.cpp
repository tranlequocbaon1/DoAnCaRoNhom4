#pragma once﻿
#include "Header.h"
#include <conio.h>
#include <iostream>
#include "Sound.h"
#include <string>
#include <Windows.h>
#include <iomanip>
#include "language.h"
#include"Draw.h"

using namespace std;

void displaysetting(int selected) {
    const string options[] = { "SFX", "Language" };
    const int numOptions = sizeof(options) / sizeof(options[0]);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Cố định khung với kích thước không thay đổi
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
    clearScreen();
    DrawBg_Hong();
    drawSetting(32, 1);

    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
    GotoXY(46, 12);
    cout << u8"┌────────────────────────────┐" << endl;
    for (int i = 0; i < numOptions; i++) {
        if (i == selected) {
            // Màu sắc khi mục đang chọn
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
            GotoXY(46, 13 + i); // Di chuyển tới dòng tương ứng với lựa chọn
            cout << u8"│   >> " << options[i];

            // Hiển thị trạng thái cho SFX
            if (i == 0) {
                cout << setw(10) << (isSFXEnabled ? " (On)" : " (Off)") << u8"         │" << endl;
            }
            else if (i == 1) {
                // Hiển thị trạng thái cho Language
                cout << setw(13) << (isEnglish ? " (English)" : "(Vietnamese)") << u8" │" << endl;
            }
        }
        else {
            // Màu sắc khi mục không được chọn
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
            GotoXY(46, 13 + i); // Di chuyển tới dòng tương ứng với lựa chọn
            cout << u8"│      " << options[i];

            // Hiển thị trạng thái cho SFX
            if (i == 0) {
                cout << setw(10) << (isSFXEnabled ? " (On)" : " (Off)") << u8"         │" << endl;
            }
            else if (i == 1) {
                // Hiển thị trạng thái cho Language
                cout << setw(13) << (isEnglish ? " (English)" : "(Vietnamese)") << u8" │" << endl;
            }
        }
    }
    GotoXY(46, 15);
    cout << u8"└────────────────────────────┘" << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
}




void Setting() {
	int choice = 0;
	char key;
	while (true) {
		displaysetting(choice);  // Hiển thị menu cài đặt
		key = _getch();  // Nhận đầu vào từ bàn phím

		if (key == 'Q' || key == 'q') {
			click();
			return;
		}
		else if (key == 13) { // Enter
			click();
			switch (choice) {
			case 0:  // Thay đổi SFX
				toggleSFX();
				break;
			case 1:  // Thay đổi ngôn ngữ
				isEnglish = !isEnglish;  // Đổi ngôn ngữ
				Box_Error_Duplicate_file(); // Cập nhật hộp thông báo khi ngôn ngữ thay đổi
				break;
			}
		}
		else if (key == 'w' || key == 'W') {
			choice = (choice - 1 + 2) % 2;  // Di chuyển lên
		}
		else if (key == 's' || key == 'S') {
			choice = (choice + 1) % 2;  // Di chuyển xuống
		}
	}
}
