#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

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

int main() {
    mostrarBanner();

    int opcion = -1;

    while (opcion != 0) {
        mostrarMenu();
        cin >> opcion;

        if (opcion < 0 || opcion > 6) {
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        } else if (opcion != 0) {
            cout << "\nFuncionalidad aun no implementada. Presione Enter para continuar...\n";
            cin.ignore(); // limpiar buffer
            cin.get();    // esperar Enter
            system(CLEAR);
            mostrarBanner();
        }
    }

    cout << "\nCerrando el Bot de Inventario Financiero...\n";
    return 0;
}