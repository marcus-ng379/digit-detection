#include <iostream>
#include <string>
#include <wx/wx.h>
#include "wxwidget/Frame.h"
#include "neural/Activations.h"

class MainApp : public wxApp {
    public:
        // On App run
        bool OnInit() override;

};
// On App run (main function)
bool MainApp::OnInit() {
    // Run any neural stuff here
    Activations myActivation;

    // === Create window ===
    Frame* mainFrame = new Frame("Window Name");
    // Inital window Size;
    mainFrame->SetClientSize(800, 600);
    // Center the window
    mainFrame->Center();

    // Complet and Show the window
    mainFrame->Show();
    std::cout << "Window Running!" << std::endl;
    return true;
}

wxIMPLEMENT_APP(MainApp);