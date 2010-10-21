// SystemSound.h : Handle system sounds for an application
//
// Copyright (c) 2004-2010 by Andrew W. Phillips.
//
// No restrictions are placed on the noncommercial use of this code,
// as long as this text (from the above copyright notice to the
// disclaimer below) is preserved.
//
// This code may be redistributed as long as it remains unmodified
// and is not sold for profit without the author's written consent.
//
// This code, or any part of it, may not be used in any software that
// is sold for profit, without the author's written consent.
//
// DISCLAIMER: This file is provided "as is" with no expressed or
// implied warranty. The author accepts no liability for any damage
// or loss of business that this product may cause.
//
#ifndef SYSTEMSOUND_INCLUDED_
#define SYSTEMSOUND_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////

// Notes
// 1. If app is NULL then the current app. name is used (CWinApp::m_pszAppName)
// 2. If key is NULL it defaults to ".current".  Alternatives are ".default" or a scheme name.
// 3. Given a sound name a key name is automatically created when necessary
//    using the application name and the sound name (with spaces etc removed)

class CSystemSound
{
public:
	// Creates a new sound event for the application, and assigns it a sound.
	// If value is NULL then the sound is created but no sound is assigned (the
	// user can then add a sound to the sound event in the Control Panel).
	// If the sound event already exists no changes are made.
	static void Add(LPCTSTR name, LPCTSTR value = NULL, LPCTSTR app = NULL, LPCTSTR key_name = NULL);

//	static void Remove(LPCTSTR name, LPCTSTR app = NULL, LPCTSTR key_name = NULL);

	// Gets a sound file name given the sound event name.
	// Returns an empty string if there is no sound attached to the event.
	static CString Get(LPCTSTR name, LPCTSTR app = NULL, LPCTSTR key_name = NULL);

	// Sets a sound file to be associated with a sound event.
	// If value is NULL then any sound attached to the event is removed.
	static void Set(LPCTSTR name, LPCTSTR value = NULL, LPCTSTR app = NULL, LPCTSTR key_name = NULL);

	// Plays a sound (if there is one) given by sound event name
	static BOOL Play(LPCTSTR name, LPCTSTR app = NULL, LPCTSTR key_name = NULL);

private:
	// Since the class only contains static functions we prohibit instantiation
	CSystemSound() {};

	// Make registry key names from sound name
	static CString make_key(LPCTSTR name, LPCTSTR app, LPCTSTR key_name);
	static CString make_label_key(LPCTSTR name);
};

#endif
