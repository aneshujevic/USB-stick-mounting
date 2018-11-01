void
start_terminal(void)
{
	char command[START_PATH]="exec gnome-terminal --working-directory=";
	strcat(command, path_to_mount_point);
	system(command);
	
	return;
}
