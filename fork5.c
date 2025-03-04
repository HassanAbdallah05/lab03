// your includes here.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
// your global variables and defined functions here.

int main() {
  // your declarations here.
  int a, b;
	
  int result; 
  printf("Enter the first integer: ");
  scanf("%d", &a);
  printf("Enter the second integer: ");
  scanf("%d", &b);

  // your code to compute the a+b in the parent and a*b in the child.
	
  pid_t pid = fork(); 

  if(pid == 0 ){
        result = a * b ;
        printf("Result %d * %d = %d\n" , a , b , result);
	exit(0);

  } else {
	  wait(NULL); 
	  result = a + b;
  	  printf("Result %d + %d = %d\n" , a , b , result) ;
  }
  return 0;
}

