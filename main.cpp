//----------------
// Libraries    ||
//----------------

# include <iostream>

//----------------
// Constants    ||
//----------------

# define GRAPH_SIZE 5
# define ADJACENT true
# define UNRELATED false
# define N_APPLICABLE false

const unsigned short
RED = 0,
BLUE = 1,
GREEN = 2,
YELLOW = 3;

//--------------------------------
// Structs, methods, functions  ||
//--------------------------------

/* Detalles del diseño en README */
struct Vertex
{
    unsigned short regionID;
    unsigned short color;
};

/*  F:  Determina si dos regiones adyacentes comparten color
    I:  pRegions (Vertex[])     - Regiones del mapa
        pIndexA, pIndexB (int)  - Indices de regiones adyacentes
    O:  Retorna true de ser invalidos, false si son validos     */
bool is_invalid(Vertex pRegions[], int& pIndexA, int& pIndexB)
{
    return pRegions[pIndexA].color == pRegions[pIndexB].color;
}// Function end

/*  F:  Determina si la colorizacion de un mapa cumple el teorema
    I:  pRegions (Vertex[]) - Regiones del mapa
        pGraph  (bool[][])  - Representacion tabular del grafo
    O:  Retorna true si se cumple el teorema, falso si no   */
bool verify_map(Vertex pRegions[], bool pGraph[][GRAPH_SIZE])
{
    int row = 0;
    for (; row < GRAPH_SIZE; row++)
    {
        int col = 0;
        for (; col < GRAPH_SIZE; col++)
        {
            if (pGraph[row][col] == ADJACENT && is_invalid(pRegions, row, col))
                return false;
        }
    }
    return true;
}// Function end

/*  F:  Despliega resultado de la validacion del teorema
    I:  pRegions (Vertex[]) - Regiones del mapa
        pGraph  (bool[][])  - Representacion tabular del grafo
    O:  Imprime mensaje correspondiente al resultado   */
void print_result(Vertex pRegions[], bool pGraph[][GRAPH_SIZE])
{
    printf("Resultado: %s\n", verify_map(pRegions, pGraph) ? "Cumple el teorema" : "No cumple el teorema");
}// Function end

//----------------
// Main program ||
//----------------

bool graph_eg[GRAPH_SIZE][GRAPH_SIZE] =
{
    {N_APPLICABLE, ADJACENT, ADJACENT, UNRELATED, UNRELATED},
    {ADJACENT, N_APPLICABLE, ADJACENT, ADJACENT, UNRELATED},
    {ADJACENT, ADJACENT, N_APPLICABLE, UNRELATED, ADJACENT},
    {UNRELATED, ADJACENT, UNRELATED, N_APPLICABLE, ADJACENT},
    {UNRELATED, UNRELATED, ADJACENT, ADJACENT, N_APPLICABLE}
};

Vertex regions_eg1[GRAPH_SIZE] =
{
    {1, RED},
    {2, YELLOW},
    {3, BLUE},
    {4, GREEN},
    {5, YELLOW}
};

Vertex regions_eg2[GRAPH_SIZE] =
{
    {1, RED},
    {2, GREEN},
    {3, BLUE},
    {4, RED},
    {5, BLUE}
};

int main()
{
    printf("\nEjemplo 1\n");
    print_result(regions_eg1, graph_eg);

    printf("\nEjemplo 2\n");
    print_result(regions_eg2, graph_eg);

    return 0;
}