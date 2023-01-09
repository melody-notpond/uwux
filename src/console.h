#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdarg.h>

void kprintf(char* format, ...);

void kprintfv(char* format, va_list va);

#endif /* CONSOLE_H */
