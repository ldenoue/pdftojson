//========================================================================
//
// Form.h
//
// Copyright 2012 Glyph & Cog, LLC
//
//========================================================================

#ifndef FORM_H
#define FORM_H

#include <aconf.h>

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "gtypes.h"

class Gfx;
class FormField;
class TextString;
//------------------------------------------------------------------------

class Form {
public:

  static Form *load(PDFDoc *docA, Catalog *catalog, Object *acroFormObj);

  virtual ~Form();

  virtual const char *getType() = 0;

  virtual void draw(int pageNum, Gfx *gfx, GBool printing) = 0;

  virtual int getNumFields() = 0;
  virtual FormField *getField(int idx) = 0;

protected:

  Form(PDFDoc *docA);

  PDFDoc *doc;
};

//------------------------------------------------------------------------

class FormField {
public:

  FormField();
  virtual ~FormField();

  virtual const char *getType() = 0;
  virtual Unicode *getName(int *length) = 0;

  virtual TextString *getNameTS() = 0;
  virtual TextString *getValueTS() = 0;
  virtual TextString *getAltTextTS() = 0;

  virtual GBool getRect(int pageNum, int *xMin, int *yMin, int *xMax, int *yMax) { *xMin = 0; *yMin = 0; *xMax = 0; *yMax = 0; return gFalse;};
  //virtual GString *getAltText(int pageNum) { return NULL; };
  //virtual GString *getNameGString() { return new GString(); };
  //virtual GString *getValueGString() { return new GString(); };
  // Return the resource dictionaries used to draw this field.  The
  // returned object must be either a dictionary or an array of
  // dictonaries.
  virtual Object *getResources(Object *res) = 0;
};

#endif
