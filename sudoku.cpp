#include "sudoku.h"

Sudoku::Sudoku() : m_number(0), m_checked(false)
{
    for (quint8 i = 0; i < 9; ++i) {
        for (quint8 j = 0; j < 9; ++j) {
            m_sudoku[i][j] = 0;
        }
    }
}

Sudoku::Sudoku(const QByteArray &sudokuRaw) : m_checked(false)
{
    quint8 offset = 0;
    m_number = sudokuRaw.mid(sudokuRaw.indexOf("Grid ") + 5, 2).toUInt();
    offset += 8;

    for (quint8 i = 0; i < 9; ++i) {
        for (quint8 j = 0; j < 9; ++j) {
            m_sudoku[i][j] = QChar(sudokuRaw.at(offset)).digitValue();
            ++offset;
        }
        ++offset;
    }
}

Sudoku::~Sudoku()
{

}

quint8 Sudoku::number() const
{
    return m_number;
}

void Sudoku::print() const
{
    QDebug debug = qDebug();
    debug << "Grid " << m_number << endl;
    for (quint8 i = 0; i < 9; ++i) {
        for (quint8 j = 0; j < 9; ++j) {
            debug << m_sudoku[i][j];
            if (j == 2 || j == 5) debug << "|";
        }
        if (i == 2 || i == 5) {
            debug << endl << "- - - - - - - - - - -";
        }
        debug << endl;
    }
}

bool Sudoku::solve()
{
    for (quint8 i = 0; i < 9; ++i) {
        for (quint8 j = 0; j < 9; ++j) {
            if (m_sudoku[i][j] == 0) {
                for (quint8 prediction = 1; prediction <= 9; ++prediction) {
                    m_sudoku[i][j] = prediction;
                    if (check() && solve()) {
                        return true;
                    }

                    m_sudoku[i][j] = 0;
                }

                return false;
            }
        }
    }

    return true;
}

bool Sudoku::check() const
{
    // Insert code here!
}

/* Original check function
bool Sudoku::check() const
{
    for (quint8 i = 0; i < 9; ++i) {
        if (!(checkRow(i) && checkCol(i) && checkBlk(i))) return false;
    }

    return true;
}
*/
bool Sudoku::checkRow(quint8 row) const
{
    QByteArray checkedNumbers;
    for (quint8 i = 0; i < 9; ++i) {
        if (m_sudoku[row][i] != 0) {
            if (!checkedNumbers.contains(m_sudoku[row][i])) {
                checkedNumbers.append(m_sudoku[row][i]);
            } else {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::checkCol(quint8 col) const
{
    QByteArray checkedNumbers;
    for (quint8 i = 0; i < 9; ++i) {
        if (m_sudoku[i][col] != 0) {
            if (!checkedNumbers.contains(m_sudoku[i][col])) {
                checkedNumbers.append(m_sudoku[i][col]);
            } else {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::checkBlk(quint8 blk) const
{
    quint8 rowOff, colOff;
    if (blk < 3) {
        rowOff = blk * 3;
        colOff = 0;
    } else if (blk < 6) {
        rowOff = (blk - 3) * 3;
        colOff = 3;
    } else {
        rowOff = (blk - 6) * 3;
        colOff = 6;
    }

    QByteArray checkedNumbers;
    for (quint8 i = 0; i < 3; ++i) {
        for (quint8 j = 0; j < 3; ++j) {
            if (m_sudoku[i + rowOff][j + colOff] != 0) {
                if (!checkedNumbers.contains(m_sudoku[i + rowOff][j + colOff])) {
                    checkedNumbers.append(m_sudoku[i + rowOff][j + colOff]);
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}

QString Sudoku::toRaw() const
{
    QString result;
    result = "Grid " + QString::number(m_number) + "\n";
    for (quint8 i = 0; i < 9; ++i)
    {
        for (quint8 j = 0; j < 9; ++j)
            result += QString::number(m_sudoku[i][j]);

        result += "\n";
    }

    return result;
}
