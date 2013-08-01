/*
** my_getnbr.c for my_getnbr in /u/all/ricard_v/cu/rendu/piscine/colles/Semaine_02
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Sat Oct 17 22:13:03 2009 vincent ricard
** Last update Sat Oct 17 22:14:41 2009 vincent ricard
*/

int		str_number_pos(char *str)
{
  int		signe;
  int		pos;
  
  signe = 1;
  pos = 0;
  while(str[pos] == '+' || str[pos] == '-')
    {
      if (str[pos] == '-')
	{
	  signe = signe * -1;
	}
      pos = pos + 1;
    }
  return (signe * pos);
}

int		my_getnbr(char *str)
{
  int		nbr;
  int		signe;
  int		first_number;
  
  nbr = 0;
  signe = 1;
  first_number = str_number_pos(str);
  if (first_number < 0)
    {
      first_number = first_number * -1;
      signe = -1;
    }
  str = str + first_number;
  while (*str >= '0' && *str <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (*str - '0');
      str = str + 1;
    }
  return (nbr * signe);
}