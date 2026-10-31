#pragma once
#include "Bicycle.h"
#include "Sale.h"
#include "frmBikeDetails.h"
#include "frmSales.h"
#include "frmSearch.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Data;
using namespace System::Data::SqlClient;
//using namespace System::Linq;

namespace BicycleServices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			bike = gcnew List<Bicycle^>();
			salesList = gcnew List<Sale^>();

			// Set up timer for live clock
			timer1->Interval = 1000;  // 1 second = 1000 milliseconds
			timer1->Tick += gcnew System::EventHandler(this, &frmMain::timer1_Tick);
			timer1->Start();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSearch;
	protected:
		List<Sale^>^ salesList;  // ← ADD THIS DECLARATION
		List<Bicycle^>^ bike;
	private: System::Windows::Forms::ListBox^ lstDisplayBike;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editBikeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ searchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;

	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripMenuItem^ searchBarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ bikeDetailsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ salesToolStripMenuItem;


	private: System::Windows::Forms::TextBox^ txtSearch1;
	private: System::Windows::Forms::Button^ btnClear;




	private: System::Windows::Forms::ToolStripMenuItem^ priceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ascendingToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ descendingToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ priceToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ ascendingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ descendingToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBoxBike;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar1;










	private: System::ComponentModel::IContainer^ components;

	private:
		//List<Sale^>^ salesList;  // ← ADD THIS DECLARATION
		String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=BicycleDB;Integrated Security=True";
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^ tsslblDateTime;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::Button^ btnRefresh;


		   SqlConnection^ conn;
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->lstDisplayBike = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editBikeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->priceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ascendingToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->descendingToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->priceToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ascendingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->descendingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->bikeDetailsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchBarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->tsslblDateTime = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->txtSearch1 = (gcnew System::Windows::Forms::TextBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->pictureBoxBike = (gcnew System::Windows::Forms::PictureBox());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBike))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(949, 53);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(173, 46);
			this->btnSearch->TabIndex = 7;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &frmMain::btnSearch_Click);
			// 
			// lstDisplayBike
			// 
			this->lstDisplayBike->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstDisplayBike->FormattingEnabled = true;
			this->lstDisplayBike->ItemHeight = 20;
			this->lstDisplayBike->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"" });
			this->lstDisplayBike->Location = System::Drawing::Point(27, 136);
			this->lstDisplayBike->Name = L"lstDisplayBike";
			this->lstDisplayBike->Size = System::Drawing::Size(1098, 484);
			this->lstDisplayBike->TabIndex = 5;
			this->lstDisplayBike->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::lstDisplayBike_SelectedIndexChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->viewToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1909, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &frmMain::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->exitToolStripMenuItem, this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->openToolStripMenuItem->Text = L"&Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::exitToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::saveToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addToolStripMenuItem,
					this->editBikeToolStripMenuItem, this->deleteToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(49, 24);
			this->editToolStripMenuItem->Text = L"&Edit";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::editToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->addToolStripMenuItem->Text = L"Add";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::addToolStripMenuItem_Click);
			// 
			// editBikeToolStripMenuItem
			// 
			this->editBikeToolStripMenuItem->Name = L"editBikeToolStripMenuItem";
			this->editBikeToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->editBikeToolStripMenuItem->Text = L"Edit Bike";
			this->editBikeToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::editBikeToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::deleteToolStripMenuItem_Click_2);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->searchToolStripMenuItem,
					this->sortToolStripMenuItem
			});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->viewToolStripMenuItem->Text = L"&View";
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(136, 26);
			this->searchToolStripMenuItem->Text = L"Search";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::searchToolStripMenuItem_Click);
			// 
			// sortToolStripMenuItem
			// 
			this->sortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->priceToolStripMenuItem,
					this->priceToolStripMenuItem1
			});
			this->sortToolStripMenuItem->Name = L"sortToolStripMenuItem";
			this->sortToolStripMenuItem->Size = System::Drawing::Size(136, 26);
			this->sortToolStripMenuItem->Text = L"Sort";
			// 
			// priceToolStripMenuItem
			// 
			this->priceToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ascendingToolStripMenuItem1,
					this->descendingToolStripMenuItem1
			});
			this->priceToolStripMenuItem->Name = L"priceToolStripMenuItem";
			this->priceToolStripMenuItem->Size = System::Drawing::Size(132, 26);
			this->priceToolStripMenuItem->Text = L"Name";
			this->priceToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::priceToolStripMenuItem_Click);
			// 
			// ascendingToolStripMenuItem1
			// 
			this->ascendingToolStripMenuItem1->Name = L"ascendingToolStripMenuItem1";
			this->ascendingToolStripMenuItem1->Size = System::Drawing::Size(170, 26);
			this->ascendingToolStripMenuItem1->Text = L"Ascending";
			this->ascendingToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmMain::ascendingToolStripMenuItem1_Click);
			// 
			// descendingToolStripMenuItem1
			// 
			this->descendingToolStripMenuItem1->Name = L"descendingToolStripMenuItem1";
			this->descendingToolStripMenuItem1->Size = System::Drawing::Size(170, 26);
			this->descendingToolStripMenuItem1->Text = L"Descending";
			this->descendingToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmMain::descendingToolStripMenuItem1_Click);
			// 
			// priceToolStripMenuItem1
			// 
			this->priceToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ascendingToolStripMenuItem,
					this->descendingToolStripMenuItem
			});
			this->priceToolStripMenuItem1->Name = L"priceToolStripMenuItem1";
			this->priceToolStripMenuItem1->Size = System::Drawing::Size(132, 26);
			this->priceToolStripMenuItem1->Text = L"Price";
			// 
			// ascendingToolStripMenuItem
			// 
			this->ascendingToolStripMenuItem->Name = L"ascendingToolStripMenuItem";
			this->ascendingToolStripMenuItem->Size = System::Drawing::Size(170, 26);
			this->ascendingToolStripMenuItem->Text = L"Ascending";
			this->ascendingToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::ascendingToolStripMenuItem_Click);
			// 
			// descendingToolStripMenuItem
			// 
			this->descendingToolStripMenuItem->Name = L"descendingToolStripMenuItem";
			this->descendingToolStripMenuItem->Size = System::Drawing::Size(170, 26);
			this->descendingToolStripMenuItem->Text = L"Descending";
			this->descendingToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::descendingToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->helpToolStripMenuItem->Text = L"&Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::helpToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(133, 26);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::aboutToolStripMenuItem_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &frmMain::timer1_Tick);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripDropDownButton1,
					this->toolStripProgressBar1, this->tsslblDateTime, this->toolStripStatusLabel1
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 724);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1909, 43);
			this->statusStrip1->TabIndex = 8;
			this->statusStrip1->Text = L"statusStrip1";
			this->statusStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &frmMain::statusStrip1_ItemClicked_1);
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->bikeDetailsToolStripMenuItem,
					this->salesToolStripMenuItem, this->searchBarToolStripMenuItem
			});
			this->toolStripDropDownButton1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(34, 41);
			this->toolStripDropDownButton1->Text = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Click += gcnew System::EventHandler(this, &frmMain::toolStripDropDownButton1_Click_1);
			// 
			// bikeDetailsToolStripMenuItem
			// 
			this->bikeDetailsToolStripMenuItem->Name = L"bikeDetailsToolStripMenuItem";
			this->bikeDetailsToolStripMenuItem->Size = System::Drawing::Size(252, 42);
			this->bikeDetailsToolStripMenuItem->Text = L"Bike Details";
			this->bikeDetailsToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::bikeDetailsToolStripMenuItem_Click);
			// 
			// salesToolStripMenuItem
			// 
			this->salesToolStripMenuItem->Name = L"salesToolStripMenuItem";
			this->salesToolStripMenuItem->Size = System::Drawing::Size(252, 42);
			this->salesToolStripMenuItem->Text = L"Sales";
			this->salesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::salesToolStripMenuItem_Click);
			// 
			// searchBarToolStripMenuItem
			// 
			this->searchBarToolStripMenuItem->Name = L"searchBarToolStripMenuItem";
			this->searchBarToolStripMenuItem->Size = System::Drawing::Size(252, 42);
			this->searchBarToolStripMenuItem->Text = L"Search Bar";
			this->searchBarToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::searchBarToolStripMenuItem_Click);
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 35);
			// 
			// tsslblDateTime
			// 
			this->tsslblDateTime->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tsslblDateTime->Name = L"tsslblDateTime";
			this->tsslblDateTime->Size = System::Drawing::Size(110, 37);
			this->tsslblDateTime->Text = L"Date Time";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(216, 37);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &frmMain::toolStripStatusLabel1_Click_1);
			// 
			// txtSearch1
			// 
			this->txtSearch1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch1->Location = System::Drawing::Point(131, 58);
			this->txtSearch1->Name = L"txtSearch1";
			this->txtSearch1->Size = System::Drawing::Size(774, 30);
			this->txtSearch1->TabIndex = 9;
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(1006, 657);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(119, 44);
			this->btnClear->TabIndex = 10;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &frmMain::btnClear_Click);
			// 
			// pictureBoxBike
			// 
			this->pictureBoxBike->Location = System::Drawing::Point(1190, 136);
			this->pictureBoxBike->Name = L"pictureBoxBike";
			this->pictureBoxBike->Size = System::Drawing::Size(675, 484);
			this->pictureBoxBike->TabIndex = 14;
			this->pictureBoxBike->TabStop = false;
			// 
			// btnRefresh
			// 
			this->btnRefresh->Location = System::Drawing::Point(744, 659);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(173, 41);
			this->btnRefresh->TabIndex = 15;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = true;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &frmMain::btnRefresh_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1909, 767);
			this->Controls->Add(this->btnRefresh);
			this->Controls->Add(this->pictureBoxBike);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->txtSearch1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->lstDisplayBike);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"frmMain";
			this->Text = L"frmMain";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBike))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolStripDropDownButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void statusStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e)
{
	//LoadBikesToList();
	 // Check initial state
}
private: System::Void toolStripDropDownButton1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	// Show confirmation dialog
	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Are you sure you want to Exit:\n\n",
		"Exit",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Warning
	);

	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		this->Close();
	}

}

