#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define maxInv 100
#define cols 4

using namespace std;


void imprimir();
void agregar();
void cargarInventario();
void actualizar_archivo();
string Esperar();


/*    variables globales        */
// arreglo carga inventario de archivo
string matrizHerram[maxInv][cols];
// constante con nombre de la base de datos
string fileInventario = "herram.txt";
// define caracter delimitador del archivo de inventario
const char delim = ',';
// arreglo de sub-cadenas
string subcadenas[cols];
int fila = 0;


/* Programa principal */
int main () 
{
    cargarInventario();
    int op;
    /*    Menu principal */
    int x;
    cout << "-----Inventario de Herramientas--------"<< endl << endl;
    cout << "1. Agregar herramienta"<<endl;
    cout << "2. Listar inventario"<<endl;
    cout << "3. Sumar dato"<<endl;
    cout << "4. Eliminar herramienta"<<endl;
    cout << "5. salir"<<endl;

    cin >> x;


    while (1 == 1 )
    {
        system("cls");
        op = x;

        switch(op)
        {
            case 1:
            {
                agregar();
                system("pause");
                //op= 0;
                break;
            }

            case 2:
            {
                imprimir();
                system("pause");
                op= 0;
                break;
            }

            case 3:
            {
                
                Esperar();
                op= 0;
                break;
            }
            case 4:
            {
                Esperar();
                op= 0;
                break;

            }
            case 5:
            {
                exit(EXIT_SUCCESS);
            }

            default:
            {
                cout << "Opcion no valida"<<endl;
                break;
            }
        }
    }    

}



//Funcion para agregar registro
void agregar()
{
    string registro;
    string nombre;
    string cantidad;
    string costo_unitario;

    cout << "Digite el numero de registro: ";
    cin>> registro;
    cout << "Digite el nombre de la herramienta: ";
    cin>>nombre;
    cout << "Digite la cantidad: ";
    cin>> cantidad;
    cout << "Digite el costo unitario: ";
    cin>> costo_unitario;

    matrizHerram[fila-1][0] = registro;
    matrizHerram[fila-1][1] = nombre;
    matrizHerram[fila-1][2] = cantidad;
    matrizHerram[fila-1][3] = costo_unitario;
    fila++;
    actualizar_archivo();

}


void actualizar_archivo()
{
    int dato;
    string str;
    ofstream temp_file("Archivo Temporal", ios::out);

    if ( temp_file.is_open() ) 
    {
       for (int x = 0; x < fila-1 ; x++)
        {
            str = matrizHerram[x][0] +","+ matrizHerram[x][1] + "," + matrizHerram[x][2] + "," + matrizHerram[x][3] + "\n";
            temp_file << str;
        }

    }
    else 
    {
        cout << "No pude abrir el archivo de inventario\n";
    }
    temp_file.close();
    remove("herram.txt");
    rename("Archivo Temporal" , "herram.txt");
      
}

//Funcion para imprimir 
void imprimir()
{   
    char enter;
    system ("cls");
    cout << "Registro" << "\t\t\t\t" << "Herramienta" << "\t\t\t\t\t" << "Cantidad" << "\t\t\t\t" << "Costo unitario" << endl;
    for (int x = 0; x < fila-1 ; x++)
    {
       for (int y = 0; y < cols ; y++) 
       {
           cout << matrizHerram[x][y] << "\t\t\t\t\t\t\t\t";
       }
       cout << endl;
    }

    cout << "Digite enter para regresar al menu";
    cin >> enter;

}



/* Función para cargar inventario en matriz */
void cargarInventario() 
{
    std::ifstream file(fileInventario);
    std::string str;

    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;

    if ( file.is_open() ) 
    {
        string strings[cols]={};
        while( file) 
        {
            std::getline(file, str);
            int tamStr = str.size();
        //std::cout << str << " ";
            while ( i <= tamStr) 
            {
                if ( str[i] == delim || i == tamStr) 
                {
                    endIndex = i;
                    string subStr = "";
                    subStr.append(str, startIndex, endIndex - startIndex); 
                    strings[currIndex] = subStr;
                    currIndex += 1;
                    startIndex = endIndex +1;
                }
                i++;
            }
            matrizHerram[fila][0] = strings[0];
            matrizHerram[fila][1] = strings[1];
            matrizHerram[fila][2] = strings[2];
            matrizHerram[fila][3] = strings[3];
            /*
            cout << matrizHerram[fila][0] << " ";
            cout << matrizHerram[fila][1] << " ";
            cout << matrizHerram[fila][2] << " ";
            cout << matrizHerram[fila][3] << " ";
            cout << fila << endl; 
            */
            fila++;
            i=0;
            currIndex = 0;
            startIndex = 0;
            endIndex = 0;

            
        }

    }
    else 
    {
        cout << "No pude abrir el archivo de inventario\n";
    }
    file.close();
    cout << "Archivo cargado"<<endl;
    cout << fila;
}

string Esperar()
{
    string recibir = "";
    cout<<"Oprima cualquier tecla para continuar, volvera al menu principal"<<endl;
    cin >> recibir;
    cout <<endl;

    return recibir;
}