//
//  main.c
//  Mission0
//
//  Created by Benjamín Valdez on 2/28/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void *checkMalloc (size_t st) {
    void *mem = malloc (st);
    if (mem == NULL) {
        printf ("Fuera de memoria.\n");
        exit (1);
    }
    return mem;
}

void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

typedef struct mision {
    char mision[14];
    struct mision *next;
} mision_t;

typedef struct activo {
    char activo[15];
    struct activo *next;
} activo_t;

typedef struct agent {
    char nombre[256];
    char apellido[256];
    int edad;
    activo_t *primerActivo;
    mision_t *primerMision;
    struct agent *next;
} agent_t;

bool validarMision(char mision[14]) {
    for (int i = 0; i < 3; i++) {
        if (!isalpha(mision[i])) {
            return false;
        }
    }
    for (int i = 3; i < 12; i++) {
        if (!isnumber(mision[i])) {
            return false;
        }
    }
    return true;
}

bool validarActivo(char activo[15]) {
    for (int i = 0; i < 4; i++) {
        if (!isalpha(activo[i])) {
            return false;
        }
    }
    for (int i = 4; i < 13; i++) {
        if (!isnumber(activo[i])) {
            return false;
        }
    }
    return true;
}

void agregarActivo (agent_t *primero, char activo[15]) {
    activo_t *nuevo = checkMalloc (sizeof (*nuevo));
    strcpy (nuevo->activo, activo);
    nuevo->next = primero->primerActivo;
    primero->primerActivo = nuevo;
}

void agregarMision (agent_t *primero, char mision[14]) {
    mision_t *nuevo = checkMalloc (sizeof (*nuevo));
    strcpy (nuevo->mision, mision);
    nuevo->next = primero->primerMision;
    primero->primerMision = nuevo;
}

void agregarAgente (agent_t **primero) {
    agent_t *nuevo = checkMalloc (sizeof (*nuevo));
    char nombre[256];
    char apellido[256];
    char activo[15];
    char mision[14];
    int edad = 0;
    int opcionA = 0;
    int opcionB = 0;
    
    flushstdin();
    printf("Introduce el nombre del agente: ");
    fgets(nombre, sizeof(nombre), stdin);
    strtok(nombre, "\n");
    strcpy (nuevo->nombre, nombre);
    
    
    printf("Introduce el apellido del agente: ");
    fgets(apellido, sizeof(apellido), stdin);
    strtok(apellido, "\n");
    strcpy (nuevo->apellido, apellido);
    
    while(opcionA != 1) {
        printf("Introduce un activo asigando al agente: ");
        fgets(activo, sizeof(activo), stdin);
        if (validarActivo(activo)) {
            agregarActivo(nuevo, activo);
            printf("Activo agregado. Si ya no deseas agregar activos teclea 1, si quieres agregar otro teclea cualquier otro numero\n");
            scanf("%d", &opcionA);
        }
        else {
            printf("Ese codigo de activo no es valido, prueba otra vez\n");
        }
        flushstdin();
    }
    
    while(opcionB != 1) {
        printf("Introduce una mision asigando al agente: ");
        fgets(mision, sizeof(mision), stdin);
        strtok(mision, "\n");
        if (validarMision(mision)) {
            agregarMision(nuevo, mision);
            printf("Mision agregada. Si ya no deseas agregar misiones teclea 1, si quieres agregar otra teclea cualquier otro numero\n");
            scanf("%d", &opcionB);
        }
        else {
            printf("Ese codigo de mision no es valido, prueba otra vez\n");
        }
        flushstdin();
    }
    
    printf("Introduce la edad del agente: ");
    scanf("%d", &edad);
    nuevo->edad = edad;
    
    nuevo->next = *primero;
    *primero = nuevo;
}

void borrarAgente(agent_t **primero, char apellido[256]) {
    agent_t* temp = *primero, *prev = NULL;
  
    if (temp != NULL && temp->apellido == apellido) {
        *primero = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->apellido != apellido) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("No se encontro a ese agente \n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Agente borrado exitosamente \n");
}

void imprimirAgentes(agent_t *agenteActual) {
    while (agenteActual != NULL) {
        printf ("El agente %s %s de %d anos tiene los siguientes activos:\n", agenteActual->nombre, agenteActual->apellido, agenteActual->edad);

        activo_t *activoActual = agenteActual->primerActivo;
        while (activoActual != NULL) {
            if (activoActual != NULL) {
                printf ("   *%s\n", activoActual->activo);
                activoActual = activoActual->next;
            }
        }
        
        printf("Misiones:\n");
        mision_t *misionActual = agenteActual->primerMision;
        while (misionActual != NULL) {
            if (misionActual != NULL) {
                printf ("   *%s\n", misionActual->mision);
                misionActual = misionActual->next;
            }
        }
        printf("\n");
        agenteActual = agenteActual->next;
    }
}

void menuPrincipal() {
    agent_t *primerAgente = NULL;
    char apellido[256];
    int opcion = 0;
    
    printf("Bienvenido a la base de datos secreta \n");
    while (opcion != 4) {
        printf("Seleccione una opcion\n");
        printf(" 1. Agregar a un agente \n 2. Eliminar a un agente \n 3. Ver a todos los agentes \n 4. Salir\n");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                agregarAgente(&primerAgente);
                break;
            case 2:
                flushstdin();
                printf("Introduce el apellido del agente a borrar: ");
                fgets(apellido, sizeof(apellido), stdin);
                strtok(apellido, "\n");
                borrarAgente(&primerAgente, apellido);
                break;
            case 3:
                if (primerAgente != NULL) {
                    imprimirAgentes(primerAgente);
                }
                else {
                    printf("Aun no hay agentes registrados\n");
                }
                break;
                
            default:
                printf("Esa opcion no esta en el menu, prueba otra vez\n");
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    menuPrincipal();
    
    return 0;
}
