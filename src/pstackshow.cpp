#include "pstackshow.h"
#include "ui_pstackshow.h"
#include "QStack"

PStackShow::PStackShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PStackShow)
{
    ui->setupUi(this);
}

PStackShow::~PStackShow()
{
    delete ui;
}

void PStackShow::Pre2Post(QStringList &phrase)
{

    static QStack <QString> stack1 , stack2 , stack3;

    QString r , r1 , r2 ;
    QString l[4]={"+" , "-" , "*" , "/" };

    for (int j=0; j<4; j++)
    {
        if (!stack2.isEmpty() && stack2.top()=="0")
        {
            r1=stack3.pop();
            r2=stack3.pop();
            r=stack1.pop();
            stack2.pop();
            QString q= r2 + " " + r1 + " " + r + " " ;
            stack3.push(q);

            r = ui->lneS1->text();
            r.remove(r.size()-2 , 2);
            ui->lneS1->setText(r);

            r = ui->lneS2->text();
            r.remove(r.size()-2 , 2);
            ui->lneS2->setText(r);

            ui->lneS3->setText(q);
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

            ui->lneS1->insert(phrase.at(0) + " ");
            ui->lneS2->insert("2 ");

            phrase.removeFirst();
            r = phrase.join(" ");
            ui->lneExp->setText(r);

            return;
        }

        else if (phrase.isEmpty() || (phrase.at(0)!=l[j] && j==3) )
        {
            if (!phrase.isEmpty())
            {
                stack3.push(phrase.at(0));

                ui->lneS3->insert(phrase.at(0) + " ");

            }

            if (stack2.top()=="2")
            {
                stack2.pop();
                stack2.push("1");

                r = ui->lneS2->text();
                r.remove(r.size()-2 , 2);
                ui->lneS2->setText(r + "1 ");

                phrase.removeFirst();
                r = phrase.join(" ");
                ui->lneExp->setText(r);

                return;

            }
            else if (stack2.top()=="1")
            {
                stack2.pop();

                r = ui->lneS2->text();
                r.remove(r.size()-2 , 2);
                ui->lneS2->setText(r);

                if (!stack2.isEmpty())
                 {
                    if (stack2.top()=="2")
                    {
                         stack2.pop();
                         stack2.push("1");
                         stack2.push("0");

                         r = ui->lneS2->text();
                         r.remove(r.size()-2 , 2);
                         ui->lneS2->setText(r + "1 0 ");

                         phrase.removeFirst();
                         r = phrase.join(" ");
                         ui->lneExp->setText(r);
                         return;

                    }
                    else
                    {
                        QString c="0 ";
                        int conter=1;
                        while (!stack2.isEmpty() && stack2.top()=="1")
                        {
                            stack2.pop();
                            c+="0 ";

                            r = ui->lneS2->text();
                            r.remove(r.size()-2 , 2);
                            ui->lneS2->setText(r);
                            conter++;

                        }
                        if (!stack2.isEmpty() && stack2.top()=="2")
                        {
                            stack2.pop();
                            stack2.push("1");

                            r.remove(r.size()-2 , 2);
                            r +="1 ";

                        }

                        for (int i=0 ; i<conter ; i++)
                            stack2.push("0");

                        ui->lneS2->setText(r + c);

                        phrase.removeFirst();
                        r = phrase.join(" ");
                        ui->lneExp->setText(r);
                        return;
                    }

                }
                stack2.push("0");
                ui->lneS2->setText("0 ");
                if (!phrase.isEmpty())
                {
                    phrase.removeFirst();
                    r = phrase.join(" ");
                    ui->lneExp->setText(r);
                }
            }
        }
    }
}


void PStackShow::Pre2In(QStringList &phrase)
{

    static QStack <QString> stack1 , stack2 , stack3;

    QString r , r1 , r2 ;
    QString l[4]={"+" , "-" , "*" , "/" };

    for (int j=0; j<4; j++)
    {
        if (!stack2.isEmpty() && stack2.top()=="0")
        {
            r1=stack3.pop();
            r2=stack3.pop();
            r=stack1.pop();
            stack2.pop();
            QString q="( "  + r2 + " " + r + " " + r1 + " ) " ;
            stack3.push(q);

            r = ui->lneS1->text();
            r.remove(r.size()-2 , 2);
            ui->lneS1->setText(r);

            r = ui->lneS2->text();
            r.remove(r.size()-2 , 2);
            ui->lneS2->setText(r);

            ui->lneS3->setText(q);
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

            ui->lneS1->insert(phrase.at(0) + " ");
            ui->lneS2->insert("2 ");

            phrase.removeFirst();
            r = phrase.join(" ");
            ui->lneExp->setText(r);

            return;
        }

        else if (phrase.isEmpty() || (phrase.at(0)!=l[j] && j==3) )
        {
            if (!phrase.isEmpty())
            {
                stack3.push(phrase.at(0));

                ui->lneS3->insert(phrase.at(0) + " ");

            }

            if (stack2.top()=="2")
            {
                stack2.pop();
                stack2.push("1");

                r = ui->lneS2->text();
                r.remove(r.size()-2 , 2);
                ui->lneS2->setText(r + "1 ");

                phrase.removeFirst();
                r = phrase.join(" ");
                ui->lneExp->setText(r);

                return;

            }
            else if (stack2.top()=="1")
            {
                stack2.pop();

                r = ui->lneS2->text();
                r.remove(r.size()-2 , 2);
                ui->lneS2->setText(r);

                if (!stack2.isEmpty())
                 {
                    if (stack2.top()=="2")
                    {
                         stack2.pop();
                         stack2.push("1");
                         stack2.push("0");

                         r = ui->lneS2->text();
                         r.remove(r.size()-2 , 2);
                         ui->lneS2->setText(r + "1 0 ");

                         phrase.removeFirst();
                         r = phrase.join(" ");
                         ui->lneExp->setText(r);
                         return;

                    }
                    else
                    {
                        QString c="0 ";
                        int conter=1;
                        while (!stack2.isEmpty() && stack2.top()=="1")
                        {
                            stack2.pop();
                            //stack2.push("0");
                            c+="0 ";

                            r = ui->lneS2->text();
                            r.remove(r.size()-2 , 2);
                            ui->lneS2->setText(r);
                            conter++;

                        }
                        if (!stack2.isEmpty() && stack2.top()=="2")
                        {
                            stack2.pop();
                            stack2.push("1");

                            r.remove(r.size()-2 , 2);
                            r +="1 ";

                        }

                        for (int i=0 ; i<conter ; i++)
                            stack2.push("0");

                        ui->lneS2->setText(r + c);

                        phrase.removeFirst();
                        r = phrase.join(" ");
                        ui->lneExp->setText(r);
                        return;
                    }

                }
                stack2.push("0");
                ui->lneS2->setText("0 ");
                if (!phrase.isEmpty())
                {
                    phrase.removeFirst();
                    r = phrase.join(" ");
                    ui->lneExp->setText(r);
                }
            }
        }
    }
}




void PStackShow::on_btnGo_clicked()
{
    if (ui->btnGo->text()=="Go")
    {
        ui->lneExp->setText(expression);
        ui->btnGo->setText("Next step");
    }

    else if (ui->btnGo->text()=="Next step")
        Pre2Post(phr);


    else if (ui->btnGo->text()=="Close")
        this->close();

}
