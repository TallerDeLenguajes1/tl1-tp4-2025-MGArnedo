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
//Funcion que crea una tarea (el contenido del nodo)
Tarea CrearTarea(int tareaID, char descripcion[], int duracion){
    Tarea nuevaTarea;
    nuevaTarea.TareaID=tareaID;
    strcpy(nuevaTarea.Descripcion,descripcion);
    nuevaTarea.Duracion=duracion;
    return nuevaTarea;
}
//Funcion que crea un nodo
Nodo * CrearNodo(Tarea Tarea){
    Nodo * nuevoNodo=(Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->T=Tarea;
    nuevoNodo->Siguiente=NULL;
    return nuevoNodo;
}
//Funcion que crea una lista vacia
Nodo * CrearLista(){
    return NULL;
}
//Funcion que inserta un nodo al comienzo de la lista
void InsertarNodo(Nodo ** Start, Nodo *Nodo)
{
    Nodo->Siguiente = *Start;
    *Start  = Nodo ;
}
//Funcion que permite mover un nodo de una lista a otra
void TransferirTarea(Nodo **tareasRealizadas,Nodo **tareasPendientes,int ID){
    Nodo * actual =*tareasPendientes;
    Nodo * anterior=NULL;
    while (actual!=NULL&&actual->T.TareaID!=ID)
    {
        anterior=actual;
        actual=actual->Siguiente;
    }
    if (actual==NULL)
    {
        printf("No se encontro ninguna tarea bajo ese ID");
        return;
    }
    if (anterior==NULL)
    {
        *tareasPendientes=actual->Siguiente;
    }else
    {
        anterior->Siguiente=actual->Siguiente;
    }
    InsertarNodo(tareasRealizadas,actual);
}
//Funcion que devuelve la cantidad de nodos de una lista enlazada
int longitud(Nodo *lista){
    int cantidadDeNodos=0;
    while (lista!=NULL)
    {
        cantidadDeNodos++;
        lista=lista->Siguiente;
    }
    return cantidadDeNodos;
}
//Funcion permita listar todas las tareas pendientes y realizadas. 
void MostrarLista(Nodo*Lista, int cantidadDeNodos){
    Nodo* listarLista = Lista;
    if (Lista==NULL)
    {
        printf("\n    Lista vacia\n");
        return;
    }
    for (int i = 0; i < cantidadDeNodos; i++)
    {
        printf("\n    Tarea ID: %d\n",listarLista->T.TareaID);
        printf("    Descripcion: %s\n",listarLista->T.Descripcion);
        printf("    Duracion: %d[minutos]\n",listarLista->T.Duracion);
        listarLista=listarLista->Siguiente;
    }
    }
//Funcion que permite buscar una tarea por ID o palabra clave

void ConsultarTareas(Nodo* tareasPendientes, Nodo* tareasRealizadas) {
    int opcion;
    printf("Ingrese '0' para buscar por ID, ingrese '1' para buscar por palabra clave: ");
    scanf("%d", &opcion);
    getchar(); 

    if (opcion == 0) { 
        int ID;
        printf("Ingrese el ID de la tarea a buscar: ");
        scanf("%d", &ID);
        getchar();

        Nodo* actual = tareasPendientes;
        printf("\nBuscando en tareas pendientes:\n");
        while (actual != NULL) {
            if (actual->T.TareaID == ID) {
                printf("    Tarea encontrada:\n");
                printf("    ID: %d\n", actual->T.TareaID);
                printf("    Descripcion: %s\n", actual->T.Descripcion);
                printf("    Duracion: %d minutos\n", actual->T.Duracion);
                return;
            }
            actual = actual->Siguiente;
        }

        actual = tareasRealizadas;
        printf("\nBuscando en tareas realizadas:\n");
        while (actual != NULL) {
            if (actual->T.TareaID == ID) {
                printf("    Tarea encontrada:\n");
                printf("    ID: %d\n", actual->T.TareaID);
                printf("    Descripcion: %s\n", actual->T.Descripcion);
                printf("    Duracion: %d minutos\n", actual->T.Duracion);
                return;
            }
            actual = actual->Siguiente;
        }

        printf("No se encontró ninguna tarea con el ID especificado.\n");

    } else if (opcion == 1) { 
        char palabraClave[100];
        printf("Ingrese una palabra clave para buscar en las descripciones: ");
        fgets(palabraClave, sizeof(palabraClave), stdin);
        palabraClave[strcspn(palabraClave, "\n")] = 0; 

        printf("\nBuscando en tareas pendientes:\n");
        Nodo* actual = tareasPendientes;
        while (actual != NULL) {
            if (strstr(actual->T.Descripcion, palabraClave) != NULL) {
                printf("    Tarea encontrada:\n");
                printf("    ID: %d\n", actual->T.TareaID);
                printf("    Descripcion: %s\n", actual->T.Descripcion);
                printf("    Duracion: %d minutos\n", actual->T.Duracion);
            }
            actual = actual->Siguiente;
        }

        printf("\nBuscando en tareas realizadas:\n");
        actual = tareasRealizadas;
        while (actual != NULL) {
            if (strstr(actual->T.Descripcion, palabraClave) != NULL) {
                printf("    Tarea encontrada:\n");
                printf("    ID: %d\n", actual->T.TareaID);
                printf("    Descripcion: %s\n", actual->T.Descripcion);
                printf("    Duracion: %d minutos\n", actual->T.Duracion);
            }
            actual = actual->Siguiente;
        }
    } else {
        printf("Opción inválida.\n");
    }
}
    
int main(){
    int respuesta=1;
    int ID=1000;
    Nodo *tareasPendientes = CrearLista();
    Nodo *tareasRealizadas = CrearLista();
    //Cargar la lista de tareas pendientes
    printf("\nCargar lista de tareas pendientes\n\n");
    while (respuesta==1)
    {
        printf("    ¿Agregar nueva tarea? (1:Si, 0:No): ");
        scanf("%d",&respuesta);
        getchar();
        if (respuesta==1)
        {
            char descripcionDeLaTarea[100];
            int duracionDeLaTarea;
            
            printf("    Tarea Nro %d[ID] -----------------------------\n",ID);
            printf("    Ingrese una descripcion de la tarea: ");
            fgets(descripcionDeLaTarea,sizeof(descripcionDeLaTarea),stdin);
            descripcionDeLaTarea[strcspn(descripcionDeLaTarea,"\n")]=0;
            printf("    Ingrese la duracion de la tarea (en minutos): ");
            scanf("%d",&duracionDeLaTarea);
            getchar();
            Tarea tareaPendiente =CrearTarea(ID,descripcionDeLaTarea,duracionDeLaTarea);
            Nodo *nuevoNodo = CrearNodo(tareaPendiente);
            InsertarNodo(&tareasPendientes,nuevoNodo);
            printf("    ¡Tarea agregada a la lista!\n\n");

        }
        ID++;
    }
    //Elegir que tareas de la lista de pendientes se van pasar a la lista de tareas realizadas.  
    respuesta=1;
    printf("\nTransferir tareas pendientes a la lista de tareas realizadas\n");
    while (respuesta==1)
    {
        printf("\n    ¿Desea transferir una tarea pendiente a la lista de tareas realizadas? (1:Si,0:No): ");
        scanf("%d",&respuesta);
        getchar();
        if (respuesta==1)
        {   
            int IDdeTareaATransferir;
            printf("    Ingrese el ID de la tarea a transferir: ");
            scanf("%d",&IDdeTareaATransferir);
            getchar();
            TransferirTarea(&tareasRealizadas,&tareasPendientes,IDdeTareaATransferir);
        }
    }
    //Mostrar por pantalla las listas de tareas pendientes y realizadas
    printf("\nLISTA de tareas PENDIENTES:\n");
    MostrarLista(tareasPendientes,longitud(tareasPendientes));
    printf("\nLISTA de tareas REALIZADAS:\n");
    MostrarLista(tareasRealizadas,longitud(tareasRealizadas));
    ConsultarTareas(tareasRealizadas,tareasPendientes);

    return 0;
}
