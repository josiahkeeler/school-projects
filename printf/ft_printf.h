#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "./libft/libft.h"

#define SPECIFIERS "cspdiuxX%"
#define FLAGS "-0.*"
#define HEX_UP "0123456789ABCDEF"
#define HEX_LOW "0123456789abcdef"


int			ft_printf(const char *, ...);
const char	*str_loop(const char *);
const char	*arg_loop(const char *, va_list);
void		ft_convert_char(const char *, va_list);
void		ft_convert_str(const char *, va_list);
void		ft_convert_spec(const char *);
const char	*ft_flags(const char *);

