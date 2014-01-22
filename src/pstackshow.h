#ifndef PSTACKSHOW_H
#define PSTACKSHOW_H

#include <QDialog>

namespace Ui {
    class PStackShow;
}

class PStackShow : public QDialog
{
    Q_OBJECT

public:
    explicit PStackShow(QWidget *parent = 0);
    void Pre2In(QStringList &);
    void Pre2Post(QStringList &);

    void setExpPhr(QString exp) {expression = exp; phr=exp.split(' ');}
    QStringList phr;
    ~PStackShow();

private:
    Ui::PStackShow *ui;
    QString expression;

private slots:
    void on_btnGo_clicked();
};

#endif // PSTACKSHOW_H
