// LEDDemo.h

#if defined( __GNUG__) && !defined(__APPLE__)
#pragma interface
#endif

#include "wx/wx.h"


#define TICK_BOX_CHECKED		301

// Define a new application
class MyApp: public wxApp
{
  public:
    MyApp(void) ;
    bool OnInit(void);

};

// Define a new frame
class LEDCanvas;

class MyFrame: public wxFrame
{
public:
    LEDCanvas *canvas;
    MyFrame (wxFrame *parent, const wxString& title, const wxPoint& pos, const wxSize& size);

	LED				*MyRedLED;
	LED				*MyYellowLED;
	LED				*MyCyanLED;
	LED				*MyBlueLED;
	LED				*MyWhiteLED;
	LED				*MyGreenLED;

private:

	wxCheckListBox	*CheckList;
	void OnTickBoxChecked (void);

DECLARE_EVENT_TABLE()
};


