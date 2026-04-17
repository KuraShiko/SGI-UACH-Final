#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib> 
#include <cctype>

using namespace std;

struct Producto {
    int id;
    string nombre;
    int stock;
};

vector<Producto> inventario;
int contadorID = 1;

void cargarDatos() {
    ifstream archivo("inventario.txt");
    if (archivo.is_open()) {
        Producto p;
        while (archivo >> p.id >> p.stock >> p.nombre) {
            inventario.push_back(p);
            if (p.id >= contadorID) {
                contadorID = p.id + 1;
            }
        }
        archivo.close();
    }
}

void guardarDatos() {
    ofstream archivo("inventario.txt");
    for (int i = 0; i < inventario.size(); i++) {
        archivo << inventario[i].id << " " 
                << inventario[i].stock << " " 
                << inventario[i].nombre << "\n";
    }
    archivo.close();
}

void agregarProducto() {
    Producto nuevo;
    cout << "\nNombre del producto: ";
    cin.ignore(); 
    getline(cin, nuevo.nombre); 
    
    for (int i = 0; i < nuevo.nombre.length(); i++) {
        if (nuevo.nombre[i] == ' ') {
            nuevo.nombre[i] = '_';
        }
    }
    
    string nombreNuevoMin = nuevo.nombre;
    for (int i = 0; i < nombreNuevoMin.length(); i++) {
        nombreNuevoMin[i] = tolower(nombreNuevoMin[i]);
    }
    
    for (int i = 0; i < inventario.size(); i++) {
        string nombreExistenteMin = inventario[i].nombre;
        for (int j = 0; j < nombreExistenteMin.length(); j++) {
            nombreExistenteMin[j] = tolower(nombreExistenteMin[j]);
        }
        
        if (nombreExistenteMin == nombreNuevoMin) {
            cout << "Error: Ese producto ya existe con la ID " << inventario[i].id << ".\n";
            cout << "Utiliza la opcion 3 para modificar su stock.\n";
            return; 
        }
    }
    
    nuevo.id = contadorID;
    
    cout << "Cantidad en stock: ";
    cin >> nuevo.stock;
    
    inventario.push_back(nuevo);
    contadorID++;
    cout << "Producto agregado con exito!\n";
}

void mostrarInventario() {
    if (inventario.empty()) {
        cout << "\nEl inventario esta vacio.\n";
        return;
    }
    
    int limite = 5; 
    int inicio = 0; 
    int opcionNavegacion = 0;

    while (true) {
        system("cls");
        cout << "\n=== LISTA DE PRODUCTOS ===\n";
        cout << "ID\tSTOCK\tNOMBRE\n";
        cout << "--------------------------\n";
        
        int fin = inicio + limite;
        if (fin > inventario.size()) {
            fin = inventario.size(); 
        }
        
        for (int i = inicio; i < fin; i++) {
            string nombrePantalla = inventario[i].nombre;
            for (int j = 0; j < nombrePantalla.length(); j++) {
                if (nombrePantalla[j] == '_') {
                    nombrePantalla[j] = ' ';
                }
            }
            cout << inventario[i].id << "\t" 
                 << inventario[i].stock << "\t" 
                 << nombrePantalla << "\n";
        }
        cout << "--------------------------\n";
        cout << "Mostrando " << inicio + 1 << " al " << fin << " de " << inventario.size() << " productos.\n\n";

        cout << "Opciones de navegacion:\n";
        if (inicio + limite < inventario.size()) {
            cout << "1. Siguiente pagina\n";
        }
        if (inicio > 0) {
            cout << "2. Pagina anterior\n";
        }
        cout << "3. Salir al menu principal\n";
        cout << "Elige una opcion: ";
        cin >> opcionNavegacion;

        if (opcionNavegacion == 1 && inicio + limite < inventario.size()) {
            inicio += limite; 
        } 
        else if (opcionNavegacion == 2 && inicio > 0) {
            inicio -= limite; 
        } 
        else if (opcionNavegacion == 3) {
            break; 
        } 
        else {
            cout << "Opcion no valida.\n";
            system("pause");
        }
    }
}

void modificarStock() {
    mostrarInventario();
    if (inventario.empty()) return;

    int idBuscar;
    cout << "\nEscribe la ID del producto a modificar: ";
    cin >> idBuscar;

    bool encontrado = false;
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].id == idBuscar) {
            
            string nombreMostrar = inventario[i].nombre;
            for (int j = 0; j < nombreMostrar.length(); j++) {
                if (nombreMostrar[j] == '_') {
                    nombreMostrar[j] = ' ';
                }
            }
            
            cout << "Nuevo stock para " << nombreMostrar << ": ";
            cin >> inventario[i].stock;
            cout << "Stock actualizado!\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Error: Esa ID no existe en el inventario.\n";
    }
}

int main() {
    cargarDatos();
    
    int opcion;
    do {
        system("cls"); 
        
        cout << "\n=== SISTEMA DE GESTION DE INVENTARIOS ===\n";
        cout << "1. Agregar producto nuevo\n";
        cout << "2. Ver inventario completo\n";
        cout << "3. Modificar stock por ID\n";
        cout << "4. Guardar y Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: 
                agregarProducto(); 
                system("pause"); 
                break;
            case 2: 
                mostrarInventario(); 
                break;
            case 3: 
                system("cls"); 
                modificarStock(); 
                system("pause"); 
                break;
            case 4: 
                guardarDatos();
                cout << "Datos guardados. Saliendo...\n"; 
                break;
            default: 
                cout << "Opcion no valida.\n";
                system("pause");
        }
    } while (opcion != 4);

    return 0;
}
