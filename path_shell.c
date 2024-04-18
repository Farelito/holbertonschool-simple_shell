#include "shell.h"

char *find_command_in_path(const char *command, const char *path)
{
  static char command_with_path[MAX_COMMAND_WITH_PATH_LENGTH];
  char *path_copy = strdup(path);
  char *path_token = strtok(path_copy, ":");

  while (path_token != NULL)
  {
    snprintf(command_with_path, sizeof(command_with_path), "%s/%s", path_token, command);
    if (access(command_with_path, X_OK) != -1)
    {
      free(path_copy);
      return command_with_path;
    }
    path_token = strtok(NULL, ":");
  }

  free(path_copy);
  return NULL;
}