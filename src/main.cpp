#include <iostream>
#include <string>
#include <wx/wx.h>
#include "wxwidget/Frame.h"
#include "neural/Training/NetworkTest.h"

int main() {
    NetworkTest network_test;
    network_test.runTests();
    return 0;
}

// class MainApp : public wxApp {
//     public:
//         // On App run
//         bool OnInit() override;

// };
// // On App run (main function)
// bool MainApp::OnInit() {
//     // Run any neural stuff here
//     std::cout << "Running program!" << std::endl;
//     NetworkTest network_test;
//     network_test.runTests();
//     std::cout << "FINISHED" << std::endl;

//     // // === Create window ===
//     // Frame* mainFrame = new Frame("Window Name");
//     // // Inital window Size;
//     // mainFrame->SetClientSize(800, 600);
//     // // Center the window
//     // mainFrame->Center();

//     // // Complet and Show the window
//     // mainFrame->Show();
//     // std::cout << "Window Running!" << std::endl;
//     return true;
// }

// wxIMPLEMENT_APP(MainApp);