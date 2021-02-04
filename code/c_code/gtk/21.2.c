#include <gtk/gtk.h>
void on_clicked(GtkWidget *widget, gpointer data)
{   
	char txt[]="this is the new title .";
	gtk_window_set_title (GTK_WINDOW (data),txt);    
}

int main(int argc, char **argv)
{
  GtkWidget *window;
  GtkWidget *button;
  char title[]="set title";
  gtk_init(&argc, &argv);
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  gtk_window_set_default_size (GTK_WINDOW (window), 250, 150);
  button=gtk_button_new_with_label("set title .");
  g_signal_connect(G_OBJECT(button), "clicked",  G_CALLBACK(on_clicked), window);
  gtk_container_add(GTK_CONTAINER(window), button);
  gtk_widget_show_all(window);
  gtk_main ();
  return 0;
}
