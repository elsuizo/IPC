/* -------------------------------------------------------------------------
@file ipc.c

@date 07/28/17 00:33:25
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

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
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../inc/ipc.h"

/**
 * @brief Read image from disk
 *
 * @param path_to_image: String pointer representing the path to the image
 *
 * @return: struct IpcImage
 */
struct IpcImage
ipc_read_Image(const char* path_to_image) {
   struct IpcImage result = {};
   result.data = stbi_load(path_to_image, &result.width, &result.height, 0, 3);
   return result;
}

struct IpcImage
ipc_read_Image_gray(const char* path) {
   struct IpcImage result = {};
   result.data = stbi_load(path, &result.width, &result.height, 0, 1);
   return result;
}

void
ipc_write_Image(const char* path, struct IpcImage* image) {

   stbi_write_png(path, image->width, image->height, 3, image->data, 0);
}

void
ipc_write_Image_gray(const char* path, struct IpcImage* image_gray) {

   stbi_write_png(path, image_gray->width, image_gray->height, 1, image_gray->data, 0);
}

struct IpcImage
sum_Images_gray(const struct IpcImage* image1, const struct IpcImage* image2) {
   /* check if the two images  */
   if ((image1->width == image2->width) && (image1->height == image2->height)) {
      int i, j;
      /* allocate image data output */
      uchar* data_output = (uchar*)malloc(sizeof(uchar) * image1->width * image2->height);
      /* initialize the struct */
      struct IpcImage result = {.width = image1->width, .height = image1->height, .data = data_output};
      /* perform the sum */
      for (i = 0; i < image1->height; ++i) {
         for (j = 0; j < image1->width; ++j) {
            result.data[(i * image1->width + j)] = image1->data[(i * image1->width + j)]
                                                         + image1->data[(i * image1->width + j)];
            }
         }
      return(result);

   } else {
      printf("Erorr the images dont have the same dimentions");
      exit(1);
   }
}

