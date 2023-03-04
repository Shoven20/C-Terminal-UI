#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

#define FG_RED "\033[31m"
#define FG_GREEN "\033[32m"
#define FG_YELLOW "\033[33m"
#define FG_WHITE "\033[0m"
#define FG_CYAN    "\033[36m"

void pencere()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    int count = 0;
    SetConsoleTitle(L"GITHUB/SHOVEN20");
    int horizontal = 0, vertical = 0;
    int x = 194, y = 400;
    HWND hwnd = GetConsoleWindow();
    MoveWindow(hwnd, 0, 0, x, y, FALSE);
    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);
    SetWindowPos(hwnd, HWND_NOTOPMOST, desktop.right / 2 - x / 2, desktop.bottom / 2 - y / 2, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
    lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
    SetWindowLong(hwnd, GWL_STYLE, lStyle);
    GetConsoleScreenBufferInfo(handle, &info);
    COORD scrollbar = {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    if (handle == 0)
        throw 0;
    else
        SetConsoleScreenBufferSize(handle, scrollbar);
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, 0, (255 * 100) / 10, LWA_ALPHA);
    CONSOLE_CURSOR_INFO info2;
    info2.dwSize = 100;
    info2.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &info2);
}

bool Feature1 = false;
bool Feature2 = false;
bool Feature3 = false;

int main()
{   
    system("cls");
  

    const int numOptions = 3;
    std::vector<bool> options(numOptions, false); // Default: all options are false
    int choice = 0;

    while (true)
    {
        pencere();
        // Print menu options
        system("cls"); // Clear the screen
        std::cout << FG_CYAN << "\n    C++ TERMINAL UI\n\n" << std::endl;
        std::cout << FG_YELLOW << "  __________________\n\n\n" << std::endl;
        for (int i = 0; i < numOptions; i++)
        {
            if (i == choice)
                std::cout << FG_YELLOW << "   > ";
            else
                std::cout << FG_WHITE << "     ";

            if (options[i])
                std::cout << FG_WHITE << "[" << FG_GREEN << "+" << FG_WHITE << "] ";
            else
                std::cout << FG_WHITE << "[" << FG_RED << "-" << FG_WHITE << "] ";

            switch (i)
            {
            case 0:
                std::cout << FG_WHITE << "Feature1";
                break;
            case 1:
                std::cout << FG_WHITE << "Feature2";
                break;
            case 2:
                std::cout << FG_WHITE << "Feature3";
                break;
            }

            std::cout << std::endl;
        }
        std::cout << FG_YELLOW << "\n\n\n  __________________\n" << std::endl;

        // Wait for user input
        int key = _getch();
        if (key == 224) // Special key (like arrow keys)
        {
            key = _getch();
            if (key == 72) // Up arrow
            {
                if (choice > 0)
                    choice--;
            }
            else if (key == 80) // Down arrow
            {
                if (choice < numOptions - 1)
                    choice++;
            }
            else if (key == 77) // Enter key
            {
                // Toggle selected option
                options[choice] = !options[choice];

                // Activate corresponding flag
                switch (choice)
                {
                case 0:
                    Feature1 = options[0];
                    break;
                case 1:
                    Feature2 = options[1];
                    break;
                case 2:
                    Feature3 = options[2];
                    break;
                }
            }
        }
       
        
    }

    return 0;
}