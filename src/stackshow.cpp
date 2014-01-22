#include "stackshow.h"
#include "ui_stackshow.h"
#include <QStack>

stackShow::stackShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stackShow)
{
    ui->setupUi(this);

}

stackShow::~stackShow()
{
    delete ui;
}

bool bozorgtarAz(QString x , QString y)
{
    if ( (x=="*" || x=="/") && ( y=="+" || y=="-" || y=="(" ) )
        return true;

    if ( (x=="+" || x=="-") && y=="(" )
        return true;

    return false;
}


void stackShow::In2Post(QStringList &phrase)
{
    static QStack <QString> stack;
    static QStringList result;
    QString r , q;


    QString l[6]={"+" , "-" , "*" , "/" , "(" , ")"};

    for (int i=0 ; i<phrase.size()  ; i++)
        for (int j=0 ; j<6 ; j++)
        {
            if ( phrase.at(i)!=l[j] && j==5 )
            {
                result.append(phrase.at(i));
                ui->lneRes->insert(phrase.at(i) + " ");
                phrase.removeFirst();
                r = phrase.join(" ");
                ui->lneExp->setText(r);
                return;
            }

            else if (phrase.at(i)==l[j])
            {

                if (stack.isEmpty() || phrase.at(i)=="(" || bozorgtarAz( phrase.at(i) , stack.top() ) )
                {
                    stack.push(phrase.at(i));
                    ui->lneStack->insert(phrase.at(i) + " ");
                    phrase.removeFirst();
                    r = phrase.join(" ");
                    ui->lneExp->setText(r);
                    return;
                }

                else if (phrase.at(i)==")")
                {
                    while (stack.top()!="(")
                    {
                        q=stack.pop();
                        result.append(q);
                        ui->lneRes->insert(q + " ");
                        q=ui->lneStack->text();
                        q.remove(q.size()-2,2);
                        ui->lneStack->setText(q);
                        return;
                    }

                    stack.pop();
                    q=ui->lneStack->text();
                    q.remove(q.size()-2,2);
                    ui->lneStack->setText(q);
                    phrase.removeFirst();
                    QString r = phrase.join(" ");
                    ui->lneExp->setText(r);
                    return;
                }

                else
                {
                    while (!stack.isEmpty() && !bozorgtarAz( phrase.at(i) , stack.top() ))
                    {
                        q=stack.pop();
                        result.append(q);
                        ui->lneRes->insert(q + " ");
                        q=ui->lneStack->text();
                        q.remove(q.size()-2,2);
                        ui->lneStack->setText(q);
                        return;
                    }
                }
                break;
            }
        }

    while (! stack.isEmpty())
    {
        q=stack.pop();
        result.append(q);
        ui->lneRes->insert(q + " ");
        q=ui->lneStack->text();
        q.remove(q.size()-2,2);
        ui->lneStack->setText(q);
        return;
    }

    ui->btnGo->setText("Close");
}


void stackShow::Post2Pre(QStringList &phrase)
{
    static QStack <QString> stack;
    QString r,r1,r2;

    QString l[4]={"+" , "-" , "*" , "/" };

    for (int i=0; i<phrase.size(); i++)
        for (int j=0 ; j<4 ; j++)
        {
            if (phrase.at(i)!=l[j] && j==3)
            {
                stack.push(phrase.at(i));
                ui->lneRes->insert(phrase.at(i) + " ");
                phrase.removeFirst();
                r = phrase.join(" ");
                ui->lneExp->setText(r);
                return;

            }

            else if ( phrase.at(i)==l[j] )
            {
                if (stack.size()<2)
                    return ;

                QStringList t = stack.toList();
                t.removeLast();
                t.removeLast();
                r = t.join(" ");

                r1=stack.pop();
                r2=stack.pop();
                stack.push( phrase.at(i) + " " + r2 + " " + r1 );

                ui->lneRes->setText( phrase.at(i) + " " + r2 + " " + r1 + " ");
                ui->lneStack->setText( r + " " + phrase.at(i) + " " + r2 + " " + r1 + " ");
                phrase.removeFirst();
                r = phrase.join(" ");
                ui->lneExp->setText(r);
                if (phrase.size()==0)
                    stack.clear();

                return;
            }
        }
}

void stackShow::Post2In(QStringList &phrase)
{
    static QStack <QString> stack;
    QString r,r1,r2;

    QString l[4]={"+" , "-" , "*" , "/" };

    for (int i=0; i<phrase.size(); i++)
        for (int j=0 ; j<4 ; j++)
        {
            if (phrase.at(i)!=l[j] && j==3)
            {
                stack.push(phrase.at(i));
                ui->lneRes->insert(phrase.at(i) + " ");
                phrase.removeFirst();
                r = phrase.join(" ");
                ui->lneExp->setText(r);
                return;

            }

            else if ( phrase.at(i)==l[j] )
            {
                if (stack.size()<2)
                    return ;

                QStringList t = stack.toList();
                t.removeLast();
                t.removeLast();
                r = t.join(" ");

                r1=stack.pop();
                r2=stack.pop();
                stack.push( "( " + r2 + " " + phrase.at(i) + " " + r1 + " ) ");

                ui->lneRes->setText(  "( " + r2 + " " + phrase.at(i) + " " + r1 + " ) ");
                ui->lneStack->setText( r + " "  "( " + r2 + " " + phrase.at(i) + " " + r1 + " ) ");
                phrase.removeFirst();
                r = phrase.join(" ");
                ui->lneExp->setText(r);
                if (phrase.size()==0)
                    stack.clear();

                return;
            }
        }
}


void stackShow::on_btnGo_clicked()
{
    Post2In(phr);
    /*if (ui->btnGo->text()=="Go")
    {
        ui->lneExp->setText(expression);
        ui->btnGo->setText("Next step");
    }

    else if (ui->btnGo->text()=="Next step")
        In2Post(phr);


    else if (ui->btnGo->text()=="Close")
        this->close();
     */


}

