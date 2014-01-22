#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionShow_step_triggered();
    void on_lineEdit2_returnPressed();
    void on_lineEdit_returnPressed();
    void on_btnEdit_clicked();
    void on_btnEMinus_clicked();
    void on_btnEPlus_clicked();
    void on_actionExit_triggered();
    void on_btnPlusMinus_clicked();
    void on_actionAbout_triggered();
    void on_btnCopy_clicked();
    void on_btnSpace_clicked();
    void on_btnToPost_clicked();
    void on_btnToIn_clicked();
    void on_btnToPre_clicked();
    void on_btnEqual_clicked();
    void on_btnC_clicked();
    void on_btnBackspace_clicked();

    void on_btnDivide_clicked();
    void on_btnMulty_clicked();
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();

    void on_btnParenLeft_clicked();
    void on_btnParenRight_clicked();

    void on_btnDot_clicked();
    void on_btn9_clicked();
    void on_btn8_clicked();
    void on_btn7_clicked();
    void on_btn6_clicked();
    void on_btn5_clicked();
    void on_btn4_clicked();
    void on_btn3_clicked();
    void on_btn2_clicked();
    void on_btn1_clicked();
    void on_btn0_clicked();
};

#endif // MAINWINDOW_H
