#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QString file;
    explicit MainWindow(QString fileName = 0,QWidget *parent = 0);
    ~MainWindow();

    void readFile(QString &file);
    void writeFile();
    void writeFile(QString &file);
    

private slots:
    void on_action_Word_Wrap_toggled(bool arg1);

    void on_action_Select_A_triggered();

    void on_action_Cut_triggered();

    void on_actionC_opy_triggered();

    void on_action_Paste_triggered();

    void on_action_Undo_triggered();

    void on_action_Find_triggered();

    void on_actionFInd_Next_triggered();

    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_actionSave_As_triggered();

    void on_action_Print_triggered();

    void on_actionRe_do_triggered();

    void on_action_Replace_triggered();

    void on_action_Go_to_triggered();

    void on_action_Font_triggered();

    void on_action_About_triggered();

    void on_action_View_Help_triggered();

    void on_action_Status_Bar_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
