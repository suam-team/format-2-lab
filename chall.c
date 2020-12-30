// gcc chall.c -o chall

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 240
char flag[BUFFER_SIZE];
char authorized_password[BUFFER_SIZE];

void pass_check()
{
  FILE *fp;
  char password[BUFFER_SIZE];
  while (1)
  {
    if ((fp = fopen("password.txt", "r")) == NULL)
    {
      puts("[ERROR] Cannot open the password file!\n");
      exit(1);
    }

    fgets(authorized_password, BUFFER_SIZE - 1, fp);
    fclose(fp);

    puts("***** AUTHORIZED ACCESS ONLY *****\n");
    puts("Please enter your password: ");

    // Receive password input
    fgets(password, BUFFER_SIZE - 1, stdin);

    // Check if the password is correct
    if (strncmp(password, authorized_password, strlen(authorized_password)) != 0)
    {
      // Clear the authorized_password variable
      memset(authorized_password, '\0', BUFFER_SIZE);

      puts("Your password is: ");
      printf(password);
      puts("The password is incorrect!\n");
    }
    else
    {
      printf("You are authorized, here's the flag: %s\n", flag);
      exit(0);
    }
  }
}

int main()
{
  setvbuf(stdout, NULL, _IONBF, 0);
  FILE *fptr;
  if ((fptr = fopen("flag.txt", "r")) == NULL)
  {
    puts("[ERROR] Cannot open the flag file!\n");
    exit(1);
  }
  fgets(flag, BUFFER_SIZE - 1, fptr);
  fclose(fptr);
  pass_check();
  return 0;
}