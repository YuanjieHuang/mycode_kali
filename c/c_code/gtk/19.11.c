#include <gtk-3.0/gtk/gtk.h>
#include <time.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *txt;
  GtkWidget *table;
  char title[]="table example";
  gtk_init (&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),300,150);
  table=gtk_table_new(2,2,TRUE);
 /* txt=gtk_entry_new();*/
  gtk_container_add(GTK_ENTRY(window),table);
  gtk_widget_show(window);
  gtk_widget_show(table);
  /*gtk_widget_show(txt);*/
  gtk_main ();
  return 0;
}
