# BHOOMI

This repository contains a small Wolfram Language script that reads pH values from an Arduino and suggests nutrient adjustments.

## Requirements
* Wolfram Mathematica or the free Wolfram Engine
* An Arduino connected over a serial port (default `COM3`)

## Usage
1. Update the serial port and desired crop in the `code` file.
2. Load the script in Mathematica using `<< path/to/code`.
3. The loop will print pH readings and simple fertilizer recommendations every few seconds.
