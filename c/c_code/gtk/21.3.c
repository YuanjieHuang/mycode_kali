#include <gtk/gtk.h>
#include <stdlib.h>
int i ;
GtkWidget *window;
GtkWidget *button;

void on_clicked(GtkWidget *widget, gpointer data)
{  
	
	char a[20],b[20];
	i++;
	gcvt((float)i,3,a);
	strcat(a, " times");
	strcpy(b,"you have clicked ");
	strcat(b,a);

	gtk_window_set_title (GTK_WINDOW (window),b);    
}

int main(int argc, char **argv)
{
  char title[]="button";
  gtk_init(&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_window_set_default_size (GTK_WINDOW (window), 250, 150);
  button=gtk_button_new_with_label(" click ");
  g_signal_connect(G_OBJECT(button), "clicked",  G_CALLBACK(on_clicked), window);
  gtk_container_add(GTK_CONTAINER(window), button);
  gtk_widget_show_all(window);
  gtk_main ();
  return 0;
}
