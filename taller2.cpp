#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;


/*
struct herramientas 
{
    int registro;
    char[30] nombre;
    int  cantidad;
    int costo;
};
*/

void add_tool(ofstream &es);
void listar_inventario(ifstream &Lec);
void modificar(ifstream &Lec, int);
void eliminar(ifstream &Lec, int );
bool verifica(int);

int menu()
{
    int x;
    system("cls");
    cout << "-----Inventario de herramientas--------"<< endl;
    cout << "1. Agregar herramienta"<<endl;
    cout << "2. Listar inventario"<<endl;
    cout << "3. Sumar dato"<<endl;
    cout << "4. Eliminar herramienta"<<endl;
    cout << "5. salir"<<endl;

    cin >> x;
    return x;

}

int main()
{
    ofstream Esc;
    ofstream Esc2;
    ifstream Lec;
    int op;
    do
    {
        system("cls");
        op = menu();
        switch(op)
        {
            case 1:
                add_tool(Esc);
            break;

            case 2:
                listar_inventario(Lec);
            break;

            case 3:
                int registro1= 0;
                cout << "Ingrese # de registro para aumentar:  ";
                cin >> registro1;
                modificar(Lec, registro1);//not sure
            break;

            case 4:
                cout << "Ingrese # de registro para eliminar:  ";
                cin >> registro1;
                eliminar(Lec, registro1);
            break;
        }
    } while (op !=5 );

    //creacion nuevo archivo
    Esc2.open("sal.txt", ios::out |ios::app);

    return 0;
}

void eliminar(ifstream &Lec, int registro1)
{
    system("cls");
    int registro = 0;
    string tool_name = "";
    int cantidad = 0;
    int costo = 0;
    //MODIFICABLES:
    int registroAux = 0;
    int cantidadAux =0;
    Lec.open("Herramientas.txt", ios::in);
    ofstream aux("Auxiliar.txt", ios::out);
    if (Lec.is_open())
    {
        registroAux = registro1;
        Lec >> registro;
        while(!Lec.eof())
        {
            Lec >> tool_name;
            Lec >> cantidad;
            Lec >> costo;
            if (registro == registroAux) // DEPENDE DE LA CANTIDAD
            {
               cout << "Herramienta eliminada..."<<endl;  
               Sleep(1500);             
            }
            else
            {
                aux << registroAux << "  "<< tool_name << "  " << cantidad<< "  " << costo << "\n";
            }
            Lec >> registro;
        }
        Lec.close();
        aux.close();
    }
    else
    {
        cout << "ERROR"<<endl;     
    }

    remove("Herramientas.txt");
    rename("Auxiliar.txt", "Herramientas.txt");

}


void modificar(ifstream &Lec, int registro1)
{
    system("cls");
    int registro = 0;
    string tool_name = "";
    int cantidad = 0;
    int costo = 0;
    //MODIFICABLES:
    int registroAux = 0;
    int cantidadAux =0;
    Lec.open("Herramientas.txt", ios::in);
    ofstream aux("Auxiliar.txt", ios::out);
    if (Lec.is_open())
    {
        registroAux = registro1;
        Lec >> registro;
        while(!Lec.eof())
        {
            Lec >> tool_name;
            Lec >> cantidad;
            Lec >> costo;
            if (registro == registroAux)
            {
                cantidadAux = cantidad + 1;
                aux << registroAux << "  "<< tool_name << "  " << cantidadAux << "  " << costo << "\n";               
            }
            else
            {
                aux << registroAux << "  "<< tool_name << "  " << cantidad<< "  " << costo << "\n";
            }
            Lec >> registro;
        }
        Lec.close();
        aux.close();
    }
    else
    {
        cout << "ERROR"<<endl;     
    }

    remove("Herramientas.txt");
    rename("Auxiliar.txt", "Herramientas.txt");


}



void listar_inventario(ifstream &Lec)
{
    system("cls");
    int registro = 0;
    string tool_name = "";
    int cantidad = 0;
    int costo = 0;

    Lec.open("Herramientas.txt", ios::in);
    if(Lec.is_open())
    {
        Lec >> registro;
        while(!Lec.eof())
        {
            Lec >>  tool_name;
            Lec >>  cantidad;
            Lec >>  costo;
            cout << "# de registro:   "<< registro << endl; 
            cout << "Nombre de la herramienta:   "<< tool_name << endl;
            cout << "Cantidad:   "<< cantidad << endl;
            cout << "costo:   "<< costo << endl;
            cout << "-------------------"<<endl;
            Lec >> registro;
        }
        Lec.close();
    }
    else
    {
        cout << "ERROR"<<endl;
    }
    system("pause");
}



bool verifica(int registro1)
{
    ifstream leer("Herramientas.txt", ios::in);
    int registro = 0;
    string tool_name = "";
    int cantidad = 0;
    int costo = 0;

    leer >> registro;
    while (!leer.eof())
    {   if (registro1 == registro )
        {
            leer.close();
            return false;
        }
        leer >> tool_name;

    }
    leer.close();
    return true;
}


void add_tool(ofstream &es)
{
    ifstream Lec;
    system("cls");
    int registro = 0;
    string tool_name = "";
    int cantidad = 0;
    int costo = 0;
    es.open("Herramientas.txt", ios::out |ios::app);
    cout << "Ingrese # registro: ";
    cin >> registro;

    cout << "Ingrese Nombre de la herramienta: ";
    cin >> tool_name;

    cout << "Cantidad : "<< cantidad++;

    cout << "Ingrese el costo de la herramienta: ";
    cin >> costo;
    
    if (verifica(registro))
    {
       es << registro << " " << tool_name << " "<< cantidad <<" "<<costo <<"\n" ;
       es.close(); 
    }
    else
    {
        modificar(Lec, registro);//not sure
        es.close();

    }


}
