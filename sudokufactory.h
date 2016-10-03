#ifndef SUDOKUFACTORY_H
#define SUDOKUFACTORY_H

#include <string>
#include <vector>

#include "sudoku.h"

class SudokuFactory
{

public:
    static std::vector<ISudoku *> createSudokus(std::string sudokuFilePath);

private:
    SudokuFactory();
    virtual ~SudokuFactory();
};

#endif // SUDOKUFACTORY_H
