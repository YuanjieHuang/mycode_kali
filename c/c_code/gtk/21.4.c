#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

GtkWidget *window;
GtkWidget *txt1;
GtkWidget *txt2;
GtkWidget *table;
GtkWidget *button;
GtkWidget *label;

void on_clicked(GtkWidget *widget, gpointer data)
{
	char a1[10];
	char a2[10];
	char a3[10];
	float a,b,c;
	 
	strcpy(a1,gtk_entry_get_text(GTK_ENTRY(txt1))); 
	strcpy(a2,gtk_entry_get_text(GTK_ENTRY(txt2))); 
	
	a=atof(a1);
	b=atof(a2);
	c=a+b;
 
	gcvt(c,7,a3);
	gtk_label_set_text(GTK_LABEL(label),a3);
}
   
int main(int argc, char **argv)
{
  char title[]="my window";
  gtk_init(&argc, &argv);
  
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_window_set_default_size (GTK_WINDOW (window), 250, 300);
  g_signal_connect(G_OBJECT(window), "delete_event",  G_CALLBACK(gtk_main_quit), NULL);
  
  txt1 = gtk_entry_new ();
  gtk_widget_show (txt1);  
  txt2 = gtk_entry_new ();
  gtk_widget_show (txt2);    
  button=gtk_button_new_with_label("OK");
  gtk_widget_show (button);
  label=gtk_label_new(" Result. ");
  gtk_widget_show (label);  
  
  table = gtk_table_new (4, 1, FALSE);
  gtk_widget_show (table);
  gtk_container_add (GTK_CONTAINER (window), table);

  gtk_table_attach (GTK_TABLE (table), txt1,0, 1,0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 11, 11); 
                    
  gtk_table_attach (GTK_TABLE (table), txt2,0, 1,1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 11,11);  
  gtk_table_attach (GTK_TABLE (table), button,0, 1,2,3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 11,11);                 
     
  gtk_table_attach (GTK_TABLE (table), label,0, 1,3,4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 11,11);
                                                     
  g_signal_connect(G_OBJECT(button), "clicked",  G_CALLBACK(on_clicked),NULL);
  gtk_widget_show_all(window);
  gtk_main ();
  return 0;
}
