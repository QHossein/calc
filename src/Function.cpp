#include "Function.h"
#include <QStack>
#include <QVariant>


bool bozorgtar(QString x , QString y)
{
    if ( (x=="*" || x=="/") && ( y=="+" || y=="-" || y=="(" ) )
        return true;

    if ( (x=="+" || x=="-") && y=="(" )
        return true;

    return false;
}

bool Equal (QString x,QString y)
{
    if ( (x=="*" || x=="/") && ( y=="*" || y=="/") )
        return true;

    if ( (x=="+" || x=="-") && ( y=="+" || y=="-") )
        return true;
    return false;

}



QString Ecal (QString num1 , QString num2 , QString operand)
{

    QVariant returnVal;
    if (operand=="+")
        returnVal = num1.toDouble() + num2.toDouble();
    if (operand=="-")
        returnVal = num1.toDouble() - num2.toDouble();
    if (operand=="*")
        returnVal = num1.toDouble() * num2.toDouble();
    if (operand=="/")
        returnVal = num1.toDouble() / num2.toDouble();
    return returnVal.toString();
}


QString Calc(QString p)
{
    QStack <QString> stack;
    QString temp , r1 , r2 , r3 ;
    QStringList phrase = p.split(" ");
    QString l[4]={"+" , "-" , "*" , "/" };
    for (int i=0 ; i<phrase.size() ; i++)
    {
        for (int j=0 ; j<4 ; j++)
        {
            if (phrase.at(i)!= l[j] && j==3)
                stack.push(phrase.at(i));

            else if (phrase.at(i)==l[j])
            {
                if (stack.size()<2)
                    return "";

                r1=stack.pop();
                r2=stack.pop();
                stack.push(Ecal(r2 , r1 ,phrase.at(i)));
                break;
            }

        }
   }
   return stack.pop();
}

QString In_to_Post(QString p)
{
    QStack <QString> stack;
    QStringList phrase=p.split(" ");
    QStringList result;
    QString l[6]={"+" , "-" , "*" , "/" , "(" , ")"};

    for (int i=0 ; i<phrase.size()  ; i++)
        for (int j=0 ; j<6 ; j++)
        {
            if ( phrase.at(i)!=l[j] && j==5 )
                result.append(phrase.at(i));

            else if (phrase.at(i)==l[j])
            {

                if (stack.isEmpty())
                    stack.push(phrase.at(i));

                else if (phrase.at(i)=="(")
                    stack.push(phrase.at(i));

                else if ( bozorgtar( phrase.at(i) , stack.top() ) )
                    stack.push(phrase.at(i));

                else if (phrase.at(i)==")")
                {
                    while (stack.top()!="(")
                        result.append(stack.pop());

                    stack.pop();
                }

                else
                {
                    while (!stack.isEmpty() && !bozorgtar( phrase.at(i) , stack.top() ))
                        result.append(stack.pop());

                    stack.push(phrase.at(i));
                }

                break;
            }
        }

    while (! stack.isEmpty())
        result.append(stack.pop());

    p=result.join(" ");
    return p;
}

QString In_to_Pre(QString p)
{
    return Post_to_Pre(In_to_Post(p));
}

QString Pre_to_In(QString p)
{
    if (p=="")
        return "";

    QStack <QString> stack1 , stack2 , stack3;
    QStringList phrase=p.split(" ");
    QString r1 , r2 ;
    QString l[4]={"+" , "-" , "*" , "/" };

    for (int i=0 ; i<phrase.size()  ; i++)
       for (int j=0; j<4; j++)
       {
            if (phrase.at(i)==l[j])
            {
                stack1.push(phrase.at(i));
                stack2.push("2");
                break;
            }

            else if (phrase.at(i)!=l[j] && j==3)
            {
                stack3.push(phrase.at(i));
                if (stack2.top()=="2")
                {
                    stack2.pop();
                    stack2.push("1");
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
                        }
                        else
                            while (stack2.top()=="1")
                            {
                                stack2.pop();
                                if (stack2.size()==0)
                                       break;
                            }

                        if (!stack2.isEmpty())
                        {
                            stack2.pop();
                            stack2.push("1");
                        }
                    }
                    while (stack1.size() > stack2.size())
                    {
                        r1=stack3.pop();
                        r2=stack3.pop();
                        stack3.push("( "  + r2 + " " + stack1.pop() + " " + r1 + " )" );
                    }
                }
            }
       }

    return stack3.top();
}

QString Pre_to_Post(QString p)
{
    return In_to_Post(Pre_to_In(p));
}

QString Post_to_Pre(QString p)
{
    QStack <QString> stack;
    QStringList phrase=p.split(" ");
    QString r1,r2;
    QString l[4]={"+" , "-" , "*" , "/" };

    for (int i=0; i<phrase.size(); i++)
        for (int j=0 ; j<4 ; j++)
        {
            if (phrase.at(i)!=l[j] && j==3)
                stack.push(phrase.at(i));

            else if ( phrase.at(i)==l[j] )
            {
                if (stack.size()<2)
                    return "";

                r1=stack.pop();
                r2=stack.pop();
                stack.push( phrase.at(i) + " " + r2 + " " + r1 );
                break;
            }
        }
    return stack.top();
}

QString Post_to_In(QString p)
{
    return Pre_to_In(Post_to_Pre(p));
}



bool isInfix(QString p)
{
    if (!isPostfix(p) && !isPrefix(p))
        return true;
    return false;
}

bool isPrefix(QString p)
{
    QStringList r=p.split(" ");
    if (r.at(0)=="+" || r.at(0)=="-" || r.at(0)=="*" || r.at(0)=="/")
           return true;
    return false;
}

bool isPostfix(QString p)
{
    QStringList r=p.split(" ");
    int l=r.size()-1;
    if (r.at(l)=="+" || r.at(l)=="-" || r.at(l)=="*" || r.at(l)=="/")
        return true;
    return false;
}

