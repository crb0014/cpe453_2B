#ifndef POPUP_H
#define POPUP_H

#define I 128
#define J 3

#include <QDialog>
#include <QRegExpValidator>
#include <QFile>
#include <QTextStream>
#include "inireader.h"
#include "iniops.h"

namespace Ui {
class popup;
}

class popup : public QDialog
{
    Q_OBJECT

public:
    explicit popup(QString addr, int arduino, QString array[I][J], QWidget *parent = 0);
    ~popup();

private slots:
    void on_newAddress_textEdited(const QString &arg1);

    void on_newAddress_editingFinished();

    void on_setButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::popup *ui;
    INIOps * ops;
    QString array[I][J];
};

#endif // POPUP_H
