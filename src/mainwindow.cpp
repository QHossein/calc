#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Function.h"
#include "about.h"
#include "post2_in2post.h"
#include "pre2.h"
#include "in2pre.h"

using namespace Qt;

bool ans=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btn0->setShortcut(Key_0);
    ui->btn1->setShortcut(Key_1);
    ui->btn2->setShortcut(Key_2);
    ui->btn3->setShortcut(Key_3);
    ui->btn4->setShortcut(Key_4);
    ui->btn5->setShortcut(Key_5);
    ui->btn6->setShortcut(Key_6);
    ui->btn7->setShortcut(Key_7);
    ui->btn8->setShortcut(Key_8);
    ui->btn9->setShortcut(Key_9);
    ui->btnDot->setShortcut(Key_Period);

    ui->btnPlus->setShortcut(Key_Plus);
    ui->btnMinus->setShortcut(Key_Minus);
    ui->btnMulty->setShortcut(Key_Asterisk);
    ui->btnDivide->setShortcut(Key_Slash);

    ui->btnC->setShortcut(Key_Delete);
    ui->btnBackspace->setShortcut(Key_Backspace);

    ui->btnSpace->setShortcut(Key_Space);
    ui->btnEqual->setShortcut(Key_Enter);

    ui->btnParenLeft->setShortcut(Key_ParenLeft);
    ui->btnParenRight->setShortcut(Key_ParenRight);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn1_clicked()
{
    (ans==true)? ui->lineEdit->setText("1") : ui->lineEdit->insert("1");
    ans=false;
}

void MainWindow::on_btn2_clicked()
{

    (ans==true)? ui->lineEdit->setText("2") : ui->lineEdit->insert("2");
    ans=false;
}

void MainWindow::on_btn3_clicked()
{
    (ans==true)? ui->lineEdit->setText("3") : ui->lineEdit->insert("3");
    ans=false;
}


void MainWindow::on_btn4_clicked()
{
    (ans==true)? ui->lineEdit->setText("4") : ui->lineEdit->insert("4");
    ans=false;
}

void MainWindow::on_btn5_clicked()
{
    (ans==true)? ui->lineEdit->setText("5") : ui->lineEdit->insert("5");
    ans=false;
}

void MainWindow::on_btn6_clicked()
{
    (ans==true)? ui->lineEdit->setText("6") : ui->lineEdit->insert("6");
    ans=false;
}

void MainWindow::on_btn7_clicked()
{
    (ans==true)? ui->lineEdit->setText("7") : ui->lineEdit->insert("7");
    ans=false;
}

void MainWindow::on_btn8_clicked()
{
    (ans==true)? ui->lineEdit->setText("8") : ui->lineEdit->insert("8");
    ans=false;
}

void MainWindow::on_btn9_clicked()
{
    (ans==true)? ui->lineEdit->setText("9") : ui->lineEdit->insert("9");
    ans=false;
}

void MainWindow::on_btnDot_clicked()
{
    (ans==true)? ui->lineEdit->setText(".") : ui->lineEdit->insert(".");
    ans=false;
}

void MainWindow::on_btn0_clicked()
{
    (ans==true)? ui->lineEdit->setText("0") : ui->lineEdit->insert("0");
    ans=false;
}

void MainWindow::on_btnSpace_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text[text.size()-1]==' ' )
        return;

    else
        ui->lineEdit->insert(" ");

    ans=false;
}

void MainWindow::on_btnParenLeft_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text[text.size()-1]==' ' )
        (ans==true)? ui->lineEdit->setText("( ") : ui->lineEdit->insert("( ");

    else
        (ans==true)? ui->lineEdit->setText(" ( ") : ui->lineEdit->insert(" ( ");

    ans=false;
}

void MainWindow::on_btnParenRight_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty())
        return;

    if (text[text.size()-1]==' ' )
        (ans==true)? ui->lineEdit->setText(") ") : ui->lineEdit->insert(") ");

    else
        (ans==true)? ui->lineEdit->setText(" ) ") : ui->lineEdit->insert(" ) ");

    ans=false;
}

void MainWindow::on_btnMinus_clicked()
{

    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text[text.size()-1]==' ' )
        ui->lineEdit->insert("- ");
    else
        ui->lineEdit->insert(" - ");

    ans=false;
}

void MainWindow::on_btnPlus_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text[text.size()-1]==' ' )
        ui->lineEdit->insert("+ ");
    else
        ui->lineEdit->insert(" + ");

    ans=false;
}

void MainWindow::on_btnMulty_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text[text.size()-1]==' ' )
        ui->lineEdit->insert("* ");
    else
        ui->lineEdit->insert(" * ");

    ans=false;
}

void MainWindow::on_btnDivide_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text[text.size()-1]==' ' )
        ui->lineEdit->insert("/ ");

    else
        ui->lineEdit->insert(" / ");

    ans=false;
}

void MainWindow::on_btnPlusMinus_clicked()
{
    QString text=ui->lineEdit->text();
    QStringList textList = text.split(" ");
    text = textList.at(textList.size()-1);
    if (text[0]=='-')
            text.remove(0,1);
    else
        text.prepend('-');

    textList.removeLast();
    textList.append(text);
    text = textList.join(" ");
    ui->lineEdit->setText(text);
    ans=false;
}

void MainWindow::on_btnEPlus_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text [text.size()-1]==' ')
        return;

    ui->lineEdit->insert("e+");
    ans=false;
}

void MainWindow::on_btnEMinus_clicked()
{
    QString text=ui->lineEdit->text();
    if (text.isEmpty() || text [text.size()-1]==' ')
        return;

    ui->lineEdit->insert("e-");
    ans=false;
}

