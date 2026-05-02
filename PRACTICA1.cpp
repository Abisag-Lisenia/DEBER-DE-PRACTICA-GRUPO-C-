#include <iostream>
#include <fstream>
using namespace std;
int main() {
ifstream archivo("estudiantes.txt");
string nombre;
double n1, n2, n3, promedio;
int total=0, aprobados=0;
double suma=0;
if (!archivo.is_open()) return 1;
while (archivo >> nombre >> n1 >> n2 >> n3) {
promedio = (n1+n2+n3)/3.0;
if (promedio >= 7) aprobados++;
suma += promedio;
total++;
}cout << "Promedio general: " << suma/total;
archivo.close();
return 0;
}
