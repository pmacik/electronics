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
LIBS:multiregister-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "10 nov 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74HC595 U1
U 1 1 54608D07
P 3900 3450
F 0 "U1" H 4050 4050 70  0000 C CNN
F 1 "74HC595" H 3900 2850 70  0000 C CNN
F 2 "~" H 3900 3450 60  0000 C CNN
F 3 "~" H 3900 3450 60  0000 C CNN
	1    3900 3450
	1    0    0    -1  
$EndComp
$Comp
L CONN_8 P2
U 1 1 54608D34
P 5050 2550
F 0 "P2" V 5000 2550 60  0000 C CNN
F 1 "CONN_8" V 5100 2550 60  0000 C CNN
F 2 "~" H 5050 2550 60  0000 C CNN
F 3 "~" H 5050 2550 60  0000 C CNN
	1    5050 2550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR01
U 1 1 54609106
P 2100 2600
F 0 "#PWR01" H 2100 2600 30  0001 C CNN
F 1 "GND" H 2100 2530 30  0001 C CNN
F 2 "" H 2100 2600 60  0000 C CNN
F 3 "" H 2100 2600 60  0000 C CNN
	1    2100 2600
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 5460916E
P 2700 1950
F 0 "K1" V 2650 1950 50  0000 C CNN
F 1 "CONN_3" V 2750 1950 40  0000 C CNN
F 2 "~" H 2700 1950 60  0000 C CNN
F 3 "~" H 2700 1950 60  0000 C CNN
	1    2700 1950
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K2
U 1 1 5460917D
P 2700 2350
F 0 "K2" V 2650 2350 50  0000 C CNN
F 1 "CONN_3" V 2750 2350 40  0000 C CNN
F 2 "~" H 2700 2350 60  0000 C CNN
F 3 "~" H 2700 2350 60  0000 C CNN
	1    2700 2350
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR02
U 1 1 5460919B
P 2000 1600
F 0 "#PWR02" H 2000 1700 30  0001 C CNN
F 1 "VCC" H 2000 1700 30  0000 C CNN
F 2 "" H 2000 1600 60  0000 C CNN
F 3 "" H 2000 1600 60  0000 C CNN
	1    2000 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3000 4700 3000
Wire Wire Line
	4700 3000 4700 2900
Wire Wire Line
	4600 3100 4800 3100
Wire Wire Line
	4800 3100 4800 2900
Wire Wire Line
	4600 3200 4900 3200
Wire Wire Line
	4900 3200 4900 2900
Wire Wire Line
	4600 3300 5000 3300
Wire Wire Line
	5000 3300 5000 2900
Wire Wire Line
	4600 3400 5100 3400
Wire Wire Line
	5100 3400 5100 2900
Wire Wire Line
	4600 3500 5200 3500
Wire Wire Line
	5200 3500 5200 2900
Wire Wire Line
	4600 3600 5300 3600
Wire Wire Line
	5300 3600 5300 2900
Wire Wire Line
	4600 3700 5400 3700
Wire Wire Line
	5400 3700 5400 2900
Wire Wire Line
	1900 3200 2500 3200
Wire Wire Line
	2500 3200 2500 3000
Wire Wire Line
	2500 3000 3200 3000
Wire Wire Line
	4600 3900 5450 3900
Wire Wire Line
	1900 3000 2350 3000
Wire Wire Line
	2350 3000 2350 2850
Wire Wire Line
	2350 2850 3100 2850
Wire Wire Line
	3100 2850 3100 3200
Wire Wire Line
	3100 3200 3200 3200
Wire Wire Line
	4900 4250 4900 4000
Wire Wire Line
	4900 4000 5450 4000
Wire Wire Line
	2700 2850 2700 4350
Wire Wire Line
	2700 4350 5000 4350
Wire Wire Line
	5000 4350 5000 4100
Wire Wire Line
	5000 4100 5450 4100
Connection ~ 2700 2850
Wire Wire Line
	1900 3100 3000 3100
Wire Wire Line
	3000 3100 3000 3500
Wire Wire Line
	3000 3500 3200 3500
Wire Wire Line
	2850 3100 2850 4250
Wire Wire Line
	2850 4250 4900 4250
Connection ~ 2850 3100
Wire Wire Line
	1900 1850 2350 1850
Wire Wire Line
	2000 1600 2000 2250
Wire Wire Line
	2000 2250 2350 2250
Connection ~ 2000 1850
Wire Wire Line
	1150 2450 2350 2450
Wire Wire Line
	2100 2050 2100 2600
Wire Wire Line
	2350 2050 2100 2050
Connection ~ 2100 2450
Wire Wire Line
	2350 1950 2250 1950
Wire Wire Line
	2250 1950 2250 3300
Wire Wire Line
	2250 3300 3200 3300
Wire Wire Line
	2350 2350 2200 2350
Wire Wire Line
	2200 2350 2200 3600
Wire Wire Line
	2200 3600 3200 3600
Wire Wire Line
	3600 1700 3600 2900
Wire Wire Line
	1000 1700 3600 1700
Connection ~ 2000 1700
Wire Wire Line
	3600 4000 1150 4000
Wire Wire Line
	1150 4000 1150 2450
$Comp
L CONN_5 P3
U 1 1 546104A6
P 5850 4100
F 0 "P3" V 5800 4100 50  0000 C CNN
F 1 "CONN_5" V 5900 4100 50  0000 C CNN
F 2 "" H 5850 4100 60  0000 C CNN
F 3 "" H 5850 4100 60  0000 C CNN
	1    5850 4100
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P1
U 1 1 546104B5
P 1500 3000
F 0 "P1" V 1450 3000 50  0000 C CNN
F 1 "CONN_5" V 1550 3000 50  0000 C CNN
F 2 "" H 1500 3000 60  0000 C CNN
F 3 "" H 1500 3000 60  0000 C CNN
	1    1500 3000
	-1   0    0    1   
$EndComp
Wire Wire Line
	1900 2800 1900 1850
Wire Wire Line
	1900 2900 2000 2900
Wire Wire Line
	2000 2900 2000 2450
Connection ~ 2000 2450
Wire Wire Line
	5450 4200 5100 4200
Wire Wire Line
	5100 4200 5100 4500
Wire Wire Line
	5100 4500 2550 4500
Wire Wire Line
	2550 4500 2550 4000
Connection ~ 2550 4000
Wire Wire Line
	5450 4300 5200 4300
Wire Wire Line
	5200 4300 5200 4600
Wire Wire Line
	5200 4600 1000 4600
Wire Wire Line
	1000 4600 1000 1700
$EndSCHEMATC
