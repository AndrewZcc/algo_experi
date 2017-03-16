#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE = 10;

int buffer[BUFFER_SIZE];
static int count  = 0;


