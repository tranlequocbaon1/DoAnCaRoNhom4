#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include "header.h"
bool resetFlag;
bool countdownActive=true;

using namespace std;



void TimerCountDown(int seconds) {
    while (seconds > 0 && countdownActive) {
        cout << "\033[H\n\n";
        cout <<"\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << seconds;
        
        GotoXY(_X, _Y);
        this_thread::sleep_for(chrono::seconds(1)); 
        if (resetFlag) {
            seconds = 30; // Reset lại thời gian
            resetFlag = false; // Đặt lại cờ reset
        }
        --seconds;
       
    } 
    
}