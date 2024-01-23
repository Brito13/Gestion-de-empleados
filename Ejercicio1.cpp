#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Ejercicio1{
       int codigo;
       string nombre;
       int edad;
};

void agregarDatos(vector<Ejercicio1> &datos);
void mostrarDatos(vector<Ejercicio1> &datos);
void actualizarDatos(vector<Ejercicio1> &datos);
void eliminarDatos(vector<Ejercicio1> &datos);

int main(int argc, char const *argv[]){
    vector<Ejercicio1> datos;
    while (true)
    {
     short opcion;
     cout <<"1)Crear\n";
     cout <<"2)Mostrar datos\n";
     cout <<"3)Actualizar\n";
     cout <<"4)Borrar\n";
     cout <<"5)Salir\n";
     do
     {
        cout <<"Introduzca la opcion:";
        cin >> opcion;
     } while (opcion > 5 || opcion < 1);
     if (opcion == 5){
        break;
     }
     switch (opcion)
     {
        case 1:
        agregarDatos(datos);
            break;
        case 2:
        mostrarDatos(datos);
            break;
        case 3:
        actualizarDatos(datos);
            break;
        case 4:
        eliminarDatos(datos);
            break;
        default:
            break;
    }
    }
    return 0;
}

void agregarDatos(vector<Ejercicio1> &datos){
     Ejercicio1 persona;
     cout <<"Introduzca el codigo:";
     cin >> persona.codigo;
     for (const auto& personas : datos){
          if (personas.codigo == persona.codigo){
              cout <<"No se puede agregar esta persona por que existe!!" << endl;
              return;
          }
     }
     cin.ignore();
     cout <<"Introduzca el nombre:";
     getline(cin,persona.nombre);
     cout <<"Introduzca la edad:";
     cin >> persona.edad;
     datos.push_back(persona);
     system("cls");
}

void mostrarDatos(vector<Ejercicio1> &datos){
     system("cls");
     for (const auto &persona: datos){
          cout <<"Codigo:" << persona.codigo << endl;
          cout <<"Nombre:" << persona.nombre << endl;
          cout <<"Edad:" << persona.edad << endl;
     }    
}

void actualizarDatos(vector<Ejercicio1> &datos){
     int codigo;
     cout <<"Introduzca el codigo de la persona:";
     cin >> codigo;
     for (auto &persona : datos){
          if (persona.codigo == codigo){
              cout <<"Introduzca el nuevo codigo:";
              cin >> persona.codigo;
              cin.ignore();
              cout <<"Introduzca el nuevo nombre:";
              getline(cin,persona.nombre);
              cout <<"Introduzca la nueva edad:";
              cin >> persona.edad;
          }
          else
          {
            cout <<"Persona no encontrada:" << endl;
          }
     }
}

void eliminarDatos(vector<Ejercicio1> &datos){
     int codigoEliminar;
     cout <<"Introduzca el codigo de la persona:";
     cin >> codigoEliminar;
     for (auto it = datos.begin() ; it != datos.end();){
         it = datos.erase(it);
         cout <<"!La Persona fue eliminada!" << endl;
         break;
     } 
}