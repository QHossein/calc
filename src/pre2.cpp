#include "pre2.h"
#include "ui_pre2.h"
#include <QStack>

Pre2::Pre2(QWidget *parent , QString _expression , QString _type) :
    QDialog(parent),
    ui(new Ui::Pre2)
{
    ui->setupUi(this);
    expression = _expression;
    phr = expression.split(" ");
    type = _type;
}

Pre2::~Pre2()
{
    delete ui;
}

void Pre2::PreTo(QStringList &phrase)
{
    QString l[4]={"+" , "-" , "*" , "/" };

    for (int j=0; j<4; j++)
    {
        if (!stack2.isEmpty() && stack2.top()=="0")
        {
            stack2.pop();
            QString r1 = stack3.pop();
            QString r2 = stack3.pop();
            QString r = stack1.pop();

            QString temp;

            if (type == "pre2in")
                    temp = "( "  + r2 + " " + r + " " + r1 + " )";

            else if (type == "pre2post")
                    temp = r2 + " " + r1 + " " + r ;

            stack3.push(temp);
            ui->stackTable1->removeColumn(ui->stackTable1->columnCount()-1);
            ui->stackTable2->removeColumn(ui->stackTable2->columnCount()-1);
            ui->stackTable2->item(0 , ui->stackTable2->columnCount()-1)->setText(temp);

            if (stack2.isEmpty())
            {
              ui->btnGo->setText("Close");
              stack3.clear();
            }
            return;
        }

        if (!phrase.isEmpty() && phrase.at(0)==l[j])
        {
            stack1.push(phrase.at(0));
            stack2.push("2");

            int index = ui->stackTable1->columnCount();
            ui->stackTable1->insertColumn(index);
            QTableWidgetItem *t1 = new QTableWidgetItem();
            t1->setText(phrase.at(0));
            t1->setTextAlignment(Qt::AlignCenter);
            ui->stackTable1->setItem( 0, index, t1);

            QTableWidgetItem *t2 = new QTableWidgetItem();
            t2->setText("2");
            t2->setTextAlignment(Qt::AlignCenter);
            ui->stackTable1->setItem( 1, index, t2);

            ui->stackTable1->scrollToItem(t1);

            phrase.removeFirst();
            ui->lneExp->setText(phrase.join(" "));
            return;
        }

        else if (phrase.isEmpty() || (phrase.at(0)!=l[j] && j==3) )
        {
            if (!phrase.isEmpty())
            {
                stack3.push(phrase.at(0));

                int index = ui->stackTable2->columnCount();
                ui->stackTable2->insertColumn(index);
                QTableWidgetItem *t1 = new QTableWidgetItem();
                t1->setText(phrase.at(0));
                t1->setTextAlignment(Qt::AlignCenter);
                ui->stackTable2->setItem( 0, index, t1);
            }

            if (stack2.top()=="2")
            {
                stack2.pop();
                stack2.push("1");
                ui->stackTable1->item(1 , ui->stackTable1->columnCount()-1)->setText("1");
                phrase.removeFirst();
                ui->lneExp->setText(phrase.join(" "));
                return;
            }
            else if (stack2.top()=="1")
            {
                stack2.pop();

                if (!stack2.isEmpty())
                 {
                    if (stack2.top()=="2")
                    {
                         stack2.pop();
                         stack2.push("1");
                         stack2.push("0");
                         ui->stackTable1->item(1 , ui->stackTable1->columnCount()-2)->setText("1");
                         ui->stackTable1->item(1 , ui->stackTable1->columnCount()-1)->setText("0");

                         phrase.removeFirst();
                         ui->lneExp->setText(phrase.join(" "));
                         return;
                    }
                    else
                    {
                        ui->stackTable1->item(1 , ui->stackTable1->columnCount()-1)->setText("0");

                        int counter = 2;
                        while (!stack2.isEmpty() && stack2.top()=="1")
                        {
                            ui->stackTable1->item(1 , ui->stackTable1->columnCount()-counter)->setText("0");
                            stack2.pop();
                            counter++;
                        }

                        if (!stack2.isEmpty() && stack2.top()=="2")
                        {
                            stack2.pop();
                            stack2.push("1");
                            ui->stackTable1->item(1 , ui->stackTable1->columnCount()-counter)->setText("1");
                        }

                        for (int i=0 ; i<counter-1 ; i++)
                            stack2.push("0");

                        phrase.removeFirst();
                        ui->lneExp->setText(phrase.join(" "));
                        return;
                    }
                }
                stack2.push("0");
                ui->stackTable1->item(1,0)->setText("0");
                if (!phrase.isEmpty())
                {
                    phrase.removeFirst();
                    ui->lneExp->setText(phrase.join(" "));
                }
            }
        }
    }
}

void Pre2::on_btnGo_clicked()
{
    if (ui->btnGo->text()=="Go")
    {
        ui->lneExp->setText(expression);
        ui->btnGo->setText("Next step");
    }

    else if (ui->btnGo->text()=="Next step")
        PreTo(phr);

    else if (ui->btnGo->text()=="Close")
        this->close();
}
