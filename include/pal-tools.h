/*
 * pal-tools.h 
 * utility functions for manipulating palettes
 * 
 * This code is offered without warranty under the MIT License. Use it as you will 
 * personally or commercially, just give credit if you do.
 */
#include <image.h>

#ifndef IMG_PAL_TOOLS
#define IMG_PAL_TOOLS

// palette component resizing

/// @brief upscales 4 bit per component palette data to 6 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
// void pal4_to_pal6(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief upscales 4 bit per component palette data to 8 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void pal4_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief upscales 5 bit per component palette data to 8 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void pal5_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief upscales 6 bit per component palette data to 8 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void pal6_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief downscales 6 bit per component palette data to 4 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
// void pal6_to_pal4(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief downscales 8 bit per component palette data to 4 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void pal8_to_pal4(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief downscales 8 bit per component palette data to 5 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void pal8_to_pal5(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief downscales 8 bit per component palette data to 6 bits per component
/// @param in_pal pointer to buffer of RGB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void pal8_to_pal6(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

void pal565_to_pal8(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);
void pal8_to_pal565(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

// palette remapping

/// @brief reorders the palette entries to the expected internal RGB from RBG
/// @param in_pal pointer to buffer of RBG palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void palRBG_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief reorders the palette entries to the expected internal RGB from BRG
/// @param in_pal pointer to buffer of BRG palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void palBRG_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);


/// @brief reorders the palette entries to the expected internal RGB from BGR
/// @param in_pal pointer to buffer of BGR palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void palBGR_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief reorders the palette entries to the expected internal RGB from GRB
/// @param in_pal pointer to buffer of GRB palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void palGRB_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

/// @brief reorders the palette entries to the expected internal RGB from GBR
/// @param in_pal pointer to buffer of GBR palette entries
/// @param out_pal pointer to buffer of RGB palette entries
/// @param entries number of entries in the palette
void palGBR_to_palRGB(img_pal_entry_t *in_pal, img_pal_entry_t *out_pal, int entries);

#endif
