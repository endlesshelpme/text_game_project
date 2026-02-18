#include "Ui.hpp"
#include <string>
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

// std::string startScreen()
// {

// }


void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void makeCharacterUi()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Enter your name: ";
}
