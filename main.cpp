#include "sudokufactory.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <set>

#include "isudoku.h"

bool isSudokuValid(const std::array<std::array<int, 9>, 9>& sudoku);

int main(int argc, char *argv[])
{
    const std::vector<ISudoku*> list = SudokuFactory::createSudokus("sudokus.txt");
    
    std::cout << "Checking puzzles..." << std::endl;

    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    auto t0 = Time::now();

    for (auto& sudoku : list)
    {
        if (!isSudokuValid(sudoku->getSudoku()))
            std::cout << "Invalid SudokuID: " << sudoku->id() << std::endl;

        delete sudoku;
    }

    auto t1 = Time::now();
    fsec fs = t1 - t0;
    ms d = std::chrono::duration_cast<ms>(fs);
    std::cout << fs.count() << "s\n";
    std::cout << d.count() << "ms\n";

    std::cout << "Program done." << std::endl;

    return 0;
}

bool isSudokuValid(const std::array<std::array<int, 9>, 9>& sudoku)
{
    /* Insert code here */
}
