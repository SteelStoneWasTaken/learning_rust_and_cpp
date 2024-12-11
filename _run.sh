cd ./target/release          # Ir para o diretório onde o executável e as bibliotecas estão localizados.
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./main  # Executar o programa 'main', incluindo o diretório atual (.) no caminho das bibliotecas.
# LD_LIBRARY_PATH   >> Define onde o sistema procura as bibliotecas compartilhadas.
# $LD_LIBRARY_PATH  >> Mantém o valor atual da variável (adiciona ao invés de sobrescrever).
# :.                >> Adiciona o diretório atual (.) ao caminho das bibliotecas, garantindo que o sistema encontre as bibliotecas no diretório local.
# ./main            >> Executa o arquivo 'main' gerado na compilação.
