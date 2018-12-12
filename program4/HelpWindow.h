#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for HelpWindow
/// </summary>
public ref class HelpWindow : public System::Windows::Forms::Form
{
public:
	HelpWindow(void)
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
	~HelpWindow()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::Windows::Forms::RichTextBox^  richTextBox1;
protected:

  protected:
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
      this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
      this->SuspendLayout();
      // 
      // richTextBox1
      // 
      this->richTextBox1->Location = System::Drawing::Point(33, 87);
      this->richTextBox1->Name = L"richTextBox1";
      this->richTextBox1->ReadOnly = true;
      this->richTextBox1->Size = System::Drawing::Size(222, 70);
      this->richTextBox1->TabIndex = 0;
      this->richTextBox1->Text = L"Use File/Open to open a Maze Data File.\n\nClick anywhere on a Maze to see if there"
         L" is an escape from that position.\n";
      // 
      // HelpWindow
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(284, 261);
      this->Controls->Add(this->richTextBox1);
      this->Name = L"HelpWindow";
      this->Text = L"About Maze";
      this->ResumeLayout(false);

   }
#pragma endregion
};