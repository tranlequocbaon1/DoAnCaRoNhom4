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
    const string optionsEnglish[] = { "SFX", "Language" };
    const string optionsVietnamese[] = { "SFX", "Ngon ngu" };
    const string* options = isEnglish ? optionsEnglish : optionsVietnamese;
    const int numOptions = sizeof(optionsEnglish) / sizeof(optionsEnglish[0]);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Cố định khung với kích thước không thay đổi
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
    

    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
    GotoXY(47, 12);
    SetConsoleTextAttribute(hConsole, (15 << 4) | 14);
    cout << u8"██████████████████████████" ;
    
    for (int i = 0; i < numOptions; i++) {
        if (i == selected) {
            // Màu sắc khi mục đang chọn
            SetConsoleTextAttribute(hConsole, (14 << 4) | 4);
            GotoXY(46, 13 + i); // Di chuyển tới dòng tương ứng với lựa chọn
            cout << u8"    >> " << options[i];

            // Hiển thị trạng thái cho SFX
            if (i == 0) {
                SetConsoleTextAttribute(hConsole, (14 << 4) | 4);
                cout << setw(10) << (isSFXEnabled ? (isEnglish ? " (On)" : " (Bat)") : (isEnglish ? " (Off)" : " (Tat)")) << u8"        " <<endl;
                SetConsoleTextAttribute(hConsole, (15 << 4) | 14);
               // cout << u8"██████" << endl;
            }
            else if (i == 1) {
                // Hiển thị trạng thái cho Language
                SetConsoleTextAttribute(hConsole, (14 << 4) | 4);
                cout << setw(13) << (isEnglish ? " (English)" : " (Tieng Viet)") << u8" " << endl;
                SetConsoleTextAttribute(hConsole, (15 << 4) | 14);
               // cout << u8"██" << endl;
            }
        }
        else {
            // Màu sắc khi mục không được chọn
            SetConsoleTextAttribute(hConsole, (14 << 4) | 0);
            GotoXY(46, 13 + i); // Di chuyển tới dòng tương ứng với lựa chọn
            cout << u8"       " << options[i];

            // Hiển thị trạng thái cho SFX
            if (i == 0) {
                SetConsoleTextAttribute(hConsole, (14 << 4) | 0);
                cout << setw(10) << (isSFXEnabled ? (isEnglish ? " (On)" : " (Bat)") : (isEnglish ? " (Off)" : " (Tat)")) << u8"        " << endl;
                SetConsoleTextAttribute(hConsole, (15 << 4) | 14);
                //cout << u8"███" << endl;
            }
            else if (i == 1) {
                // Hiển thị trạng thái cho Language
                SetConsoleTextAttribute(hConsole, (14 << 4) | 0);
                cout << setw(13) << (isEnglish ? " (English)" : " (Tieng Viet)") << u8" " << endl;
                SetConsoleTextAttribute(hConsole, (15 << 4) | 14);
                //cout << u8"██" << endl;
            }
        }
    }
    GotoXY(47, 15);
    SetConsoleTextAttribute(hConsole, (15 << 4) | 14);
    cout << u8"██████████████████████████" << endl;
    GotoXY(73, 12);
    SetConsoleTextAttribute(hConsole, (15 << 4) | 6);

    cout << u8"█" << endl;
    GotoXY(74, 13);
    cout << u8"█" << endl;
    GotoXY(74, 14);
    cout << u8"█" << endl;
    GotoXY(73, 15);
    cout << u8"█" << endl;
   
    
}




void Setting() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice = 0;
	char key;
    clearScreen();
    DrawBg_Hong();
    drawSetting(32, 1);
	nhan1:while (true) {
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
                goto nhan1;
				break;
			case 1:  // Thay đổi ngôn ngữ
				isEnglish = !isEnglish;  // Đổi ngôn ngữ
				

                goto nhan1;
                GotoXY(70, 13);
                SetConsoleTextAttribute(hConsole, (15 << 4) | 14);
                cout << u8"████" << endl;
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
