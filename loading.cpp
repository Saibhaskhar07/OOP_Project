#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "loading.h"
using namespace std;

void loading::hideCursor()
{
    std::cout << "\e[?25l";  // ANSI escape code to hide cursor
}

void loading::showCursor()
{
    std::cout << "\e[?25h";  // ANSI escape code to show cursor
}

void loading::clearScreen()
{
    std::cout << "\e[1;1H\e[2J";  // ANSI escape code to clear screen
}

void loading::print()
{
    hideCursor();  // Hide cursor before displaying animation ⏳

    int sec = 150;

    std::string array[] = {"◴", "◷", "◶", "◵"};
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 4; ++j) {
            clearScreen();
            std::cout << array[j] << " Loading.." << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(sec));
        }

    }
    clearScreen();
    showCursor();  // Show cursor before exiting
}

