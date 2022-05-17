#include "main.h"

/*
 * print_int - prints integer
 * @l: va_list arguments of printf
 * @f: pointer to the struct flag
 * Return: list of charater to be printed
 */
int print_int(va_list l, flags_t *f)
{
  int a = va_arg(l, int);
  int b = count_digit(a);

  if (f->space == 1 && f->plus == 0 && a >= 0)
    b += _putchar(' ');
  if (f->plus == 1 && a >= 0)
    b += _putchar('+');
  if (a <= 0)
    b++;
  print_number(a);
  return (b);
}

/*
 * print_unsigned - prints  unsigned integer
 * @l: va_list arguments of print f
 * @f: pointer to the struct flag
 * Return: list of char to be printed
 */
int print_unsigned(va_list l, flags_t *f)
{
  unsigned int c = va_arg(l, unsigned int);
  char *s = convert(c, 10, 0);

  (void)f;
  return (_puts(s));
}

/*
 * print_number - function that loops through intigers and print all digits
 * @n: integer to be printed
 */
void print_number(int n)
{
  unsigned int n1;

  if (n < 0)
  {
    _putchar('-');
    n1 = -n;
  }
  else
    n1 = n;

  if (n1 / 10)
    print_number(n1 / 10);
  _putchar((n1 % 10) + '0');
}

/*
 * count_digit - returns no of digits
 * @i: integer to determine
 * Return: number of digits
 */
int count_digit(int i)
{
  unsigned int d = 0;
  unsigned int k;

  if (i < 0)
    k = i * -1;
  else
    k = i;
  while (k != 0)
  {
    k /= 10;
    d++;
  }
  return (d);
}
