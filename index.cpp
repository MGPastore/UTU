#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>  // Para std::reverse
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

    // Método para imprimir el JSON completo en un orden específico
    void printOutJson() {
        vector<string> claves = { "nombre", "edad", "ciudad" }; // Definir el orden deseado de las claves

        cout << "{ ";
        for (size_t i = 0; i < claves.size(); ++i) {
            cout << "\"" << claves[i] << "\": \"" << datos[claves[i]] << "\"";
            if (i != claves.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }

    // Función para convertir el JSON a un array de solo valores, en un orden específico, y luego imprimirlo
    void jsonToArrayAndPrint() {
        vector<string> claves = { "nombre", "edad", "ciudad" }; // Orden deseado de las claves
        vector<string> array;

        // Agregar los valores de acuerdo al orden de las claves
        for (const auto& clave : claves) {
            array.push_back(datos[clave]);
        }

        // Imprimir el array de valores en el orden especificado
        cout << "Array de valores resultante en orden deseado: [ ";
        for (size_t i = 0; i < array.size(); ++i) {
            cout << "\"" << array[i] << "\"";
            if (i != array.size() - 1) {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }

    // Función para convertir el JSON a un array de solo claves y luego imprimirlo
    void jsonToKeyArrayAndPrint() {
        vector<string> claves = { "nombre", "edad", "ciudad" }; // Orden deseado de las claves

        // Imprimir el array de claves
        cout << "Array de claves resultante: [ ";
        for (size_t i = 0; i < claves.size(); ++i) {
            cout << "\"" << claves[i] << "\"";
            if (i != claves.size() - 1) {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }

    // Función para obtener la cantidad de valores en el JSON
    void getJsonSize() {
        cout << "El JSON tiene " << datos.size() << " valores." << endl;
    }

    // Función para obtener el valor de una clave
    string getValueByKey(const string& clave) {
        auto it = datos.find(clave);
        if (it != datos.end()) {
            return it->second;  // Retorna el valor correspondiente a la clave
        } else {
            return "Clave no encontrada";  // Si no se encuentra la clave
        }
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

    cout << "JSON generado en orden deseado: ";
    json.printOutJson();

    // Convertir el JSON a un array de solo valores y mostrarlo en orden deseado
    json.jsonToArrayAndPrint();

    // Convertir el JSON a un array de solo claves y mostrarlo
    json.jsonToKeyArrayAndPrint();

    // Mostrar el tamaño del JSON
    json.getJsonSize();

    // Obtener un valor por su clave
    string clave = "edad";
    cout << "El valor de la clave \"" << clave << "\" es: " << json.getValueByKey(clave) << endl;

    // Intentar obtener un valor con una clave que no existe
    clave = "pais";
    cout << "El valor de la clave \"" << clave << "\" es: " << json.getValueByKey(clave) << endl;

    return 0;
}