private: System::Void addToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//frmSales^ saleDetails = gcnew frmSales();
	//saleDetails->ShowDialog();

		// Check if bikes are loaded
	if (bike == nullptr || bike->Count == 0)
	{
		MessageBox::Show("No bikes loaded. Please click File → Open first.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	// Pass both bikes AND sales (you need to create salesList in frmMain)
	//frmSales^ saleForm = gcnew frmSales(bike, salesList);

	// Pass the bike list to frmSales
	frmSales^ saleForm = gcnew frmSales(bike, salesList);
	saleForm->ShowDialog();

	// Refresh the main display after sales (stock may have changed)
	RefreshListBox();
}
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show(
		L"Bicycle Store Sales Management Application\n\n" +
		L"Version: 1.0\n" +
		L"Developer: KGOSANA MR\n" +
		L"223388841\n\n" +
		L"Tshwane University of Technology\n" +
		L"PGM216D - Assignment 2\n" +
		L"Copyright © 2026 \n" +
		L"All Rights Reserved",
		L"About",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
}
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Are you sure you want to Clear:\n\n",
		"clear",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Warning
	);

	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		txtSearch1->Clear();
		lstDisplayBike->Items->Clear();
		pictureBoxBike->Image = nullptr;
	}

}

private: void LoadBikePicture(int bikeId)
{
	try
	{
		// Image path relative to executable
		String^ imagePath = Application::StartupPath + "\\..\\..\\images\\" + bikeId + ".png";

		// Use the exact path where your images are stored
		//String^ imagePath = "C:\\Users\\MOTSHINA\\Desktop\\PGM2116 2026\\Assignment\\Assignment 2\\A2\\Bicycle_Services\\images\\" + bikeId + ".png";

		// Check if file exists
		if (System::IO::File::Exists(imagePath))
		{
			pictureBoxBike->Image = System::Drawing::Image::FromFile(imagePath);
			pictureBoxBike->SizeMode = PictureBoxSizeMode::Zoom;
		}
		else
		{
			// Try .jpg if .png not found
			imagePath = Application::StartupPath + "\\images\\" + bikeId + ".jpg";
			if (System::IO::File::Exists(imagePath))
			{
				pictureBoxBike->Image = System::Drawing::Image::FromFile(imagePath);
				pictureBoxBike->SizeMode = PictureBoxSizeMode::Zoom;
			}
			else
			{
				pictureBoxBike->Image = nullptr;
			}
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message, "Picture Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		pictureBoxBike->Image = nullptr;
	}
}
private: System::Void searchToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (txtSearch1->Text == nullptr || String::IsNullOrEmpty(txtSearch1->Text))
	{
		MessageBox::Show("Enter the info you want to search for.", "error searching",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}


	if (txtSearch1->Text != nullptr && !String::IsNullOrEmpty(txtSearch1->Text))
	{
		try
		{

				// Create search form
			frmSearch^ searchForm = gcnew frmSearch();

			// Pass the bike list using the property
			searchForm->BikeList = this->bike;

			// Pass the search text
			searchForm->SearchText = txtSearch1->Text;

			// Show the form
			searchForm->ShowDialog();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error opening search: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	
}

	   private: System::Void deleteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	   {
		   try
		   {
			   // Check if an item is selected in the listbox
			   if (lstDisplayBike->SelectedIndex < 0)
			   {
				   MessageBox::Show("Please select a Bicycle to delete.",
					   "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   return;
			   }

			   // Get the selected account from the accounts collection using the selected index
			   int selectedIndex = lstDisplayBike->SelectedIndex;
			   //customerAccounts^ selectedAccount = accounts[selectedIndex];

			   // Show confirmation dialog
			   System::Windows::Forms::DialogResult result = MessageBox::Show(
				   "Are you sure you want to delete Bicycle:\n\n" 
				 //  "Account No: " + selectedAccount->getAccountNo() + "\n" +
				   //"Customer: " + selectedAccount->getCustomerName(),
				  , "Confirm Delete",
				   MessageBoxButtons::YesNo,
				   MessageBoxIcon::Warning
			   );

			   if (result == System::Windows::Forms::DialogResult::Yes)
			   {
				   // Remove from accounts collection
				   bike->RemoveAt(selectedIndex);

				   // Remove from listbox display
				   lstDisplayBike->Items->RemoveAt(selectedIndex);

				   MessageBox::Show("Account deleted successfully!", "Success",
					   MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
		   }
		   catch (Exception^ ex)
		   {
			   MessageBox::Show("Error deleting account: " + ex->Message,
				   "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }
	   }

	private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (txtSearch1->Text == nullptr || String::IsNullOrEmpty(txtSearch1->Text))
		{
			MessageBox::Show("Enter the info you want to search for.", "error searching",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (txtSearch1->Text != nullptr && !String::IsNullOrEmpty(txtSearch1->Text))
		{
			try
			{
				// Create search form
				frmSearch^ searchForm = gcnew frmSearch();

				// Pass the bike list using the property
				searchForm->BikeList = this->bike;

				// Pass the search text
				searchForm->SearchText = txtSearch1->Text;

				// Show the form (ONCE, not twice)
				searchForm->ShowDialog();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error opening search: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
	private: System::Void bikeDetailsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmBikeDetails^ bicycleDetails = gcnew frmBikeDetails();
		bicycleDetails->ShowDialog();
	}

	private: System::Void salesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//frmSales^ saleDetails = gcnew frmSales();
		//saleDetails->ShowDialog();

			// Check if bikes are loaded
		if (bike == nullptr || bike->Count == 0)
		{
			MessageBox::Show("No bikes loaded. Please click File → Open first.", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Pass the bike list to frmSales
		frmSales^ saleForm = gcnew frmSales(bike, salesList);

		//frmSales^ saleForm = gcnew frmSales(bike);
		saleForm->ShowDialog();

		// Refresh the main display after sales (stock may have changed)
		RefreshListBox();
	}


	private: System::Void searchBarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Pass the bike list through constructor (LIKE YOUR MUNICIPALITY)
		/*frmSearch^ searchForm = gcnew frmSearch();
		searchForm->SearchText = txtSearch1->Text;
		searchForm->ShowDialog();*/

		if (txtSearch1->Text == nullptr || String::IsNullOrEmpty(txtSearch1->Text))
		{
			MessageBox::Show("Enter the info you want to search for.", "error searching",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}


		if (txtSearch1->Text != nullptr && !String::IsNullOrEmpty(txtSearch1->Text))
		{
			try
			{

				// Create search form
				frmSearch^ searchForm = gcnew frmSearch();

				// Pass the bike list using the property
				searchForm->BikeList = this->bike;

				// Pass the search text
				searchForm->SearchText = txtSearch1->Text;

				// Show the form
				searchForm->ShowDialog();

			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error opening search: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	}

	private: System::Void editBikeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Check if a bike is selected
		if (lstDisplayBike->SelectedIndex < 0)
		{
			MessageBox::Show("Please select a bike to edit.", "No Selection",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Get the selected bike
		Bicycle^ selectedBike = bike[lstDisplayBike->SelectedIndex];

		// Open frmBikeDetails with the selected bike
		frmBikeDetails^ bikeForm = gcnew frmBikeDetails(selectedBike);

		// Show the form
		bikeForm->ShowDialog();

		// Refresh the list after editing
		RefreshListBox();
	}

	private: System::Void deleteToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
	{

	}

	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
	
		//try
		//{
		//	// Clear existing data
		//	bike->Clear();
		//	lstDisplayBike->Items->Clear();

		//	// Open connection
		//	conn = gcnew SqlConnection(connString);
		//	conn->Open();

		//	// Select ALL bikes with their sales information
		//	SqlCommand^ command = gcnew SqlCommand(
		//		"SELECT b.BikeId, b.BikeName, b.Price, b.AvailableStock, b.ImagePath, " +
		//		"ISNULL(SUM(s.[Quantity Sold]), 0) as TotalSold, " +
		//		"ISNULL(SUM(s.[Cost Of Sales]), 0) as TotalCost, " +
		//		"ISNULL(AVG(s.[Commission Percent]), 0) as AvgCommission " +
		//		"FROM Bike b " +
		//		"LEFT JOIN Sales s ON b.BikeId = s.BikeId " +
		//		"GROUP BY b.BikeId, b.BikeName, b.Price, b.AvailableStock, b.ImagePath", conn);

		//	SqlDataReader^ reader = command->ExecuteReader();

		//	// Read each row and store in Bicycle object
		//	while (reader->Read())
		//	{
		//		// Create new Bicycle object
		//		Bicycle^ newBike = gcnew Bicycle();

		//		// Store bike data
		//		newBike->setBikeId(reader->GetInt32(0));        // BikeId
		//		newBike->setBikeName(reader->GetString(1));     // BikeName
		//		newBike->setPrice(Convert::ToDouble(reader->GetValue(2)));       // Price
		//		newBike->setAvailableStock(reader->GetInt32(3)); // AvailableStock

		//		// Handle NULL for ImagePath
		//		if (reader->IsDBNull(4))
		//			newBike->setImagePath("");
		//		else
		//			newBike->setImagePath(reader->GetString(4)); // ImagePath

		//		// Get total sold from sales
		//		int totalSold = reader->GetInt32(5);

		//		// Add to local List
		//		bike->Add(newBike);

		//		String^ stockDisplay;
		//		if (newBike->getAvailableStock() == 0)
		//			stockDisplay = "OUT OF STOCK";
		//		else
		//			stockDisplay = newBike->getAvailableStock().ToString();

		//		// Format the bike name
		//		String^ bikeNameDisplay = newBike->getBikeName();
		//		if (bikeNameDisplay->Length > 50)
		//		{
		//			bikeNameDisplay = bikeNameDisplay->Substring(0, 37) + "...";
		//		}
		//		else
		//		{
		//			bikeNameDisplay = bikeNameDisplay->Substring(0, 37);
		//		}

		//		// Display bike info with total sold
		//		lstDisplayBike->Items->Add(String::Format(
		//			"{0,-3}   {1,-40}   R{2,8:N2}   {3,-12}   Sold: {4}",
		//			newBike->getBikeId().ToString(),
		//			bikeNameDisplay,
		//			newBike->getPrice(),
		//			stockDisplay,
		//			totalSold
		//		));
		//	}

		//	reader->Close();
		//	conn->Close();

		//	MessageBox::Show("Loaded " + bike->Count + " bikes with sales data from database!",
		//		"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		//}
		//catch (Exception^ ex)
		//{
		//	MessageBox::Show("Error: " + ex->Message, "Error",
		//		MessageBoxButtons::OK, MessageBoxIcon::Error);
		//}

		try
		{
			// Clear existing data
			bike->Clear();
			salesList->Clear();  // ← ADD THIS - Clear sales list too
			lstDisplayBike->Items->Clear();

			// Open connection
			conn = gcnew SqlConnection(connString);
			conn->Open();

			// Select ALL bikes with their sales information
			SqlCommand^ command = gcnew SqlCommand(
				"SELECT b.BikeId, b.BikeName, b.Price, b.AvailableStock, b.ImagePath, " +
				"ISNULL(SUM(s.[Quantity Sold]), 0) as TotalSold " +
				"FROM Bike b " +
				"LEFT JOIN Sales s ON b.BikeId = s.BikeId " +
				"GROUP BY b.BikeId, b.BikeName, b.Price, b.AvailableStock, b.ImagePath", conn);

			SqlDataReader^ reader = command->ExecuteReader();

			// Read each row and store in Bicycle object
			while (reader->Read())
			{
				// Create new Bicycle object
				Bicycle^ newBike = gcnew Bicycle();

				// Store bike data
				newBike->setBikeId(reader->GetInt32(0));
				newBike->setBikeName(reader->GetString(1));
				newBike->setPrice(Convert::ToDouble(reader->GetValue(2)));
				newBike->setAvailableStock(reader->GetInt32(3));

				// Handle NULL for ImagePath
				if (reader->IsDBNull(4))
					newBike->setImagePath("");
				else
					newBike->setImagePath(reader->GetString(4));

				// Get total sold from sales
				int totalSold = reader->GetInt32(5);

				// Add to local List
				bike->Add(newBike);

				String^ stockDisplay = (newBike->getAvailableStock() == 0) ? "OUT OF STOCK" : newBike->getAvailableStock().ToString();

				// Format the bike name
				String^ bikeNameDisplay = newBike->getBikeName();
				if (bikeNameDisplay->Length > 50)
					bikeNameDisplay = bikeNameDisplay->Substring(0, 37) + "...";
				else
					bikeNameDisplay = bikeNameDisplay->Substring(0, 37);

				// Display bike info with total sold
				lstDisplayBike->Items->Add(String::Format(
					"{0,-3}   {1,-40}   R{2,8:N2}   {3,-12}   Sold: {4}",
					newBike->getBikeId().ToString(),
					bikeNameDisplay,
					newBike->getPrice(),
					stockDisplay,
					totalSold
				));
			}
			reader->Close();

			// ========== ADD THIS - LOAD SALES INTO SALE CLASS ==========
			SqlCommand^ saleCmd = gcnew SqlCommand(
				"SELECT SaleId, BikeId, [Quantity Sold], SaleDate, [Cost Of Sales], [Commission Percent] FROM Sales", conn);

			SqlDataReader^ saleReader = saleCmd->ExecuteReader();

			while (saleReader->Read())
			{
				Sale^ newSale = gcnew Sale();
				newSale->setSaleId(saleReader->GetInt32(0));
				newSale->setBikeId(saleReader->GetInt32(1));
				newSale->setQuantitySold(saleReader->GetInt32(2));
				newSale->setSaleDate(saleReader->GetDateTime(3));
				newSale->setCostOfSale((double)saleReader->GetDecimal(4));
				newSale->setCommissionPercent((double)saleReader->GetDecimal(5));

				salesList->Add(newSale);
			}
			saleReader->Close();
			// ========== END OF ADDED CODE ==========

			conn->Close();

		/*	MessageBox::Show("Loaded " + bike->Count + " bikes and " + salesList->Count + " sales from database!",
				"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);*/
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}



	}

	private: void RefreshListBox()
	{
		lstDisplayBike->Items->Clear();

		for each (Bicycle ^ b in bike)
		{
			String^ stockDisplay = (b->getAvailableStock() == 0) ? "OUT OF STOCK" : b->getAvailableStock().ToString();

			lstDisplayBike->Items->Add(String::Format(
				"{0,-3}   {1,-40}   R{2,8:N2}   {3,-12}",
				b->getBikeId().ToString(),
				b->getBikeName(),
				b->getPrice(),
				stockDisplay
			));
		}
	}


	private: System::Void ascendingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Bubble sort algorithm
		for (int i = 0; i < bike->Count - 1; i++)
		{
			for (int j = 0; j < bike->Count - i - 1; j++)
			{
				// Compare prices
				if (bike[j]->getPrice() > bike[j + 1]->getPrice())
				{
					// Swap the bikes
					Bicycle^ temp = bike[j];
					bike[j] = bike[j + 1];
					bike[j + 1] = temp;
				}
			}
		}

		// Refresh the display
		RefreshListBox();

		MessageBox::Show("Bikes sorted by Price (Lowest to Highest)", "Sort Complete",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void descendingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Bubble sort algorithm
		for (int i = 0; i < bike->Count - 1; i++)
		{
			for (int j = 0; j < bike->Count - i - 1; j++)
			{
				// Compare prices
				if (bike[j]->getPrice() < bike[j + 1]->getPrice())
				{
					// Swap the bikes
					Bicycle^ temp = bike[j];
					bike[j] = bike[j + 1];
					bike[j + 1] = temp;
				}
			}
		}

		// Refresh the display
		RefreshListBox();

		MessageBox::Show("Bikes sorted by Price (Highest to Lowest)", "Sort Complete",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void descendingToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Bubble sort algorithm
		for (int i = 0; i < bike->Count - 1; i++)
		{
			for (int j = 0; j < bike->Count - i - 1; j++)
			{
				// Compare bike names (case insensitive)
				if (String::Compare(bike[j]->getBikeName(), bike[j + 1]->getBikeName(), true) < 0)
				{
					// Swap the bikes
					Bicycle^ temp = bike[j];
					bike[j] = bike[j + 1];
					bike[j + 1] = temp;
				}
			}
		}

		// Refresh the display
		RefreshListBox();
	}

	private: System::Void priceToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}

	private: System::Void ascendingToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Bubble sort algorithm
		for (int i = 0; i < bike->Count - 1; i++)
		{
			for (int j = 0; j < bike->Count - i - 1; j++)
			{
				// Compare bike names (case insensitive)
				if (String::Compare(bike[j]->getBikeName(), bike[j + 1]->getBikeName(), true) > 0)
				{
					// Swap the bikes
					Bicycle^ temp = bike[j];
					bike[j] = bike[j + 1];
					bike[j + 1] = temp;
				}
			}
		}

		// Refresh the display
		RefreshListBox();
	}

	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			// Open database connection
			conn = gcnew SqlConnection(connString);
			conn->Open();

			int savedCount = 0;
			int updatedCount = 0;

			// Loop through each bike in your local list
			for each (Bicycle ^ b in bike)
			{
				if (b->getBikeId() == 0)
				{
					// INSERT new bike (no ID yet)
					SqlCommand^ cmd = gcnew SqlCommand(
						"INSERT INTO Bike (BikeName, Price, AvailableStock, ImagePath) VALUES (@Name, @Price, @Stock, @ImagePath)",
						conn);

					cmd->Parameters->AddWithValue("@Name", b->getBikeName());
					cmd->Parameters->AddWithValue("@Price", b->getPrice());
					cmd->Parameters->AddWithValue("@Stock", b->getAvailableStock());

					if (String::IsNullOrEmpty(b->getImagePath()))
						cmd->Parameters->AddWithValue("@ImagePath", DBNull::Value);
					else
						cmd->Parameters->AddWithValue("@ImagePath", b->getImagePath());

					cmd->ExecuteNonQuery();

					// Get the new ID
					SqlCommand^ idCmd = gcnew SqlCommand("SELECT SCOPE_IDENTITY()", conn);
					int newId = Convert::ToInt32(idCmd->ExecuteScalar());
					b->setBikeId(newId);

					savedCount++;
				}
				else
				{
					// UPDATE existing bike
					SqlCommand^ cmd = gcnew SqlCommand(
						"UPDATE Bike SET BikeName = @Name, Price = @Price, AvailableStock = @Stock, ImagePath = @ImagePath WHERE BikeId = @Id",
						conn);

					cmd->Parameters->AddWithValue("@Id", b->getBikeId());
					cmd->Parameters->AddWithValue("@Name", b->getBikeName());
					cmd->Parameters->AddWithValue("@Price", b->getPrice());
					cmd->Parameters->AddWithValue("@Stock", b->getAvailableStock());

					if (String::IsNullOrEmpty(b->getImagePath()))
						cmd->Parameters->AddWithValue("@ImagePath", DBNull::Value);
					else
						cmd->Parameters->AddWithValue("@ImagePath", b->getImagePath());

					cmd->ExecuteNonQuery();
					updatedCount++;
				}
			}

			// Close connection
			conn->Close();

			// Show success message
			MessageBox::Show(String::Format("Saved successfully!\n\nNew bikes added: {0}\nBikes updated: {1}\nTotal: {2}",
				savedCount, updatedCount, bike->Count),
				"Save Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error saving to database: " + ex->Message,
				"Save Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void deleteToolStripMenuItem_Click_2(System::Object^ sender, System::EventArgs^ e)
	{
		// Check if something is selected
		if (lstDisplayBike->SelectedIndex == -1)
		{
			MessageBox::Show("Please select a bike to delete.", "No Selection",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
		 
		// Confirm with user
		System::Windows::Forms::DialogResult confirm = MessageBox::Show("Delete selected bike?", "Confirm Delete",
			System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question);

		if (confirm == System::Windows::Forms::DialogResult::Yes)
		{
			int selectedIndex = lstDisplayBike->SelectedIndex;
			Bicycle^ bikeToDelete = bike[selectedIndex];

			try
			{
				// Delete from database
				conn = gcnew SqlConnection(connString);
				conn->Open();

				SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Bike WHERE BikeId = @Id", conn);
				cmd->Parameters->AddWithValue("@Id", bikeToDelete->getBikeId());
				cmd->ExecuteNonQuery();

				conn->Close();

				// Delete from local list
				bike->RemoveAt(selectedIndex);
				lstDisplayBike->Items->RemoveAt(selectedIndex);
				pictureBoxBike->Image = nullptr;

				MessageBox::Show("Bike deleted successfully!", "Success",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Delete failed: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void lstDisplayBike_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{

		if (lstDisplayBike->SelectedIndex >= 0)
		{
			// Get the selected bike from your list
			Bicycle^ selectedBike = bike[lstDisplayBike->SelectedIndex];

			// Get the bike ID
			int bikeId = selectedBike->getBikeId();

			// Call the method to load the picture
			LoadBikePicture(bikeId);
		}

	}

	private: System::Void statusStrip1_ItemClicked_1(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) 
	{

	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		// Get current date and time with seconds
		String^ currentDateTime = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");

		// Update the status strip label
		//tsslblDateTime->Text = "Date/Time: " + currentDateTime;

		// Update status strip with both record count and time
		toolStripStatusLabel1->Text = String::Format("Records: {0}  |  Date/Time: {1}",
			bike->Count, currentDateTime);
	}

	private: System::Void toolStripStatusLabel1_Click_1(System::Object^ sender, System::EventArgs^ e)
	{

	}

	private: System::Void editToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}

	private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		RefreshListBox();
		MessageBox::Show("List refreshed!", "Refresh",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

};
}
