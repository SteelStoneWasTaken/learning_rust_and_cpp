#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <iostream>

extern "C" int duplicar(int x);

void onButtonClicked(QLineEdit* inputField) {
    bool ok;
    int num = inputField->text().toInt(&ok);

    if (ok) {
        num = duplicar(num);
        std::cout << num << std::endl;
    } else {
        std::cout << "..." << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "en_US.UTF-8");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Janela Simples");
    window.resize(300, 200);

    // // // // // // // // // // // // // // // // // //

    // inputField
    QLineEdit *inputField = new QLineEdit(&window);
    inputField->setPlaceholderText("Digite um número");
    // button
    QPushButton *button = new QPushButton("Duplicar", &window);
    QObject::connect(button, &QPushButton::clicked, [&]() { onButtonClicked(inputField); });


    QVBoxLayout *layout = new QVBoxLayout(&window); // //
    //                                                 //
    layout->addWidget(inputField);                     //
    layout->addWidget(button);                         //
    //                                                 //
    window.setLayout(layout);  // // // // // // // // //

    window.show();
    return app.exec();
}
