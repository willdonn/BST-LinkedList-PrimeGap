#include <gmp.h>

unsigned long primeGap(const mpz_t a, const mpz_t b)
{
   mpz_t p1, p2, pgap, pgapMax;
   mpz_init(p1);
   mpz_init(p2);
   mpz_init(pgap);
   mpz_init(pgapMax);
   mpz_set(p1, a);
   mpz_nextprime(p2, a);
      while (mpz_cmp(p2, b) <= 0)
      {
         mpz_sub(pgap, p2, p1);
         mpz_set(p1, p2);

         if (mpz_cmp(pgap, pgapMax) > 0)
         {
            mpz_set(pgapMax, pgap);
         }
         mpz_nextprime(p2, p1);
      }
   return mpz_get_ui(pgapMax);
}
