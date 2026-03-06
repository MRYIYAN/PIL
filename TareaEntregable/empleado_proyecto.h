#ifndef EMPLEADO_PROYECTO_H
#define EMPLEADO_PROYECTO_H

//=======================================================//
//                   IMPORTS                             //
//=======================================================//
#include <stdlib.h>

#define MAX 5   // máximo empleados por proyecto


//=======================================================//
//               ESTRUCTURAS PRINCIPALES                 //
//=======================================================//

// Estructura empleado
// usamos typedef porque así se ha solicitado
typedef struct {
    char nombre[50];
    char apellido[50];
    int edad;
    float salario;
    int id;
} Empleado;


// Estructura proyecto tiene un array de punteros a empleados
typedef struct {
    char titulo[150];
    Empleado *empleados[MAX];   // aquí guardamos direcciones
    int meses;
} Proyecto;


//=======================================================//
//                 PROTOTIPOS DE FUNCIONES               //
//=======================================================//
// Todas las funciones trabajan con punteros para evitar
// copias de estructuras y manejar arreglos dinámicos

void proyectosDeEmpleado(Empleado *e, Proyecto *p, int nProy); // Imprime los proyectos de un empleado dado

void empleadosDeProyecto(Proyecto *p);

void empleadoMasMenos(Empleado *e, int nEmp, Proyecto *p, int nProy); // Encuentra el empleado con más y menos proyectos asignados

void proyectoMasMenos(Proyecto *p, int nProy);

#endif