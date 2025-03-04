#include <unistd.h>
 
int main() {

  char *binary_path = "/bin/bash";
  // Argument Array
  char *const args[] = {binary_path, "-c", "echo \"Visit $HOSTNAME:$PORT from your browser.$PATH\"", NULL};
 // Environment Variable Array
  char *const env[] = {"HOSTNAME=https://www.cs.ku.edu.kw/", "PORT=80", NULL};
 
  execve(binary_path, args, env);
 
  return 0;
}
