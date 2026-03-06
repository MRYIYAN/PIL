#ifndef EMPLEADO_PROYECTO_H
#define EMPLEADO_PROYECTO_H

#include <stdlib.h> 

#define MAX 5   // maximo empleados por proyecto (lo dice el enunciado)


//===========================================================//
// Estructura empleado
// usamos typedef porque así se ha solicitado
//===========================================================//
typedef struct {
    char nombre[50];
    char apellido[50];
    int edad;
    float salario;
    int id;
} Empleado;


// Estructura proyecto
// tiene un array de punteros a empleados (no empleados normales!)
typedef struct {
    char titulo[150];
    Empleado *empleados[MAX];   // aqui guardamos direcciones
    int meses;
} Proyecto;


// Funciones que vamos a usar
// todas reciben los punteros 

void proyectosDeEmpleado(Empleado *e, Proyecto *p, int nProy);

void empleadosDeProyecto(Proyecto *p);

void empleadoMasMenos(Empleado *e, int nEmp, Proyecto *p, int nProy);

void proyectoMasMenos(Proyecto *p, int nProy);

#endif