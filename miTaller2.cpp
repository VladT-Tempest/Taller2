#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define maxInv 100
#define cols 4

using namespace std;

/*    variables globales        */
// arreglo carga inventario de archivo
string matrizHerram[maxInv][cols];
// constante con nombre de la base de datos
string fileInventario = "herram.txt";
// define caracter delimitador del archivo de inventario
const char delim = ',';
// arreglo de sub-cadenas
string subcadenas[cols];

/*    Menu principal */
int menu()
{
    int x;
    system("cls");
    cout << "-----Inventario de Herramientas--------"<< endl << endl;
    cout << "1. Agregar herramienta"<<endl;
    cout << "2. Listar inventario"<<endl;
    cout << "3. Sumar dato"<<endl;
    cout << "4. Eliminar herramienta"<<endl;
    cout << "5. salir"<<endl;

    cin >> x;
    return x;

}




/* Función para cargar inventario en matriz */
void cargarInventario() {
    std::ifstream file(fileInventario);
    std::string str;

    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;

    if ( file.is_open() ) {
        int fila = 0;
        string strings[cols]={};
        while( file ) {
            std::getline(file, str);
            int tamStr = str.size();
        //std::cout << str << " ";
            while ( i <= tamStr) {
                if ( str[i] == delim || i == tamStr) {
                    endIndex = i;
                    string subStr = "";
                    subStr.append(str, startIndex, endIndex - startIndex); 
                    strings[currIndex] = subStr;
                    currIndex += 1;
                    startIndex = endIndex +1;
                }
                i++;
            }
            /*matrizHerram[fila][0] = strings[0];
            matrizHerram[fila][1] = strings[1];
            matrizHerram[fila][2] = strings[2];
            matrizHerram[fila][3] = strings[3];
            std::cout << matrizHerram[fila][0] << " ";
            std::cout << matrizHerram[fila][1] << " ";
            std::cout << matrizHerram[fila][2] << " ";
            std::cout << matrizHerram[fila][3] << " ";
            std::cout << fila << endl; */
            fila++;
            i=0;
            currIndex = 0;
            startIndex = 0;
            endIndex = 0;
        }

    }
    else {
        std::cout << "No pude abrir el archivo de inventario\n";
    }
}


/* Programa principal */
int main () {
  //  int op;
   
   cargarInventario();
/*
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
*/
    return 0;
}

