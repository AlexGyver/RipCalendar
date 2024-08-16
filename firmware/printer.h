#pragma once
#include <GyverNTP.h>
#include <SoftwareSerial.h>

#include "printer_class.h"

#define PRINTER_RX D1
#define PRINTER_TX D2

SoftwareSerial uart(PRINTER_RX, PRINTER_TX);
Printer printer(uart);

void printer_init() {
    uart.begin(9600);
    printer.begin();
    printer.config(5, 170, 4);
}