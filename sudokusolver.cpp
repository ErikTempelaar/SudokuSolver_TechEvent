#include "sudokusolver.h"

SudokuSolver::SudokuSolver(QString sudokuPath) : m_sudokuIndex(0)
{
    if (sudokuPath.isEmpty()) return;

    QFile file(sudokuPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file:" << sudokuPath << endl;
        return;
    }

    m_result.setFileName(sudokuPath.insert(sudokuPath.indexOf(".txt"), "Results"));
    if (!m_result.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning() << "Could not create result file: " << sudokuPath << endl;
        return;
    }

    QByteArray buf(file.size(), '-');
    buf = file.readAll();
    file.close();

    qDebug() << "Reading puzzles...";

    bool enable = true;
    quint8 i = 0;
    qint32 currentPuzzle = 0;
    qint32 nextPuzzle = 0;
    while (enable) {
        if (currentPuzzle >= 0) {
            nextPuzzle = buf.indexOf(QString("Grid %1").arg(i + 2, 2, 10, QChar('0')), currentPuzzle);

            m_sudokuList.append(new Sudoku(buf.mid(currentPuzzle, nextPuzzle - currentPuzzle)));

            currentPuzzle = nextPuzzle;
            ++i;
        } else {
            enable = false;
        }
    }
}

SudokuSolver::~SudokuSolver()
{
    m_result.close();
}

void SudokuSolver::solve()
{
    QTextStream stream(&m_result);
    qDebug() << "Start solving...";
    for (Sudoku* index : m_sudokuList)
    {
        if (!index->solve()) qDebug() << "Sudoku " << index->number() << "failed.";
        else
        {
            qDebug() << ".";
            stream << index->toRaw();
            return;
        }
    }
    qDebug() << "Stop solving...";
}

void SudokuSolver::check()
{
    for (Sudoku* index : m_sudokuList)
        index->solve();
}

const QVector<Sudoku *> &SudokuSolver::sudokuList() const
{
    return m_sudokuList;
}
