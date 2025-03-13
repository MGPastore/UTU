#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class System {
public:
    void printOutInt(int valor) {
        cout << "Valor entero: " << valor << endl;
    }

    void printOutString(const string& texto) {
        cout << "Texto: " << texto << endl;
    }

    void printOutFloat(float valor) {
        cout << "Valor flotante: " << valor << endl;
    }

    void printOutJson(const string& clave, const string& valor) {
        cout << "{ \"" << clave << "\": \"" << valor << "\" }" << endl;
    }
};

class Json {
private:
    map<string, string> datos;

public:
    // Método para agregar clave-valor al JSON
    void add(const string& clave, const string& valor) {
        datos[clave] = valor;
    }

    // Método para imprimir el JSON completo
    void printOutJson() {
        cout << "{ ";
        for (auto it = datos.begin(); it != datos.end(); ++it) {
            cout << "\"" << it->first << "\": \"" << it->second << "\"";
            if (next(it) != datos.end()) {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }

    // Función para convertir el JSON a un array de solo valores y luego imprimirlo
    void jsonToArrayAndPrint() {
        vector<string> array;
        for (auto& item : datos) {
            array.push_back(item.second);  // Solo se agrega el valor
        }

        // Imprimir el array de valores
        cout << " [ ";
        for (auto& valor : array) {
            cout << "\"" << valor << "\"";
            if (&valor != &array.back()) {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
};

int main() {
    System system;
    Json json;

    // Usamos la clase System para imprimir datos
    system.printOutInt(42);
    system.printOutString("Hola Mundo");
    system.printOutFloat(3.14f);

    // Usamos la clase Json para crear y mostrar un JSON
    json.add("nombre", "Maximiliano");
    json.add("edad", "25");
    json.add("ciudad", "Montevideo");

    cout << "JSON generado: ";
    json.printOutJson();

    // Convertir el JSON a un array de solo valores y mostrarlo en una sola función
    json.jsonToArrayAndPrint();

    return 0;
}
