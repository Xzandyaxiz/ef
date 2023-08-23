#include <stdio.h>
#include <stdlib.h>
#include "ef_parser.h"

// Read file contents at certain path
char *read_file(const char *path)
{
  FILE *file = fopen(path, "r");
  if (file == NULL)
    return NULL;

  fseek(file, 0, SEEK_END);
  int f_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *source = calloc(f_size, 1);

  int i;
  for (i = 0; i < f_size; i++)
  {
    source[i] = fgetc(file);
  }

  source[i] = 0;
  fclose(file);

  return source;
}

/*
 * Getting next cmd argument and
 * shifting to the left
 * */
char *shift(int *argc, char ***argv)
{
  if (*argc < 1)
    return NULL;

  char *res = **argv;
  *argv += 1;
  *argc -= 1;

  return res;
}

int main(int argc, char **argv)
{
  shift(&argc, &argv);
  if (argc < 1)
  {
    printf("Insufficient arguments!\n");
    return 1;
  }

  const char *path = shift(&argc, &argv);
  char *source = read_file(path);

  printf("%s\n", source);

  free(source);

  return 0;
}
