#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "./libft/libft.h"

#define HEX_UP "0123456789ABCDEF"
#define HEX_LOW "0123456789abcdef"

typedef struct	s_format
{
	unsigned int	mem;
	int	width;
	int	precision;
}				t_format;

int			ft_printf(const char *, ...);
const char	*str_loop(const char *);
const char	*arg_loop(const char *, va_list, t_format *);
void		ft_convert_char(const char *, va_list, t_format *);
void		ft_convert_str(const char *, va_list, t_format *);
void		ft_convert_int(const char *, va_list, t_format *);
void		ft_convert_uint(const char *, va_list, t_format *);
void		ft_convert_hex(const char *, va_list, t_format *);
void		ft_convert_ptr(const char *, va_list, t_format *);
const char	*ft_flags0(const char *, va_list, t_format *);
const char	*ft_flags1(const char *, va_list, t_format *);
void		ft_puthex(unsigned long, char);
void		ft_putlchar(int, int);
void		ft_putlstr(char *, int);
void		ft_putuint(unsigned int);
int			ft_intlen(long, int);
int			ft_ulen(unsigned long, int);
void		init_flags(t_format *flags);



