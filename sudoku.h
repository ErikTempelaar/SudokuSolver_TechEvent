#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <array>

#include "isudoku.h"

class Sudoku : public ISudoku
{
public:
    Sudoku();
    virtual ~Sudoku();

    void addLine(std::stringstream &stringstream);

    static short s_id;

    // ISudoku
    short id() const;
    // Left>Right, Top>Bottom
    const std::array<std::array<int, 9>, 9>& getSudoku() const;

private:
    short m_rowCount;
    short m_id;
    std::array<std::array<int, 9> , 9> m_sudoku;
};

#endif // SUDOKU_H
