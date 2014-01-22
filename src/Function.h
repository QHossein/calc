#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>

bool bozorgtar(QString , QString);
bool Equal (QString , QString);

QString Ecal(QString , QString , QString);
QString Calc(QString);

QString In_to_Post(QString);
QString In_to_Pre(QString);
QString Pre_to_In(QString);
QString Pre_to_Post(QString);
QString Post_to_In(QString);
QString Post_to_Pre(QString);

bool isInfix(QString);
bool isPrefix(QString);
bool isPostfix(QString);


#endif // FUNCTION_H

