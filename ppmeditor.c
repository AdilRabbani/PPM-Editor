              
//   AUTHOR NAME : ADIL RABBANI       MERIT NO. 3103          

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

                                                            // FUNCTION PROTOTYPES
int negate_red(int *red);
int negate_green(int *green);
int negate_blue(int *blue);
int flatten_red(int *red);
int flatten_green(int *green);
int flatten_blue(int *blue);
int grey_scale(int *red, int *green, int *blue);
int extreme_contrast(int *red, int *green, int *blue);

int main()
{
	int i = 0;
	int rows, columns, max_color_value, j = 1,avg_pixel,sum_pixel,red,green,blue;
	char character[5],img_file[50], output_img_file[50], choice_1, choice_2, choice_3, choice_4, choice_5, choice_6, choice_7, choice_8;
	FILE *fp_img;                                                                                   // A file pointer pointing to the image that would be read.
	FILE *fp_img_out;                                                                             // A file pointer pointing to the image that would be used to write after editing.

	system("COLOR 3F");                                                                            // Just a change of color to the console.
	printf("\t+-------------------------------------------------+\n");                     
	printf("\t|                                                 |\n");
	printf("\t|         Portable Pixmap (PPM) Image Editor      |\n");
	printf("\t|          ADIL RABBANI AND HASHIR SALAM          |\n");
	printf("\t|                                                 |\n");
	printf("\t+-------------------------------------------------+\n\n\n");

	printf("Enter name of image file : ");                                                      // Asking the user to type the name of the ppm image file to be read.
	gets(img_file);

	printf("\n\n");

	printf("Enter name of output file : ");                                                    // Asking the user to type the name of the ppm image file to be written.
	gets(output_img_file);

	fp_img = fopen(img_file, "r");                                                            // Opening the ppm file to be read.
	fp_img_out = fopen(output_img_file, "w");                                                   // Opening the ppm file to be written.

	printf("\n\n");

	printf("               Here are your choices:\n\n");                                       // Menu for the user.
	printf("   [1] convert to greyscale\n");
	printf("   [2] negative of red          [3] negative of green\n");
	printf("   [4] negative of blue         [5] just the reds\n");
	printf("   [6] just the greens          [7] just the blues\n");
	printf("   [8] extreme contrast\n\n");

	printf("   Do you want [1]? (y/n) ");                                                         // Asking the user for converting image to grey scale
	scanf(" %c", &choice_1);

	printf("\n");

	printf("   Do you want [2]? (y/n) ");                                                        // Asking the user for converting the image to a negative of red.
	scanf(" %c", &choice_2);

	printf("\n");

	printf("   Do you want [3]? (y/n) ");                                                          // Asking the user for converting the image to a negative of green.
	scanf(" %c", &choice_3);

	printf("\n");

	printf("   Do you want [4]? (y/n) ");                                                       // Asking the user for converting the image to a negative of blue.
	scanf(" %c", &choice_4);

	printf("\n");

	printf("   Do you want [5]? (y/n) ");                                                           // Asking the user for converting the image to just the red pixels.
	scanf(" %c", &choice_5);

	printf("\n");

	printf("   Do you want [6]? (y/n) ");                                                         // Asking the user for converting the image to just the green pixels
	scanf(" %c", &choice_6);

	printf("\n");

	printf("   Do you want [7]? (y/n) ");                                                     // Asking the user for converting the image to just the blue pixels.
	scanf(" %c", &choice_7);

	printf("\n");

	printf("   Do you want [8]? (y/n) ");                                                          // Asking the user for converting the image to extreme contrast.
	scanf(" %c", &choice_8);

	printf("\n\n");
	if (fp_img == NULL)                                                                          // If the image is empty show a message and exit the program.
	{
		perror("Aie Aie Aie, error reading file.");
		exit(EXIT_FAILURE);
	}

	else{

		while (j <= 2)                                                                           // Scanning and Writing the two characters P and 3 for the header of the image
		{
			fscanf(fp_img, "%c", &character[j]);
			fprintf(fp_img_out, "%c", character[j]);
			++j;
		}

		fscanf(fp_img, "   %d %d   ", &rows, &columns);                                       // Scanning and Writing the rows and columns that are included in the header of the ppm image file.
		fprintf(fp_img_out, "   %d %d   ", rows, columns);

		fscanf(fp_img, "  %d  ", &max_color_value);                                      // Scanning and Writing the max color value, also included in the header of the ppm image file.
		fprintf(fp_img_out, "  %d  ", max_color_value);


		while (!feof(fp_img)){                                                        // Loop for scanning and writing the whole image using EOF.

			fscanf(fp_img, "    %d %d %d    ", &red, &green, &blue);                 // Start scanning red, green and blue pixels.

			if (choice_1 == 'y' || choice_1 == 'Y')                                  // If choice_1 is 'y' or 'Y'.
			{
				grey_scale(&red, &green, &blue);                                     // Calling function grey_scale.
			}


			if (choice_2 == 'y' || choice_2 == 'Y')                                   // If choice_3 is 'y' or 'Y'.
			{
				negate_red(&red);                                                   // Calling function negate_red.
			}


			if (choice_3 == 'y' || choice_3 == 'Y')                                      // If choice_4 is 'y' or 'Y'.
			{
				negate_green(&green);                                                       // Calling function negate_green.
			}


			if (choice_4 == 'y' || choice_4 == 'Y')                                            // If choice_5 is 'y' or 'Y'.
			{
				negate_blue(&blue);                                                            // Calling function negate_blue.
			}



			if (choice_5 == 'y' || choice_5 == 'Y')                                                // If choice_6 is 'y' or 'Y'.
			{
				flatten_red(&red);                                                                // Calling function flatten_red.
			}


			if (choice_6 == 'y' || choice_6 == 'Y')                                                 // If choice_7 is 'y' or 'Y'.
			{
				flatten_green(&green);                                                              // Calling function flatten_green.
			}


			if (choice_7 == 'y' || choice_7 == 'Y')                                                    // If choice_8 is 'y' or 'Y'.
			{
				flatten_blue(&blue);                                                                   // Calling function flatten_blue.
			}


			if (choice_8 == 'y' || choice_8 == 'Y')                                                    // If choice_9 is 'y' or 'Y'.
			{
				extreme_contrast(&red, &green, &blue);                                                // Calling function extreme_contrast.
			}


			fprintf(fp_img_out, "    %d %d %d    ", red, green, blue);                                  // Writing red, green, blue pixels of the image with editing.

			++i;
		}
		fclose(fp_img);                                                                                  // Closing the 'read' image.
		fclose(fp_img_out);                                                                              // Closing the 'written' image.
	}

	printf("\n\n");

	printf("  %s is created!", output_img_file);

	printf("\n\n");

	return 0;
}


