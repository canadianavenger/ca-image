#include <pal-tools.h>

static void pal_to_pal(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries, int in_max, int out_max) {
    for(int i = 0; i < entries; i++) {
        img_pal_entry_t entry = {in_pal[i].r, in_pal[i].g, in_pal[i].b};
        uint16_t comp = entry.r;
        comp *= out_max;
        comp += (in_max + 1) / 2;
        comp /= in_max;
        out_pal[i].r = comp;

        comp = entry.g;
        comp *= out_max;
        comp += (in_max + 1) / 2;
        comp /= in_max;
        out_pal[i].g = comp;

        comp = entry.b;
        comp *= out_max;
        comp += (in_max + 1) / 2;
        comp /= in_max;
        out_pal[i].b = comp;
    }
}

// void pal4_to_pal6(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
//     pal_to_pal(in_pal, out_pal, entries, ((1 << 4) - 1), ((1 << 6) -1));
// }

void pal4_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    pal_to_pal(in_pal, out_pal, entries, ((1 << 4) - 1), ((1 << 8) -1));
}

void pal5_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    pal_to_pal(in_pal, out_pal, entries, ((1 << 5) - 1), ((1 << 8) -1));
}

void pal6_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    pal_to_pal(in_pal, out_pal, entries, ((1 << 6) - 1), ((1 << 8) -1));
}

// void pal6_to_pal4(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
//     pal_to_pal(in_pal, out_pal, entries, ((1 << 6) - 1), ((1 << 4) -1));
// }

void pal8_to_pal4(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    pal_to_pal(in_pal, out_pal, entries, ((1 << 8) - 1), ((1 << 4) -1));
}

void pal8_to_pal5(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    pal_to_pal(in_pal, out_pal, entries, ((1 << 8) - 1), ((1 << 5) -1));
}

void pal8_to_pal6(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries) {
    pal_to_pal(in_pal, out_pal, entries, ((1 << 8) - 1), ((1 << 6) -1));
}
