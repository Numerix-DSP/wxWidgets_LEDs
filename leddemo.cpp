// LED Demo

#ifdef __GNUG__
	#pragma implementation "leddemo.cpp"
	#pragma interface "leddemo.cpp"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

#include "wx/image.h"

#include "led.h"
#include "leddemo.h"


MyFrame   *frame = (MyFrame *) NULL;

IMPLEMENT_APP(MyApp)

MyApp::MyApp()
{
}

bool MyApp::OnInit(void)
{
  wxImage::AddHandler(new wxPNGHandler);

  // Create the main frame window - positioned in the centre of the screen
  frame = new MyFrame((wxFrame *) NULL, _T("LED Demo"), wxPoint(420, 250), wxDefaultSize);

  frame->Show(TRUE);

  return TRUE;
}


MyFrame::MyFrame(wxFrame *frame, const wxString& title, const wxPoint& pos, const wxSize& size):
  wxFrame(frame, -1, title, pos, size)
{
	int		i;

						// Panel to place the controls on
	wxPanel	*panel = new wxPanel (this, -1, wxDefaultPosition, GetSize());

						// Make the top-level layout; a vertical box to contain all widgets and sub-layouts.
	wxBoxSizer *VSizer = new wxBoxSizer (wxVERTICAL);

	wxBoxSizer *HSizer0 = new wxBoxSizer (wxHORIZONTAL);	// Graph + left labels
	wxBoxSizer *HSizer1 = new wxBoxSizer (wxHORIZONTAL);	// Bottom labels

	VSizer->Add (HSizer0, 0, wxALIGN_CENTER | wxALL, 0);
	VSizer->Add (HSizer1, 0, wxALIGN_CENTER | wxALL, 0);

	HSizer0->Add (MyRedLED = new LED (this, -1, RED_LED), 0, wxALIGN_TOP | wxALIGN_LEFT | wxALL, 5);
	HSizer0->Add (MyGreenLED = new LED (this, -1, GREEN_LED), 0, wxALIGN_TOP | wxALIGN_LEFT | wxALL, 5);
	HSizer0->Add (MyBlueLED = new LED (this, -1, BLUE_LED), 0, wxALIGN_TOP | wxALIGN_LEFT | wxALL, 5);
	HSizer0->Add (MyYellowLED = new LED (this, -1, YELLOW_LED), 0, wxALIGN_TOP | wxALIGN_LEFT | wxALL, 5);
	HSizer0->Add (MyCyanLED = new LED (this, -1, CYAN_LED), 0, wxALIGN_TOP | wxALIGN_LEFT | wxALL, 5);
	HSizer0->Add (MyWhiteLED = new LED (this, -1, WHITE_LED), 0, wxALIGN_TOP | wxALIGN_LEFT | wxALL, 5);

	MyRedLED->On (TRUE);									// Initialize LEDs on
	MyGreenLED->On (TRUE);
	MyBlueLED->On (TRUE);
	MyYellowLED->On (TRUE);
	MyCyanLED->On (TRUE);
	MyWhiteLED->On (TRUE);

	static const wxString LEDOptions[] =
	{
		"Red LED On / Off",
		"Green LED On / Off",
		"Blue LED On / Off",
		"Yellow LED On / Off",
		"Cyan LED On / Off",
		"White LED On / Off",
		"Flash All LEDs",
	};

	CheckList = new wxCheckListBox(panel, TICK_BOX_CHECKED, wxDefaultPosition, wxSize(150,120), NUMBER_OF_LEDS+1, LEDOptions, 0, wxDefaultValidator, "LED Options");

	for (i = 0; i < NUMBER_OF_LEDS; i++)
	{
		CheckList->Check (i);
	}
	HSizer1->Add (CheckList, 0, wxALIGN_CENTER | wxALL, 5);

	SetAutoLayout (TRUE);
	SetSizer (VSizer);

	VSizer->SetSizeHints (this);
	VSizer->Fit (this);

}


void MyFrame::OnTickBoxChecked (void)
{
//	wxMessageBox (_T("Got here"), _T("MyFrame::OnTickBoxChecked"), wxOK | wxICON_INFORMATION, this);

	if (CheckList->IsChecked(RED_LED))
		MyRedLED->On (TRUE);
	else
		MyRedLED->On (FALSE);

	if (CheckList->IsChecked(GREEN_LED))
		MyGreenLED->On (TRUE);
	else
		MyGreenLED->On (FALSE);

	if (CheckList->IsChecked(BLUE_LED))
		MyBlueLED->On (TRUE);
	else
		MyBlueLED->On (FALSE);

	if (CheckList->IsChecked(YELLOW_LED))
		MyYellowLED->On (TRUE);
	else
		MyYellowLED->On (FALSE);

	if (CheckList->IsChecked(CYAN_LED))
		MyCyanLED->On (TRUE);
	else
		MyCyanLED->On (FALSE);

	if (CheckList->IsChecked(WHITE_LED))
		MyWhiteLED->On (TRUE);
	else
		MyWhiteLED->On (FALSE);

	if (CheckList->IsChecked(WHITE_LED+1))
	{
		MyRedLED->Flash (TRUE);
		MyGreenLED->Flash (TRUE);
		MyBlueLED->Flash (TRUE);
		MyYellowLED->Flash (TRUE);
		MyCyanLED->Flash (TRUE);
		MyWhiteLED->Flash (TRUE);
	}
	else
	{
		MyRedLED->Flash (FALSE);
		MyGreenLED->Flash (FALSE);
		MyBlueLED->Flash (FALSE);
		MyYellowLED->Flash (FALSE);
		MyCyanLED->Flash (FALSE);
		MyWhiteLED->Flash (FALSE);
	}

}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_CHECKLISTBOX (TICK_BOX_CHECKED, MyFrame::OnTickBoxChecked)
END_EVENT_TABLE()

