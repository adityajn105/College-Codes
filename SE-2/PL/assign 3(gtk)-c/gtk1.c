#include <gtk/gtk.h>


static gboolean expose_event(GtkWidget *widget, GdkEventExpose *event)
{
  

  GdkGC *black_gc = widget->style->black_gc;
  GdkGC *white_gc = widget->style->white_gc;


  gdk_draw_arc(widget->window, black_gc, FALSE,250,325, 150,150, 64*120,64*120);
  gdk_draw_arc(widget->window, black_gc, FALSE,50,325, 150,150, 64*300,64*120);
  gdk_draw_arc(widget->window, black_gc, FALSE,120,190, 200,200, 64*295,64*315);

  gdk_draw_rectangle(widget->window,black_gc,FALSE, 420,335, 190,120);

  gdk_draw_line(widget->window,black_gc, 480,335,480,455);
  gdk_draw_line(widget->window,black_gc, 450,290,420,335);
  gdk_draw_line(widget->window,black_gc, 450,290,480,335);
  gdk_draw_line(widget->window,black_gc, 450,290,610,290);
  gdk_draw_line(widget->window,black_gc, 610,290,610,335);
  gdk_draw_line(widget->window,black_gc, 435,400,435,455);
  gdk_draw_line(widget->window,black_gc, 465,400,465,455);
  gdk_draw_line(widget->window,black_gc, 435,400,465,400);


gdk_draw_arc(widget->window, black_gc, TRUE,530,365, 35,35, 64*0,64*360);
 

 return TRUE;
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),1500,500);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
   g_signal_connect(G_OBJECT(window), "expose_event", G_CALLBACK(expose_event), NULL);
    gtk_widget_show(window);
    gtk_main();    
    return 0;
}
