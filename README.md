# pdftojson
using XPDF, pdftojson extracts text from PDF files as JSON, including word bounding boxes.

To compile:

./configure
make

You will find pdftojson inside /xpdf/pdftojson

Use with:

pdftojson <input.pdf> <output.json>

