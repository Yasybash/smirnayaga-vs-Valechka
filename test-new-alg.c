
/*
  File for 'test-new-alg' task implementation.
*/

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"
#include "threads/synch.h"
#include "devices/timer.h"

void ispolnenie(void)
{
  while (thread_current ()->CPU_BURST != 0);
  msg("");
}

void init(void)
{
  set_fcfs = true;
  global_nomer = 1;
}

void test_new_alg(void) 
{
  init();

  thread_current()->nomer = global_nomer - 1;

  thread_create_fcfs ("proc0", 5, 8, ispolnenie, NULL);
  thread_create_fcfs ("proc1", 4, 1, ispolnenie, NULL);
  thread_create_fcfs ("proc2", 12, 4, ispolnenie, NULL);
  thread_create_fcfs ("proc3", 63, 4, ispolnenie, NULL);
  thread_create_fcfs ("proc4", 60, 1, ispolnenie, NULL);
  thread_create_fcfs ("proc5", 54, 7, ispolnenie, NULL);

  msg("vse potoky sozdany");
  msg("seychas dolzhno nachatsya ispolneniye");
  
  thread_current()->nomer = 32;
  thread_yield();
  msg("eto konec testa");
}
