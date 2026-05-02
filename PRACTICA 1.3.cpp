#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Producto {
    string nombre;
    double precio;
    int cantidad;
};

int main() {
    // --- PASO 1: Creación del archivo productos.txt ---
    ofstream archivoEscritura("productos.txt");
    if (archivoEscritura.is_open()) {
        archivoEscritura << "Laptop 850 2" << endl;
        archivoEscritura << "Mouse 15 5" << endl;
        archivoEscritura << "Teclado 30 3" << endl;
        archivoEscritura << "Monitor 180 2" << endl;
        archivoEscritura.close();
        cout << "[+] Archivo productos.txt creado exitosamente.\n" << endl;
    }

    // --- PASO 2: Lectura y Procesamiento ---
    ifstream archivoLectura("productos.txt");
    string nombre;
    double precio, totalGeneral = 0;
    int cantidad;

    Producto mayorUnitario = {"", 0.0, 0};
    bool primero = true;

    cout << left << setw(15) << "PRODUCTO" << setw(10) << "CANT." << setw(15) << "SUBTOTAL" << endl;
    cout << "------------------------------------------" << endl;

    while (archivoLectura >> nombre >> precio >> cantidad) {
        double subtotal = precio * cantidad;
        totalGeneral += subtotal;

        cout << left << setw(15) << nombre << setw(10) << cantidad << "$" << subtotal << endl;

        // Validar producto con mayor precio unitario
        if (primero || precio > mayorUnitario.precio) {
            mayorUnitario = {nombre, precio, cantidad};
            primero = false;
        }
    }

    cout << "------------------------------------------" << endl;
    cout << "TOTAL A PAGAR: $" << totalGeneral << endl;
    cout << "PRODUCTO MAS CARO: " << mayorUnitario.nombre << " ($" << mayorUnitario.precio << ")" << endl;

    archivoLectura.close();
    return 0;
}
