#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    fprintf(stderr, "Usage: ./recover infile\n");
    return 1;
  }

  FILE *data_file = fopen(argv[1], "r");
  if (data_file == NULL)
  {
    fprintf(stderr, "Could not open %s\n", argv[1]);
    return 2;
  }

  typedef uint8_t BYTE;

  BYTE data_buffer[512];
  int image_count = 0;
  char file_name[8];

  while(fread(&data_buffer, sizeof(BYTE), 512, data_file) == 512)
  {
    if (data_buffer[0] == 0xff && data_buffer[1] == 0xd8 && data_buffer[2] == 0xff && (data_buffer[3] & 0xf0) == 0xe0 )
    {
      sprintf(file_name, "%03i.jpg", image_count);
      printf("found image %s\n", file_name);
      image_count++;
    }
  }

  return 0;
}
