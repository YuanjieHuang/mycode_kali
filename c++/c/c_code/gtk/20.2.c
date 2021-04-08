#include <gtk/gtk.h>
#include <time.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *txt;
  GtkWidget *table;
  GtkWidget *button;
  GtkWidget *label;
  char title[]="table example";
  gtk_init (&argc, &argv);
  
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),350,150);
  table=gtk_table_new(2,2,FALSE);
  button=gtk_button_new_with_label("OK");
  label=gtk_label_new("this is a label");
  txt=gtk_entry_new();
  
  gtk_container_add(GTK_ENTRY(window),table);
  gtk_table_attach (GTK_TABLE (table), button, 0, 1, 0, 1,
                      (GtkAttachOptions) (GTK_FILL),
                      (GtkAttachOptions) (0), 0,0);
  gtk_table_attach (GTK_TABLE (table), label, 1, 2, 0, 1,
                      (GtkAttachOptions) (GTK_FILL),
                      (GtkAttachOptions) (0), 0,0);        
  gtk_table_attach (GTK_TABLE (table), txt, 0, 1, 1, 2,
                      (GtkAttachOptions) (GTK_FILL),
                      (GtkAttachOptions) (0), 0,0);                
  
  gtk_widget_show(window);
  gtk_widget_show(table);
  gtk_widget_show(txt);
  gtk_widget_show(button);
  gtk_widget_show(label);
  
  gtk_main ();
  return 0;
}
