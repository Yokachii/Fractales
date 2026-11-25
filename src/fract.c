#include "../include/mat.h"
#include "raylib.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

static Color palette(double t, int max_iter) {
    if (t >= max_iter) return BLACK;
    double s = t / 32.0;
    return (Color){
        (unsigned char)(127.5 + 127.5 * cos(6.2832 * (s + 0.00))),
        (unsigned char)(127.5 + 127.5 * cos(6.2832 * (s + 0.33))),
        (unsigned char)(127.5 + 127.5 * cos(6.2832 * (s + 0.67))),
        255
    };
}

static double mandel(Complexe c, int max_iter, double inf) {
    // double zr = 0, zi = 0, zr2 = 0, zi2 = 0;
    Complexe z = cree_complexe(0,0);
    Complexe z2 = cree_complexe(0,0);
    int i = 0;
    while (i < max_iter && z2.reel + z2.im <= inf*inf) {
        z.im = 2.0 * z.reel * z.im + c.im;
        z.reel = z2.reel - z2.im + c.reel;
        z2.reel = z.reel * z.reel;
        z2.im = z.im * z.im;
        i++;
    }
    if (i >= max_iter) return max_iter;
    return i + 1.0 - log2(log(z2.reel + z2.im) / 2.0);  // lissage continu
    // return i;
}

void draw_mandlebrot(int W, int H, double inf){
    InitWindow(W, H, "Mandelbrot");
    SetTargetFPS(60);

    Color *pixels = malloc(W * H * sizeof(Color));
    Image img = { pixels, W, H, 1, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 };
    Texture2D tex = LoadTextureFromImage(img);

    double cx = -0.5, cy = 0.0; // Centre
    double scale = 3.0 / W; // Largeur en int et pas en px
    int dirty = 1;

    while (!WindowShouldClose()) {
        Vector2 m = GetMousePosition();

        // zom
        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            double mx = cx + (m.x - W / 2.0) * scale;
            double my = cy + (m.y - H / 2.0) * scale;
            double f = (wheel > 0) ? 0.8 : 1.25;
            scale *= f;
            cx = mx - (m.x - W / 2.0) * scale;
            cy = my - (m.y - H / 2.0) * scale;
            dirty = 1;
        }
        // move
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 d = GetMouseDelta();
            if (d.x != 0 || d.y != 0) {
                cx -= d.x * scale;
                cy -= d.y * scale;
                dirty = 1;
            }
        }

        if (dirty) {
            // plus on zoome, plus il faut d'itérations
            int max_iter = 100 + (int)(60.0 * log2(3.0 / (W * scale) + 1.0));
            for (int y = 0; y < H; y++){
                for (int x = 0; x < W; x++) {
                    Complexe c = cree_complexe(cx + (x - W / 2.0) * scale, cy + (y - H / 2.0) * scale);
                    pixels[y * W + x] = palette(mandel(c, max_iter, inf), max_iter);
                }
            }

            UpdateTexture(tex, pixels);
            dirty = 0;
        }

        BeginDrawing();
        DrawTexture(tex, 0, 0, WHITE);
        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadTexture(tex);
    free(pixels);
    CloseWindow();

}

void draw_dragon(int W, int H){
    
}