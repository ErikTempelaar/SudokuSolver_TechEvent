#include <QCoreApplication>

#include "sudokusolver.h"


int main(int argc, char *argv[])
{
    SudokuSolver solver("C:/Users/Gerard/Documents/sudoku.txt"); // C:\"Users\"gerar_000\"Documents\"sudoku\"sudoku1.txt

    solver.solve();

    QCoreApplication a(argc, argv);

    return a.exec();
}
