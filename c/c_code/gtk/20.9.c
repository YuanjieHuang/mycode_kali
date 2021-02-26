#include <gtk/gtk.h>
#include <time.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *txt;
  GtkWidget *txt2;
  GtkWidget *table;
  GtkWidget *button;
  GtkWidget *label;
  GtkWidget *label2;
  char title[]="user login window";
  gtk_init (&argc, &argv);
  
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_widget_set_usize(GTK_WINDOW (window),350,100);
  table=gtk_table_new(3,2,FALSE);
  button=gtk_button_new_with_label("   login   ");
  label=gtk_label_new("  username:  ");
  label2=gtk_label_new("  password:  ");
  txt=gtk_entry_new();
  txt2=gtk_entry_new();
  
  gtk_container_add(GTK_ENTRY(window),table);
                      
  gtk_table_attach (GTK_TABLE (table), label, 0, 1, 0, 1,
                      (GtkAttachOptions) (GTK_EXPAND),
                      (GtkAttachOptions) (0), 0,0);
  gtk_table_attach (GTK_TABLE (table), txt, 1, 2, 0, 1,
                      (GtkAttachOptions) (GTK_EXPAND),
                      (GtkAttachOptions) (0), 0,0);
  gtk_table_attach (GTK_TABLE (table), label2, 0, 1, 1, 2,
                      (GtkAttachOptions) (GTK_EXPAND),
                      (GtkAttachOptions) (0), 0,0);
  gtk_table_attach (GTK_TABLE (table), txt2, 1, 2, 1, 2,
                      (GtkAttachOptions) (GTK_EXPAND),
                      (GtkAttachOptions) (0), 0,0); 
  gtk_table_attach (GTK_TABLE (table), button, 1, 2, 2, 3,
                      (GtkAttachOptions) (GTK_EXPAND),
                      (GtkAttachOptions) (0), 0,0);
 
  
  gtk_widget_show(window);
  gtk_widget_show(table);
  gtk_widget_show(txt);
  gtk_widget_show(txt2);
  gtk_widget_show(button);
  gtk_widget_show(label);
  gtk_widget_show(label2);

  
  gtk_main ();
  return 0;
}
