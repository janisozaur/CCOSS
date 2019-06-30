#ifndef _GUITEXTPANEL_
#define _GUITEXTPANEL_

//////////////////////////////////////////////////////////////////////////////////////////
// File:            GUITextPanel.h
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     GUITextPanel class
// Project:         GUI Library
// Author(s):       Jason Boettcher
//                  jackal@shplorb.com
//                  www.shplorb.com/~jackal


namespace RTE
{


//////////////////////////////////////////////////////////////////////////////////////////
// Class:           GUITextPanel
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     A text panel class.
// Parent(s):       Panel.
// Class history:   1/20/2004 GUITextPanel Created.

class GUITextPanel :
    public GUIPanel
{

//////////////////////////////////////////////////////////////////////////////////////////
// Public member variable, method and friend function declarations

public:

    // Text panel signals
    enum {
        Clicked = 0,
        MouseDown,
        Changed,
        Enter
    } Signals;


//////////////////////////////////////////////////////////////////////////////////////////
// Constructor:     GUITextPanel
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Constructor method used to instantiate a GUITextPanel object in
//                  system memory.
// Arguments:       GUIManager.

    GUITextPanel(GUIManager *Manager);


//////////////////////////////////////////////////////////////////////////////////////////
// Constructor:     GUITextPanel
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Constructor method used to instantiate a GUITextPanel object in
//                  system memory.
// Arguments:       None.

    GUITextPanel();


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Create the panel.
// Arguments:       Position, Size.

    void Create(int X, int Y, int Width, int Height);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          ChangeSkin
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the skin has been changed.
// Arguments:       New skin pointer.

    void ChangeSkin(GUISkin *Skin);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Draw
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Draws the panel
// Arguments:       Screen class

    void Draw(GUIScreen *Screen);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          OnMouseDown
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse goes down on the panel
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseDown(int X, int Y, int Buttons, int Modifier);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:  OnMouseUp
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse goes up on the panel
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseUp(int X, int Y, int Buttons, int Modifier);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          OnMouseMove
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse moves (over the panel, or when captured).
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseMove(int X, int Y, int Buttons, int Modifier);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          OnKeyPress
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when a key is pressed (OnDown & repeating).
// Arguments:       KeyCode, Modifier.

    void OnKeyPress(int KeyCode, int Modifier);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the text in the textpanel.
// Arguments:       Text.

    void SetText(const std::string Text);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetRightText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the extra text which appears right-justified in the textpanel.
// Arguments:       Text.

    void SetRightText(const std::string rightText);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the text in the textpanel.
// Arguments:       None.

    std::string GetText(void) { return m_Text; }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetRightText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the extra text which appears right-justified in the textpanel.
// Arguments:       None.

    std::string GetRightText(void) { return m_RightText; }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetSelection
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the start and end indexes of the selection text.
// Arguments:       Start, End.

    void SetSelection(int Start, int End);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetSelectionStart
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the start index of the selection.
// Arguments:       None.
// Returns:         Index of the start of the selection. -1 if no selection

    int GetSelectionStart(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetSelectionEnd
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the end index of the selection.
// Arguments:       None.
// Returns:         Index of the end of the selection. -1 if no selection

    int GetSelectionEnd(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          ClearSelection
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Clears the selection. Does NOT remove the selection text though.
// Arguments:       None.

    void ClearSelection(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetSelectionText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the selection text.
// Arguments:       None.

    std::string GetSelectionText(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          RemoveSelectionText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Removes the characters in the selection.
// Arguments:       None.

    void RemoveSelectionText(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetCursorPos
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets where the cursor should be. This will clear any selection.
// Arguments:       The index of the new cursor position.

    void SetCursorPos(int cursorPos);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetLocked
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the locked state on the textbox.
// Arguments:       Locked.

    void SetLocked(bool Locked);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetLocked
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the locked state on the textbox.
// Arguments:       None.

    bool GetLocked(void);


//////////////////////////////////////////////////////////////////////////////////////////
// Private member variable and method declarations

private:


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          UpdateText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Updates the cursor and start positions.
// Arguments:       Typing, Increment.

    void UpdateText(bool Typing = false, bool DoIncrement = true);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          DoSelection
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Update the selection.
// Arguments:       Start, End.

    void DoSelection(int Start, int End);


// Members

    // Font
    Uint32            m_FontSelectColor;

    std::string        m_Text;
    // Appears right-justified in the text field
    std::string        m_RightText;
    bool            m_Focus;
    bool            m_Locked;
    // The distance from the side and top of the text box, to the side and top of the first line of text
    int            m_WidthMargin;
    int            m_HeightMargin;

    // Cursor
    int                m_CursorX, m_CursorY;
    int                m_CursorIndex;
    Uint32            m_CursorColor;
    // Hacky way to make cursor blink without a timer
    int                 m_CursorBlinkCount;

    int                m_StartIndex;

    // Selection
    bool            m_GotSelection;
    int                m_StartSelection;
    int                m_EndSelection;
    Uint32            m_SelectedColorIndex;
    int                m_SelectionX, m_SelectionWidth;

};


}; // namespace RTE


#endif  //  _GUITEXTPANEL_