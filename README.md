# pdftojson
using XPDF, pdftojson extracts text from PDF files as JSON, including word bounding boxes.

## Compile

    ./configure
    make

On MacOS, you might need to specify libpng and libfreetype locations, e.g.

    ./configure --with-libpng-library=/usr/local/Cellar/libpng/1.6.16/lib/  --with-libpng-includes=/usr/local/Cellar/libpng/1.6.16/include/ --with-freetype2-library=/usr/local/lib/ --with-freetype2-includes=/usr/local/include/freetype2/

You will find pdftojson inside the directory xpdf/pdftojson

## Usage

    pdftojson <input.pdf> <output.json>

## File format

The JSON produced looks like:
    [
      { "pages":14,
        "number":1,
        "width":612,
        "height":792,
        "text":[
          [115,162,41,14,0,"What "],
          ...
        ]
      },
      { "pages":14,
        "number":2,
        "width":612,
        "height":792,
        "text":[
          [115,162,41,14,0,"Here "],
          ...
        ]
      },
      ...
    ];
    
For each page, the text array contains: [top,left,width,height,0,text]
