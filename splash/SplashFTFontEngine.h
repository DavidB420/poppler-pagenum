//========================================================================
//
// SplashFTFontEngine.h
//
//========================================================================

//========================================================================
//
// Modified under the Poppler project - http://poppler.freedesktop.org
//
// Copyright (C) 2006 Takashi Iwai <tiwai@suse.de>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef SPLASHFTFONTENGINE_H
#define SPLASHFTFONTENGINE_H

#if HAVE_FREETYPE_FREETYPE_H || HAVE_FREETYPE_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include <ft2build.h>
#include FT_FREETYPE_H
#include "goo/gtypes.h"

class SplashFontFile;
class SplashFontFileID;
class SplashFontSrc;

//------------------------------------------------------------------------
// SplashFTFontEngine
//------------------------------------------------------------------------

class SplashFTFontEngine {
public:

  static SplashFTFontEngine *init(GBool aaA);

  ~SplashFTFontEngine();

  // Load fonts.
  SplashFontFile *loadType1Font(SplashFontFileID *idA, SplashFontSrc *src,  char **enc);
  SplashFontFile *loadType1CFont(SplashFontFileID *idA, SplashFontSrc *src,  char **enc);
  SplashFontFile *loadOpenTypeT1CFont(SplashFontFileID *idA, SplashFontSrc *src,  char **enc);
  SplashFontFile *loadCIDFont(SplashFontFileID *idA, SplashFontSrc *src);
  SplashFontFile *loadOpenTypeCFFFont(SplashFontFileID *idA, SplashFontSrc *src);
  SplashFontFile *loadTrueTypeFont(SplashFontFileID *idA, SplashFontSrc *src,
				   Gushort *codeToGID, int codeToGIDLen, int faceIndex = 0);

private:

  SplashFTFontEngine(GBool aaA, FT_Library libA);

  GBool aa;
  FT_Library lib;
  GBool useCIDs;

  friend class SplashFTFontFile;
  friend class SplashFTFont;
};

#endif // HAVE_FREETYPE_FREETYPE_H || HAVE_FREETYPE_H

#endif
