#include "mainwindow.h"
#include "find.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QPrintDialog>
#include <QPrinter>


MainWindow::MainWindow(QString fileName,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPlainTextEdit *area = ui->plainTextEdit;
    setCentralWidget(area);

    file = fileName;
    if (fileName != NULL){
        readFile(fileName);
    }

    connect(ui->plainTextEdit,SIGNAL(undoAvailable(bool)),ui->action_Undo,SLOT(setEnabled(bool)));
    connect(ui->plainTextEdit,SIGNAL(redoAvailable(bool)),ui->actionRe_do,SLOT(setEnabled(bool)));
    connect(ui->plainTextEdit,SIGNAL(copyAvailable(bool)),ui->actionC_opy,SLOT(setEnabled(bool)));
    connect(ui->plainTextEdit,SIGNAL(copyAvailable(bool)),ui->action_Cut,SLOT(setEnabled(bool)));
    connect (ui->plainTextEdit,SIGNAL(copyAvailable(bool)),ui->actionFInd_Next,SLOT(setChecked(bool)));

    connect(ui->action_Exit,SIGNAL(triggered()),this,SLOT(close()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile(QString &fileName){
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream textStream(&file);
    QString line = textStream.readAll();
    file.close();
    ui->plainTextEdit->appendPlainText(line);
}

void MainWindow::writeFile(){

}

void MainWindow::writeFile(QString &file){

}


void MainWindow::on_action_New_triggered()
{
    MainWindow *w = new MainWindow();
    w->show();
}


void MainWindow::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));

    if (fileName != NULL){
        if (ui->plainTextEdit->toPlainText().length() < 1){
            readFile(fileName);
        }else{
            MainWindow *w = new MainWindow(fileName);
            w->show();
        }
    }
}

void MainWindow::on_action_Save_triggered()
{
QString temp  = QFileDialog::getSaveFileName(this,
                                            tr("Save File"), "",
                                             tr("All Files (*.*)"));
}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_action_Print_triggered()
{
    QTextDocument *document = ui->plainTextEdit->document();
    QPrinter printer;

    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (dlg->exec() != QDialog::Accepted)
        return;

    document->print(&printer);

}

void MainWindow::on_action_Undo_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionRe_do_triggered()
{
    ui->plainTextEdit->redo();
}


void MainWindow::on_action_Cut_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionC_opy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_action_Paste_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_action_Find_triggered()
{
    Find find;
    find.getMainWindowUI(ui);
    find.setModal(false);
    find.exec();
    ui->plainTextEdit->find("hell");

}

void MainWindow::on_actionFInd_Next_triggered()
{
    if (ui->plainTextEdit->find(ui->plainTextEdit->textCursor().selectedText())){
        // since statement is true, do nothing :)
    }else{
        QMessageBox::information(this,"Error","Reached to end of document");
    }
}

void MainWindow::on_action_Replace_triggered()
{

}

void MainWindow::on_action_Go_to_triggered()
{

}

void MainWindow::on_action_Select_A_triggered()
{
    ui->plainTextEdit->selectAll();
}

void MainWindow::on_action_Word_Wrap_toggled(bool arg1)
{

    if (arg1){
        ui->plainTextEdit->setWordWrapMode(QTextOption::WordWrap);
    }else{
        ui->plainTextEdit->setWordWrapMode(QTextOption::NoWrap);
    }

}

void MainWindow::on_action_Font_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                     &ok, QFont("Helvetica [Cronyx]", 10), this);
     if (ok) {
         // the user clicked OK and font is set to the font the user selected
         ui->plainTextEdit->setFont(font);
     } else {
         // the user canceled the dialog; font is set to the initial
         // value, in this case Helvetica [Cronyx], 10
     }
}

void MainWindow::on_action_About_triggered()
{
    QMessageBox::about(this,"About Notepad","This Notepad is design and developed by Vineet Garg using Qt 5 for educational purposes");
}

void MainWindow::on_action_View_Help_triggered()
{

}

void MainWindow::on_action_Status_Bar_triggered()
{

}
