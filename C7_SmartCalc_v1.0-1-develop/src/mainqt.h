#ifndef MAINQT_H
#define MAINQT_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QToolTip>

QT_BEGIN_NAMESPACE
namespace Ui { class MainQT; }
QT_END_NAMESPACE

class MainQT : public QMainWindow
{
    Q_OBJECT

public:
    MainQT(QWidget *parent = nullptr);
    ~MainQT();

protected:
     void keyPressEvent(QKeyEvent *event);

private slots:
    void on_Button_reset_clicked();
    void on_Button_result_clicked();
    void push_button_digit();
    void on_Button_dot_clicked();
    void on_Button_sign_clicked();
    void push_button_operator();
    void push_button_func();

    void on_Button_Graphic_clicked();
    void on_Button_ClearGraph_clicked();
    void showToolTip();

    void on_lineEdit_x_editingFinished();
    void on_button_calc_credit_clicked();
    void on_button_clear_credit_clicked();

private:
    Ui::MainQT *ui;
};
#endif // MAINQT_H
