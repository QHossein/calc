#ifndef POST2_IN2POST_H
#define POST2_IN2POST_H

#include <QDialog>
#include <QStack>
namespace Ui {
    class Post2_In2Post;
}
///
/// \brief Convert Postfix to prefix & postfix to infix. also convert infix to postfix
///
class Post2_In2Post : public QDialog
{
    Q_OBJECT

public:
    explicit Post2_In2Post(QWidget *parent = 0, QString _exp = "" , QString _type = "");
    void In2Post(QStringList &);
    void PostTo(QStringList &);
    ~Post2_In2Post();

private:
    Ui::Post2_In2Post *ui;
    QString expression;
    QString type;
    QStringList phr;
    QStack <QString> stack;
    QStringList result;


private slots:
    void on_btnGo_clicked();
};

#endif // POST2_IN2POST_H
