#ifndef CALCULATORMAINWINDOW_H
#define CALCULATORMAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

#include "../ui_calculator.h"

class CalculatorMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // constructor
    explicit CalculatorMainWindow(QWidget *parent = nullptr);

    // initializing fields
    void init(const Ui::MainWindow &calculator);

private:
    // the input field of the 1st argument
    QLineEdit *arg1_edt = nullptr;
    // the input field of the 2nd argument
    QLineEdit *arg2_edt = nullptr;
    // The output field is the result
    QLineEdit *result_edt = nullptr;

    // for intermediate calculations
    float arg1, arg2, result;

    // data entry routine and checking for correctness
    bool input_arguments();
    // the subroutine for displaying a text message in the output field
    void output_result(const QString &text);

public slots:
    // The addition routine
    void plus();
    // subtraction routine
    void minus();
    // The multiplication routine
    void multiplication();
    // The division routine
    void division();
};

#endif // CALCULATORMAINWINDOW_H
