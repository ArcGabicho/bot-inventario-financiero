# 📦 Bot Controlador de Inventario Financiero

**Bot profesional de escritorio en C++ para el control automatizado de inventarios financieros.**  
Diseñado para empresas, pymes y consultores que necesitan gestionar y auditar ingresos, egresos y activos financieros de forma eficiente, segura y organizada.

---

## 🚀 Funcionalidades principales

- 🧾 Registro de ingresos y egresos financieros
- 📊 Visualización completa del inventario financiero
- 📝 Edición y eliminación de movimientos
- 📤 Exportación de reportes financieros en CSV/PDF
- 🧠 Sistema inteligente de detección de inconsistencias
- 🔧 Panel de configuración para personalizar reglas contables
- 🔐 Seguridad básica con validaciones y cifrado local opcional

---

## 💼 Aplicaciones empresariales

Ideal para:

- Departamentos de contabilidad
- Empresas de logística y operaciones
- Pymes que desean digitalizar su control financiero
- Contadores y auditores independientes
- Consultorías de gestión financiera

---

## 🖥️ Requisitos del sistema

- **Sistema operativo**: Windows, Linux o macOS
- **Compilador**: C++17 o superior (GCC, Clang, MSVC)
- **Recursos mínimos**:
    - CPU: Dual Core 2.0 GHz
    - RAM: 2 GB
    - Disco: 50 MB libres

---

## 🛠️ Instalación y ejecución

### 🔧 Compilación

#### Windows:
```bash
g++ -std=c++17 -o inventario_bot main.cpp
```
```bash
inventario_bot.exe
```

---

## 🧪 Ejemplo de uso

1. Seleccione "Registrar nuevo ingreso financiero"
2. Ingrese monto, descripción y fecha
3. Visualice en "Ver inventario financiero"
4. Exporte el reporte mensual en PDF
5. Controle y analice los movimientos desde el panel principal

---

## 📁 Estructura del proyecto

```bash
inventario-bot/
├── include/
│   ├── inventario.h
│   ├── entrada.h
│   ├── reporte.h
│   └── utils.h
├── src/
│   ├── inventario.cpp
│   ├── entrada.cpp
│   ├── reporte.cpp
│   └── utils.cpp
├── data/
│   └── movimientos.csv
├── exports/
│   └── [archivos PDF/CSV generados]
├── config/
│   └── settings.json
├── main.cpp
├── LICENSE
└── README.md
```

---

## 🔒 Seguridad

- Validación básica de entradas

- Control de acceso a archivos sensibles

- Opcional: integración futura con sistema de login y cifrado de datos

---

## 📄 Licencia

Este proyecto está licenciado bajo los términos de la [MIT License](LICENSE).

---

## 👤 Autor

**Gabriel Polack**  
Consultor TI & Arquitecto de Software – BlackMount Corporation E.I.R.L  
🌐 Especialista en Gestion de Proyectos TI, Desarrollo Full Stack y Soluciones Empresariales
