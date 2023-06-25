#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zip.h>
#include "usage_case.h"

 
void cas_d_usage()
{
  printf(
      " Usage:./zip [OPTION] ... [FILE]....\n"
      "Options:\n"

      "        -h,--help                  Show this help\n"
      "        -o, --open                 Open a zip file for browsing\n"
      "        -b, --bruteforce           Try to bruteforce the password\n"
      "        -d, --dictionary=FILE      Try to bruteforce the password with a dictionary\n"
      "        -p, --password=PASSWORD    Use this password\n"
      "        -e, --extract=FILE Extract this file\n"
      "        -i, --include=FILE Include this file\n"
      "\n");
}