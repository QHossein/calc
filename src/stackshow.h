#ifndef STACKSHOW_H
#define STACKSHOW_H

#include <QDialog>

namespace Ui {
    class stackShow;
}

class stackShow : public QDialog
{
    Q_OBJECT

public:
    explicit stackShow(QWidget *parent = 0);
    void In2Post(QStringList &);
    void Post2Pre(QStringList &);
    void Post2In(QStringList &);
    void setExpPhr(QString exp) {expression = exp; phr=exp.split(' ');}
    QStringList phr;
    ~stackShow();

private:
    Ui::stackShow *ui;
    QString expression;

private slots:
    void on_btnGo_clicked();
};

#endif // STACKSHOW_H
