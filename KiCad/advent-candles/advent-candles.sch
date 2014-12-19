EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino
LIBS:sewer
LIBS:advent-candles-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "19 dec 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_MINI U1
U 1 1 5493C428
P 1900 3250
F 0 "U1" H 2400 2300 70  0000 C CNN
F 1 "ARDUINO_MINI" H 2650 2200 70  0000 C CNN
F 2 "DIL20" H 1900 3200 60  0000 C CNN
F 3 "" H 1900 3250 60  0000 C CNN
	1    1900 3250
	1    0    0    -1  
$EndComp
$Comp
L DS1307-MODULE MOD1
U 1 1 5493C6EE
P 3950 3250
F 0 "MOD1" H 3950 3700 60  0000 C CNN
F 1 "DS1307-MODULE" V 3950 3250 60  0000 C CNN
F 2 "" H 3750 3250 60  0000 C CNN
F 3 "" H 3750 3250 60  0000 C CNN
	1    3950 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 3850 3100 3850
Wire Wire Line
	3100 3850 3100 3050
Wire Wire Line
	3100 3050 3350 3050
Wire Wire Line
	1200 3550 950  3550
Wire Wire Line
	950  3550 950  1850
Wire Wire Line
	950  1850 2850 1850
Wire Wire Line
	2850 1850 2850 3150
Wire Wire Line
	2850 3150 3350 3150
Wire Wire Line
	1200 3450 1050 3450
Wire Wire Line
	1050 3450 1050 1950
Wire Wire Line
	1050 1950 2800 1950
Wire Wire Line
	2800 1950 2800 3250
Wire Wire Line
	2800 3250 3350 3250
Wire Wire Line
	1900 2100 1900 2050
Wire Wire Line
	1900 2050 2750 2050
Wire Wire Line
	2750 2050 2750 3350
Wire Wire Line
	2750 3350 3350 3350
Wire Wire Line
	3350 3450 3200 3450
Wire Wire Line
	3200 3450 3200 4800
Wire Wire Line
	3200 4800 1900 4800
$Comp
L GND #PWR01
U 1 1 5493C73F
P 2450 4900
F 0 "#PWR01" H 2450 4900 30  0001 C CNN
F 1 "GND" H 2450 4830 30  0001 C CNN
F 2 "" H 2450 4900 60  0000 C CNN
F 3 "" H 2450 4900 60  0000 C CNN
	1    2450 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 4900 2450 4800
Connection ~ 2450 4800
$Comp
L R R1
U 1 1 5493C763
P 3850 4050
F 0 "R1" V 3930 4050 40  0000 C CNN
F 1 "R" V 3857 4051 40  0000 C CNN
F 2 "~" V 3780 4050 30  0000 C CNN
F 3 "~" H 3850 4050 30  0000 C CNN
	1    3850 4050
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5493C770
P 3850 4250
F 0 "R2" V 3930 4250 40  0000 C CNN
F 1 "R" V 3857 4251 40  0000 C CNN
F 2 "~" V 3780 4250 30  0000 C CNN
F 3 "~" H 3850 4250 30  0000 C CNN
	1    3850 4250
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 5493C776
P 3850 4450
F 0 "R3" V 3930 4450 40  0000 C CNN
F 1 "R" V 3857 4451 40  0000 C CNN
F 2 "~" V 3780 4450 30  0000 C CNN
F 3 "~" H 3850 4450 30  0000 C CNN
	1    3850 4450
	0    -1   -1   0   
$EndComp
$Comp
L R R4
U 1 1 5493C77C
P 3850 4650
F 0 "R4" V 3930 4650 40  0000 C CNN
F 1 "R" V 3857 4651 40  0000 C CNN
F 2 "~" V 3780 4650 30  0000 C CNN
F 3 "~" H 3850 4650 30  0000 C CNN
	1    3850 4650
	0    -1   -1   0   
$EndComp
$Comp
L LED D1
U 1 1 5493C784
P 4400 4050
F 0 "D1" H 4400 4150 50  0000 C CNN
F 1 "LED" H 4400 3950 50  0000 C CNN
F 2 "~" H 4400 4050 60  0000 C CNN
F 3 "~" H 4400 4050 60  0000 C CNN
	1    4400 4050
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 5493C791
P 4400 4250
F 0 "D2" H 4400 4350 50  0000 C CNN
F 1 "LED" H 4400 4150 50  0000 C CNN
F 2 "~" H 4400 4250 60  0000 C CNN
F 3 "~" H 4400 4250 60  0000 C CNN
	1    4400 4250
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 5493C797
P 4400 4450
F 0 "D3" H 4400 4550 50  0000 C CNN
F 1 "LED" H 4400 4350 50  0000 C CNN
F 2 "~" H 4400 4450 60  0000 C CNN
F 3 "~" H 4400 4450 60  0000 C CNN
	1    4400 4450
	1    0    0    -1  
$EndComp
$Comp
L LED D4
U 1 1 5493C79D
P 4400 4650
F 0 "D4" H 4400 4750 50  0000 C CNN
F 1 "LED" H 4400 4550 50  0000 C CNN
F 2 "~" H 4400 4650 60  0000 C CNN
F 3 "~" H 4400 4650 60  0000 C CNN
	1    4400 4650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5493C7A5
P 4800 4900
F 0 "#PWR02" H 4800 4900 30  0001 C CNN
F 1 "GND" H 4800 4830 30  0001 C CNN
F 2 "" H 4800 4900 60  0000 C CNN
F 3 "" H 4800 4900 60  0000 C CNN
	1    4800 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4050 4800 4050
Wire Wire Line
	4800 4050 4800 4900
Wire Wire Line
	4600 4250 4800 4250
Connection ~ 4800 4250
Wire Wire Line
	4600 4450 4800 4450
Connection ~ 4800 4450
Wire Wire Line
	4600 4650 4800 4650
Connection ~ 4800 4650
Wire Wire Line
	4200 4650 4100 4650
Wire Wire Line
	4200 4450 4100 4450
Wire Wire Line
	4200 4250 4100 4250
Wire Wire Line
	4200 4050 4100 4050
Wire Wire Line
	3600 3750 3600 4050
Wire Wire Line
	3600 3750 2600 3750
Wire Wire Line
	3600 4250 3500 4250
Wire Wire Line
	3500 4250 3500 3650
Wire Wire Line
	3500 3650 2600 3650
Wire Wire Line
	3600 4450 3000 4450
Wire Wire Line
	3000 4450 3000 3550
Wire Wire Line
	3000 3550 2600 3550
Wire Wire Line
	3600 4650 2700 4650
Wire Wire Line
	2700 4650 2700 3300
Wire Wire Line
	2700 3300 2600 3300
$EndSCHEMATC
