/* -------------------------------------------------------------------------
@file test.c

@date 07/28/17 00:25:59
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail
Test file
Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "../inc/ipc.h"


int main(void)
{
   struct IpcImage img1 = {};
   char* path_img1 = "/home/elsuizo/Pictures/back.png";
   img1 = ipc_read_Image(path_img1);
   return 0;
}

