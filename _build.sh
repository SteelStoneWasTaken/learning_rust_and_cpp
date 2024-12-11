cargo build --release
cd src

echo "Compilando C++"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./../target/release  # Garantir que o linker encontre libapp
g++ -fPIC -o main main.cpp $(pkg-config --cflags --libs Qt6Core Qt6Gui Qt6Widgets) -L./../target/release -lapp -ldl
echo "Compilação completa."

mv main ./../target/release/
