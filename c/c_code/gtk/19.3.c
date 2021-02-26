#include <gtk/gtk.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  char title[]="set size , set position.";
  gtk_init (&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),400,200);
  gtk_widget_set_uposition (GTK_WINDOW (window),200,200);
  gtk_widget_show(window);
  gtk_main ();
  return 0;
}
