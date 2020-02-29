//
//  main.c
//  Mission0
//
//  Created by Benjamín Valdez on 2/28/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *chkMalloc (size_t sz) {
    void *mem = malloc (sz);

    // Just fail immediately on error.

    if (mem == NULL) {
        printf ("Out of memory! Exiting.\n");
        exit (1);
    }

    // Otherwise we know it worked.

    return mem;
}

typedef struct mision {
    char mision[14];
    struct mision *next;
} mision_t;

typedef struct activo {
    char activos[15];
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

void menuPrincipal() {
    int opcion = 0;
    printf("Bienvenido a la base de datos secreta \n");
    while (opcion != 4) {
        printf("Seleccione una opcion\n");
        printf(" 1. Agregar a un agente \n 2. Eliminar a un agente \n 3. Ver a todos los agentes \n 4. Salir\n");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case <#constant#>:
                <#statements#>
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
