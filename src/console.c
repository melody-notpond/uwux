#include "console.h"
#include "opensbi.h"

void kprintfv(char* format, va_list va) {
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case '%':
                    sbi_console_putchar('%');
                    break;
                case 's': {
                    char* s = va_arg(va, char*);
                    while (*s) {
                        sbi_console_putchar(*s);
                        s++;
                    }
                    break;
                }

                case 'x': {
                    int i = va_arg(va, int);
                    if (i == 0) {
                        sbi_console_putchar('0');
                    } else {
                        char buffer[8];
                        for (int j = 0; i != 0; j++, i /= 16) {
                            buffer[8 - j - 1] = "0123456789abcdef"[i % 16];
                        }
                        for (int j = 0; j < 8; j++) {
                            sbi_console_putchar(buffer[j]);
                        }
                    }

                    break;
                }

                case 'i': {
                    int i = va_arg(va, int);
                    if (i == 0) {
                        sbi_console_putchar('0');
                    } else {
                        char buffer[10];
                        for (int j = 0; i != 0; j++, i /= 10) {
                            buffer[10 - j - 1] = "0123456789abcdef"[i % 10];
                        }
                        for (int j = 0; j < 10; j++) {
                            sbi_console_putchar(buffer[j]);
                        }
                    }

                    break;
                }
            }
            format++;
        } else {
            sbi_console_putchar(*format);
            format++;
        }
    }
}

void kprintf(char* format, ...) {
    va_list va;
    va_start(va, format);
    kprintfv(format, va);
    va_end(va);
}

