malloc, free, write, va_start, va_arg, va_copy,
va_end


• The prototype of ft_printf should be int ft_printf(const char *, ...);
• You have to recode the libc’s printf function
• It must not do the buffer management like the real printf
• It will manage the following conversions: cspdiuxX%
• It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions
• It will be compared with the real printf
• You must use the command ar to create your librairy, using the command libtool
is forbidden.

int ft_printf(const char *, ...)
{
    
}