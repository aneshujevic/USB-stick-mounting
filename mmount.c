char path_to_mount_point[PATH_L];
bool opened;

void
remove_newline(char *str, int bound)
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
mount(void * arg)
{
  char dev_name[DEV_NAME_L];
  char command[COMMAND_L] = "sudo mount /dev/";

  system("lsblk");

  printf("Enter the name of the device that you want to mount:\n");
  fgets(dev_name, DEV_NAME_L-1, stdin);
  remove_newline(dev_name, DEV_NAME_L);

  printf("Enter the path where you want the device to be mounted to:\n");
  fgets(path_to_mount_point, PATH_L-1, stdin);
  remove_newline(path_to_mount_point, PATH_L);

  strcat(command, dev_name);
  strcat(command, " ");
  strcat(command, path_to_mount_point);
  printf("Enter the password for \" %s \" command..\n", command);
  system(command);
  opened = true;

  return 0;
}
