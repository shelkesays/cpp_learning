// CPP program to reverse bits using lookup table.
#include<bits/stdc++.h>
using namespace std;

// Generate a lookup table for 32bit operating system
// using macro
#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

// Lookup table that store the reverse of each table
unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) };

/* Function to reverse bits of num */
int reverseBits(unsigned int num)
{
    int reverse_num = 0;

     // Reverse and then rearrange

                   // first chunk of 8 bits from right
     reverse_num = lookuptable[ num & 0xff ]<<24 |

                   // second chunk of 8 bits from  right
                   lookuptable[ (num >> 8) & 0xff ]<<16 |

                   lookuptable[ (num >> 16 )& 0xff ]<< 8 |
                   lookuptable[ (num >>24 ) & 0xff ] ;

    return reverse_num;
}

//driver program to test above function
int main()
{
    int x = 12456;
    printf("%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u\n%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u\n%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u\n%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u\n", R6(0));
    printf("%d\n", 0xff);
    printf("%d\n", (12 & 0xff) << 24);
    printf("%u\n", reverseBits(x));
    return 0;
}
