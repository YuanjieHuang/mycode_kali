#include <gtk/gtk.h>
#include <time.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *txt;
  char title[]="entry example";
  gtk_init (&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),300,150);
  txt=gtk_entry_new();
  gtk_container_add(GTK_ENTRY(window),txt);
  gtk_widget_show(window);
  gtk_widget_show(txt);
  gtk_main ();
  return 0;
}
