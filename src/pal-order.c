#include <pal-tools.h>

void palRBG_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        out_pal[i].r = entry.r;
        out_pal[i].g = entry.b;
        out_pal[i].b = entry.g;
    }
}
void palBGR_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        out_pal[i].r = entry.b;
        out_pal[i].g = entry.g;
        out_pal[i].b = entry.r;
    }
}

void palBRG_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        out_pal[i].r = entry.b;
        out_pal[i].g = entry.r;
        out_pal[i].b = entry.g;
    }
}

void palGRB_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        out_pal[i].r = entry.g;
        out_pal[i].g = entry.r;
        out_pal[i].b = entry.b;
    }
}

void palGBR_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        out_pal[i].r = entry.g;
        out_pal[i].g = entry.b;
        out_pal[i].b = entry.r;
    }
}
