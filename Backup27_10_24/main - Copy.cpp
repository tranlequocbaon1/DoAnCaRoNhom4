#include "Header.h"
int main() {
    int choice = 0;
    char key;

    while (true) {
        displayMenu(choice);
        key = _getch(); // Nhận đầu vào từ bàn phím mà không cần nhấn Enter

        if (key == 'w' || key == 'W') {
            choice = (choice - 1 + 6) % 6; // Di chuyển lên
        }
        else if (key == 's' || key == 'S') {
            choice = (choice + 1) % 6; // Di chuyển xuống
        }
        else if (key == 13) { // Enter key
            switch (choice) {
                //thuc hien hanh dong
            case 0:
                startGame();
                break;
            case 1:
                showInstructions();
                break;
            case 2:
                about();
                break;
            case 3:
                LoadGameWithFileName();
                break;
            case 4:
                Setting();
                break;
            case 5:
                cout << "Cam on da choi! Tam biet!\n";
                return 0;
            }
        }
    }

    return 0;
}
