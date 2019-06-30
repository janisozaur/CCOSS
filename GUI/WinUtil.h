#ifndef _WINUTIL_
#define _WINUTIL_

//////////////////////////////////////////////////////////////////////////////////////////
// File:            WinUtil.h
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     WinUtil class
// Project:         GUI Library
// Author(s):       Jason Boettcher
//                  jackal@shplorb.com
//                  www.shplorb.com/~jackal


#include <string>


namespace RTE
{


//////////////////////////////////////////////////////////////////////////////////////////
// Class:           WinUtil
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     A utility class with misc static functions for different things,
//                  platform specific to windows
// Parent(s):       None.
// Class history:   5/21/2008 WinUtil Created.

class WinUtil {

//////////////////////////////////////////////////////////////////////////////////////////
// Public member variable, method and friend function declarations

public:


//////////////////////////////////////////////////////////////////////////////////////////
// Constructor:     WinUtil
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Constructor method used to instantiate a WinUtil object in system
//                  memory.
// Arguments:       None.

    WinUtil() { };


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetClipboardText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the text from the clipboard.
// Arguments:       Pointer to string receiving the text.
// Returns:         Boolean. True if text was available in the clipboard.

    static bool GetClipboardText(std::string *Text);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetClipboardText
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the text in the clipboard.
// Arguments:       String to put into the clipboard.
// Returns:         Boolean. True if text was added to the clipboard.

    static bool SetClipboardText(std::string Text);
};


}; // namespace RTE


#endif  //  _WINUTIL_