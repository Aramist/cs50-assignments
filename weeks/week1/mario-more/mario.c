#include <stdio.h>


void makePyramid(int height) {
  for (int line = 1; line <= height; line++){
    // total width is (height  +1) * 2
    // num spaces on each side is height - line
    // num spaces in center is 2
    for (int s = 0; s < height - line; s++) printf(" ");
    for (int c = 0; c < line; c++) printf("#");
    printf("  ");
    for (int c = 0; c < line; c++) printf("#");
    printf("\n");
  }
}
    

int main(void) {
  int height = 0;
  do {
	  printf("Height: ");
	  scanf("%i", &height);
  } while ( height < 1 || height > 8);
  
  makePyramid(height);
}
