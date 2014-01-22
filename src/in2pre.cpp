#include "in2pre.h"
#include "ui_in2pre.h"
#include "Function.h"
#include <QStack>


in2pre::in2pre(QWidget *parent , QString _expression) :
    QDialog(parent),
    ui(new Ui::in2pre)
{
    ui->setupUi(this);
    expression = _expression;
    phr = Reverse(expression).split(" ");

}

in2pre::~in2pre()
{
    delete ui;
}


QString in2pre::Reverse(QString exp)
{
    QStringList list = exp.split(" ");
    QStringList data;
    for (int i=list.length()-1 ; i >=0 ; i--)
    {
        if (list.at(i)=="(")
            data.append(")");

        else if (list.at(i)==")")
            data.append("(");

        else
            data.append(list.at(i));
    }
    return data.join(" ");
}



void in2pre::In2Pre(QStringList &phrase)
{

    QString temp;
    QString l[6]={"+" , "-" , "*" , "/" , "(" , ")"};

    for (int i=0 ; i<phrase.size()  ; i++)
        for (int j=0 ; j<6 ; j++)
        {
            if ( phrase.at(i)!=l[j] && j==5 )
            {
                result.append(phrase.at(i));
                ui->lneRes->insert(phrase.at(i) + " ");

                phrase.removeFirst();
                ui->lneRev->setText(phrase.join(" "));
                return;
            }

            else if (phrase.at(i)==l[j])
            {

                if (stack.isEmpty() || phrase.at(i)=="(" || bozorgtar( phrase.at(i) , stack.top() ) || Equal( phrase.at(i) , stack.top() ) )
                {
                    stack.push(phrase.at(i));

                    int index = ui->stackTable->columnCount();
                    ui->stackTable->insertColumn(index);
                    QTableWidgetItem *t = new QTableWidgetItem();
                    t->setText(phrase.at(i));
                    t->setTextAlignment(Qt::AlignCenter);
                    ui->stackTable->setItem( 0, index, t );
                    ui->stackTable->scrollToItem(t);

                    phrase.removeFirst();
                    ui->lneRev->setText(phrase.join(" "));
                    return;
                }

                else if (phrase.at(i)==")")
                {
                    while (stack.top()!="(")
                    {
                        temp = stack.pop();
                        result.append(temp);
                        ui->lneRes->insert(temp + " ");
                        ui->stackTable->removeColumn(ui->stackTable->columnCount()-1);
                        return;
                    }

                    stack.pop();
                    ui->stackTable->removeColumn(ui->stackTable->columnCount()-1);
                    phrase.removeFirst();
                    ui->lneRev->setText(phrase.join(" "));
                    return;
                }

                else
                {
                    while (!stack.isEmpty() && !bozorgtar( phrase.at(i) , stack.top() ))
                    {
                        temp = stack.pop();
                        result.append(temp);
                        ui->lneRes->insert(temp + " ");
                        ui->stackTable->removeColumn(ui->stackTable->columnCount()-1);
                        return;
                    }
                }
                break;
            }
        }

    while (! stack.isEmpty())
    {
        temp = stack.pop();
        result.append(temp);
        ui->lneRes->insert(temp + " ");
        ui->stackTable->removeColumn(ui->stackTable->columnCount()-1);
        return;
    }

    ui->lneRev_2->setText(Reverse(result.join(" ")));
    ui->btnGo->setText("Close");
}


void in2pre::on_btnGo_clicked()
{
    if (ui->btnGo->text()=="Go")
    {
        ui->lneExp->setText(expression);
        ui->btnGo->setText("Next step");
    }

    else if (ui->btnGo->text()=="Next step")
    {
        if (ui->lneExp->isEnabled())
        {
            ui->lneRev->setText(phr.join(" "));
            ui->lneExp->setDisabled(1);
            return;
        }
        else
            In2Pre(phr);
    }

    else if (ui->btnGo->text()=="Close")
        this->close();
}
