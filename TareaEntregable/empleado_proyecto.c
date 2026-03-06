//=======================================================//
//                   IMPORTS                             //
//=======================================================//
#include <stdio.h>
#include "empleado_proyecto.h"

// Esta funcion imprime los proyectos donde participa un empleado
// le pasamos el empleado por puntero
void proyectosDeEmpleado(Empleado *e, Proyecto *p, int nProy)
{
    printf("\nProyectos de %s %s:\n", e->nombre, e->apellido);

    // Aqui recorremos todos los proyectos
    for(int i = 0; i < nProy; i++)
    {
        // cada proyecto puede tener hasta max empleados
        for(int j = 0; j < MAX; j++)
        {
            // comparamos 
            if(p[i].empleados[j] == e)
            {
                printf(" - %s\n", p[i].titulo);
            }
        }
    }
}


//=======================================================//
//  Listados de empleados por proyecto                   //
//=======================================================//

// Esta función imprime la lista de empleados de un proyecto dado
// Recorremos el arreglo hasta encontrar un NULL, que marca el fin
void empleadosDeProyecto(Proyecto *p)
{
    printf("\nEmpleados del proyecto: %s\n", p->titulo);

    for(int i = 0; i < MAX; i++)
    {
        // si es NULL significa que ya no hay mas empleados
        if(p->empleados[i] != NULL)
        {
            printf(" - %s %s\n",
                   p->empleados[i]->nombre,
                   p->empleados[i]->apellido);
        }
    }
}



//=======================================================//
//  Análisis de cargas de trabajo                        //
//=======================================================//

// Aquí buscamos el empleado con más y menos proyectos asignados
// Usamos contadores y comparamos mientras recorremos empleados y proyectos
void empleadoMasMenos(Empleado *e, int nEmp, Proyecto *p, int nProy)
{
    int max = -1;
    int min = 99;
    int posMax = 0;
    int posMin = 0;

    // recorremos empleados
    for(int i = 0; i < nEmp; i++)
    {
        int cont = 0;  // contador de proyectos

        // miramos todos los proyectos
        for(int j = 0; j < nProy; j++)
        {
            for(int k = 0; k < MAX; k++)
            {
                if(p[j].empleados[k] == &e[i])
                {
                    cont++;
                }
            }
        }

        // vamos comparando para ver cual tiene mas
        if(cont > max)
        {
            max = cont;
            posMax = i;
        }

        if(cont < min)
        {
            min = cont;
            posMin = i;
        }
    }

    printf("\nEmpleado con MAS proyectos: %s (%d)\n",
           e[posMax].nombre, max);

    printf("Empleado con MENOS proyectos: %s (%d)\n",
           e[posMin].nombre, min);
}



//=======================================================//
//  Estadísticas de proyectos                            //
//=======================================================//

// Encuentra el proyecto con más empleados y el que tiene menos
// Itera sobre el listado y mantiene máximos y mínimos actualizados
void proyectoMasMenos(Proyecto *p, int nProy)
{
    int max = -1;
    int min = 99; 
    int posMax = 0;
    int posMin = 0;

    for(int i = 0; i < nProy; i++)
    {
        int cont = 0;

        for(int j = 0; j < MAX; j++)
        {
            if(p[i].empleados[j] != NULL)
            {
                cont++;
            }
        }

        if(cont > max)
        {
            max = cont;
            posMax = i;
        }

        if(cont < min)
        {
            min = cont;
            posMin = i;
        }
    }

    printf("\nProyecto con mas empleados: %s (%d)\n",
           p[posMax].titulo, max);

    printf("Proyecto con menos empleados: %s (%d)\n",
           p[posMin].titulo, min);
}