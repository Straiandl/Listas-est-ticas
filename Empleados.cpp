#include <iostream>
#include <string>

const int MAX_EMPLEADOS = 100; // Tamaño máximo de la lista

class empleado {
private:
    int ClaveEmpleado;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string ReportaA;

public:
    empleado() : ClaveEmpleado(0), nombre(""), domicilio(""), sueldo(0), ReportaA("") {}

    void setClaveE(int clave) { ClaveEmpleado = clave; }
    void setnombre(std::string nom) { nombre = nom; }
    void setdomicilio(std::string dom) { domicilio = dom; }
    void setsueldo(float s) { sueldo = s; }
    void setReporta(std::string reporta) { ReportaA = reporta; }

    int getClave() const { return ClaveEmpleado; }
    float getsueldo() const { return sueldo; }

    friend std::ostream& operator<<(std::ostream& os, const empleado& emp);
    friend std::istream& operator>>(std::istream& is, empleado& emp);
};

std::ostream& operator<<(std::ostream& os, const empleado& emp) {
    os << "\nClave de empleado: " << emp.ClaveEmpleado
       << "\nNombre: " << emp.nombre
       << "\nDomicilio: " << emp.domicilio
       << "\nSueldo: " << emp.sueldo
       << "\nReporta a: " << emp.ReportaA << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, empleado& emp) {
    std::cout << "Introduce la clave de empleado: ";
    is >> emp.ClaveEmpleado;

    std::cin.ignore(); // Limpiar el buffer
    std::cout << "Introduce el nombre: ";
    std::getline(is, emp.nombre);

    std::cout << "Introduce el domicilio: ";
    std::getline(is, emp.domicilio);

    std::cout << "Introduce el sueldo: ";
    is >> emp.sueldo;

    std::cin.ignore(); // Limpiar el buffer
    std::cout << "Introduce a quien reporta: ";
    std::getline(is, emp.ReportaA);

    return is;
}

class ListaEmpleados {
private:
    empleado lista[MAX_EMPLEADOS]; // Arreglo estático de empleados
    int cantidad; // Cantidad actual de empleados en la lista

public:
    ListaEmpleados() : cantidad(0) {}

    bool vacia() const {
        return cantidad == 0;
    }

    bool llena() const {
        return cantidad == MAX_EMPLEADOS;
    }

    void insertar(const empleado& emp) {
        if (llena()) {
            std::cout << "Error: La lista esta llena.\n";
            return;
        }
        lista[cantidad] = emp;
        cantidad++;
        std::cout << "Empleado insertado correctamente.\n";
    }

    int buscar(int clave) const {
        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getClave() == clave) {
                return i; // Devuelve la posición del empleado
            }
        }
        return -1; // No se encontró el empleado
    }

    void eliminar(int clave) {
        int pos = buscar(clave);
        if (pos == -1) {
            std::cout << "Error: No se encontro el empleado.\n";
            return;
        }
        for (int i = pos; i < cantidad - 1; i++) {
            lista[i] = lista[i + 1];
        }
        cantidad--;
        std::cout << "Empleado eliminado correctamente.\n";
    }

    void imprimir() const {
        if (vacia()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }
        for (int i = 0; i < cantidad; i++) {
            std::cout << lista[i] << std::endl;
        }
    }
};

int main() {
    ListaEmpleados lista;
    int op = 0;

    while (op != 7) {
        std::cout << "\nMenú:\n 1: Insertar empleado.\n 2: Buscar empleado.\n 3: Eliminar empleado.\n 4: Verificar si la lista está vacía.\n 5: Verificar si la lista está llena.\n 6: Imprimir lista de empleados.\n 7: Salir.\n\n";
        std::cin >> op;

        switch (op) {
            case 1: {
                if (lista.llena()) {
                    std::cout << "La lista está llena.\n";
                } else {
                    empleado emp;
                    std::cin >> emp;
                    lista.insertar(emp);
                }
                break;
            }
            case 2: {
                int clave;
                std::cout << "Introduce la clave del empleado a buscar: ";
                std::cin >> clave;
                int pos = lista.buscar(clave);
                if (pos == -1) {
                    std::cout << "Empleado no encontrado.\n";
                } else {
                    std::cout << "Empleado encontrado:\n";
                    // Aquí podrías imprimir el empleado si tuvieras acceso a la lista.
                }
                break;
            }
            case 3: {
                int clave;
                std::cout << "Introduce la clave del empleado a eliminar: ";
                std::cin >> clave;
                lista.eliminar(clave);
                break;
            }
            case 4:
                if (lista.vacia()) {
                    std::cout << "La lista esta vacía.\n";
                } else {
                    std::cout << "La lista no esta vacía.\n";
                }
                break;
            case 5:
                if (lista.llena()) {
                    std::cout << "La lista esta llena.\n";
                } else {
                    std::cout << "La lista no esta llena.\n";
                }
                break;
            case 6:
                lista.imprimir();
                break;
            case 7:
                std::cout << "Gracias.\n";
                break;
            default:
                std::cout << "Opcion no valida.\n";
                break;
        }
    }

    return 0;
}