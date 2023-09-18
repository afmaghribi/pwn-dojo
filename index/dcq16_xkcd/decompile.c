undefined8 main(void)

{
  int iVar1;
  char *pcVar2;
  size_t length;
  ulong uVar3;
  undefined input_user [4];
  int local_34;
  char *local_30;
  char *local_28;
  FILE *flag;
  
  setvbuf((FILE *)stdout,(char *)0x0,2,0);
  setvbuf((FILE *)stdin,(char *)0x0,2,0);
  bzero(globals + 0x200,0x100);
  flag = fopen64("flag","r");
  if (flag == (FILE *)0x0) {
    puts("Could not open the flag.");
    return 0xffffffff;
  }
  fread(globals + 0x200,1,0x100,flag); // Put flag to address globals + 0x200
  while( true ) {
    iVar1 = fgetln(stdin,input_user);
    local_28 = (char *)(long)iVar1;
    pcVar2 = strtok(local_28,"?"); // Delimiter ?
    local_30 = (char *)(long)(int)pcVar2; // save string before delimiter to local_30
    iVar1 = strcmp(local_30,"SERVER, ARE YOU STILL THERE"); // check if the string equal to
    if (iVar1 != 0) {
      puts("MALFORMED REQUEST");
      exit(-1);
    }
    pcVar2 = strtok((char *)0x0,"\""); // Delimiter "
    local_30 = (char *)(long)(int)pcVar2; // save string before delimiter to local_30
    iVar1 = strcmp(local_30," IF SO, REPLY "); // check if the string equal to
    if (iVar1 != 0) break;
    pcVar2 = strtok((char *)0x0,"\""); // Delimiter "
    local_30 = (char *)(long)(int)pcVar2; // save string before delimiter to local_30
    length = strlen(local_30); // check the len of that string
    memcpy(globals,local_30,length); // put the string to addres globals
    pcVar2 = strtok((char *)0x0,"("); // Delimiter (
    local_30 = (char *)(long)(int)pcVar2; // save string before delimiter to local_30
    pcVar2 = strtok((char *)0x0,")"); // Delimiter )
    local_30 = (char *)(long)(int)pcVar2; // save string before delimiter to local_30
    __isoc99_sscanf(local_30,"%d LETTERS",&local_34); // local_30 as input to local_34
    globals[local_34] = 0; // set value on globals[local_34] to null
    uVar3 = (ulong)local_34;
    length = strlen(globals); 
    if (length < uVar3) { // we need to make sure null byte placed right after the last char on flag
      puts("NICE TRY");
      exit(-1);
    }
    puts(globals); // print value on globals until reach null byte
  }
  puts("MALFORMED REQUEST");
  exit(-1);
}

// Since our input located before flag store we can make our input to fill the gap until the flag store
// the put null byte after our flag

