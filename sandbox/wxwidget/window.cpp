#include "window.h"

bool MyApp::OnInit() {
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "wxWidgets Test");
    frame->Show(true);
    return true;
}

