#include "wxwidget/window.h"
#include "neural/Activations.h"

bool mainApp::OnInit() {
    Activations myNetwork; // Use your neural network here
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "wxWidgets Test");
    frame->Show(true);
    return true;
}