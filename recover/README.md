```txt
# JPEG Recovery Tool (recover)

## What it does
This program scans a raw data file (typically a memory card image) for JPEG signatures (0xFF 0xD8 0xFF 0xE? where ? is 0x0 to 0xF) and extracts each JPEG image into a separate file. The recovered images are saved as `000.jpg`, `001.jpg`, `002.jpg`, etc. in the current directory.

## How to compile
Compile the code using a C compiler (e.g., gcc):
```bash
gcc main.c -o recover
```

## How to run
Execute the program with the input file as the only argument:
```bash
./recover <input_file>
```

Example:
```bash
./recover card.raw
```

## Requirements
- The input file must be readable and contain 512‑byte blocks.
- The program expects the input file to contain contiguous JPEG data (no fragmentation).
- It will not overwrite existing files with the same names unless you delete them first.

## Output
- Recovered JPEG images: `000.jpg`, `001.jpg`, …
- If no JPEGs are found, no output files are created.
```
