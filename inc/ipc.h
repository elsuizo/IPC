/* -------------------------------------------------------------------------
@file ipc.h

@date 07/28/17 00:29:00
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Image processing routines in C
@detail

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
#ifndef IPC_H
#define IPC_H
/*-------------------------------------------------------------------------
 *                        includes
 -------------------------------------------------------------------------*/
/* NOTE(elsuizo:2017-07-28):estas son funciones mas generales */
/* #include "../inc/stb.h" */
#include "../inc/stb_image.h"
#include "../inc/stb_image_write.h"

/*-------------------------------------------------------------------------
 *                        defines
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
 *                        typedef
 -------------------------------------------------------------------------*/
typedef unsigned char uchar;

/*-------------------------------------------------------------------------
 *                        custom datatypes
 -------------------------------------------------------------------------*/
struct IpcImage {
   int width;
   int height;
   uchar* data;
};
/*-------------------------------------------------------------------------
 *                        functions prototypes
-------------------------------------------------------------------------*/
struct IpcImage
ipc_read_Image(const char* path_to_image);

struct IpcImage
ipc_read_Image_gray(const char* path_to_image);

void
ipc_write_Image(const char* path, struct IpcImage* image);

void
ipc_write_Image_gray(const char* path, struct IpcImage* image_gray);

struct IpcImage
sum_Images_gray(const struct IpcImage* image1, const struct IpcImage* image2);


#endif /* end of ipc code */



