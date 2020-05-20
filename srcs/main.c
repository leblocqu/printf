#include "../includes/ft_printf.h"
#include <stdlib.h>

int main()
{
	//char	*n;
	//short int n;
	int n;
	//long n;
	//long long n;
	//double n;
	//long double n;

	// manque l'arrondis inter '.' 19999.9 preci de 0 => 20000.0

	n = 0;
	dprintf(1, "\n\n-----------------------------------------------\n\n");
	dprintf(1, "NORMAL\n\n\n");

	

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %d\t", n));

	dprintf(1, " %d\n", ft_printf("  %1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %30.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %30.12d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "PLUS\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %+d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "MOINS\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %-d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %-.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "ZERO\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %01d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %01d\t", n));

	dprintf(1, " %d\n", ft_printf("  %010d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %010d\t", n));

	dprintf(1, " %d\n", ft_printf("  %0.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %0.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %0.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %0.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %0.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %0.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %010.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %010.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %010.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %010.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %010.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %010.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %010.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %010.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %020.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %020.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "HASH\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %#d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#01d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#01d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#0.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#0.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %#0.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#0.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#0.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#0.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#020.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#020.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "ESPACE\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %   d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   .0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   .0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %   .1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   .1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   .10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   .10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %   20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %   20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "PLUS + ZERO\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %+0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+01d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+01d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+010d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+010d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+00.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+00.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %+00.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+00.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+00.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+00.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+010.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+010.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+010.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+010.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+010.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+010.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+010.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+010.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+020.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+020.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "HASH + ZERO\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %#0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#01d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#01d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#0.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#0.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %#0.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#0.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#0.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#0.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#010.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#010.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#020.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#020.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "ESPACE + ZERO\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  % 0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 0d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 01d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 01d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 010d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 010d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 0.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 0.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  % 0.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 0.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 0.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 0.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 010.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 010.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 010.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 010.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  % 20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % 20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "PLUS + HASH + ZERO\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %+#0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#01d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#01d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#010d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#010d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#0.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#0.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %+#0.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#0.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#0.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#0.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#010.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#010.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#010.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#010.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#010.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#010.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#010.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#010.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %+#020.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %+#020.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "ESPACE + HASH + ZERO\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  % #0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #0d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #01d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #01d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #010d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #010d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #0.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #0.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  % #0.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #0.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #0.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #0.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #010.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #010.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #010.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #010.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #010.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #010.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #010.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #010.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  % #020.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % #020.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "MOINS + PLUS\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %-+d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %-+.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %-+20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %-+20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "ESPACE + MOINS\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  % -d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -1d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -10d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  % -.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  % -20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  % -20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "PLUS + HASH\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %#+d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %#+.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#+20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#+20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "ESPACE + HASH\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %# d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# 1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# 1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# 10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# 10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# .0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# .0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %# .1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# .1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# .10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# .10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# 10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# 10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# 10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# 10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# 10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# 10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# 10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# 10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %# 20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %# 20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "MOINS + HASH\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %#-d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-.0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %#-.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#-20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#-20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");

	dprintf(1, "ESPACE + MOINS + HASH\n\n\n");

	dprintf(1, "-----------------------------------------------\n\n");
	dprintf(1, " %d\n", ft_printf("  %#- d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- 1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- 1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- 10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- 10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- .0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- .0d\t", n));
	
	dprintf(1, " %d\n", ft_printf("  %#- .1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- .1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- .10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- .10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- 10.0d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- 10.0d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- 10.1d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- 10.1d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- 10.12d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- 10.12d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- 10.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- 10.10d\t", n));

	dprintf(1, " %d\n", ft_printf("  %#- 20.10d\t", n));
	dprintf(1, " %d\n\n", dprintf(1, "  %#- 20.10d\t", n));
	dprintf(1, "-----------------------------------------------\n\n");
}