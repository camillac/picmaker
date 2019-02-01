#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int distance(int x, int y){
  return (int)sqrt(pow((double)(x-250), 2) + pow((double)(y-250),2));
}

int distance_sphere(int x, int y){
  return (int)sqrt(pow((double)(x-200), 2) + pow((double)(y-200),2));
}

int main(){
  char * line = calloc(sizeof(char), 16);
  int fd;
  int rgb[3];

  fd = open("meow.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  sprintf(line, "P3 500 500 255\n");
  write(fd, line, strlen(line));

  int counter = 0;
  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 500; j++){
      if (distance(i,j) < 150) {
        rgb[0] = (256-distance_sphere(i,j)) % 256;
        rgb[1] = (256-distance_sphere(i,j)) % 256;
        rgb[2] = (256-distance_sphere(i,j)) % 256;

        if (i == 200 && j == 200){
          rgb[0] = 256;
          rgb[1] = 256;
          rgb[2] = 256;
        }
      }

      else {
        rgb[0] = 0;
        rgb[1] = 0;
        rgb[2] = 0;
      }
      sprintf(line, "%d %d %d ", rgb[0], rgb[1], rgb[2]);
      write(fd, line, strlen(line));
    }
    counter+=10;
  }
  close(fd);
}
