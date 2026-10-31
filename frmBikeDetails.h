#pragma once
#include "Bicycle.h"
#include "Sale.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::IO;


namespace BicycleServices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for frmBikeDetails
	/// </summary>
	public ref class frmBikeDetails : public System::Windows::Forms::Form
	{
	public:
		frmBikeDetails(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			currentBike = gcnew Bicycle();
			isEditMode = false;
			this->Text = "Add New Bicycle";
			txtBicycleID->ReadOnly = true;
			connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=BicycleDB;Integrated Security=True";

		}

		// Constructor that receives bike to edit (from frmMain)
		frmBikeDetails(Bicycle^ bike)
		{
			InitializeComponent();
			currentBike = bike;
			isEditMode = true;
			this->Text = "Edit Bicycle";
			txtBicycleID->ReadOnly = true;
			connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=BicycleDB;Integrated Security=True";

			// Initialize timer
			timer1 = gcnew System::Windows::Forms::Timer();
			timer1->Interval = 1000;  // 1 second
			timer1->Tick += gcnew System::EventHandler(this, &frmBikeDetails::timer1_Tick);
			timer1->Start();

			// Load bike data into form
			LoadBikeData();
		}

		// Property to get edited bike
		property Bicycle^ CurrentBike
		{
			Bicycle^ get() { return currentBike; }
		}

	private: void InitializeTimer()
	{
		timer1 = gcnew System::Windows::Forms::Timer();
		timer1->Interval = 1000;  // 1 second
		timer1->Tick += gcnew System::EventHandler(this, &frmBikeDetails::timer1_Tick);
		timer1->Start();
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmBikeDetails()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBicycleID;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtBicycleName;
	private: System::Windows::Forms::TextBox^ txtavailableStock;


	private: System::Windows::Forms::MaskedTextBox^ mtxtPrice;



	private: System::Windows::Forms::Button^ btnClear;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ListBox^ lstBikeDetails;

	private: System::Windows::Forms::Button^ btnUpdates;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
			// Data
		Bicycle^ currentBike;
		bool isEditMode;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
		   String^ connString;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->txtBicycleID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtBicycleName = (gcnew System::Windows::Forms::TextBox());
			this->txtavailableStock = (gcnew System::Windows::Forms::TextBox());
			this->mtxtPrice = (gcnew System::Windows::Forms::MaskedTextBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnUpdates = (gcnew System::Windows::Forms::Button());
			this->lstBikeDetails = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtBicycleID
			// 
			this->txtBicycleID->Location = System::Drawing::Point(276, 28);
			this->txtBicycleID->Name = L"txtBicycleID";
			this->txtBicycleID->Size = System::Drawing::Size(469, 27);
			this->txtBicycleID->TabIndex = 0;
			this->txtBicycleID->TextChanged += gcnew System::EventHandler(this, &frmBikeDetails::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(66, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Bicycle ID : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(66, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Bicycle Name : ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(66, 187);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Price : ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(66, 265);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(138, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Available Stock : ";
			// 
			// txtBicycleName
			// 
			this->txtBicycleName->Location = System::Drawing::Point(276, 108);
			this->txtBicycleName->Name = L"txtBicycleName";
			this->txtBicycleName->Size = System::Drawing::Size(469, 27);
			this->txtBicycleName->TabIndex = 6;
			// 
			// txtavailableStock
			// 
			this->txtavailableStock->Location = System::Drawing::Point(276, 262);
			this->txtavailableStock->Name = L"txtavailableStock";
			this->txtavailableStock->Size = System::Drawing::Size(469, 27);
			this->txtavailableStock->TabIndex = 7;
			// 
			// mtxtPrice
			// 
			this->mtxtPrice->Location = System::Drawing::Point(276, 184);
			this->mtxtPrice->Name = L"mtxtPrice";
			this->mtxtPrice->Size = System::Drawing::Size(469, 27);
			this->mtxtPrice->TabIndex = 8;
			// 
			// btnClear
			// 
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(598, 346);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(147, 50);
			this->btnClear->TabIndex = 10;
			this->btnClear->Text = L"Clear ";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &frmBikeDetails::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnUpdates);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->btnClear);
			this->groupBox1->Controls->Add(this->txtBicycleID);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->mtxtPrice);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->txtavailableStock);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->txtBicycleName);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(58, 597);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(814, 420);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Bicycle Details";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmBikeDetails::groupBox1_Enter);
			// 
			// btnUpdates
			// 
			this->btnUpdates->Location = System::Drawing::Point(407, 346);
			this->btnUpdates->Name = L"btnUpdates";
			this->btnUpdates->Size = System::Drawing::Size(132, 50);
			this->btnUpdates->TabIndex = 11;
			this->btnUpdates->Text = L"Update";
			this->btnUpdates->UseVisualStyleBackColor = true;
			this->btnUpdates->Click += gcnew System::EventHandler(this, &frmBikeDetails::btnUpdates_Click);
			// 
			// lstBikeDetails
			// 
			this->lstBikeDetails->FormattingEnabled = true;
			this->lstBikeDetails->ItemHeight = 16;
			this->lstBikeDetails->Location = System::Drawing::Point(58, 51);
			this->lstBikeDetails->Name = L"lstBikeDetails";
			this->lstBikeDetails->Size = System::Drawing::Size(745, 500);
			this->lstBikeDetails->TabIndex = 12;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(855, 51);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(567, 500);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &frmBikeDetails::timer1_Tick);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 1037);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1492, 26);
			this->statusStrip1->TabIndex = 14;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(151, 20);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &frmBikeDetails::toolStripStatusLabel1_Click);
			// 
			// frmBikeDetails
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1492, 1063);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lstBikeDetails);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmBikeDetails";
			this->Text = L"frmBikeDetails";
			this->Load += gcnew System::EventHandler(this, &frmBikeDetails::frmBikeDetails_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("Are you syre you want to Clear!! ", "Clear Form",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			lstBikeDetails->Items->Clear();
			mtxtPrice->Clear();
			txtavailableStock->Clear();
			txtBicycleID->Clear();
			txtBicycleName->Clear();
			pictureBox1->Image = nullptr;
		}
	}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void frmBikeDetails_Load(System::Object^ sender, System::EventArgs^ e) {
}


	   // Load bike data into form (for Edit mode)
	   void LoadBikeData()
	   {
		   if (currentBike != nullptr)
		   {
			   txtBicycleID->Text = currentBike->getBikeId().ToString();
			   txtBicycleName->Text = currentBike->getBikeName();
			   mtxtPrice->Text = currentBike->getPrice().ToString("N2");
			   txtavailableStock->Text = currentBike->getAvailableStock().ToString();
			   //pictureBox1->Text = currentBike->getImagePath();

			   // Load the picture
			   LoadBikePicture(currentBike->getBikeId());

			   // Display details in ListBox
			   DisplayBikeDetails();
		   }
	   }

	   // Load bike picture
	   void LoadBikePicture(int bikeId)
	   {
		   try
		   {
			   String^ imagePath = Application::StartupPath + "\\..\\..\\images\\" + bikeId + ".png";

			   if (File::Exists(imagePath))
			   {
				   pictureBox1->Image = Image::FromFile(imagePath);
				   pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
			   }
			   else
			   {
				   pictureBox1->Image = nullptr;
			   }
		   }
		   catch (Exception^)
		   {
			   pictureBox1->Image = nullptr;
		   }
	   }

	   // Display bike details in ListBox
	   void DisplayBikeDetails()
	   {
		   lstBikeDetails->Items->Clear();

		   lstBikeDetails->Items->Add("========== BICYCLE DETAILS ==========");
		   lstBikeDetails->Items->Add("");
		   lstBikeDetails->Items->Add(String::Format("Bicycle ID:       {0}", currentBike->getBikeId()));
		   lstBikeDetails->Items->Add(String::Format("Bicycle Name:     {0}", currentBike->getBikeName()));
		   lstBikeDetails->Items->Add(String::Format("Price:            R {0:N2}", currentBike->getPrice()));
		   lstBikeDetails->Items->Add(String::Format("Available Stock:  {0}", currentBike->getAvailableStock()));
		   lstBikeDetails->Items->Add(String::Format("Image Path:       {0}", currentBike->getImagePath()));
		   lstBikeDetails->Items->Add("");
		   lstBikeDetails->Items->Add("=====================================");
	   }

	   // Validate input
	   bool ValidateInput()
	   {
		   if (String::IsNullOrWhiteSpace(txtBicycleName->Text))
		   {
			   MessageBox::Show("Please enter a bicycle name.", "Validation Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   return false;
		   }

		   double price;
		   if (!Double::TryParse(mtxtPrice->Text, price) || price <= 0)
		   {
			   MessageBox::Show("Please enter a valid price (greater than 0).", "Validation Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   return false;
		   }

		   int stock;
		   if (!Int32::TryParse(txtavailableStock->Text, stock) || stock < 0)
		   {
			   MessageBox::Show("Please enter a valid stock quantity (0 or more).", "Validation Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   return false;
		   }

		   return true;
	   }

	   // Browse for image
		private: System::Void btnBrowse_Click(System::Object^ sender, System::EventArgs^ e)
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Title = "Select Bike Image";
			openFileDialog->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				txtavailableStock->Text = openFileDialog->FileName;

				try
				{
					pictureBox1->Image = Image::FromFile(openFileDialog->FileName);
					pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
				}
				catch (Exception^) {}
			}
		}

			   // Save button click
		private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidateInput())
				return;

			// Update the bike object
			currentBike->setBikeName(txtBicycleName->Text);
			currentBike->setPrice(Double::Parse(mtxtPrice->Text));
			currentBike->setAvailableStock(Int32::Parse(txtavailableStock->Text));
			//currentBike->setImagePath(txtImagePath->Text);
			
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}

			   // Cancel button click
		private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Close();
		}

		private: void UpdateBikeInDatabase()
		{
			// Validate input first
			if (!ValidateInput())
				return;

			// Update the bike object with new values
			currentBike->setBikeName(txtBicycleName->Text);
			currentBike->setPrice(Double::Parse(mtxtPrice->Text));
			currentBike->setAvailableStock(Int32::Parse(txtavailableStock->Text));

			// Refresh the display in ListBox
			DisplayBikeDetails();

			// Show success message
			MessageBox::Show("Bicycle updated successfully!", "Update Complete",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}


	private: System::Void btnUpdates_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!ValidateInput())
			return;

		// Update the bike object
		currentBike->setBikeName(txtBicycleName->Text);
		currentBike->setPrice(Double::Parse(mtxtPrice->Text));
		currentBike->setAvailableStock(Int32::Parse(txtavailableStock->Text));

		// Update display
		DisplayBikeDetails();

		// Save to database
		UpdateBikeInDatabase();

		MessageBox::Show("Bicycle updated successfully!", "Update Complete",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	if (toolStripStatusLabel1 != nullptr)
	{
		toolStripStatusLabel1->Text = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
	}
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) 
{

}
};
}
