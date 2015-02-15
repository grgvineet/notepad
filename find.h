#ifndef FIND_H
#define FIND_H

#include <QDialog>
#include "ui_mainwindow.h"

namespace Ui {
class Find;
}

class Find : public QDialog
{
    Q_OBJECT

    
public:
    explicit Find(QWidget *parent = 0);
    ~Find();
    void getMainWindowUI(Ui::MainWindow *mainWindowUI);



private:
    Ui::Find *ui;
};

#endif // FIND_H
