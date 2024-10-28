#include <stdio.h>
#include <stdlib.h>
#include <image.h>

pal_image_t *image_alloc(unsigned width, unsigned height, unsigned colours) {
    pal_image_t *img = NULL;

    if(NULL == (img = calloc(1, sizeof(pal_image_t) + (width * height) + (colours * sizeof(img_pal_entry_t))) )) {
        return NULL;
    }

    img->width = width;
    img->height = height;
    img->colours = colours;
    img->image_size = width * height;
    img->pal = (img_pal_entry_t  *)&img->data[img->image_size];
    return img;
}

// currently this function isn't strictly necessary, a simle free will do
// but if down the road we decide to alter the underlying structure/allocations
// this function will handle it appropriately
void image_free(pal_image_t *img) {
    if(NULL == img) return;
    free(img);
}
