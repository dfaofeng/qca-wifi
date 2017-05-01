
EEPROM_PATH=..\..\..\..\..\..\target\src\wlan\wal\whal\eeprom

..\Debug\EepromUtilBin2Txt_qc9k.exe eeprom_qc9k_2.tpl boardData_2_QC98XX.bin eeprom_qc9k_dflt_2.txt qc98xxtemplate_generic.h

..\Debug\EepromUtilBin2Txt_qc9k.exe eeprom_qc9k_2.tpl boardData_2_QC98XX_cus223_gld.bin eeprom_qc9k_dflt_2_cus223.txt qc98xxtemplate_1_1_cus223.h

..\Debug\EepromUtilBin2Txt_qc9k.exe eeprom_qc9k_2.tpl boardData_2_QC98XX_wb342_gld.bin eeprom_qc9k_dflt_2_wb342.txt qc98xxtemplate_1_1_wb342.h

..\Debug\EepromUtilBin2Txt_qc9k.exe eeprom_qc9k_2.tpl boardData_2_QC98XX_xb340_gld.bin eeprom_qc9k_dflt_2_xb340.txt qc98xxtemplate_1_1_xb340.h

..\Debug\EepromUtilBin2Txt_qc9k.exe eeprom_qc9k_2.tpl boardData_2_QC98XX_cus226_gld.bin eeprom_qc9k_dflt_2_cus226.txt qc98xxtemplate_1_1_cus226.h

..\Debug\EepromUtilBin2Txt_qc9k.exe eeprom_qc9k_2.tpl boardData_2_QC98XX_xb141_gld.bin eeprom_qc9k_dflt_2_xb141.txt qc98xxtemplate_1_1_xb141.h

..\Debug\EepromUtilBin2Txt_qc9k.exe eeprom_qc9k_2.tpl boardData_2_QC98XX_xb143_gld.bin eeprom_qc9k_dflt_2_xb143.txt qc98xxtemplate_1_1_xb143.h

copy /Y qc98xxtemplate_*.h %EEPROM_PATH%