
This is a simple, yet versatile eeprom utiility tool.
It consists of two parts: a template based EEPROM bin file parser, and a  
template based EEPROM bin file generator.

The typical use case is to modify some content of an existing EEPROM bin file.

Usage example:

  eepromBin2Txt.out <template> <input bin> <output text>

  You modify the output text file, and then re-generate the bin file,

  eepromTxt2Bin.out <template> <input text> <output bin>

The template is a by-product of the calibration when EEPROM file is created.

The utility is indepedent of the EEPROM file format change sa long as the template
is available.

How to detect the mismatch of the template file and EEPROM bin file?
The utility is generic and doesn't know the EEPROM format. It is mechanically
parsing the bin file using the template.
One way to detect is to display the generated bin file, and check the compatibility
of its version with the template version (which should be a part of the template 
file name).



