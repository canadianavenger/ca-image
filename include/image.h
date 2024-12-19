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
/// default arrangement is [pixel data][extra data][palette data]
/// pointers may be re-ordered if desired
/// code should use the pointers and not assume any arrangement in 
typedef struct {
    unsigned width;       // width of image in pixels
    unsigned height;      // height of image in pixels
    unsigned colours;     // number of palette entries (this times size of img_pal_entry_t is the palette size in bytes)
    int      transparent; // index of transparent colour, -1 if not used
    size_t   image_size;  // size of image in bytes. 
    size_t   extra_size;  // size of additional data allocation space
    img_pal_entry_t  *pal;// poinnter to the palette RGB data in buf[] 
    uint8_t  *extra;      // pointer to the 'extra' data in buf[]
    uint8_t  *pixels;     // pointer to the pixel data in buf[]
    uint8_t  buf[];       // our allocated data buffer
} pal_image_t;

/// @brief allocates and initializes space for an image of the defined size
/// @param width   width in pixels of the image
/// @param height  height in pixels of the image
/// @param colours maximum number of colours the palette will contain
/// @return returns a pointer to the allocated memory, or NULL
pal_image_t *image_alloc(unsigned int width, unsigned int height, unsigned int colours, unsigned int extra);

/// @brief frees the memory allocated using image_alloc()
/// @param img // pointer to the previously allocated memory
void image_free(pal_image_t *img);

#endif
