#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <iostream>

extern "C" int duplicar(int x);
extern "C" int retornar();

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Janela Simples");
    window.resize(300, 200);

    // // // // // // // // // // // // // // // // // //

    // Input
    QLineEdit *input = new QLineEdit(&window);
    input->setPlaceholderText("Digite um número");

    // Button
    QPushButton *button = new QPushButton("Duplicar", &window);

    QObject::connect(button, &QPushButton::clicked, [&]() {
        bool ok;
        duplicar(input->text().toInt(&ok));
        std::cout << retornar() << std::endl;
    });


    QVBoxLayout *layout = new QVBoxLayout(&window); // //
    //                                                 //
    layout->addWidget(input);                          //
    layout->addWidget(button);                         //
    //                                                 //
    window.setLayout(layout);  // // // // // // // // //

    window.show();
    return app.exec();
}
