#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define maxInv 100
#define cols 4

using namespace std;

/*    variables globales        */
// arreglo carga inventario de archivo
int matrizHerram[maxInv][cols];
// constante con nombre de la base de datos
string fileInventario = "herram.txt";
// definde caracter delimitador del archivo de inventario
const char delim = ',';
// arreglo de sub-cadenas
string subcadenas[cols];

/*    Menu principal */
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

/* Función para dividir strings */
int * split (string str, char separator)  
{  
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    int tamStr = str.size();
    string strings[cols]={};
    while (i <= tamStr)  
    {  
        if ( str[i] == separator || i == tamStr )  
        {  
            endIndex = i;  
            static string subStr = "";  
            subStr.append(str, startIndex, endIndex - startIndex);  
            strings[currIndex] = subStr;  
            currIndex += 1;  
            startIndex = endIndex + 1;  
        }  
        i++;  
        }  
        return  strings; 
}  


/* Función para cargar inventario en matriz */
void cargarInventario() {
    std::ifstream file(fileInventario);
    std::string str;

    if ( file.is_open() ) {
        while( file ) {
            std::getline(file, str);
            //std::cout << str ;
            std::cout << split(str, delim);
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

