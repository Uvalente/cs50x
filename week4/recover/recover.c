#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    printf("Usage: ./recover infile\n");
    return 1;
  }

  FILE *data_file = fopen(argv[1], "r");
  if (data_file == NULL)
  {
    printf("Could not open %s\n", argv[1]);
    return 2;
  }

  return 0;
}
