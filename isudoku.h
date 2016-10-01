#ifndef ISUDOKU_H
#define ISUDOKU_H

#include <array>

class ISudoku
{
public:
    virtual short id() const = 0;

    // Left>Right, Top>Bottom
    virtual const std::array<std::array<int, 9>, 9>& getSudoku() const = 0;
};

#endif // ISUDOKU_H
