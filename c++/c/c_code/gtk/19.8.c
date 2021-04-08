#include <gtk/gtk.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;
  char title[]="button example.";
  char txt[]="button .";
  char txt2[50];
  gtk_init (&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),300,150);
  button=gtk_button_new_with_label(txt);
  gtk_container_add(GTK_CONTAINER(window),button);
  strcpy(txt2,gtk_button_get_label(GTK_BUTTON(button)));
  strcat(txt2,"\n append string.");
  gtk_button_set_label(GTK_BUTTON(button),txt2);
  gtk_widget_show(window);
  gtk_widget_show(button);
  gtk_main ();
  return 0;
}
