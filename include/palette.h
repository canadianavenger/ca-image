/*
 * palette.h 
 * default palettes for various video modes
 * 
 * This code is offered without warranty under the MIT License. Use it as you will 
 * personally or commercially, just give credit if you do.
 */
#include <image.h>
#include <stdbool.h>

#ifndef IMG_PALETTE
#define IMG_PALETTE

// greyscale

/// @brief returns the greyscale rgb value for the given index within the range of 0..shades-1
/// @param index: the index of the shade we want
/// @param shades: the total number of possible shades we want to select from
/// @return the rgb palette entry for the selected shade (all 3 components set to the same value)
img_pal_entry_t gs_dac(uint8_t index, uint16_t shades);

/// @brief generates a palette of the selected number of shades
/// @param pal: pointer to a img_pal_entry_t buffer large enough to hold the selected palette 
/// @param shades: the number of shades in the palette
void gs_pal(img_pal_entry_t *pal, uint16_t shades);

/* *************************************************************************
   *************************************************************************
   ************************************************************************* */

// CGA

/// @brief converts the CGA colour index value into a RGB888 palette value
///        CGA index to colour conversion function:
///          intens = (index >> 3) & 1
///          red   = 85 * (intens | ((index >> 1) & 2))
///          green = (index == 6)? 85 : (85 * (intens | (index & 2))) // brown fix
///          blue  = 85 * (intens | ((index << 1) & 2))
///        brown fix:
///                   green component is halved to 85 (0x55) when colour is 6 for a true brown; 
///                   instead of 170 (0xAA) as it would normally calculate to, 
///                   which produces a dark-yellow colour instead of brown
/// @param index: the index for the color we want (0-15)
/// @param enhanced: if 'true' Enables an improved RGB palette that better emulates the actual screen colors on CGA displays a bit better
/// @param nofix: if 'true' specifies to disable the "brown fix" that IBM had in their circuitry
///               (this is to emulate what some cheap CGA clone cards would have displayed)
/// @return the requested rgb palette entry from the full 16 colour CGA palette
img_pal_entry_t cga_dac(uint8_t index, bool enhanced, bool nofix);

/// @brief returns the CGA palette for the selected mode, number of colours returned depends on mode
/// @param pal: pointer to a img_pal_entry_t buffer large enough to hold the selected palette
/// @param mode: selects which CGA palette to use
///              0: CGA Mode 4, palette 0, dark colours   [4 colour mode]  [black, dark green, dark red, brown]
///              1: CGA Mode 4, palette 0, bright colours [4 colour mode]  [black, light green, light red, yellow]
///              2: CGA Mode 4, palette 1, dark colours   [4 colour mode]  [black, dark cyan, dark magenta, light grey]
///              3: CGA Mode 4, palette 1, bright colours [4 colour mode]  [black, light cyan, light magenta, white]
///              4: CGA Mode 5, dark colours              [4 colour mode]  [black, dark cyan, dark red, light gray]
///              5: CGA Mode 5, bright colours            [4 colour mode]  [black, light cyan, light red, white]
///              16: The full 16 colour CGA palette
///              Note: For modes 0-5, the CGA palette is fixed except for entry 0 which defaults to black.
///                    The  CGA hardware allowed entry 0 (background colour) to be set to any of t he 16 possible colours
///                    This function will always return black as the background colour. After getting the palette you can
///                    use `cga_dac()` to get a different CGA colour to assign to entry 0 in the palette.
/// @param enhanced: if 'true' Enables an improved RGB palette that better emulates the actual screen colors on CGA displays a bit better
/// @param nofix: if 'true' specifies to disable the "brown fix" that IBM had in their circuitry
///               (this is to emulate what some cheap CGA clone cards would have displayed)
void cga_pal(img_pal_entry_t *pal, uint8_t mode, bool enhanced, bool nofix);

/* *************************************************************************
   *************************************************************************
   ************************************************************************* */

// EGA

/// @brief converts the index value to RGB888 according to EGA translation
/// @param index: index of the colour in the palette to return
/// @return the requested rgb palette entry from the full 64 colour EGA palette
img_pal_entry_t ega_dac(uint8_t index);

/// @brief returns the default 16 colour EGA palette
/// @param pal: pointer to a img_pal_entry_t buffer large enough to hold the selected palette
void ega_pal(img_pal_entry_t *pal);

/* *************************************************************************
   *************************************************************************
   ************************************************************************* */

// VGA

/// @brief returns the default DAC settings for the selected index from the default 256 colour palette
/// @param index: index of the colour in the palette to return
/// @return the requested rgb palette entry from the full 256 colour VGA palette
img_pal_entry_t vga_dac(uint8_t index);

/// @brief returns the default 16 colour or 256 colour VGA palette
/// @param pal: pointer to a img_pal_entry_t buffer large enough to hold the selected palette
/// @param colours: number of colours in the palette (max 256) [typical 16, 256]
void vga_pal(img_pal_entry_t *pal, uint16_t colours);

#endif