//========================================================================
//
// HTMLGen.h
//
// Copyright 2010 Glyph & Cog, LLC
//
//========================================================================

#ifndef JSONGEN_H
#define JSONGEN_H

#include <aconf.h>

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

class GString;
class PDFDoc;
class TextOutputDev;
class TextFontInfo;
class SplashOutputDev;

//------------------------------------------------------------------------

class JSONGen {
public:

  JSONGen(double backgroundResolutionA);
  ~JSONGen();

  GBool isOk() { return ok; }

  double getBackgroundResolution() { return backgroundResolution; }
  void setBackgroundResolution(double backgroundResolutionA)
    { backgroundResolution = backgroundResolutionA; }

  GBool getDrawInvisibleText() { return drawInvisibleText; }
  void setDrawInvisibleText(GBool drawInvisibleTextA)
    { drawInvisibleText = drawInvisibleTextA; }

  void startDoc(PDFDoc *docA);
  int convertPage(int pg,
                  int (*writeHTML)(void *stream, const char *data, int size),
                  void *htmlStream,int (*writePNG)(void *stream, const char *data, int size),
                  void *pngStream,void *pngStream2, GBool createPng);

private:

  GString *getFontDefn(TextFontInfo *font, double *scale);

  double backgroundResolution;
  GBool drawInvisibleText;

  PDFDoc *doc;
  TextOutputDev *textOut;
  SplashOutputDev *splashOut;

  GBool ok;
};

#endif
