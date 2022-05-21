#include "mainqt.h"
#include "ui_mainqt.h"

#ifdef __cplusplus
extern "C" {
#endif
    #include "s21_smartCalc.h"
#ifdef __cplusplus
}
#endif

MainQT::MainQT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainQT)
{
    ui->setupUi(this);


    ui->Button_result->setCheckable(true);
    ui->Button_result->setChecked(false);

    connect(ui->Button_0, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_1, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_2, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_3, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_4, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_5, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_6, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_7, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_8, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_9, SIGNAL(clicked()), this, SLOT(push_button_digit()));

    connect(ui->Button_x, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_openBracket, SIGNAL(clicked()), this, SLOT(push_button_digit()));
    connect(ui->Button_closeBracket, SIGNAL(clicked()), this, SLOT(push_button_digit()));

    connect(ui->Button_mod, SIGNAL(clicked()), this, SLOT(push_button_operator()));
    connect(ui->Button_div, SIGNAL(clicked()), this, SLOT(push_button_operator()));
    connect(ui->Button_plus, SIGNAL(clicked()), this, SLOT(push_button_operator()));
    connect(ui->Button_mult, SIGNAL(clicked()), this, SLOT(push_button_operator()));
    connect(ui->Button_sub, SIGNAL(clicked()), this, SLOT(push_button_operator()));
    connect(ui->Button_pow, SIGNAL(clicked()), this, SLOT(push_button_operator()));

    connect(ui->Button_cos, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_sin, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_tan, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_acos, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_asin, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_atan, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_sqrt, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_ln, SIGNAL(clicked()), this, SLOT(push_button_func()));
    connect(ui->Button_log, SIGNAL(clicked()), this, SLOT(push_button_func()));

}

void MainQT::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::SHIFT) {
        switch (event->key()) {
        case Qt::Key_C:
            ui->Button_acos->animateClick();
            break;
        case Qt::Key_S:
            ui->Button_asin->animateClick();
            break;
        case Qt::Key_T:
            ui->Button_atan->animateClick();
            break;
        case Qt::Key_L:
            ui->Button_log->animateClick();
            break;
        case '(':
            ui->Button_openBracket->animateClick();
            break;
        case ')':
            ui->Button_closeBracket->animateClick();
            break;
        case Qt::Key_Plus:
            ui->Button_plus->animateClick();
            break;
        case Qt::Key_Percent:
            ui->Button_mod->animateClick();
            break;
        case Qt::Key_Asterisk:
            ui->Button_mult->animateClick();
            break;
        case '^':
            ui->Button_pow->animateClick();
            break;
        case Qt::Key_Minus:
            ui->Button_sub->animateClick();
            break;
        }
    } else {
        int len = ui->display->text().length();
        switch (event->key()) {
        case Qt::Key_1:
            ui->Button_1->animateClick();
            break;
        case Qt::Key_2:
            ui->Button_2->animateClick();
            break;
        case Qt::Key_3:
            ui->Button_3->animateClick();
            break;
        case Qt::Key_4:
            ui->Button_4->animateClick();
            break;
        case Qt::Key_5:
            ui->Button_5->animateClick();
            break;
        case Qt::Key_6:
            ui->Button_6->animateClick();
            break;
        case Qt::Key_7:
            ui->Button_7->animateClick();
            break;
        case Qt::Key_8:
            ui->Button_8->animateClick();
            break;
        case Qt::Key_9:
            ui->Button_9->animateClick();
            break;
        case Qt::Key_0:
            ui->Button_0->animateClick();
            break;
        case Qt::Key_Equal:
            ui->Button_result->animateClick();
            break;
        case Qt::Key_Escape:
            if(ui->tabWidget->currentWidget() == ui->Calc){
                ui->Button_reset->animateClick();
            } else if(ui->tabWidget->currentWidget() == ui->Graph){
                ui->Button_ClearGraph->animateClick();
            } else if(ui->tabWidget->currentWidget() == ui->Credit) {
                ui->button_clear_credit->animateClick();
            }
            break;
        case Qt::Key_Return:
            if(ui->tabWidget->currentWidget() == ui->Calc) {
                ui->Button_result->animateClick();
            } else if(ui->tabWidget->currentWidget() == ui->Graph){
                ui->Button_Graphic->click();
            } else if(ui->tabWidget->currentWidget() == ui->Credit) {
                ui->button_calc_credit->animateClick();
            }
            break;
        case '/':
            ui->Button_div->animateClick();
            break;
        case Qt::Key_Backspace:
            ui->display->setText(ui->display->text().remove(len-1,1));
            break;
        case Qt::Key_Delete:
            ui->display->setText(ui->display->text().remove(len-1,1));
            break;
        case '.':
            ui->Button_dot->animateClick();
            break;
        case Qt::Key_Minus:
            ui->Button_sub->animateClick();
            break;
        case Qt::Key_X:
            ui->Button_x->animateClick();
            break;
        case Qt::Key_G:
            ui->Button_Graphic->animateClick();
            break;
        case Qt::Key_C:
            ui->Button_cos->animateClick();
            break;
        case Qt::Key_S:
            ui->Button_sin->animateClick();
            break;
        case Qt::Key_T:
            ui->Button_tan->animateClick();
            break;
        case Qt::Key_Q:
            ui->Button_sqrt->animateClick();
            break;
        case Qt::Key_L:
            ui->Button_ln->animateClick();
            break;
        case Qt::Key_M:
            ui->Button_mod->animateClick();
            break;
        default:
            break;
        }
    }
}

