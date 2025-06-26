#include "dzwig.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^){
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm());
    return 0;
}