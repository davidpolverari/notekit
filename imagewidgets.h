#ifndef IMAGEWIDGETS_H
#define IMAGEWIDGETS_H

#include "config.h"

#include <gtkmm.h>

class CImageWidget : public Gtk::DrawingArea
{
public:
	CImageWidget(Glib::RefPtr<Gdk::Window> wnd);
	virtual ~CImageWidget();
	
	int w,h;
	
	bool selected;
	
	Glib::RefPtr<Gdk::Window> target_window;
	Cairo::RefPtr<Cairo::Surface> image;
	Cairo::RefPtr<Cairo::Context> image_ctx;
	void SetSize(int x, int y);
	
	virtual void Redraw();

	virtual bool on_draw(const Cairo::RefPtr<Cairo::Context> &ctx);
	
	virtual void on_unrealize();
	virtual void destroy_notify_();
};

#ifdef HAVE_LASEM

class CLatexWidget : public CImageWidget
{
public:
	CLatexWidget(Glib::RefPtr<Gdk::Window> wnd, Glib::ustring source);
	virtual ~CLatexWidget();
	
	Glib::ustring source;
	
	virtual void Redraw();
};

#endif

#endif