MainQT::~MainQT()
{
    delete ui;
}

void MainQT::on_Button_reset_clicked()
{
    ui->inputTextField->clearFocus();
    ui->inputTextField->clear();

    ui->lineEdit_x->clearFocus();
    ui->lineEdit_x->clear();

    ui->Button_ClearGraph->click();

    ui->display->setText("0");
}

void MainQT::showToolTip()
{
        QToolTip::showText(ui->lineEdit_x->mapToGlobal(QPoint()), "Enter x value!");
}

void MainQT::on_Button_result_clicked()
{
    if(ui->display->text() != "0" && !ui->inputTextField->hasFocus() && ui->display->text() != "ERROR!" && ui->Button_result->isChecked()) {
        ui->inputTextField->setText(ui->inputTextField->text() + ui->display->text());
    }

     if(!ui->inputTextField->text().isEmpty()){
         double x = 0;
         if((ui->inputTextField->text().contains('x') && !ui->lineEdit_x->text().isEmpty()) && ui->lineEdit_x->text() != "0") {
             x = ui->lineEdit_x->text().toDouble();
         } else {
            showToolTip();
         }

         QByteArray ba = ui->inputTextField->text().toLower().toLatin1();
         char *buff = ba.data(); // to c_string convert

        if(IsNormalInputString(buff)) {
           ui->display->setText(QString::number(GetResult(buff, x), 'f', 7));
        } else {
           ui->display->setText("ERROR!");
        }
        ui->Button_result->setChecked(true);
        }
}

void MainQT::push_button_digit()
{
    if(ui->display->text() == "0" || ui->display->text() == "ERROR!" || ui->Button_result->isChecked()) {
         ui->Button_result->setChecked(false);
         ui->display->clear();
         ui->inputTextField->clear();
    }

    QPushButton *pushButtonObj = (QPushButton*)sender();
    ui->display->setText(ui->display->text() + pushButtonObj->text());
}

void MainQT::push_button_func() {
    QPushButton *pushButtonObj = (QPushButton*)sender();

    if(ui->display->text() == "0" || ui->display->text() == "ERROR!" || ui->Button_result->isChecked()) {
        ui->Button_result->setChecked(false);
        ui->display->clear();
        ui->inputTextField->clear();
    }
//    else {
        ui->display->setText(ui->display->text() + pushButtonObj->text() + "(");
//    }
}

void MainQT::push_button_operator() {
    QPushButton *pushButtonObj = (QPushButton*)sender();
    if(ui->Button_result->isChecked() && ui->display->text() != "ERROR!") {
        ui->inputTextField->setText(ui->display->text() + pushButtonObj->text());
        ui->Button_result->setChecked(false);
        ui->display->clear();
    } else if(!ui->display->text().isEmpty() && ui->display->text() != "ERROR!") {
        ui->inputTextField->setText(ui->inputTextField->text() + ui->display->text() + pushButtonObj->text());
        ui->display->clear();
    }
    else {
        ui->display->setText("ERROR!");
    }
}

void MainQT::on_Button_dot_clicked()
{
  if(ui->display->text() != "ERROR!" && !ui->Button_result->isChecked()) {
    if(!ui->display->text().contains('.')) {
        ui->display->setText(ui->display->text()+".");
    }
  }
}

void MainQT::on_Button_sign_clicked() {
    if(ui->display->text()!=("0") && ui->display->text() != "ERROR!" && !ui->Button_result->isChecked()) {
        if(ui->display->text().toDouble()) {
            ui->display->setText(QString::number(ui->display->text().toDouble()*-1));
        } else if(!ui->display->text().contains("-")){
            ui->display->setText("-"+ui->display->text());
        } else {
            ui->display->setText(ui->display->text().remove("-"));
        }
    }
}

const double precision = 0.0000001;
bool equal(double x, double y) { return (x - y) < precision; }
bool less_or_equal(double x, double y) { return equal(x, y) || (x < y); }

