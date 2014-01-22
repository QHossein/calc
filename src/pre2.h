#ifndef PRE2_H
#define PRE2_H

#include <QDialog>
#include <QStack>

namespace Ui {
    class Pre2;
}
///
/// \brief convert prefix to infix & prefix to postfix
///
class Pre2 : public QDialog
{
    Q_OBJECT

public:
    explicit Pre2(QWidget *parent = 0 , QString _expression = "" , QString _type = "");
    void PreTo(QStringList &);
    ~Pre2();

private:
    Ui::Pre2 *ui;
    QString expression;
    QString type;
    QStringList phr;
    QStack <QString> stack1 , stack2 , stack3;

private slots:
    void on_btnGo_clicked();
};

#endif
