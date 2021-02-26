#include <stdlib.h>
#include <gtk/gtk.h>
float a,b ;/*定义两个参于运算的变量。*/
int hasdot;/*是否有小数点。*/
int method;/*运算方法。*/

  GtkWidget *window;/*这一部分是定义元件。*/
  GtkWidget *table1;
  GtkWidget *entry1;
  GtkWidget *table2;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;
  GtkWidget *button6;
  GtkWidget *button7;
  GtkWidget *button8;
  GtkWidget *button9;
  GtkWidget *button10;
  GtkWidget *button11;
  GtkWidget *button12;
  GtkWidget *button13;
  GtkWidget *button14;
  GtkWidget *button15;
  GtkWidget *button16;
  
void input(GtkWidget *widget, gpointer data)
{
	gtk_entry_append_text(GTK_ENTRY(entry1),gtk_button_get_label(widget));
}

void jia(GtkWidget *widget, gpointer data)
{
	char num[20];
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(entry1)));
	if(a==0)
	{
	   gtk_entry_set_text(GTK_ENTRY(entry1),"");
	   a=atof(num);
	}
	else
	{
	    b=atof(num);	 
	    switch(method)
	    {
		   case  0 :
		      a=a+b; break ;
		   case 1:
		      a=a-b; break ; 
		   case  2 :
		      a=a*b; break ;
		   case  3 :
		      a=a/b; break ;
	     }
	gcvt(a,5,num);
	b=0;
	method=0;
	gtk_entry_set_text(GTK_ENTRY(entry1),num);
	}
	hasdot=0;
}
void jian(GtkWidget *widget, gpointer data)
{
	method=1;
   	char num[20];
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(entry1)));
	if(a==0)
	{
	   gtk_entry_set_text(GTK_ENTRY(entry1),"");
	   a=atof(num);
	}
	else
	{
		b=atof(num);
	}
	hasdot=0;
}

void cheng(GtkWidget *widget, gpointer data)
{
    method=2;
    char num[20];
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(entry1)));
	if(a==0)
	{
	   gtk_entry_set_text(GTK_ENTRY(entry1),"");
	   a=atof(num);
	}
	else
	{
		b=atof(num);
	}
	hasdot=0;
}
void chu(GtkWidget *widget, gpointer data)
{
    method=3;
    char num[20];
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(entry1)));
	if(a==0)
	{
	gtk_entry_set_text(GTK_ENTRY(entry1),"");
	a=atof(num);
	
	}
	else
	{
		b=atof(num);
	}
	hasdot=0;
}

void dot(GtkWidget *widget, gpointer data)
{  
	if(hasdot==0)
	{
	   gtk_entry_append_text(GTK_ENTRY(entry1),gtk_button_get_label(widget));
	   hasdot=1;
	}	
}

void clear(GtkWidget *widget, gpointer data)
{   
	gtk_entry_set_text(GTK_ENTRY(entry1),"");
	hasdot=0;
	a=0;
	b=0;
	method=0;
}

void interface()
{	
  char title[]="mywin";
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window),title);
  
  
  table1 = gtk_table_new (2, 1, FALSE);
  gtk_widget_show (table1);
  gtk_container_add (GTK_CONTAINER (window), table1);
  
  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_table_attach (GTK_TABLE (table1), entry1, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
                    
  table2 = gtk_table_new (4, 4, FALSE);
  gtk_widget_show (table2);
  gtk_table_attach (GTK_TABLE (table1), table2, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
                    
 button1 = gtk_button_new_with_mnemonic ("1");
  gtk_widget_show (button1);
  gtk_table_attach (GTK_TABLE (table2), button1, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (button1, 50, 30);

  button2 = gtk_button_new_with_mnemonic ("2");
  gtk_widget_show (button2);
  gtk_table_attach (GTK_TABLE (table2), button2, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (button2, 50, 30);
  

  button3 = gtk_button_new_with_mnemonic ("3");
  gtk_widget_show (button3);
  gtk_table_attach (GTK_TABLE (table2), button3, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (button3, 50, 30);

  button4 = gtk_button_new_with_mnemonic ("4");
  gtk_widget_show (button4);
  gtk_table_attach (GTK_TABLE (table2), button4, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button5 = gtk_button_new_with_mnemonic ("5");
  gtk_widget_show (button5);
  gtk_table_attach (GTK_TABLE (table2), button5, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button6 = gtk_button_new_with_mnemonic ("6");
  gtk_widget_show (button6);
  gtk_table_attach (GTK_TABLE (table2), button6, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button7 = gtk_button_new_with_mnemonic ("7");
  gtk_widget_show (button7);
  gtk_table_attach (GTK_TABLE (table2), button7, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button8 = gtk_button_new_with_mnemonic ("8");
  gtk_widget_show (button8);
  gtk_table_attach (GTK_TABLE (table2), button8, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button9 = gtk_button_new_with_mnemonic ("9");
  gtk_widget_show (button9);
  gtk_table_attach (GTK_TABLE (table2), button9, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button10 = gtk_button_new_with_mnemonic ("0");
  gtk_widget_show (button10);
  gtk_table_attach (GTK_TABLE (table2), button10, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button11 = gtk_button_new_with_mnemonic (".");
  gtk_widget_show (button11);
  gtk_table_attach (GTK_TABLE (table2), button11, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button12 = gtk_button_new_with_mnemonic ("+  =");
  gtk_widget_show (button12);
  gtk_table_attach (GTK_TABLE (table2), button12, 2, 3, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button13 = gtk_button_new_with_mnemonic ("-");
  gtk_widget_show (button13);
  gtk_table_attach (GTK_TABLE (table2), button13, 3, 4, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (button13, 50, -1);

  button14 = gtk_button_new_with_mnemonic ("X");
  gtk_widget_show (button14);
  gtk_table_attach (GTK_TABLE (table2), button14, 3, 4, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button15 = gtk_button_new_with_mnemonic ("/");
  gtk_widget_show (button15);
  gtk_table_attach (GTK_TABLE (table2), button15, 3, 4, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  button16 = gtk_button_new_with_mnemonic ("CE");
  gtk_widget_show (button16);
  gtk_table_attach (GTK_TABLE (table2), button16, 3, 4, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
}
void addsignal()
{
   g_signal_connect(G_OBJECT(button1), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button2), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button3), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button4), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button5), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button6), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button7), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button8), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button9), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button10), "clicked",  G_CALLBACK(input),NULL);
   g_signal_connect(G_OBJECT(button11), "clicked",  G_CALLBACK(dot),NULL);
   g_signal_connect(G_OBJECT(button12), "clicked",  G_CALLBACK(jia),NULL);
   g_signal_connect(G_OBJECT(button13), "clicked",  G_CALLBACK(jian),NULL);
   g_signal_connect(G_OBJECT(button14), "clicked",  G_CALLBACK(cheng),NULL);
   g_signal_connect(G_OBJECT(button15), "clicked",  G_CALLBACK(chu),NULL);
   g_signal_connect(G_OBJECT(button16), "clicked",  G_CALLBACK(clear),NULL);
   g_signal_connect(G_OBJECT(window), "delete_event",  gtk_main_quit, NULL); 
   g_signal_connect(G_OBJECT(window), "delete_event",  gtk_main_quit, NULL); 	
}

int main (int argc, char *argv[])
{ 
   a=0;
   b=0;
   hasdot=0;
   gtk_set_locale ();
   gtk_init (&argc, &argv);
   method=0;  
   interface();
   addsignal();         
   gtk_widget_show(window);
   gtk_main ();
   return 0;
}
