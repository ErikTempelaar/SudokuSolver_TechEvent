#include "sudoku.h"

#include <iostream>
#include <sstream>

short Sudoku::s_id = 0;

Sudoku::Sudoku()
    : m_rowCount(-1)
    , m_id      (s_id)
{
    ++s_id;
    std::cout << " Created Sudoku "  << m_id << "." << std::endl;
}

Sudoku::~Sudoku()
{

}

void Sudoku::addLine(std::stringstream& stream)
{
    if (m_rowCount != -1)
    {
        int n;
        int columnCount = 8;
        while (stream >> n)
        {
            while (n)
            { // loop till there's nothing left
                m_sudoku[m_rowCount][columnCount] = n % 10; // assign the last digit
                n /= 10; // "right shift" the number
                columnCount--;
            }
        }
    }
    ++m_rowCount;
}


short Sudoku::id() const
{
    return m_id;
}

// Left>Right, Top>Bottom
const std::array<std::array<int, 9>, 9>& Sudoku::getSudoku() const
{
    return m_sudoku;
}
