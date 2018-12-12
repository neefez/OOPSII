#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Trial.h"
#include "VectorTrial.h"
#include "ListTrial.h"
#include "DequeTrial.h"
#include "MultisetTrial.h"
#include "MultimapTrial.h"
#include <msclr\marshal_cppstd.h>

#pragma once

namespace Prog5 {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;
   Trial * trial;
   const int DEQUE = 2;
   const int MULTISET = 3;
   const int MULTIMAP = 4;

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
         this->comboBox1->SelectedIndex = 0;
         this->comboBox2->SelectedIndex = 0;
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
   private: System::Windows::Forms::ComboBox^  comboBox1;
   protected:
   private: System::Windows::Forms::ListBox^  listBox1;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Button^  button1;
   private: System::Windows::Forms::TextBox^  textBox1;
   private: System::Windows::Forms::Button^  button2;
   private: System::Windows::Forms::Label^  label2;

   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::Label^  label6;
   private: System::Windows::Forms::Button^  button3;
   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::ComboBox^  comboBox2;
   private: System::Windows::Forms::TextBox^  textBox2;


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
         this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
         this->listBox1 = (gcnew System::Windows::Forms::ListBox());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->textBox1 = (gcnew System::Windows::Forms::TextBox());
         this->button2 = (gcnew System::Windows::Forms::Button());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->button3 = (gcnew System::Windows::Forms::Button());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
         this->textBox2 = (gcnew System::Windows::Forms::TextBox());
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
         this->SuspendLayout();
         // 
         // comboBox1
         // 
         this->comboBox1->DisplayMember = L"0";
         this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
         this->comboBox1->FormattingEnabled = true;
         this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"vector", L"list", L"deque", L"multiset", L"multimap" });
         this->comboBox1->Location = System::Drawing::Point(328, 55);
         this->comboBox1->Name = L"comboBox1";
         this->comboBox1->Size = System::Drawing::Size(157, 21);
         this->comboBox1->TabIndex = 0;
         this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
         // 
         // listBox1
         // 
         this->listBox1->FormattingEnabled = true;
         this->listBox1->Location = System::Drawing::Point(26, 93);
         this->listBox1->Name = L"listBox1";
         this->listBox1->Size = System::Drawing::Size(182, 433);
         this->listBox1->TabIndex = 1;
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(23, 77);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(52, 13);
         this->label1->TabIndex = 2;
         this->label1->Text = L"String list:";
         // 
         // button1
         // 
         this->button1->Location = System::Drawing::Point(99, 55);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(109, 35);
         this->button1->TabIndex = 3;
         this->button1->Text = L"Add String";
         this->button1->UseVisualStyleBackColor = true;
         this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
         // 
         // textBox1
         // 
         this->textBox1->Location = System::Drawing::Point(26, 32);
         this->textBox1->Name = L"textBox1";
         this->textBox1->Size = System::Drawing::Size(182, 20);
         this->textBox1->TabIndex = 4;
         this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
         // 
         // button2
         // 
         this->button2->Location = System::Drawing::Point(49, 532);
         this->button2->Name = L"button2";
         this->button2->Size = System::Drawing::Size(125, 42);
         this->button2->TabIndex = 5;
         this->button2->Text = L"Delete Selected String";
         this->button2->UseVisualStyleBackColor = true;
         this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(325, 39);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(55, 13);
         this->label2->TabIndex = 6;
         this->label2->Text = L"Container:";
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Location = System::Drawing::Point(325, 105);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(57, 13);
         this->label3->TabIndex = 8;
         this->label3->Text = L"Trial Type:";
         // 
         // numericUpDown1
         // 
         this->numericUpDown1->BackColor = System::Drawing::SystemColors::Window;
         this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
         this->numericUpDown1->Location = System::Drawing::Point(328, 190);
         this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
         this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
         this->numericUpDown1->Name = L"numericUpDown1";
         this->numericUpDown1->ReadOnly = true;
         this->numericUpDown1->Size = System::Drawing::Size(157, 20);
         this->numericUpDown1->TabIndex = 9;
         this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Location = System::Drawing::Point(325, 174);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(105, 13);
         this->label4->TabIndex = 10;
         this->label4->Text = L"Number of Iterations:";
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Location = System::Drawing::Point(23, 16);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(89, 13);
         this->label6->TabIndex = 12;
         this->label6->Text = L"Add a new string:";
         // 
         // button3
         // 
         this->button3->Location = System::Drawing::Point(355, 244);
         this->button3->Name = L"button3";
         this->button3->Size = System::Drawing::Size(94, 34);
         this->button3->TabIndex = 13;
         this->button3->Text = L"Start Timing";
         this->button3->UseVisualStyleBackColor = true;
         this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label5->Location = System::Drawing::Point(246, 306);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(348, 26);
         this->label5->TabIndex = 14;
         this->label5->Text = L"Trial completed in 0 microseconds.";
         this->label5->Visible = false;
         // 
         // comboBox2
         // 
         this->comboBox2->DisplayMember = L"0";
         this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
         this->comboBox2->FormattingEnabled = true;
         this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
            L"Add Front - Remove Front", L"Add Front - Remove Rear",
               L"Add Rear - Remove Front", L"Add Rear - Remove Rear"
         });
         this->comboBox2->Location = System::Drawing::Point(328, 121);
         this->comboBox2->MaxDropDownItems = 3;
         this->comboBox2->Name = L"comboBox2";
         this->comboBox2->Size = System::Drawing::Size(157, 21);
         this->comboBox2->TabIndex = 7;
         // 
         // textBox2
         // 
         this->textBox2->Location = System::Drawing::Point(328, 122);
         this->textBox2->Name = L"textBox2";
         this->textBox2->ReadOnly = true;
         this->textBox2->Size = System::Drawing::Size(157, 20);
         this->textBox2->TabIndex = 15;
         this->textBox2->Text = L"Sorted";
         this->textBox2->Visible = false;
         // 
         // MyForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(684, 661);
         this->Controls->Add(this->textBox2);
         this->Controls->Add(this->label5);
         this->Controls->Add(this->button3);
         this->Controls->Add(this->label6);
         this->Controls->Add(this->label4);
         this->Controls->Add(this->numericUpDown1);
         this->Controls->Add(this->label3);
         this->Controls->Add(this->comboBox2);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->button2);
         this->Controls->Add(this->textBox1);
         this->Controls->Add(this->button1);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->listBox1);
         this->Controls->Add(this->comboBox1);
         this->Name = L"MyForm";
         this->Text = L"MyForm";
         this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
