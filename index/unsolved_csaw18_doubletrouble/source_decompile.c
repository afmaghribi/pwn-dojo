undefined4 sortArray(int *input_size,int stored_array)

{
  int i;
  int j;
  undefined8 tmp;
  
  for (i = 0; i < *input_size; i = i + 1) {
    for (j = 0; j < *input_size + -1; j = j + 1) {
      if ((stored_array[j+1]) < (stored_array[j)) {
        tmp = stored_array[j];
        stored_array[j] = stored_array[j+1];
        stored_array[j+1] = tmp;
      }
    }
  }
  return 1;
}


// how to know value param 3-6
// br *0x080496fa -> call   0x8049309 <findArray>
// Since binary 32 bit, arg is stored on stack. So check the stack
// 0xffffcc40│+0x0000: 0xffffcc6c  →  param 1
// 0xffffcc44│+0x0004: 0xffffcc78  →  param 2
// 0xffffcc48│+0x0008: 0x00000000  →  param 3
// 0xffffcc4c│+0x000c: 0xc0590000  →  param 4
// 0xffffcc50│+0x0010: 0x00000000  →  param 5
// 0xffffcc54│+0x0014: 0xc0240000  →  param 6
// param 4 + 3 => 0xc059000000000000 => ./hex2dbl 0xc059000000000000 = -100
// param 6 + 5 => 0xc024000000000000 => ./hex2dbl 0xc059000000000000 = -10
// So we can write the func as below

int findArray(int *input_size,int stored_value, double param_3, double param_4)

// param_3 -> -100
// param_4 -> -10

{
  int arrayLen;
  
  arrayLen = *input_size;
  while( *input_size < 2 * arrayLen ) {// https://github.com/NationalSecurityAgency/ghidra/issues/3954
    if (((( -100 < stored_value[input_size - arrayLen])) < -10))
        break;
        return *input_size - arrayLen; // If there is negative number will immediately stop looping, so we can control how much we want increament size. return value is saved as index for fav number, but input_size stay changed
    *input_size = *input_size + 1; // increament input_size +1. 
  }
  *input_size = arrayLen; 
  return 0;
}