void MainWindow::on_btnBackspace_clicked()
{
    QString text=ui->lineEdit->text();
    if (!text.isEmpty() && text[text.size()-1]==' ')
        ui->lineEdit->backspace();

    ui->lineEdit->backspace();

    ans=false;
}

void MainWindow::on_btnC_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_btnCopy_clicked()
{
    QString text=ui->lineEdit2->text();
    ui->lineEdit->setText(text);

    ans=false;
}


void MainWindow::on_btnEqual_clicked()
{
    ans=true;
    QString text = ui->lineEdit->text();
    ui->lineEdit->clear();
    if (text.isEmpty())
        return;
    if (text [text.size()-1] == ' ')
            text.remove(text.size()-1, text.size() );

    if (isPostfix(text))
    {
        ui->lineEdit->setText(Calc(text));
        (Calc(text)=="") ? ui->lineEdit2->setText("") : ui->lineEdit2->setText(text);
    }

    else if (isPrefix(text))
    {
        ui->lineEdit->setText(Calc(Pre_to_Post(text)));
        ui->lineEdit2->setText(text);
    }

    else
    {
        ui->lineEdit->setText(Calc(In_to_Post(text)));
        ui->lineEdit2->setText(text);
    }
}

void MainWindow::on_btnToPre_clicked()
{

    QString text = ui->lineEdit->text();

    ui->lineEdit->clear();
    if (text.isEmpty())
        return;

    if (text [text.size()-1] == ' ')
        text.remove(text.size()-1, text.size() );


    if (ui->actionShow_step->isChecked())
    {
        if (isInfix(text))
        {
            in2pre p(0 , text);
            p.exec();
        }
        else if (isPostfix(text))
        {
            Post2_In2Post p(0 , text , "post2pre");
            p.exec();
        }

    }


    if (isPrefix(text) && isPostfix(text)) // text not valid
        ui->lineEdit->setText("");

    else if (isPrefix(text))
         ui->lineEdit->setText(text);

    else if (isPostfix(text))
    {
        ui->lineEdit->setText( Post_to_Pre(text)); // postfix 2 prefix
        ui->lineEdit2->setText(text);
    }

    else if (isInfix(text))
    {
        ui->lineEdit->setText( In_to_Pre(text)); // infix 2 prefix
        ui->lineEdit2->setText(text);
    }
}

void MainWindow::on_btnToIn_clicked()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->clear();
    if (text.isEmpty())
        return;

    if (text [text.size()-1] == ' ')
        text.remove(text.size()-1, text.size() );


    if (ui->actionShow_step->isChecked())
    {
        if (isPostfix(text))
        {
            Post2_In2Post p(0 , text , "post2in");
            p.exec();

        }

        else if (isPrefix(text))
        {
            Pre2 p(0 , text , "pre2in");
            p.exec();
        }
    }


    if (isPrefix(text) && isPostfix(text)) // text not valid
        ui->lineEdit->setText("");

    else if (isInfix(text))
         ui->lineEdit->setText(text);

    else if (isPostfix(text))
    {
        ui->lineEdit->setText( Post_to_In(text)); // postfix 2 infix
        (Post_to_In(text)=="")? ui->lineEdit2->setText("") : ui->lineEdit2->setText(text);
    }

    else if (isPrefix(text))
    {
        ui->lineEdit->setText( Pre_to_In(text)); // prefix 2 infix
        ui->lineEdit2->setText(text);
    }

}

void MainWindow::on_btnToPost_clicked()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->clear();
    if (text.isEmpty())
        return;

    if (text [text.size()-1] == ' ')
        text.remove(text.size()-1, text.size() );


    if (ui->actionShow_step->isChecked())
    {
        if (isInfix(text))
        {
            Post2_In2Post p(0 , text , "in2post");
            p.exec();
        }

        else if (isPrefix(text))
        {
            Pre2 p(0 , text , "pre2post");
            p.exec();
        }

    }


    if (isPrefix(text) && isPostfix(text)) // text not valid
        ui->lineEdit->setText("");

    else if (isPostfix(text))
         ui->lineEdit->setText(text);

    else if (isInfix(text))
    {
        ui->lineEdit->setText( In_to_Post(text)); // infix 2 postfix
        ui->lineEdit2->setText(text);
    }

    else if (isPrefix(text))
    {
        ui->lineEdit->setText( Pre_to_Post(text)); // prefix 2 postfix
        ui->lineEdit2->setText(text);
    }
}

void MainWindow::on_actionAbout_triggered()
{
    //QMessageBox::information(this, tr("About Calculator"),tr("this Application designed by Mr.s.h.h"));
    this->close();
    About x;
    x.exec();
    this->show();

}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox::information(this, tr("Thank"),tr("Thank you for choose this application"));
    exit(0);
}

void MainWindow::on_btnEdit_clicked()
{
    if (ui->btnEdit->text()=="Edit")
    {
        ui->lineEdit->setReadOnly(0);
        ui->btnEdit->setText("Ok");
    }

    else
    {
        ui->lineEdit->setReadOnly(1);
        ui->btnEdit->setText("Edit");
    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    ui->btnEqual->click();
}

void MainWindow::on_lineEdit2_returnPressed()
{
    ui->btnEqual->click();
}



void MainWindow::on_actionShow_step_triggered()
{
    if (ui->actionShow_step->isChecked())
        statusBar()->showMessage(tr("show steps is on"));
    else
        statusBar()->showMessage(tr("show steps is off"));
}
