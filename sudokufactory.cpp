#include "sudokufactory.h"

#include <iostream>
#include <fstream>
#include <sstream>

std::vector<ISudoku *> SudokuFactory::createSudokus(std::string sudokuFilePath)
{
    std::vector<ISudoku*> listSudokus;

    if (sudokuFilePath.empty())
        return listSudokus;

    std::cout << "Reading puzzles..." << std::endl;

    std::ifstream sudokuSource(sudokuFilePath);
    if (sudokuSource.is_open())
    {
        std::string line;
        int numberOfLines = 0;
        Sudoku* sudoku = nullptr;
        while (getline (sudokuSource, line))
        {
            if (numberOfLines % 10 == 0)
            {
                sudoku = new Sudoku();
                listSudokus.push_back(sudoku);
            }

            std::stringstream ss;
            ss.str(line);
            if (sudoku != nullptr)
                sudoku->addLine(ss);
            std::cout << ss.str() << std::endl;

            ++numberOfLines;
        }
        sudokuSource.close();
    }
}
