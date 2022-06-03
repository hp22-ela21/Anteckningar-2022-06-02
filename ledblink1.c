/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <unistd.h> /* Innehåller sleep och usleep. */

/*****************************************************
* file_write: Skriver en rad med text fill en fil.
*             Ingående argument filepath utgörs av
*             själva filsökvägen, medan data utgörs
*             av den text som skall skrivas.
*****************************************************/
static void file_write(const char* filepath, const char* data)
{
   FILE* fstream = fopen(filepath, "w");

   if (!fstream)
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
   }
   else
   {
      fprintf(fstream, "%s", data);
      fclose(fstream);
   }

   return;
}

/******************************************************
* main: Ansluter två lysdioder till PIN 17 samt 22
*       Dessa PINs reserveras och sätts till utportar.
*       Lysdiodena blinkar var 50:e millisekund.
*******************************************************/
int main(void)
{
   file_write("/sys/class/gpio/export", "17");
   file_write("/sys/class/gpio/export", "22");

   file_write("/sys/class/gpio/gpio17/direction", "out");
   file_write("/sys/class/gpio/gpio22/direction", "out");

   while (1)
   {
      file_write("/sys/class/gpio/gpio17/value", "1");
      file_write("/sys/class/gpio/gpio22/value", "0");
      usleep(50 * 1000);
      file_write("/sys/class/gpio/gpio17/value", "0");
      file_write("/sys/class/gpio/gpio22/value", "1");
      usleep(50 * 1000);
   }
   return 0;
}
