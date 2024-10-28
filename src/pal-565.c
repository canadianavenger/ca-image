#include <pal-tools.h>

void pal565_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        uint16_t comp = entry.r;
        comp *= ((1 << 8) -1);
        comp += (1 << 5) / 2;
        comp /= ((1 << 5) - 1);
        out_pal[i].r = comp;

        comp = entry.g;
        comp *= ((1 << 8) -1);
        comp += (1 << 6) / 2;
        comp /= ((1 << 6) - 1);
        out_pal[i].g = comp;

        comp = entry.b;
        comp *= ((1 << 8) -1);
        comp += (1 << 5) / 2;
        comp /= ((1 << 5) - 1);
        out_pal[i].b = comp;
    }
}

void pal8_to_pal565(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        uint16_t comp = entry.r;
        comp *= ((1 << 5) - 1);
        comp += (1 << 8) / 2;
        comp /= ((1 << 8) -1);
        out_pal[i].r = comp;

        comp = entry.g;
        comp *= ((1 << 6) - 1);
        comp += (1 << 8) / 2;
        comp /= ((1 << 8) -1);
        out_pal[i].g = comp;

        comp = entry.b;
        comp *= ((1 << 5) - 1);
        comp += (1 << 8) / 2;
        comp /= ((1 << 8) -1);
        out_pal[i].b = comp;
    }
}