int negate_red(int *red)
{
	*red = 255 - *red;                                     // Red pixel = 255 - Red pixel.

	return *red;                                           // returning red pixel after editing.

}

int negate_green(int *green)
{
	*green = 255 - *green;                                  // Green pixel = 255 - Green pixel.

	return *green;                                           // returning green pixel after editing.

}

int negate_blue(int *blue)
{
	*blue = 255 - *blue;                                          // Blue pixel = 255 - Blue pixel.

	return *blue;                                               // returning blue pixel after editing.

}

int flatten_red(int *red)
{
	if (*red > 0)                                                    // If red pixel is greater than 0.
	{
		*red = 0;                                                    // Red pixel = 0.
	}

	return *red;
}

int flatten_green(int *green)
{
	if (*green > 0)                                                   // If green pixel is greater than 0.
	{
		*green = 0;                                                    // Green pixel = 0..
	}

	return *green;
}

int flatten_blue(int *blue)
{
	if (*blue > 0)                                                      // If blue pixel is greater than 0.
	{
		*blue = 0;                                                      // Blue pixel = 0.
	}

	return *blue;
}


int grey_scale(int *red, int *green, int *blue)
{
	int sum_pixel = 0;                                                      // An int for taking the sum of the red, green, blue pixels.
	int avg_pixel;                                                            // An int for taking the average of the red, green, blue pixels.

	sum_pixel = *red + *green + *blue;                                        // Taking their sum.

	avg_pixel = sum_pixel / 3;                                                 // Taking their average.
	*red = avg_pixel;                                                          // Assigning the average value to red pixel.
	*green = avg_pixel;                                                         // Assigning the average value to green pixel.
	*blue = avg_pixel;                                                          // Assigning the average value to blue pixel.

	return *red;                                                                 // Returning red pixel after assigning average value.
	return *green;                                                               // Returning green pixel after assigning average value.
	return *blue;                                                                // Returning blue pixel after assigning average value.
}

int extreme_contrast(int *red, int *green, int *blue)
{
	if (*red > 128)                                                                  // If red pixel is greater than the half of the color depth.
	{
		*red = 255;                                                                   // Red pixel = 255.
	}

	else if (*red < 128)                                                              // If red pixel is less than half of the color depth.
	{
		*red = 0;                                                                      // Red pixel = 0.
	}

	if (*green < 128)                                                                  // If green pixel is less than half of the color depth.
	{
		*green = 0;                                                                        // Green pixel = 0.
	}

	else if (*green > 128)                                                                 // If green pixel is greater than the half of the color depth.
	{
		*green = 255;                                                                       // Green pixel = 255.
	}

	if (*blue < 128)                                                                      // If blue pixel is less than half of the color depth.
	{
		*blue = 0;                                                                        // Blue pixel = 0.
	}

	else if (*blue > 128)                                                                  // If blue pixel is greater than the half of the color depth.
	{
		*blue = 255;                                                                         // Blue pixel = 255.
	}

	return *red;                                                                           // Returning red pixel after editing.
	return *green;                                                                          // Returning green pixel after editing.
	return *blue;                                                                           // Returning blue pixel after editing.
}


