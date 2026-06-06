HOW TO RUN THE BMP FILTER PROGRAM

1. Save all four files in the same folder:
   - bmp.h
   - helpers.h
   - helpers.c
   - filter.c

2. Compile the program using gcc (or clang). Example:
   gcc -o filter filter.c helpers.c -lm

   Note: -lm is for the math library (not strictly required here but safe).

3. Run the program with a 24‑bit uncompressed BMP image.
   Syntax:
   ./filter [flag] input.bmp output.bmp

   Available flags:
     b   blur
     g   grayscale
     r   reflect (horizontal mirror)
     s   sepia

   Example:
   ./filter g landscape.bmp gray_landscape.bmp

4. The output file will be a valid BMP image. If the input does not match the
   required format (24‑bit, uncompressed, BITMAPINFOHEADER version), the program
   will show an error.

Requirements:
- Operating system: Linux, macOS, or Windows with a compiler like MinGW.
- The BMP file must be a 24‑bit truecolor (RGB) uncompressed BMP.

Troubleshooting:
- "Unsupported file format" → Convert your image to 24‑bit BMP using an image
  editor or command line tools like ImageMagick.
- "Only one filter allowed" → Use exactly one flag.
- "Invalid filter" → Use only b, g, r, or s.
