/*
 * bmp.h 
 * interface definitions for a writing an indexed 256 colour Windows BMP file
 * 
 * This code is offered without warranty under the MIT License. Use it as you will 
 * personally or commercially, just give credit if you do.
 */
#include <stdint.h>
#include <stdlib.h>

#ifndef CA_IMAGE
#define CA_IMAGE

/// @brief generic palette structure
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} img_pal_entry_t;

/// @brief neutral container for storing paletted images
typedef struct {
    unsigned width;       // width of image in pixels
    unsigned height;      // height of image in pixels
    unsigned colours;     // number of palette entries
    int      transparent; // index of transparent colour, -1 if not used
    size_t   image_size;  // size of image in bytes. (also defines the offset to the start of the palette data)
    img_pal_entry_t  *pal;
    uint8_t  data[];      // pixel data stored as one byte per pixel
                          // palette RGB data is appended after image data
} pal_image_t;

/// @brief allocates and initializes space for an image of the defined size
/// @param width   width in pixels of the image
/// @param height  height in pixels of the image
/// @param colours maximum number of colours the palette will contain
/// @return returns a pointer to the allocated memory, or NULL
pal_image_t *image_alloc(unsigned width, unsigned height, unsigned colours);

/// @brief frees the memory allocated using image_alloc()
/// @param img // pointer to the previously allocated memory
void image_free(pal_image_t *img);

#endif
