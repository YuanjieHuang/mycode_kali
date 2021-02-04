#include <gtk/gtk.h>
#include <time.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *label;
  char title[]="label example:time";
  char txt[50]="time:\n";
  char time_txt[50];
  time_t timep;
  gtk_init (&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),300,150);
  label=gtk_label_new("");
  gtk_container_add(GTK_CONTAINER(window),label);
  
  time (&timep);
  strcpy(time_txt,asctime(gmtime(&timep)));
  strcat(txt,time_txt);
  gtk_label_set_text(GTK_LABEL(label),txt);
  
  gtk_widget_show(window);
  gtk_widget_show(label);
  gtk_main ();
  return 0;
}
