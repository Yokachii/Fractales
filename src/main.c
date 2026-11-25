#include "../include/mat.h"
#include "../include/fract.h"
#include <stdlib.h>
#include "raylib.h"


int main(int argc, char *argv[]) {

    if (argc<=1) {
        fprintf(stderr, "Usage: %s <size_px>\n", argv[0]);
        fprintf(stderr, "Example: %s 800\n", argv[0]);
        return 1;
    }

    int size_px = (argc > 1) ? atoi(argv[1]) : 800;

    printf("Building a fractar of %dpx\n",size_px);

    // Complexe z = cree_complexe(1,1);

    // printf("r:%f;i:%f;n:%f,a:%fdeg\n",z.reel,z.im,z.norme,rad2deg(z.arg));

    draw_mandlebrot(size_px,size_px,100);
}