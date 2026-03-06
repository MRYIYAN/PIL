//==========================================================//
// TAREA2 ENTREGABLE 6/03/2026
//==========================================================//

// Se define una estrutura de tipo "empleado" que almacenará el nombre del empleado el apellido del empleado,
// Su edad, su salario, el departamento dentro de la empresa en el que trabaja y un número entero positivo
// que identifica el empleado (ID). Otra estructura de tipo "proyecto" contendra un array de punteros a los empleados adscritos al proyecto (maximo de 5 personas por proyecto)
// el título del proyecto y el tiempo, en meses, concedido al proyecto. Luego, creará funciones que le permitan obtener estadísticas básicas, tales como imprimir la lista de proyectos 
// para un empleado dado, imprimir la lista de empleados que participan en un proyecto dado, determinar el empleado que está participando en más proyectos y el que participa en menos proyectos,
// determinar el proyecto que tiene más empleados adscritos y el que menos tiene.
// Es importante tomar en cuenta que se deben pasar las estructuras por referencia (usando punteros) a las funciones que se van a crear. 
// Por otra parte, la definición de todas las estructuras debe usar typedef. 
// Cuando un proyecto tenga menos de cinco empleados participando en él, colocará el valor NULL en las últimas entradas del array de empleados adscritos al proyecto. 
// Recuerde que este valor NULL está definido en la librería stdlib.h 

//==========================================================//

#include <stdio.h>
#include <string.h>
#include "empleado_proyecto.h"

int main()
{
    // Creamos los empleados  
    Empleado e[7] = {
        {"Juan","Pedraza",25,1245.50,10010},
        {"Marta","Hidalgo",31,1732.70,10011},
        {"Pablo","Paredes",28,1154.00,10012},
        {"Juana","Ortega",35,2250.00,10013},
        {"Marco","Gamboa",42,1800.00,10014},
        {"Gabriela","Salas",33,1915.25,10015},
        {"Pedro","Rius",24,1545.33,10016}
    };

    // Creamos los proyectos
    Proyecto p[5];

    // Proyecto 1
    strcpy(p[0].titulo,"Cuello de botella en horas punta");
    p[0].meses = 8;
    p[0].empleados[0] = &e[0];
    p[0].empleados[1] = &e[3];
    p[0].empleados[2] = NULL;
    p[0].empleados[3] = NULL;
    p[0].empleados[4] = NULL;

    // Proyecto 2
    strcpy(p[1].titulo,"Luminosidad alta sistemas enfriamiento");
    p[1].meses = 15;
    p[1].empleados[0] = &e[1];
    p[1].empleados[1] = &e[2];
    p[1].empleados[2] = &e[6];
    p[1].empleados[3] = NULL;
    p[1].empleados[4] = NULL;

    // Proyecto 3
    strcpy(p[2].titulo,"Minimizacion riesgos escaleras");
    p[2].meses = 26;
    p[2].empleados[0] = &e[0];
    p[2].empleados[1] = NULL;
    p[2].empleados[2] = NULL;
    p[2].empleados[3] = NULL;
    p[2].empleados[4] = NULL;

    // Proyecto 4
    strcpy(p[3].titulo,"Apertura nuevo comedor");
    p[3].meses = 12;
    p[3].empleados[0] = &e[0];
    p[3].empleados[1] = &e[1];
    p[3].empleados[2] = &e[4];
    p[3].empleados[3] = &e[6];
    p[3].empleados[4] = NULL;

    // Proyecto 5
    strcpy(p[4].titulo,"Optimizar tiempo respuesta");
    p[4].meses = 17;
    p[4].empleados[0] = &e[0];
    p[4].empleados[1] = &e[1];
    p[4].empleados[2] = &e[2];
    p[4].empleados[3] = &e[4];
    p[4].empleados[4] = &e[6];

    // Probamos las funciones
    proyectosDeEmpleado(&e[0], p, 5);
    empleadosDeProyecto(&p[4]);
    empleadoMasMenos(e, 7, p, 5);
    proyectoMasMenos(p, 5);

    return 0;
}