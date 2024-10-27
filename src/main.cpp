#include <QApplication>

#include "../ui_calculator.h"
#include "CalculatorMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // creating objects
    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    // initializing objects
    calculator.setupUi(&window);
    window.init(calculator);
    // output of the main window
    window.show();

    return a.exec();
}
