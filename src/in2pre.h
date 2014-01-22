#ifndef IN2PRE_H
#define IN2PRE_H

#include <QDialog>
#include <QStack>
namespace Ui {
    class in2pre;
}
///
/// \brief convert infix to postfix
///
class in2pre : public QDialog
{
    Q_OBJECT

public:
    explicit in2pre(QWidget *parent = 0 , QString _expression = "");
    void In2Pre(QStringList &);
    QString Reverse (QString);
    ~in2pre();

private:
    Ui::in2pre *ui;
    QString expression;
    QStringList phr;
    QStack <QString> stack;
    QStringList result;


private slots:
    void on_btnGo_clicked();
};

#endif // IN2PRE_H
