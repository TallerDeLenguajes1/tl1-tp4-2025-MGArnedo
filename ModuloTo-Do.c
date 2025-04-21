/*Considere la siguiente situación: En la misma distribuidora del práctico anterior ahora surgió 
la necesidad de llevar un control de las tareas realizadas por sus empleados. Usted forma 
parte del equipo de programación que se encargará de hacer el módulo en cuestión que a 
partir de ahora se llamará módulo To-Do: 
Tareas 
Cada empleado tiene un listado de tareas a realizar y debe indicar en el sistema si fueron 
realizadas o no. Para ello deberá crear dos listas enlazadas: una para las tareas pendientes y 
otra para las tareas realizadas. Cada vez que se marque una tarea como realizada deberá 
mover la tarea de la lista de tareas pendientes a la lista de tareas realizadas. 
Las estructuras de datos necesarias son las siguientes: */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Tarea{ 
    int TareaID;//Numérico autoincremental comenzando en 1000 
    char Descripcion[100];  //       
    int Duracion; // entre 10 – 100  
    }typedef Tarea;  
struct Nodo{ 
    Tarea T;  
    struct Nodo *Siguiente;  
}typedef Nodo; 
Tarea CrearTarea(int tareaID, char descripcion[], int duracion){
    Tarea nuevaTarea;
    nuevaTarea.TareaID=tareaID;
    strcpy(nuevaTarea.Descripcion,descripcion);
    nuevaTarea.Duracion=duracion;
    return nuevaTarea;
}
Nodo * CrearNodo(Tarea Tarea){
    Nodo * nuevoNodo=malloc(sizeof(Nodo));
    nuevoNodo->T=Tarea;
    nuevoNodo->Siguiente=NULL;
    return nuevoNodo;
}
Nodo * CrearLista(){
    return NULL;
}
int main(){
    //1) Desarrolle una interfaz de carga de tareas para solicitar tareas pendientes, en la cual se 
    //solicite descripción y duración de la misma (el id debe ser generado automáticamente por 
    //el sistema, de manera autoincremental comenzando desde el número 1000). Al cabo de 
    //cada tarea consulte al usuario si desea ingresar una nueva tarea o finalizar la carga. 
    int respuesta=1;
    int ID=1000;
    Nodo *tareasPendientes = CrearLista();
    Nodo *tareasRealizadas = CrearLista();
    printf("Iniciando carga de la lista de tareas");
    while (respuesta==1)
    {
        printf("¿Desea agregar una nueva tarea o finalizar la carga? (0:No, 1:Si): ");
        scanf("%d",&respuesta);
        getchar();
        if (respuesta==1)
        {
            char descripcionDeLaTarea[1000];
            int duracionDeLaTarea;
            printf("Ingrese por pantalla la descripción de la tarea: ");
            fgets(descripcionDeLaTarea,sizeof(descripcionDeLaTarea),stdin);
            descripcionDeLaTarea[strcspn(descripcionDeLaTarea,"\n")]=0;
            getchar();
            printf("Ingrese por pantalla la duracion de la tarea (minutos): ");
            scanf("%d",&duracionDeLaTarea);
            getchar();
            Tarea tareaPendiente =CrearTarea(ID,descripcionDeLaTarea,duracionDeLaTarea);
            Nodo *nuevoNodo = CrearNodo(tareaPendiente);
            nuevoNodo->Siguiente = tareasPendientes;
            tareasPendientes = nuevoNodo;
            printf("Tarea agregada a la lista");

        }else
        {
            printf("Finalizando carga de la lista de tareas...");
        }
        ID++;
    }

    //2) Implemente una interfaz para elegir qué tareas de la lista de pendientes deben ser 
    //transferidas a la lista de tareas realizadas.  
    respuesta=1;
    printf("Iniciando transferencia de tareas pendientes a la lista de tareas realizadas");
    while (respuesta==1)
    {
        printf("¿Desea transferir una tarea pendiente a la lista de tareas realizadas? (0:No, 1:Si): ");
        scanf("%d",&respuesta);
        getchar();
        if (respuesta==1)
        {   
            printf("Lista actual de tareas pendientes: ");

        }else
        {
            
        }
    }
    printf("Finalizando transferencia de la lista de tareas pendientes a la lista de tareas realizadas");

    return 0;
}





//3) Implemente una funcionalidad que permita listar todas las tareas pendientes y realizadas. 

//4) Implemente una funcionalidad que permita consultar tareas por id o palabra clave y 
//mostrarlas por pantalla, indicando si corresponde a una tarea pendiente o realizada.
