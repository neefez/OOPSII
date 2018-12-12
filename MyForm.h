#pragma once

namespace Lab6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
   private: System::Windows::Forms::ListBox^  ListBox;
   private: System::Windows::Forms::TextBox^  TextBox;
   protected:


   private: System::Windows::Forms::Button^  button1;
   private: System::Windows::Forms::Button^  button2;
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
         this->ListBox = (gcnew System::Windows::Forms::ListBox());
         this->TextBox = (gcnew System::Windows::Forms::TextBox());
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->button2 = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         // 
         // ListBox
         // 
         this->ListBox->FormattingEnabled = true;
         this->ListBox->Location = System::Drawing::Point(12, 31);
         this->ListBox->Name = L"ListBox";
         this->ListBox->Size = System::Drawing::Size(151, 290);
         this->ListBox->Sorted = true;
         this->ListBox->TabIndex = 0;
         // 
         // TextBox
         // 
         this->TextBox->Location = System::Drawing::Point(180, 79);
         this->TextBox->Name = L"TextBox";
         this->TextBox->Size = System::Drawing::Size(151, 20);
         this->TextBox->TabIndex = 1;
         this->TextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
         // 
         // button1
         // 
         this->button1->Location = System::Drawing::Point(217, 123);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(75, 23);
         this->button1->TabIndex = 2;
         this->button1->Text = L"add text";
         this->button1->UseVisualStyleBackColor = true;
         this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
         // 
         // button2
         // 
         this->button2->Location = System::Drawing::Point(217, 208);
         this->button2->Name = L"button2";
         this->button2->Size = System::Drawing::Size(75, 39);
         this->button2->TabIndex = 3;
         this->button2->Text = L"delete selected text";
         this->button2->UseVisualStyleBackColor = true;
         this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
         // 
         // MyForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(343, 353);
         this->Controls->Add(this->button2);
         this->Controls->Add(this->button1);
         this->Controls->Add(this->TextBox);
         this->Controls->Add(this->ListBox);
         this->Name = L"MyForm";
         this->Text = L"MyForm";
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
   }
   private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
      if(TextBox->Text->Length != 0)
         ListBox->Items->Add(TextBox->Text);
      TextBox->Text = "";
   }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
   if(ListBox->SelectedIndex >= 0)
      ListBox->Items->Remove(ListBox->SelectedItem);
}
};
}
