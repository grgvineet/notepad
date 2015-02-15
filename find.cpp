#include "find.h"
#include "ui_find.h"

Find::Find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);

}

Find::~Find()
{
    delete ui;
}

void Find::getMainWindowUI(Ui::MainWindow *mainWindowUI){

//    int caseSensitive,matchWholeWord,findBackward;

//    caseSensitive = (ui->matchCase->isChecked()? QTextDocument::FindCaseSensitively : 0);
//    matchWholeWord = (ui->matchWholeWord->isChecked() ? QTextDocument::FindWholeWords : 0);
//    findBackward = (ui->searchBackward->isChecked() ? QTextDocument::FindBackward : 0);

////    QFlag<FindFlag> option =  caseSensitive | matchWholeWord | findBackward ;
////    QTextDocument::Find

////    QTextDocument::FindFlags options = caseSensitive | matchWholeWord | findBackward ;
//    QTextDocument::FindFlag ff(caseSensitive);
//    mainWindowUI->plainTextEdit->find()
////    if (mainWindowUI->plainTextEdit->find(ui->findLineEdit->text(),caseSensitive)){
////        // nothing to do
////    }else{

////    }
}
