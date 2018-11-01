
void
remove_newline_u(char *str, int bound)
{
  int i=0;
  while(i != bound)
  {
    if(str[i] == '\n')
    {
      str[i] = str[i+1];
      str[i+1] = 0;
      break;
    }
    i++;
  }
}

int
umount(void * arg)
{
  char dev_name[DEV_NAME_L];
  char command[COMMAND_L] = "sudo umount ";
  char reply;

  system("lsblk");

  printf("Enter the name of the device that you want to unmount:\n");
  fgets(dev_name, DEV_NAME_L-1, stdin);
  remove_newline_u(dev_name, DEV_NAME_L);

  strcat(command, dev_name);
  printf("Enter the password for \" %s \" command..\n", command);
  system(command);
  opened=false;

  return 0;
}
