#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
  // Ensure proper usage
  if (argc == 1)
  {
    fprintf(stderr, "Usage: ./recover infile\n");
    return 1;
  }

  // Open data file
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
  FILE *recovered_data = NULL;
  //bool open?

  // Read data in 512 bytes chunks
  while (fread(&data_buffer, sizeof(BYTE), 512, data_file) == 512)
  {
    // Check for jpg signature bytes
    if (data_buffer[0] == 0xff && data_buffer[1] == 0xd8 && data_buffer[2] == 0xff && (data_buffer[3] & 0xf0) == 0xe0)
    {
      // Close previous file if present
      if (image_count > 0)
      {
        fclose(recovered_data);
      }

      // Create file name according to image count
      sprintf(file_name, "%03i.jpg", image_count);
      image_count++;

      // Open new file to write data
      recovered_data = fopen(file_name, "w");
      if (recovered_data == NULL)
      {
        fclose(data_file);
        printf("Could not create 0");
        return 3;
      }

      // Write data
      fwrite(data_buffer, sizeof(BYTE), 512, recovered_data);
    }
  }

  return 0;
}
