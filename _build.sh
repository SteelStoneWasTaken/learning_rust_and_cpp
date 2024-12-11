cargo build --release # Compilar biblioteca Rust.
cd src                # Ir para o diretório src (onde está o main.cpp).

echo "Compilando C++" # Início da compilação do código C++.

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./../target/release  # Definir onde estão as bibliotecas Rust.
g++ -fPIC -o main main.cpp $(pkg-config --cflags --libs Qt6Core Qt6Gui Qt6Widgets) -L./../target/release -lapp -ldl # Compilando C++ (explicação abaixo)
# g++                    >> Compilador C++ utilizado (GNU C++ Compiler)
# -fPIC                  >> Indica que o código pode ser carregado em qualquer endereço de memória (necessário para usar a biblioteca).
# -o main                >> Define o nome do executável gerado (main).
# main.cpp               >> O arquivo C++ que será compilado.
# $(...)       >> Executa o comando dentro dos parênteses e insere o resultado. >>
#              pkg-config             >> Ferramenta que fornece informações sobre bibliotecas do sistema.
#              --cflags               >> Retorna as flags necessárias para compilar o código (como diretórios de inclusão).
#              --libs                 >> Retorna as flags necessárias para o linking (onde encontrar as bibliotecas).
#              ...                    >> Bibliotecas do Qt6 necessárias para o código C++.
# -L./../target/release  >> Define onde o compilador encontra as bibliotecas externas, no caso, a biblioteca Rust.
# -lapp                  >> Especifica a biblioteca Rust (libapp), definida em cargo.toml.
# -ldl                   >> Linka a biblioteca de manipulação dinâmica de bibliotecas do Linux.
mv main ./../target/release/ # Move o executável para o diretório de bibliotecas.

echo "Compilação completa." # Finaliza a mensagem informando que a compilação foi concluída.
