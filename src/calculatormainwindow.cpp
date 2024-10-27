#include "calculatormainwindow.h"

CalculatorMainWindow::CalculatorMainWindow(QWidget *parent)
    : QMainWindow{parent}
{}

void CalculatorMainWindow::init(const Ui::MainWindow &calculator)
{
    arg1_edt = calculator.arg1_edt;
    arg2_edt = calculator.arg2_edt;
    result_edt = calculator.result_edt;
    resize(500, 200);
}

bool CalculatorMainWindow::input_arguments()
{
    // trying to convert from a string to a real type
    try {
        // if it didn't work out
        arg1 = std::stof(arg1_edt->text().toStdString());
        arg2 = std::stof(arg2_edt->text().toStdString());
    } catch (...) {
        // then return a negative result
        return false;
    }

    // additional correctness check: there should be no text after the number
    if(QString::number(arg1) != arg1_edt->text())
        return false;
    if(QString::number(arg2) != arg2_edt->text())
        return false;

    // if the execution of the subroutine has reached here, then the input is correct
    return true;
}

void CalculatorMainWindow::output_result(const QString &text)
{
    result_edt->setText(text);
}

void CalculatorMainWindow::plus()
{
    // data entry
    if(!input_arguments()) {
        output_result("ERROR");
        return;
    }

    // calculation
    result = arg1 + arg2;

    // output of the result
    output_result(QString::number(result));
}

void CalculatorMainWindow::minus()
{
    // data entry
    if(!input_arguments()) {
        output_result("ERROR");
        return;
    }

    // calculation
    result = arg1 - arg2;

    // output of the result
    output_result(QString::number(result));
}

void CalculatorMainWindow::multiplication()
{
    // data entry
    if(!input_arguments()) {
        output_result("ERROR");
        return;
    }

    // calculation
    result = arg1 * arg2;

    // output of the result
    output_result(QString::number(result));
}

void CalculatorMainWindow::division()
{
    // data entry
    if(!input_arguments()) {
        output_result("ERROR");
        return;
    }

    // calculation
    if(arg2 == 0) {
        output_result("ERROR");
        return;
    }
    result = arg1 / arg2;

    // output of the result
    output_result(QString::number(result));
}
