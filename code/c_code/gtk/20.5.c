#include <gtk/gtk.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *vbox1;
  char title[]="vbox example";
  gtk_init (&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),350,150);
  
  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (window), vbox1);  
  
  gtk_widget_show(window);  
  gtk_main ();
  return 0;
}
