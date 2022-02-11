#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// variables globales
// arreglo carga inventario de archivo
int matrizHerram[100][4];
// constante con nombre de la base de datos
string fileInventario = "herram.txt";
// definde caracter delimitador del archivo de inventario
const char delim = ',';


int menu()
{
    int x;
    system("cls");
    cout << "-----Inventario de herramientas--------"<< endl << endl;
    cout << "1. Agregar herramienta"<<endl;
    cout << "2. Listar inventario"<<endl;
    cout << "3. Sumar dato"<<endl;
    cout << "4. Eliminar herramienta"<<endl;
    cout << "5. salir"<<endl;

    cin >> x;
    return x;

}

void listarInventario() {
    std::ifstream file(fileInventario);
    std::string str;
    
    if ( file.is_open() ) {
        while( file ) {
            std::getline(file, str);
            std::cout << str ;
        }
    }
    else {
        std::cout << "No pude abrir el archivo de inventario\n";
    }
}

int main () {
    int op;
   
*
    do
    {
        system("cls");
        op = menu();
        switch(op)
        {
            case 1:
                
            break;

            case 2:
                listarInventario();
            break;

            case 3:
                
            break;

            case 4:
                
            break;
        }
    } while (op !=5 );

    return 0;
}

