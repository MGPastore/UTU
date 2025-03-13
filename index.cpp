#include <iostream>
#include <string>
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
        cout << " \"" << clave << "\": \"" << valor << "\" " << endl;
    }
};

int main() {
    System system;

    system.printOutInt(42);
    system.printOutString("Hola Mundo");
    system.printOutFloat(3.14f);
    system.printOutJson("nombre", "Maximiliano");

    return 0;
}
