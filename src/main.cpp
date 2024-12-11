#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>

extern "C" int duplicar(int x);

void onButtonClicked() {
    int num;
    num = duplicar(2);
    std::cout << "2*2= " << num << std::endl;
}

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "en_US.UTF-8");

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Janela Simples");
    window.resize(300, 200);

    // Criar o botão
    QPushButton *button = new QPushButton("Clique Aqui", &window);

    // Conectar o sinal de clique do botão ao slot que imprime no console
    QObject::connect(button, &QPushButton::clicked, &onButtonClicked);

    // Usar um layout para organizar o botão
    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(button);

    window.setLayout(layout);

    window.show();
    return app.exec();
}