void MainQT::on_Button_Graphic_clicked()
{
    ui->tabWidget->setCurrentWidget(ui->Graph);
    ui->Graph->clearGraphs();
    QVector <double> qv_x, qv_y;

    double start = ui->doubleSpinBox_from->value();
    double step = ui->doubleSpinBox_step->value();
    double end = ui->doubleSpinBox_to->value();

    if(ui->inputTextField->text().isEmpty() && !ui->display->text().isEmpty()) {
        ui->inputTextField->setText(ui->display->text());
    }

    if(!ui->inputTextField->text().isEmpty() && ui->display->text() != "ERROR!") {
        QByteArray ba = ui->inputTextField->text().toLower().toLatin1();
        char *buff = ba.data(); // to c_string convert

    for(double i = start; less_or_equal(i, end); i+=step) {
        double res = GetResult(buff, i);
        if(!isnan(res) && res < 1e6 && res > -1e6) {
          qv_x.append(i);
          qv_y.append(res);
        }
    }

    ui->Graph->addGraph();

    ui->Graph->graph()->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->Graph->graph()->setPen(QColor(Qt::red));
    ui->Graph->graph()->setLineStyle(QCPGraph::lsNone);

    ui->Graph->graph()->addData(qv_x, qv_y);

//    ui->Graph->xAxis->setRange(-2, 2);
//    ui->Graph->yAxis->setRange(-2, 2);

    ui->Graph->replot();

    ui->Graph->setInteraction(QCP::iRangeZoom, true);
    ui->Graph->setInteraction(QCP::iRangeDrag, true);
    }
}

void MainQT::on_Button_ClearGraph_clicked()
{
        ui->Graph->clearGraphs();
        ui->Graph->replot();
}

void MainQT::on_lineEdit_x_editingFinished()
{
    ui->lineEdit_x->setValidator( new QDoubleValidator(0, 100, 2, this) );
}


void MainQT::on_button_calc_credit_clicked()
{
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    if(ui->doubleSpinBox_Credit_1->value() > 0 && ui->spinBox_Credit_2->value() > 0 && ui->doubleSpinBox_Credit_3->value() > 0) {
        double totalAmount = ui->doubleSpinBox_Credit_1->value();
        double period = ui->spinBox_Credit_2->value();
        double percentageRate = ui->doubleSpinBox_Credit_3->value();
        if(ui->radioButton_Y->isChecked()) {
            period = period * 12;
        }

        double monthlyPayment;
        if(ui->radioButton_A->isChecked()) {
            monthlyPayment = CreditCalc(totalAmount, period, percentageRate, 1);
            ui->credit_result_1->setText(QString::number((monthlyPayment), 'f', 2));
            double overpayment = (roundf(monthlyPayment*100)/100 * period) - totalAmount;
            ui->credit_result_2->setText(QString::number((overpayment), 'f', 2));
            ui->credit_result_3->setText(QString::number((monthlyPayment * period), 'f', 2));
        } else {
            double allProcent = 0;
            double sumDeptAndProcent = 0;

            double debtPart = totalAmount / period;
            for( int i = 0; i < period; ++i ) {
              monthlyPayment = CreditCalc(totalAmount, period - i, percentageRate, 2);

              ui->tableWidget->insertRow(i);

              QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(monthlyPayment));
              ui->tableWidget->setItem( i, 0, item );
              sumDeptAndProcent+=monthlyPayment;

              item = new QTableWidgetItem(QString("%1").arg(debtPart));
              ui->tableWidget->setItem( i, 1, item );

              double procent = monthlyPayment - debtPart;
              item = new QTableWidgetItem(QString("%1").arg(procent));
              ui->tableWidget->setItem( i, 2, item );
              allProcent+=procent;

              totalAmount = totalAmount - debtPart;
              item = new QTableWidgetItem(QString("%1").arg(totalAmount < 0.01 ? 0 : totalAmount));
              ui->tableWidget->setItem( i, 3, item );
            }

              double firstValue = ui->tableWidget->item(0, 0)->text().toDouble();
              double lastValue = ui->tableWidget->item(ui->tableWidget->rowCount()-1, 0)->text().toDouble();

              ui->credit_result_1->setText(QString::number(firstValue, 'f', 2)+"..."+QString::number(lastValue, 'f', 2));
              ui->credit_result_2->setText(QString::number(allProcent, 'f', 2));
              ui->credit_result_3->setText(QString::number(sumDeptAndProcent, 'f', 2));
        }
        } else {
         ui->button_clear_credit->animateClick();
         QMessageBox messageBox;
         messageBox.critical(0,"Error","Enter correct value");
         messageBox.setFixedSize(500,200);
    }
}

void MainQT::on_button_clear_credit_clicked()
{
    ui->credit_result_1->setText("0");
    ui->credit_result_2->setText("0");
    ui->credit_result_3->setText("0");
    ui->doubleSpinBox_Credit_1->setValue(0);
    ui->spinBox_Credit_2->setValue(0);
    ui->doubleSpinBox_Credit_3->setValue(0);

    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }
}

