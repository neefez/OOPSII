#pragma once
#include "HelpWindow.h"
#include "Maze.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <fstream>
using namespace std;

namespace Prog4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
   Maze * maze;
	
   /// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   protected:
   private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Panel^  mazePanel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
         this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->mazePanel = (gcnew System::Windows::Forms::Panel());
         this->menuStrip1->SuspendLayout();
         this->SuspendLayout();
         // 
         // menuStrip1
         // 
         this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
            this->fileToolStripMenuItem,
               this->helpToolStripMenuItem
         });
         this->menuStrip1->Location = System::Drawing::Point(0, 0);
         this->menuStrip1->Name = L"menuStrip1";
         this->menuStrip1->Size = System::Drawing::Size(624, 24);
         this->menuStrip1->TabIndex = 0;
         this->menuStrip1->Text = L"menuStrip1";
         // 
         // fileToolStripMenuItem
         // 
         this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
            this->openToolStripMenuItem,
               this->exitToolStripMenuItem
         });
         this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
         this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
         this->fileToolStripMenuItem->Text = L"File";
         // 
         // openToolStripMenuItem
         // 
         this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
         this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
         this->openToolStripMenuItem->Text = L"Open";
         this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
         // 
         // exitToolStripMenuItem
         // 
         this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
         this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
         this->exitToolStripMenuItem->Text = L"Exit";
         this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
         // 
         // helpToolStripMenuItem
         // 
         this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
         this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
         this->helpToolStripMenuItem->Text = L"Help";
         this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
            | System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(12, 35);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(163, 26);
         this->label1->TabIndex = 1;
         this->label1->Text = L"Maze Solution";
         // 
         // mazePanel
         // 
         this->mazePanel->Location = System::Drawing::Point(211, 140);
         this->mazePanel->Name = L"mazePanel";
         this->mazePanel->Size = System::Drawing::Size(200, 100);
         this->mazePanel->TabIndex = 2;
         // 
         // MyForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(624, 601);
         this->Controls->Add(this->mazePanel);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->menuStrip1);
         this->MainMenuStrip = this->menuStrip1;
         this->Name = L"MyForm";
         this->Text = L"MyForm";
         this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
         this->menuStrip1->ResumeLayout(false);
         this->menuStrip1->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
      Close();
   }
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
   HelpWindow ^ f = gcnew HelpWindow();
   f->ShowDialog();
}
private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
   delete maze;
   _CrtDumpMemoryLeaks();
}
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
   OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
   openFileDialog1->InitialDirectory = ".";

   if (openFileDialog1->ShowDialog() == ::DialogResult::OK)
   {
      char filename[1024];
      for (int i = 0; i < openFileDialog1->FileName->Length; i++)
      {
        filename[i] = openFileDialog1->FileName[i];
      }
      filename[openFileDialog1->FileName->Length] = '\0';
      ifstream ifs;
      ifs.open(filename);
      maze = new Maze(mazePanel, ifs);
      if (!maze->IsValid())
         MessageBox::Show("The maze was not valid! Please try again.");
      ifs.close();
   }


 //  else
   //   MessageBox::Show("The maze was not valid! Please try again.");
}
};
}