//-------------------------------------------------------------------
// Adds the text inside textBox1 to the list of strings and puts
// the cursor back into the text box.
//-------------------------------------------------------------------
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
   if (textBox1->Text->Length != 0)
      listBox1->Items->Add(textBox1->Text);
   textBox1->Text = "";
   textBox1->Focus();
}

//-------------------------------------------------------------------
// Deletes the selected item from the string list if an item is
// selected.
//-------------------------------------------------------------------
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
   if (listBox1->SelectedIndex >= 0)
      listBox1->Items->Remove(listBox1->SelectedItem);
}

//-------------------------------------------------------------------
// Event in which the window is closed, deletes the trial pointer
// and dumps memory leaks.
//-------------------------------------------------------------------
private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
   _CrtDumpMemoryLeaks();
}

//-------------------------------------------------------------------
// Event for the press of the "start trial" button. Takes the
// strings from the string list and makes them into a vector of
// strings. Creates the trial and runs it.
//-------------------------------------------------------------------
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
   StringList vec;
   for (int i = 0; i < listBox1->Items->Count; i++)
   {
      msclr::interop::marshal_context context;
      string standardString = context.marshal_as<string>(listBox1->Items[i]->ToString());
      vec.push_back(standardString);
   }
   
   Trial::TrialType t;
   switch (comboBox2->SelectedIndex)
   {
      case 0:
         t = Trial::FRONT_FRONT;
         break;
      case 1:
         t = Trial::FRONT_REAR;
         break;
      case Trial::REAR_FRONT:
         t = Trial::REAR_FRONT;
         break;
      case Trial::REAR_REAR:
         t = Trial::REAR_REAR;
         break;
      default:
         break;
   }
   
   switch (comboBox1->SelectedIndex)
   {
      case 0:
         trial = new VectorTrial(vec, int(numericUpDown1->Value), t);
         break;
      case 1:
         trial = new ListTrial(vec, int(numericUpDown1->Value), t);
         break;
      case DEQUE:
         trial = new DequeTrial(vec, int(numericUpDown1->Value), t);
         break;
      case MULTISET:
         t = Trial::SORTED;
         trial = new MultisetTrial(vec, int(numericUpDown1->Value), t);
         break;
      case MULTIMAP:
         t = Trial::SORTED;
         trial = new MultimapTrial(vec, int(numericUpDown1->Value), t);
         break;
      default:
         break;
   }

   label5->Text = "Trial completed in " + trial->Run() + " microseconds.";
   label5->Visible = true;
   delete trial;
}

//-------------------------------------------------------------------
// Event for when the user selects which type of data structure
// they want for the trial. If multiset or multimap, makes the
// trial type "sorted."
//-------------------------------------------------------------------
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{
   if (comboBox1->SelectedIndex == MULTISET || comboBox1->SelectedIndex == MULTIMAP)
   {
      comboBox2->Visible = false;
      textBox2->Visible = true;
   }
   else
   {
      comboBox2->SelectedIndex = 0;
      textBox2->Visible = false;
      comboBox2->Visible = true;
   }
}

//-------------------------------------------------------------------
// Event to add the string in textBox1 to the string list whenever
// the user presses the enter key.
//-------------------------------------------------------------------
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{
   if (e->KeyChar == '\r')
   {
      if (textBox1->Text->Length != 0)
         listBox1->Items->Add(textBox1->Text);
      textBox1->Text = "";
   }
}
};
}
