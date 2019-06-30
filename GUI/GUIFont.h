#ifndef _GUIFONT_
#define _GUIFONT_

//////////////////////////////////////////////////////////////////////////////////////////
// File:            GUIFont.h
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     GUIFont class
// Project:         GUI Library
// Author(s):       Jason Boettcher
//                  jackal@shplorb.com
//                  www.shplorb.com/~jackal


namespace RTE
{


//////////////////////////////////////////////////////////////////////////////////////////
// Class:           GUIFont
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     A class to handle the drawing of text
// Parent(s):       None.
// Class history:   1/7/2004 GUIFont Created.

class GUIFont {

//////////////////////////////////////////////////////////////////////////////////////////
// Public member variable, method and friend function declarations

public:

    // Horizontal Text Alignment, 
    enum {
        Left = 0,
        Centre,
        Right
    } HAlignment;

    // Vertical Text Alignment, 
    enum {
        Top = 0,
        Middle,
        Bottom
    } VAlignment;

    // Character structure
    typedef struct {
        int            m_Width;
        int            m_Height;
        int            m_Offset;
    } Character;

    // Font Color structure
    typedef struct {
        Uint32        m_Color;
        GUIBitmap    *m_Bitmap;
    } FontColor;


//////////////////////////////////////////////////////////////////////////////////////////
// Constructor:     GUIFont
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Constructor method used to instantiate a GUIFont object in system
//                  memory.
// Arguments:       None.

    GUIFont(std::string Name);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Load
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Loads the font from an image file.
// Arguments:       Screen class, Filename of image.

    bool Load(GUIScreen *Screen, const std::string Filename);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          CacheColor
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Pre-Calculates the font using a specific color.
// Arguments:       Color.

    void CacheColor(Uint32 Color);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetFontColor
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Finds a font color structure from the cache.
// Arguments:       Color.

    FontColor *GetFontColor(Uint32 Color);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Draw
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Draws text to a bitmap.
// Arguments:       Bitmap, Position, Text, Color, Drop-shadow, 0 = none.

    void Draw(GUIBitmap *Bitmap, int X, int Y, const std::string Text, Uint32 Shadow = 0);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          DrawAligned
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Draws text to a bitmap aligned.
// Arguments:       Bitmap, Position, Text.

    void DrawAligned(GUIBitmap *Bitmap, int X, int Y, const std::string Text, int HAlign, int VAlign = Top, int maxWidth = 0, Uint32 Shadow = 0);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetColor
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the current color.
// Arguments:       Color.

    void SetColor(Uint32 Color);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          CalculateWidth
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Calculates the width of a piece of text.
// Arguments:       Text.

    int CalculateWidth(const std::string Text);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          CalculateWidth
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Calculates the width of a piece of text.
// Arguments:       Character.

    int CalculateWidth(const char Character);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          CalculateHeight
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Calculates the height of a piece of text, if it's wrapped within a
//                  max width.
// Arguments:       Text, and the max width. If 0, no wrapping is done.

    int CalculateHeight(const std::string Text, int MaxWidth = 0);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetFontHeight
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the font height.
// Arguments:       None.

    int GetFontHeight(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetName
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the name of the font
// Arguments:       None.

    std::string GetName(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Destroy
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Destroys the font data
// Arguments:       None.

    void Destroy(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetKerning
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Get the character kerning (spacing)
// Arguments:       None.

    int GetKerning(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetKerning
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Set the character kerning (spacing), in pixels. 1 = one empty pixel
//                  between chars, 0 = chars are touching.
// Arguments:       None.

    void SetKerning(int newKerning = 1) { m_Kerning = newKerning; }


//////////////////////////////////////////////////////////////////////////////////////////
// Private member variable and method declarations

private:

    GUIBitmap        *m_Font;
    GUIScreen        *m_Screen;
    std::vector<FontColor >    m_ColorCache;

    int                m_FontHeight;
    Uint32            m_MainColor;
    Uint32            m_CurrentColor;
    GUIBitmap        *m_CurrentBitmap;
    std::string        m_Name;
    Character        m_Characters[256];
    // The highest index of valid characters that was read in from the file
    int                m_CharIndexCap;

    int                m_Kerning;            // Spacing between characters
    int                m_Leading;            // Spacing between lines
};


}; // namespace RTE


#endif  //  _GUIFONT_