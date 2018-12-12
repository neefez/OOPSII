//-------------------------------------------------------------------
// Name:    Zack Neefe, Darius Fieschko
// Project: Data Structure Time Trials
// Purpose: Primary cpp file that contains the main function for the
//          application; starts running the main form.
//          Cody Schluenz did not contribute to the Program.
//-------------------------------------------------------------------
#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//-------------------------------------------------------------------
// Starts the main form
//-------------------------------------------------------------------
[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Prog5::MyForm form;
	Application::Run(%form);
}
