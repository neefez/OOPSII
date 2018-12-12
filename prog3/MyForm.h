//-------------------------------------------------------------------
// Name:    Zack Neefe
// Project: Bot Wars Visual C++ Program
// Purpose: MyForm is the GUI of the bot wars system. It has a button
//          to create a chosen VBot as well as parameters of where
//          to place the VBot. There is a slider to change how 
//          quickly the VBots update their position.
//-------------------------------------------------------------------
#pragma once
#include "VBotList.h"
#include "RedBot.h"
#include "PanBot.h"
#include "MadBot.h"
const int THIRD_SELECTED = 2;

namespace Program3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
   VBotList * list = new VBotList;
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
   private: System::Windows::Forms::Panel^  panel1;
   protected:
   private: System::Windows::Forms::Button^  button1;
   private: System::Windows::Forms::TrackBar^  timerSpeedTrackBar;

   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::ComboBox^  comboBox1;
   private: System::Windows::Forms::NumericUpDown^  startx;
   private: System::Windows::Forms::NumericUpDown^  starty;
   private: System::Windows::Forms::Timer^  timer1;
   private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
      int initxcoord = 0;
      int initycoord = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->components = (gcnew System::ComponentModel::Container());
         this->panel1 = (gcnew System::Windows::Forms::Panel());
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->timerSpeedTrackBar = (gcnew System::Windows::Forms::TrackBar());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
         this->startx = (gcnew System::Windows::Forms::NumericUpDown());
         this->starty = (gcnew System::Windows::Forms::NumericUpDown());
         this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timerSpeedTrackBar))->BeginInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startx))->BeginInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->starty))->BeginInit();
         this->SuspendLayout();
         // 
         // panel1
         // 
         this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
         this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
         this->panel1->Location = System::Drawing::Point(45, 98);
         this->panel1->Name = L"panel1";
         this->panel1->Size = System::Drawing::Size(520, 516);
         this->panel1->TabIndex = 0;
         this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
         // 
         // button1
         // 
         this->button1->Location = System::Drawing::Point(368, 47);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(75, 23);
         this->button1->TabIndex = 1;
         this->button1->Text = L"Add VBot";
         this->button1->UseVisualStyleBackColor = true;
         this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
         // 
         // timerSpeedTrackBar
         // 
         this->timerSpeedTrackBar->Cursor = System::Windows::Forms::Cursors::Default;
         this->timerSpeedTrackBar->Location = System::Drawing::Point(475, 47);
         this->timerSpeedTrackBar->Maximum = 300;
         this->timerSpeedTrackBar->Minimum = 20;
         this->timerSpeedTrackBar->Name = L"timerSpeedTrackBar";
         this->timerSpeedTrackBar->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
         this->timerSpeedTrackBar->Size = System::Drawing::Size(104, 45);
         this->timerSpeedTrackBar->TabIndex = 2;
         this->timerSpeedTrackBar->TickFrequency = 100;
         this->timerSpeedTrackBar->Value = 300;
         this->timerSpeedTrackBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::timerSpeedTrackBar_ValueChanged);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(504, 31);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(38, 13);
         this->label1->TabIndex = 3;
         this->label1->Text = L"Speed";
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(26, 22);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(90, 13);
         this->label2->TabIndex = 4;
         this->label2->Text = L"Select VBot Type";
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Location = System::Drawing::Point(161, 22);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(39, 13);
         this->label3->TabIndex = 5;
         this->label3->Text = L"Start X";
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Location = System::Drawing::Point(259, 22);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(39, 13);
         this->label4->TabIndex = 6;
         this->label4->Text = L"Start Y";
         // 
         // comboBox1
         // 
         this->comboBox1->DisplayMember = L"0";
         this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
         this->comboBox1->FormattingEnabled = true;
         this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Red Bot", L"Pan Bot", L"Mad Bot" });
         this->comboBox1->Location = System::Drawing::Point(22, 47);
         this->comboBox1->Name = L"comboBox1";
         this->comboBox1->Size = System::Drawing::Size(102, 21);
         this->comboBox1->TabIndex = 7;
         // 
         // startx
         // 
         this->startx->Location = System::Drawing::Point(148, 47);
         this->startx->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
         this->startx->Name = L"startx";
         this->startx->Size = System::Drawing::Size(68, 20);
         this->startx->TabIndex = 8;
         this->startx->ValueChanged += gcnew System::EventHandler(this, &MyForm::startx_ValueChanged);
         // 
         // starty
         // 
         this->starty->Location = System::Drawing::Point(249, 48);
         this->starty->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
         this->starty->Name = L"starty";
         this->starty->Size = System::Drawing::Size(68, 20);
         this->starty->TabIndex = 9;
         this->starty->ValueChanged += gcnew System::EventHandler(this, &MyForm::starty_ValueChanged);
         // 
         // timer1
         // 
         this->timer1->Enabled = true;
         this->timer1->Interval = 300;
         this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
         // 
         // MyForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(624, 634);
         this->Controls->Add(this->starty);
         this->Controls->Add(this->startx);
         this->Controls->Add(this->comboBox1);
         this->Controls->Add(this->label4);
         this->Controls->Add(this->label3);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->timerSpeedTrackBar);
         this->Controls->Add(this->button1);
         this->Controls->Add(this->panel1);
         this->Name = L"MyForm";
         this->Text = L"MyForm";
         this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
         this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timerSpeedTrackBar))->EndInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startx))->EndInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->starty))->EndInit();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
      //----------------------------------------------------------------
      // Event in which the user clicks the "Add VBot" button. Uses the
      // coordinates in the X and Y boxes and the VBot teyp in the drop
      // down list to make a new VBot.
      //----------------------------------------------------------------
   private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
      if (comboBox1->SelectedIndex == 0)
      {
         VBot * temp = new RedBot(initxcoord, initycoord, this->panel1);
         list->Add(temp);
      }
      else if (comboBox1->SelectedIndex == 1)
      {
         VBot * temp = new PanBot(initxcoord, initycoord, this->panel1);
         list->Add(temp);
      }
      else if (comboBox1->SelectedIndex == THIRD_SELECTED)
      {
         VBot * temp = new MadBot(initxcoord, initycoord, this->panel1);
         list->Add(temp);
      }
   }
   //----------------------------------------------------------------
   // Loads the form.
   //----------------------------------------------------------------
   private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
   }
   //----------------------------------------------------------------
   // Updates all of the VBots in the list. Invalidates the panel
   // to reload the VBots.
   //----------------------------------------------------------------
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
   int j = list->GetNum();
   for (int i = 0; i < j; i++)
   {
      if (!list->Update(i))
         j = list->GetNum();
      this->panel1->Invalidate();
   }
}
   //----------------------------------------------------------------
   // Changes the interval of the timer based on the position of
   // the trackbar's cursor.
   //----------------------------------------------------------------
private: System::Void timerSpeedTrackBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
   timer1->Interval = timerSpeedTrackBar->Value;
}
   //----------------------------------------------------------------
   // Changes the desired x coordinate to the value in the box.
   //----------------------------------------------------------------
private: System::Void startx_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
   initxcoord = Decimal::ToInt32(startx->Value);
}
   //----------------------------------------------------------------
   // Changes the desired y coordinate to the value in the box.
   //----------------------------------------------------------------
private: System::Void starty_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
   initycoord = Decimal::ToInt32(starty->Value);
}
   //----------------------------------------------------------------
   // Shows all of the VBots currently in the list.
   //----------------------------------------------------------------
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
   list->Show();
}
   //----------------------------------------------------------------
   // Turns off the timer and deletes the list pointer.
   //----------------------------------------------------------------
private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
   timer1->Enabled = false;
   delete list;
}
};
}
