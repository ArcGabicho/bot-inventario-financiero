#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

struct MovimientoFinanciero {
    int id;
    string tipo; // "Ingreso" o "Egreso"
    string descripcion;
    double monto;
};

vector<MovimientoFinanciero> inventario;
int siguienteId = 1;

void mostrarBanner() {
    system(CLEAR);
    cout << R"(
  ____        _        ____            _             _
 | __ )  __ _| |_ __ _|  _ \ ___  __ _(_) ___  _ __ (_)_ __   __ _
 |  _ \ / _` | __/ _` | |_) / _ \/ _` | |/ _ \| '_ \| | '_ \ / _` |
 | |_) | (_| | || (_| |  _ <  __/ (_| | | (_) | | | | | | | | (_| |
 |____/ \__,_|\__\__,_|_| \_\___|\__, |_|\___/|_| |_|_|_| |_|\__, |
                                 |___/                       |___/

         BOT CONTROLADOR DE INVENTARIO FINANCIERO
==================================================================
)";
    this_thread::sleep_for(chrono::seconds(2));
}

void mostrarMenu() {
    cout << R"(
----------------------- MENU PRINCIPAL -----------------------

1. Ver inventario financiero
2. Registrar nuevo ingreso financiero
3. Registrar nuevo egreso financiero
4. Editar movimientos existentes
5. Generar reporte de inventario
6. Configuraciones del sistema
0. Salir

---------------------------------------------------------------
Ingrese una opcion: )";
}

void verInventario() {
    cout << "\n--- Inventario Financiero ---\n";
    if (inventario.empty()) {
        cout << "No hay movimientos registrados.\n";
    } else {
        for (const auto& mov : inventario) {
            cout << "ID: " << mov.id << " | " << mov.tipo << " | " << mov.descripcion << " | Monto: $" << mov.monto << '\n';
        }
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void registrarMovimiento(const string& tipo) {
    MovimientoFinanciero mov;
    mov.id = siguienteId++;
    mov.tipo = tipo;
    cout << "\nDescripcion: ";
    cin.ignore();
    getline(cin, mov.descripcion);
    cout << "Monto: $";
    cin >> mov.monto;
    inventario.push_back(mov);
    cout << "\n" << tipo << " registrado exitosamente.\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void editarMovimiento() {
    int id;
    cout << "\nIngrese el ID del movimiento a editar: ";
    cin >> id;
    bool encontrado = false;
    for (auto& mov : inventario) {
        if (mov.id == id) {
            encontrado = true;
            cout << "Descripcion actual: " << mov.descripcion << "\nNueva descripcion: ";
            cin.ignore();
            getline(cin, mov.descripcion);
            cout << "Monto actual: $" << mov.monto << "\nNuevo monto: $";
            cin >> mov.monto;
            cout << "\nMovimiento editado exitosamente.\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            break;
        }
    }
    if (!encontrado) {
        cout << "\nNo se encontro el movimiento.\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
    }
}

void generarReporte() {
    double totalIngresos = 0, totalEgresos = 0;
    for (const auto& mov : inventario) {
        if (mov.tipo == "Ingreso") totalIngresos += mov.monto;
        else if (mov.tipo == "Egreso") totalEgresos += mov.monto;
    }
    cout << "\n--- Reporte de Inventario ---\n";
    cout << "Total Ingresos: $" << totalIngresos << '\n';
    cout << "Total Egresos: $" << totalEgresos << '\n';
    cout << "Balance: $" << (totalIngresos - totalEgresos) << "\n";
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void configuraciones() {
    cout << "\n--- Configuraciones del Sistema ---\n";
    cout << "(No hay configuraciones disponibles en esta version)\n";
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

int main() {
    mostrarBanner();

    int opcion = -1;

    while (opcion != 0) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                verInventario();
                break;
            case 2:
                registrarMovimiento("Ingreso");
                break;
            case 3:
                registrarMovimiento("Egreso");
                break;
            case 4:
                editarMovimiento();
                break;
            case 5:
                generarReporte();
                break;
            case 6:
                configuraciones();
                break;
            case 0:
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
        if (opcion != 0) {
            system(CLEAR);
            mostrarBanner();
        }
    }

    cout << "\nCerrando el Bot de Inventario Financiero...\n";
    return 0;
}