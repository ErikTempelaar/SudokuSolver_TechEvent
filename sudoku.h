#ifndef SUDOKU_H
#define SUDOKU_H

#include <QtCore>

class Sudoku : public QObject
{
    Q_OBJECT

public:
    Sudoku();
    Sudoku(const QByteArray &sudokuRaw);
    ~Sudoku();

    quint8 number() const;
    void print() const;

    bool solve();
    bool check() const;

    QString toRaw() const;

    SetChecked(bool correct){ m_checked = correct; }
    GetChecked() const      { return m_checked; }

signals:
    void finished(quint16 result);

private:
    quint8 m_number;
    quint8 m_sudoku[9][9];

    bool checkRow(quint8 row) const;
    bool checkCol(quint8 col) const;
    bool checkBlk(quint8 blk) const;

    bool m_checked;

    Q_DISABLE_COPY(Sudoku)
};

#endif // SUDOKU_H
