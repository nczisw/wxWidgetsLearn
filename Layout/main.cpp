#include <wx\wx.h>
#include <wx\listctrl.h>
#include <wx\splitter.h>


class MyApp : public wxApp 
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame 
{
public:
    MyFrame(const wxString& title, const wxPoint& point, const wxSize& size);
};


bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("Hello world!", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;

}

MyFrame::MyFrame(const wxString& title, const wxPoint& point, const wxSize& size)
    :wxFrame(nullptr, wxID_ANY, title, point, size) {
    /*
    wxPanel* panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
    panel_top->SetBackgroundColour(wxColor(100, 100, 200));

    wxPanel* panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
    panel_bottom->SetBackgroundColour(wxColor(100, 200, 100));

    wxPanel* panel_bottom_right = new wxPanel(panel_bottom, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
    panel_bottom_right->SetBackgroundColour(wxColor(200, 200, 100));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(panel_top, 1, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);
    sizer->Add(panel_bottom, 1, wxEXPAND | wxALL, 10);

    wxSizer* sizer_bottom = new wxBoxSizer(wxVERTICAL);
    wxSizer* sizer_centering = new wxBoxSizer(wxHORIZONTAL);
    sizer_centering->Add(panel_bottom_right, 0, wxALIGN_CENTER);
    sizer_bottom->Add(sizer_centering, 1, wxALIGN_CENTER);

    panel_bottom->SetSizerAndFit(sizer_bottom);

    this->SetSizerAndFit(sizer);

    */

    /*
    wxListView* list = new wxListView(this, wxID_ADD, wxDefaultPosition, wxSize(300, 200));
    list->InsertColumn(0, "Name");
    list->InsertColumn(1, "Item");

    wxButton* ok_button = new wxButton(this, wxID_ANY, "Ok");
    wxButton* cancel_button = new wxButton(this, wxID_ANY, "Cancel");

    wxSizer* s1 = new wxBoxSizer(wxVERTICAL);
    s1->Add(list, 1, wxEXPAND | wxALL, 5);

    wxSizer* s2 = new wxBoxSizer(wxHORIZONTAL);
    s2->Add(ok_button, 0, wxRIGHT, 5);
    s2->Add(cancel_button, 0);

    s1->Add(s2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 5);

    this->SetSizerAndFit(s1);
    */

    wxSplitterWindow* splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER | wxSP_LIVE_UPDATE);
    wxSplitterWindow* right_splitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER | wxSP_LIVE_UPDATE);

    wxPanel* left = new wxPanel(splitter);
    wxPanel* right = new wxPanel(right_splitter);
    wxPanel* bottom = new wxPanel(right_splitter);

    left->SetBackgroundColour(wxColor(100, 200, 100));
    right->SetBackgroundColour(wxColor(200, 100, 100));
    bottom->SetBackgroundColour(wxColor(200, 200, 100));

    right_splitter->SetMinimumPaneSize(100);
    splitter->SetMinimumPaneSize(200);

    right_splitter->SplitHorizontally(right, bottom);
    right_splitter->SetSashGravity(1.0);

    splitter->SplitVertically(left, right_splitter);

}