#include <image.h>

pal_image_t *image_alloc(unsigned width, unsigned int height, unsigned int colours, unsigned int extra) {
    pal_image_t *img = NULL;

    if(NULL == (img = calloc(1, sizeof(pal_image_t) + (width * height) + (colours * sizeof(img_pal_entry_t)) + extra) )) {
        return NULL;
    }

    // default arangement is [pixel_data][extra data][palette data]
    // but can be re-ordered by external code if a particular arrangement is desired
    img->width = width;
    img->height = height;
    img->colours = colours;
    img->transparent = -1;
    img->image_size = width * height;
    img->extra_size = extra;

    img->pixels = img->buf;
    img->extra = &img->buf[img->image_size];
    img->pal = (img_pal_entry_t  *)&img->buf[img->image_size + img->extra_size];
    return img;
}

// currently this function isn't strictly necessary, a simle free will do
// but if down the road we decide to alter the underlying structure/allocations
// this function will handle it appropriately
void image_free(pal_image_t *img) {
    if(NULL == img) return;
    free(img);
}
