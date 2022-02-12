#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

#define maxInv 100
#define cols 4

using namespace std;


void imprimir();
void agregar();
void cargarInventario();
void actualizar_archivo();
void eliminar();
void precios();
string Esperar();


/*    variables globales        */
// arreglo carga inventario de archivo
string matrizHerram[maxInv][cols];
int matrizPrecios[maxInv][3];
string matrizPrecios2[maxInv][3];
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

    while (1 == 1 )
    {
        system("cls");
        cout << "-----Inventario de Herramientas--------"<< endl << endl;
        cout << "1. Agregar herramienta"<<endl;
        cout << "2. Listar inventario"<<endl;
        cout << "3. Eliminar herramienta"<<endl;
        cout << "4. verificar precios"<<endl;
        cout << "5. salir"<<endl;

        cin >> op;

        switch(op)
        {
            case 1:
            {
                agregar();
                break;
            }

            case 2:
            {
                imprimir();
                break;
            }

            case 3:
            {
                eliminar();
                break;
            }
            case 4:
            {
                precios();
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

void eliminar()
{
    string registro;

    cout << "Digite el numero de registro de la herramienta a borrar: ";
    cin>> registro;

    for (int x = 0; x < fila-1 ; x++)
    {

        if (matrizHerram[x][0] == registro)
        {
            matrizHerram[x][0] = " ";
            matrizHerram[x][1] = " ";
            matrizHerram[x][2] = " ";
            matrizHerram[x][3] = " ";
        }

    }
    
    actualizar_archivo();
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
    string str;
    ofstream temp_file("Archivo Temporal", ios::out);

    if ( temp_file.is_open() ) 
    {
       for (int x = 0; x < fila-1 ; x++)
        {
            if (matrizHerram[x][0]!= " ")
            {
                str = matrizHerram[x][0] +","+ matrizHerram[x][1] + "," + matrizHerram[x][2] + "," + matrizHerram[x][3] + "\n";
                temp_file << str;
                
            }
            
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
    const char separator= ' ';
    const int ancho1 = 30;
    const int ancho2 = 15;
    system ("cls");
    cout << left << setw(ancho2) << setfill(separator) << "Registro"; 
    cout << left << setw(ancho1) << setfill(separator) << "Herramienta";
    cout << left << setw(ancho2) << setfill(separator) << "Cantidad";
    cout << left << setw(ancho2) << setfill(separator) << "Costo unitario";
    cout << endl;
    for (int x = 0; x < fila-1 ; x++)
    {
       cout << left << setw(ancho2) << setfill(separator) << matrizHerram[x][0]; 
       cout << left << setw(ancho1) << setfill(separator) << matrizHerram[x][1];
       cout << left << setw(ancho2) << setfill(separator) << matrizHerram[x][2];
       cout << left << setw(ancho2) << setfill(separator) << matrizHerram[x][3];
       cout << endl;
    }

    system("pause");
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


void precios()
{
    int cantidad= 0;
    int costUnitario= 0;
    int cont_precios = 0;
    for (int x = 0; x < fila-2 ; x++)
    {
        cantidad = stoi(matrizHerram[x][2]);
        costUnitario = stoi(matrizHerram[x][3]);
        //cout << stoi(matrizHerram[x][3]) * stoi(matrizHerram[x][2])<< endl;
        // GLITCH????
        if (cantidad*costUnitario >= 1000000)
        {
            matrizPrecios[cont_precios][0] = stoi(matrizHerram[x][0]);
            matrizPrecios[cont_precios][1] = stoi(matrizHerram[x][3]) * stoi(matrizHerram[x][2]);
cout << matrizPrecios[cont_precios][0] << " " <<  matrizPrecios[cont_precios][1]<<endl;
            cont_precios++;
        }
    }
    // Crea matrizPrecios2 con datos para ordenar
    int limite = 1000000;
    int val = 0;
    for(int i = 0; i < fila ; i++) {
        if (matrizPrecios[i][1] >= limite) {
            matrizPrecios2[val][0] = to_string(matrizPrecios[i][0]);
            matrizPrecios2[val][1] = matrizHerram[i][1];
            matrizPrecios2[val][2] = to_string(matrizPrecios[i][1]);
cout << matrizPrecios2[val][0] << " " <<  matrizPrecios2[val][1]<< " " <<  matrizPrecios2[val][2]<<" "<<val<<endl;
            val++;
        }
    }
    // bubble sort

cout << val << endl;
    int registroTmp = 0;
    string  nombreTmp = "";
    int costoTotalTmp = 0;
    for (int i = 0; i<val; i++) {
        for (int j = i+1; j<val; j++) {
            if(matrizPrecios2[j][0] < matrizPrecios2[i][0]) {
                registroTmp = stoi(matrizPrecios2[i][0]);
                nombreTmp = matrizPrecios2[i][1];
                costoTotalTmp = stoi(matrizPrecios2[i][2]);
    cout<<registroTmp<<" "<<nombreTmp<<" "<<costoTotalTmp<<" "<<i<<" "<<j<<endl;
                matrizPrecios2[i][0] = matrizPrecios2[j][0];
                matrizPrecios2[i][1] = matrizPrecios2[j][1];
                matrizPrecios2[i][2] = matrizPrecios2[j][2];
                matrizPrecios2[j][0] = registroTmp;
                matrizPrecios2[j][1] = nombreTmp;
                matrizPrecios2[j][2] = costoTotalTmp;
            }
        } 
    }
 /*   for(int i=0; i<val;i++) {
        cout << matrizPrecios2[i][0] << " " << matrizPrecios2[i][1] << " " << matrizPrecios2[i][2] << endl;
    }
    */
   system("pause");
}