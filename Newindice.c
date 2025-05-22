#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    fpos_t inicio_pos, fin_pos;
    int inicio_encontrado = 0;
    int contador = 0;

    archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Leer los 20 caracteres y determinar posiciones
    while (contador < 20) {
        fpos_t pos_actual;
        fgetpos(archivo, &pos_actual);  // Obtener posición actual
        int caracter = fgetc(archivo);  // Leer carácter

        if (caracter == EOF) break;  // Fin de archivo prematuro

        if (!isspace(caracter)) {
            if (!inicio_encontrado) {
                inicio_pos = pos_actual;  // Guardar posición de inicio
                inicio_encontrado = 1;
            }
            fin_pos = pos_actual;  // Actualizar posición final
        }

        contador++;
    }

    fclose(archivo);

    // Convertir posiciones fpos_t a numéricas
    archivo = fopen("datos.txt", "r");
    long pos_inicio, pos_fin;

    if (inicio_encontrado) {
        fsetpos(archivo, &inicio_pos);
        pos_inicio = ftell(archivo);
        fsetpos(archivo, &fin_pos);
        pos_fin = ftell(archivo);
        printf("Posición de inicio: %ld\n", pos_inicio);
        printf("Posición de fin: %ld\n", pos_fin);
    } else {
        printf("No hay caracteres válidos en la cadena.\n");
    }

    fclose(archivo);
    return 0;
}
