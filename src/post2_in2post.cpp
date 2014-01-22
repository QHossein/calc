#include "post2_in2post.h"
#include "ui_post2_in2post.h"
#include "Function.h"
#include <QStack>

Post2_In2Post::Post2_In2Post(QWidget *parent , QString _expression , QString _type) :
    QDialog(parent),
    ui(new Ui::Post2_In2Post)
{

    ui->setupUi(this);

    expression = _expression;
    phr = expression.split(" ");
    type = _type;

    if (type != "in2post")
    {
        ui->lneRes->hide();
        ui->label_res->hide();
    }
}

Post2_In2Post::~Post2_In2Post()
{
    delete ui;
}

void Post2_In2Post::In2Post(QStringList &phrase)
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
                ui->lneExp->setText(phrase.join(" "));
                return;
            }

            else if (phrase.at(i)==l[j])
            {

                if (stack.isEmpty() || phrase.at(i)=="(" || bozorgtar( phrase.at(i) , stack.top() ) )
                {
                    stack.push(phrase.at(i));

                    int index = ui->stackTable->columnCount();
                    ui->stackTable->insertColumn(index);
                    QTableWidgetItem *t = new QTableWidgetItem();
                    t->setText(phrase.at(i));
                    t->setTextAlignment(Qt::AlignCenter);
                    ui->stackTable->setItem( 0, index, t);
                    ui->stackTable->scrollToItem(t);

                    phrase.removeFirst();
                    ui->lneExp->setText(phrase.join(" "));
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
                    ui->lneExp->setText(phrase.join(" "));
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

    while (!stack.isEmpty())
    {
        temp = stack.pop();
        result.append(temp);
        ui->lneRes->insert(temp + " ");
        ui->stackTable->removeColumn(ui->stackTable->columnCount()-1);

        if (stack.isEmpty())
            ui->btnGo->setText("Close");

        return;
    }

    if (stack.isEmpty())
        ui->btnGo->setText("Close");
}


void Post2_In2Post::PostTo(QStringList &phrase)
{
    QString l[4]={"+" , "-" , "*" , "/" };

    for (int i=0; i<phrase.size(); i++)
        for (int j=0 ; j<4 ; j++)
        {
            if (phrase.at(i)!=l[j] && j==3)
            {
                stack.push(phrase.at(i));

                int index = ui->stackTable->columnCount();
                ui->stackTable->insertColumn(index);
                QTableWidgetItem *t = new QTableWidgetItem();
                t->setText(phrase.at(i));
                t->setTextAlignment(Qt::AlignCenter);
                ui->stackTable->setItem( 0, index, t);
                ui->stackTable->scrollToItem(t);

                ui->lneRes->insert(phrase.at(i) + " ");
                phrase.removeFirst();
                ui->lneExp->setText(phrase.join(" "));
                return;
            }

            else if ( phrase.at(i)==l[j] )
            {
                if (stack.size()<2)
                    return ;

                QString r1 = stack.pop();
                QString r2 = stack.pop();

                QString temp;

                if (type == "post2in")
                    temp = "( " + r2 + " " + phrase.at(i) + " " + r1 + " )";

                else if (type == "post2pre")
                    temp =  phrase.at(i) + " " + r2 + " " + r1 ;

                stack.push(temp);
                ui->stackTable->removeColumn(ui->stackTable->columnCount()-1);
                ui->stackTable->item(0,ui->stackTable->columnCount()-1)->setText(temp);

                phrase.removeFirst();
                ui->lneExp->setText(phrase.join(" "));

                if (phrase.size()==0)
                    ui->btnGo->setText("Close");
                return;
            }
        }
}

void Post2_In2Post::on_btnGo_clicked()
{
    if (ui->btnGo->text()=="Go")
    {
        ui->lneExp->setText(expression);
        ui->btnGo->setText("Next step");
    }

    else if (ui->btnGo->text()=="Next step")
    {
        if (type == "in2post")
            In2Post(phr);

        else
            PostTo(phr);
    }

    else if (ui->btnGo->text()=="Close")
        this->close();
}

