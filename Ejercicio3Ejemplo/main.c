#include <stdio.h>
#include <string.h>

// Definimos una constante para el número máximo de empleados por proyecto
#define MAX_EMP_PROY 5

// ============================================================
// DEFINICIÓN DE ESTRUCTURAS
// ============================================================

// Estructura que representa a un empleado
struct Empleado {
    char nombre[50];
    char apellido[50];
    int edad;
    float salario;
    char departamento[50];
    int id;
};

// Estructura que representa a un proyecto
struct Proyecto {
    // Array de punteros a empleados (IMPORTANTE: son punteros, no empleados directos)
    struct Empleado *empleados[MAX_EMP_PROY];

    char titulo[50];
    char departamento[50];
    int meses;
};

// ============================================================
// FUNCIONES
// ============================================================


// ------------------------------------------------------------
// Función para imprimir los empleados que participan
// en cada proyecto
// ------------------------------------------------------------
void imprimirEmpleadosPorProyecto(struct Proyecto *proyectos, int nProy) {

    // Recorremos todos los proyectos
    for (int i = 0; i < nProy; i++) {

        printf("\n==============================\n");
        printf("Proyecto: %s\n", proyectos[i].titulo);
        printf("Departamento: %s\n", proyectos[i].departamento);
        printf("Duración: %d meses\n", proyectos[i].meses);
        printf("Empleados asignados:\n");

        // Recorremos el array de punteros (máximo 5)
        for (int j = 0; j < MAX_EMP_PROY; j++) {

            // MUY IMPORTANTE: comprobar que no sea NULL
            if (proyectos[i].empleados[j] != NULL) {

                // Accedemos usando ->
                printf(" - %s %s (ID: %d)\n",
                       proyectos[i].empleados[j]->nombre,
                       proyectos[i].empleados[j]->apellido,
                       proyectos[i].empleados[j]->id);
            }
        }
    }
}


// ------------------------------------------------------------
// Función para imprimir los proyectos en los que participa
// cada empleado
// ------------------------------------------------------------
void imprimirProyectosPorEmpleado(struct Empleado *empleados, int nEmp,
                                  struct Proyecto *proyectos, int nProy) {

    // Recorremos todos los empleados
    for (int i = 0; i < nEmp; i++) {

        printf("\n=================================\n");
        printf("Empleado: %s %s\n",
               empleados[i].nombre,
               empleados[i].apellido);

        printf("Proyectos en los que participa:\n");

        // Recorremos todos los proyectos
        for (int j = 0; j < nProy; j++) {

            // Recorremos los 5 posibles empleados del proyecto
            for (int k = 0; k < MAX_EMP_PROY; k++) {

                // Comparamos direcciones (punteros)
                if (proyectos[j].empleados[k] == &empleados[i]) {
                    printf(" - %s\n", proyectos[j].titulo);
                }
            }
        }
    }
}


// ------------------------------------------------------------
// Función que cuenta en cuántos proyectos participa
// un empleado concreto
// ------------------------------------------------------------
int contarProyectosEmpleado(struct Empleado *emp,
                            struct Proyecto *proyectos, int nProy) {

    int contador = 0;

    // Recorremos todos los proyectos
    for (int i = 0; i < nProy; i++) {

        for (int j = 0; j < MAX_EMP_PROY; j++) {

            // Si el puntero coincide, sumamos
            if (proyectos[i].empleados[j] == emp) {
                contador++;
            }
        }
    }

    return contador;
}


// ------------------------------------------------------------
// Determinar empleado con más y menos proyectos
// ------------------------------------------------------------
void estadisticasEmpleados(struct Empleado *empleados, int nEmp,
                           struct Proyecto *proyectos, int nProy) {

    int max = -1;
    int min = 9999;
    int posMax = 0;
    int posMin = 0;

    for (int i = 0; i < nEmp; i++) {

        // Pasamos la dirección del empleado
        int total = contarProyectosEmpleado(&empleados[i], proyectos, nProy);

        if (total > max) {
            max = total;
            posMax = i;
        }

        if (total < min) {
            min = total;
            posMin = i;
        }
    }

    printf("\n=================================\n");
    printf("Empleado con MÁS proyectos: %s %s (%d proyectos)\n",
           empleados[posMax].nombre,
           empleados[posMax].apellido,
           max);

    printf("Empleado con MENOS proyectos: %s %s (%d proyectos)\n",
           empleados[posMin].nombre,
           empleados[posMin].apellido,
           min);
}


// ------------------------------------------------------------
// Contar empleados dentro de un proyecto
// ------------------------------------------------------------
int contarEmpleadosProyecto(struct Proyecto *proy) {

    int contador = 0;

    for (int i = 0; i < MAX_EMP_PROY; i++) {

        if (proy->empleados[i] != NULL) {
            contador++;
        }
    }

    return contador;
}


// ------------------------------------------------------------
// Determinar proyecto con más y menos empleados
// ------------------------------------------------------------
void estadisticasProyectos(struct Proyecto *proyectos, int nProy) {

    int max = -1;
    int min = 9999;
    int posMax = 0;
    int posMin = 0;

    for (int i = 0; i < nProy; i++) {

        int total = contarEmpleadosProyecto(&proyectos[i]);

        if (total > max) {
            max = total;
            posMax = i;
        }

        if (total < min) {
            min = total;
            posMin = i;
        }
    }

    printf("\n=================================\n");
    printf("Proyecto con MÁS empleados: %s (%d empleados)\n",
           proyectos[posMax].titulo, max);

    printf("Proyecto con MENOS empleados: %s (%d empleados)\n",
           proyectos[posMin].titulo, min);
}


// ============================================================
// MAIN
// ============================================================

int main() {

    // Creamos empleados directamente en un array
    struct Empleado empleados[3] = {
        {"Juan", "Perez", 30, 2000.0, "IT", 1},
        {"Ana", "Garcia", 28, 2200.0, "IT", 2},
        {"Luis", "Martinez", 35, 2500.0, "Redes", 3}
    };

    // Creamos proyectos
    struct Proyecto proyectos[2];

    // -------- Proyecto 1 --------
    strcpy(proyectos[0].titulo, "Firewall Corporativo");
    strcpy(proyectos[0].departamento, "IT");
    proyectos[0].meses = 6;

    // Asignamos empleados usando direcciones (&)
    proyectos[0].empleados[0] = &empleados[0];
    proyectos[0].empleados[1] = &empleados[1];

    // Las posiciones restantes deben ser NULL (MUY IMPORTANTE)
    proyectos[0].empleados[2] = NULL;
    proyectos[0].empleados[3] = NULL;
    proyectos[0].empleados[4] = NULL;

    // -------- Proyecto 2 --------
    strcpy(proyectos[1].titulo, "Auditoria Red");
    strcpy(proyectos[1].departamento, "Redes");
    proyectos[1].meses = 4;

    proyectos[1].empleados[0] = &empleados[0];
    proyectos[1].empleados[1] = &empleados[2];

    proyectos[1].empleados[2] = NULL;
    proyectos[1].empleados[3] = NULL;
    proyectos[1].empleados[4] = NULL;

    // Probamos todas las funciones
    imprimirEmpleadosPorProyecto(proyectos, 2);
    imprimirProyectosPorEmpleado(empleados, 3, proyectos, 2);
    estadisticasEmpleados(empleados, 3, proyectos, 2);
    estadisticasProyectos(proyectos, 2);

    return 0;

    // gcc practica.c -o practica
   //./practica 

   // gcc main.c empleado.c proyecto.c -o programa
}