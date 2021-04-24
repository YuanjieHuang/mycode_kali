#include <gtk/gtk.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *vbox1;
  GtkWidget *button;
  GtkWidget *label;
  GtkWidget *entry;
  char title[]="vbox example";
  gtk_init (&argc, &argv);
  
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),350,150);
  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  entry=gtk_entry_new();
  label=gtk_label_new("this is a label");
  button=gtk_button_new_with_label(" OK ");
  gtk_widget_show (button);
  gtk_widget_show (label);
  gtk_widget_show (entry);
  
  gtk_container_add (GTK_CONTAINER (window), vbox1);  
  gtk_box_pack_start (GTK_BOX (vbox1),label, TRUE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1),button, TRUE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1),entry, TRUE, FALSE, 0);
 
  gtk_widget_show(window);  
  gtk_main ();
  return 0;
}
