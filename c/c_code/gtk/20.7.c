#include <gtk/gtk.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *hpaned1;
  char title[]="hpaned example";
  
  gtk_init (&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),350,150);
  
  hpaned1 = gtk_hpaned_new ();
  gtk_widget_show (hpaned1);
  gtk_container_add (GTK_CONTAINER (window), hpaned1);
  gtk_paned_set_position (GTK_PANED (hpaned1), 62);
  
  gtk_widget_show(window);  
  gtk_main ();
  return 0;
}
