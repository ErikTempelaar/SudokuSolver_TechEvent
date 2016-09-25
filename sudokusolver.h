#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <QtCore>
#include "sudoku.h"

class SudokuSolver : public QObject
{
    Q_OBJECT

public:
    SudokuSolver(QString sudokuPath);
    ~SudokuSolver();

    void solve();
    void check();

    const QVector<Sudoku *> &sudokuList() const;

private:
    QVector<Sudoku*> m_sudokuList;
    quint8 m_sudokuIndex;
    QFile m_result;

};

#endif // SUDOKUSOLVER_H
