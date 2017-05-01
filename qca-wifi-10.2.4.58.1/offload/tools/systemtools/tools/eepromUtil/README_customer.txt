
Selective EEPROM field utility
------------------------------

To read a field:
- eepromReadField <field> <eeprom bin file> (<eeprom template>)

To modify a field, and re-geneate the eeprom bin file
- eepromModifyField <field> <value> <eeprom bin file> (<eeprom template>)

Please note the re-generated bin file is the same one from the input, so 
keep a copy if you want to keep the original bin file.

For example, to change mac addr

eepromModifyField macAddr 112233445566 calData_sd32-039-d0190.bin
eepromReadField macAddr calData_sd32-039-d0190.bin

macAddr value is a 6 bytes hex, no space, no 0x.


