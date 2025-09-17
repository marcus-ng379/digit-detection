#include <wx/wx.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "wxWidgets Test");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
