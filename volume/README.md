```txt
# WAV Volume Changer (volume)

## What it does
This program reads a WAV audio file, preserves its header (first 44 bytes), and multiplies every 16‑bit audio sample by a scaling factor. The result is a new WAV file with adjusted volume. Positive factors increase volume; values between 0 and 1 decrease it; negative factors invert polarity.

## How to compile
Compile with a C compiler (e.g., gcc):
```bash
gcc main.c -o volume
```

## How to run
```bash
./volume input.wav output.wav factor
```

Example:
```bash
./volume original.wav louder.wav 2.0   # double volume
./volume original.wav quieter.wav 0.5  # half volume
```

## Requirements
- Input file must be a valid WAV file with a 44‑byte header (standard PCM format).
- The program reads 16‑bit little‑endian samples (common for WAV).
- Output file will be overwritten if it already exists.

## Notes
- Scaling may cause clipping if the factor is too high (samples exceed ±32767). The program does not clamp the values.
- Only the audio data is modified; the header (sample rate, channels, etc.) remains unchanged.
```
