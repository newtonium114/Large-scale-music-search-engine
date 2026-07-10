//
// Created by rache on 7/9/2026.
//
#include "UserInterface.h"

int main()
{
    UserInterface ui(
    songs,
    titleTable,
    artistTable,
    songTrie,
    buildTime,
    trieBuildTime
);

    ui.displayMainMenu();

    return 0;
}