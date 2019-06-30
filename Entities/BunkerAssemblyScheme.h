#ifndef _RTEBUNKERASSEMBLYSCHEME_
#define _RTEBUNKERASSEMBLYSCHEME_

//////////////////////////////////////////////////////////////////////////////////////////
// File:            BunkerAssemblyScheme.h
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Header file for the BunkerAssemblyScheme class.
// Project:         Retro Terrain Engine
// Author(s):       Daniel Tabar
//                  data@datarealms.com
//                  http://www.datarealms.com


//////////////////////////////////////////////////////////////////////////////////////////
// Inclusions of header files

#include <iostream>
#include <sstream>
#include <string>

#include "DDTTools.h"
#include "SceneObject.h"
#include "Vector.h"
#include "FrameMan.h"
#include "SceneMan.h"
//#include "MovableMan.h"

#define ICON_WIDTH 69
#define AREA_PER_DEPLOYMENT 64

namespace RTE
{

class ContentFile;


//////////////////////////////////////////////////////////////////////////////////////////
// Class:           BunkerAssemblyScheme
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     A feature of the terrain, which includes foreground color layer,
//                  material layer and optional background layer.
// Parent(s):       SceneObject.
// Class history:   08/23/2002 BunkerAssemblyScheme created.

class BunkerAssemblyScheme:
    public SceneObject
{


//////////////////////////////////////////////////////////////////////////////////////////
// Public member variable, method and friend function declarations

public:

	// Different scheme properties are encoded on colors of scheme bitmap
	enum SchemeColor 
	{
		SCHEME_COLOR_EMPTY = g_KeyColor,  // Empty sections, MUST BE ALWAYS EMPTY
		SCHEME_COLOR_PASSABLE = 5,		  // Passable sections, MUST BE ALWAYS PASSBLE, I.E. HAVE ONLY BACKGROUNDS
		SCHEME_COLOR_VARIABLE = 4,		  // May be passable or not. Expect air.
		SCHEME_COLOR_WALL = 3			  // Always impassable, but may be empty. Expect terrain.
	};

	// Scheme properties, when drawed in game UIs
	enum PresentationColor 
	{
		PAINT_COLOR_PASSABLE = 5,
		PAINT_COLOR_VARIABLE = 48,
		PAINT_COLOR_WALL = 13
	};

	const static int ScaleX = 24;
	const static int ScaleY = 24;
	const static int SchemeWidth = 2;

// Concrete allocation and cloning definitions
ENTITYALLOCATION(BunkerAssemblyScheme)


//////////////////////////////////////////////////////////////////////////////////////////
// Constructor:     BunkerAssemblyScheme
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Constructor method used to instantiate a BunkerAssemblyScheme object in system
//                  memory. Create() should be called before using the object.
// Arguments:       None.

    BunkerAssemblyScheme() { Clear(); }


//////////////////////////////////////////////////////////////////////////////////////////
// Destructor:      ~BunkerAssemblyScheme
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Destructor method used to clean up a BunkerAssemblyScheme object before deletion
//                  from system memory.
// Arguments:       None.

    virtual ~BunkerAssemblyScheme() { Destroy(true); }


//////////////////////////////////////////////////////////////////////////////////////////
// Pure V. method:  Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Makes the BunkerAssemblyScheme object ready for use.
// Arguments:       None.
// Return value:    An error return value signaling sucess or any particular failure.
//                  Anything below 0 is an error signal.

    virtual int Create();

//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Creates a BunkerAssemblyScheme to be identical to another, by deep copy.
// Arguments:       A reference to the BunkerAssemblyScheme to deep copy.
// Return value:    An error return value signaling sucess or any particular failure.
//                  Anything below 0 is an error signal.

    int Create(const BunkerAssemblyScheme &reference);


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  ReadProperty
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Reads a property value from a Reader stream. If the name isn't
//                  recognized by this class, then ReadProperty of the parent class
//                  is called. If the property isn't recognized by any of the base classes,
//                  false is returned, and the Reader's position is untouched.
// Arguments:       The name of the property to be read.
//                  A Reader lined up to the value of the property to be read.
// Return value:    An error return value signaling whether the property was successfully
//                  read or not. 0 means it was read successfully, and any nonzero indicates
//                  that a property of that name could not be found in this or base classes.

    virtual int ReadProperty(std::string propName, Reader &reader);


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  Reset
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Resets the entire BunkerAssemblyScheme, including its inherited members, to
//                  their default settings or values.
// Arguments:       None.
// Return value:    None.

    virtual void Reset() { Clear(); SceneObject::Reset(); }


//////////////////////////////////////////////////////////////////////////////////////////
// Pure V. method:  Save
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Saves the complete state of this BunkerAssemblyScheme to an output stream for
//                  later recreation with Create(Reader &reader);
// Arguments:       A Writer that the BunkerAssemblyScheme will save itself with.
// Return value:    An error return value signaling sucess or any particular failure.
//                  Anything below 0 is an error signal.

    virtual int Save(Writer &writer) const;

/*
//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Makes the BunkerAssemblyScheme object ready for use.
// Arguments:       An input stream that the BunkerAssemblyScheme will create itself from.
//                  Whether there is a class name in the stream to check against to make
//                  sure the correct type is being read from the stream.
// Return value:    An error return value signaling sucess or any particular failure.
//                  Anything below 0 is an error signal.

    virtual int Create(std::istream &stream, bool checkType = true);


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  Save
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Saves the complete state of this BunkerAssemblyScheme to an output stream for
//                  later recreation with Create(istream &stream);
// Arguments:       An output stream that the BunkerAssemblyScheme will save itself to.
// Return value:    An error return value signaling sucess or any particular failure.
//                  Anything below 0 is an error signal.

    virtual int Save(std::ostream &stream) const;
*/

//////////////////////////////////////////////////////////////////////////////////////////
// Pure V. method:  Destroy
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Destroys and resets (through Clear()) the BunkerAssemblyScheme object.
// Arguments:       Whether to only destroy the members defined in this derived class, or
//                  to destroy all inherited members also.
// Return value:    None.

    virtual void Destroy(bool notInherited = false);


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  GetClass
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the ClassInfo instance of this Entity.
// Arguments:       None.
// Return value:    A reference to the ClassInfo of this' class.

    virtual const Entity::ClassInfo & GetClass() const { return m_sClass; }


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  GetClassName
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the class name of this Entity.
// Arguments:       None.
// Return value:    A string with the friendly-formatted type name of this object.

    virtual const std::string & GetClassName() const { return m_sClass.GetName(); }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:			GetBitmapWidth
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the width this' bitmap.
// Arguments:       None.
// Return value:    Width of bitmap.

	const int GetBitmapWidth() const { return m_pPresentationBitmap->w; }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:			GetBitmapHeight
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the height this' material bitmap.
// Arguments:       None.
// Return value:    Height of 'material' bitmap.

	const int GetBitmapHeight() const { return m_pPresentationBitmap->h; }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:			GetBitmapOffset
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the offset of presentation bitmap
// Arguments:       None.
// Return value:    Offset of bitmap

	const Vector GetBitmapOffset() const { return m_BitmapOffset; }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetBitmap
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the BITMAP object that this BunkerAssemblyScheme uses for its fore-
//                  ground color representation.
// Arguments:       None.
// Return value:    A pointer to the foreground color BITMAP object. Ownership is not
//                  transferred.

    BITMAP * GetBitmap() const { return m_pPresentationBitmap; }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetArea
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the area of the structure bitmap.
// Arguments:       None.
// Return value:    None.

    int GetArea() const { return m_pBitmap->h * m_pBitmap->w; }


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetGraphicalIcon
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets a bitmap showing a good identifyable icon of this, for use in
//                  GUI lists etc.
// Arguments:       None.
// Return value:    A good identifyable graphical representation of this in a BITMAP, if
//                  available. If not, 0 is returned. Ownership is NOT TRANSFERRED!

    virtual BITMAP * GetGraphicalIcon();


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  SetTeam
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets which team this belongs to.
// Arguments:       The assigned team number.
// Return value:    None.

    virtual void SetTeam(int team);

//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  IsOnScenePoint
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Indicates whether this' current graphical representation overlaps
//                  a point in absolute scene coordinates.
// Arguments:       The point in absolute scene coordinates.
// Return value:    Whether this' graphical rep overlaps the scene point.

    virtual bool IsOnScenePoint(Vector &scenePoint) const;


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  Draw
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Draws this BunkerAssemblyScheme's current graphical representation to a
//                  BITMAP of choice.
// Arguments:       A pointer to a BITMAP to draw on.
//                  The absolute position of the target bitmap's upper left corner in the Scene.
//                  In which mode to draw in. See the DrawMode enumeration for the modes.
//                  Whether to not draw any extra 'ghost' items of this MovableObject,
//                  like indicator arrows or hovering HUD text and so on.
// Return value:    None.

    virtual void Draw(BITMAP *pTargetBitmap,
                      const Vector &targetPos = Vector(),
                      DrawMode mode = g_DrawColor,
                      bool onlyPhysical = false) const;

//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  GetOneTypePerScene
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Returns whether sceneman should select just a single assembly for this scheme
//					and use it everywhere on the scene.
// Arguments:       None.
// Return value:    Whether we allowed to use just one type of assembly for this scheme

	virtual bool IsOneTypePerScene() { return m_IsOneTypePerScene; } ;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetSymmetricSchemeName
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the name of the scheme symmetric to this one.
// Arguments:       None.
// Return value:    Symmetric scheme name.

	virtual string GetSymmetricSchemeName() const { return m_SymmetricScheme; };

//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetAssemblyGroup
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the name of group to which assemblies linked with this scheme must be added.
// Arguments:       None.
// Return value:    Assembly group name.

	virtual string GetAssemblyGroup() const { return m_AssemblyGroup; };


//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  GetLimit
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Returns the limit of these schemes per scene. 0 - no limit.
// Arguments:       None.
// Return value:    Scheme limit.

	virtual int GetLimit() { return m_Limit; };



//////////////////////////////////////////////////////////////////////////////////////////
// Virtual method:  GetMaxDeployments
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Returns the number of deployments this scheme is allowed to place.
// Arguments:       None.
// Return value:    Deployments limit.

	virtual int GetMaxDeployments() const { return m_MaxDeployments; };


//////////////////////////////////////////////////////////////////////////////////////////
// Protected member variable and method declarations

protected:

    // Member variables
    static Entity::ClassInfo m_sClass;

    ContentFile m_BitmapFile;

    // Not owned by this
    BITMAP *m_pBitmap;
	BITMAP *m_pPresentationBitmap;
	BITMAP *m_pIconBitmap;

    // The objects that are placed along with this in the scene
    std::list<SOPlacer> m_ChildObjects;

	// If this is true then sceneman must select a single assembly for this scheme and use it everywhere on the scene
	bool m_IsOneTypePerScene;
	// How many assemblies can placed on one scene?
	int m_Limit;
	// Drawable bitmap offset of this bunker assembly
	Vector m_BitmapOffset;
	// How many deployments should be selected during placement
	int m_MaxDeployments;
	// Scheme symmetric to this one
	string m_SymmetricScheme;
	// To which group we should add assemblies linked to this scheme
	string m_AssemblyGroup;

//////////////////////////////////////////////////////////////////////////////////////////
// Private member variable and method declarations

private:

//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Clear
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Clears all the member variables of this BunkerAssemblyScheme, effectively
//                  resetting the members of this abstraction level only.
// Arguments:       None.
// Return value:    None.

    void Clear();


    // Disallow the use of some implicit methods.
    BunkerAssemblyScheme(const BunkerAssemblyScheme &reference) { DDTAbort("Tried to use forbidden method"); }
    void operator=(const BunkerAssemblyScheme &rhs) { DDTAbort("Tried to use forbidden method"); }

};

} // namespace RTE

#endif // File