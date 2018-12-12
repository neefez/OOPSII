//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: This file contains the Main() function that starts the
//          program.
//-------------------------------------------------------------------
#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);

   Program3::MyForm form;
   Application::Run(%form);
}