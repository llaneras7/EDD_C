#include <stdio.h>
#include <string.h>

    /*Declaración del tipo struct Libro

    id Identificador con dos caracteres, se añade un tercer hueco para el carácter terminador
    precio valor del libro*/
    struct Libro
    {
        char id[3]; // Carácter terminador \0
        float *precio;
    };

    /**
     * @brief Cambiar el valor del factor con el nuevo introducido
     * @param factor Valor a modificar
     * @param nuevoValor Valor nuevo a establecer
     */
    void cambiarFactorGeneral(float *direccion_factor, float nuevoValor) 
    {
        //
        *direccion_factor = nuevoValor;
    }

    /**
     * @brief Aplica un porcentaje [0..N].
     * @param lb libro al que se debe aplicar el porcentaje.
     * @param factor Factor a aplicar.
     */
    void aplicarFactorPrecioLibro(struct Libro lb, float factor)
    {
        *lb.precio *= factor;
        //Se podria pasar un puntero a Libro y usar lb->precio para desreferenciar el puntero
    }

    //Un array en C es un puntero al primer elemento del array

    /**
     * @brief Modifica el id del libro
     * @param lb libro que debe moficar su id
     * @param nuevoId nuevo id a aplicar
     */
    void cambiarIdLibro(struct Libro *lb, char *nuevoId)
    {
        strcpy(lb -> id, nuevoId);
    }

    int main(void)
    {
        struct Libro lb1 = {"AD", 100};
        float factor = 0;

        cambiarFactorGeneral(&factor, 0.25f);
        aplicarFactorPrecioLibro(lb1, factor);
        // cambiarIdLibro()

        return 0;
    }
