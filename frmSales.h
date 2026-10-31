#pragma once
#include "Bicycle.h"
#include "Sale.h"



namespace BicycleServices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	/// <summary>
	/// Summary for frmSales
	/// </summary>
	public ref class frmSales : public System::Windows::Forms::Form
	{
	public:
		frmSales(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			bikeList = gcnew List<Bicycle^>();
			salesList = gcnew List<Sale^> ();
			connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=BicycleDB;Integrated Security=True";
			LoadBikesIntoComboBox();

		}

		//// Constructor that receives bike list from frmMain
		//frmSales(List<Bicycle^>^ bikes)
		//{
		//	InitializeComponent();

		//	// STORE THE RECEIVED DATA
		//	this->bikeList = bikes;
		//	this->selectedBike = nullptr;

		//	// Initialize timer
		//	timer1 = gcnew System::Windows::Forms::Timer();
		//	timer1->Interval = 1000;  // 1 second
		//	timer1->Tick += gcnew System::EventHandler(this, &frmSales::timer1_Tick);
		//	timer1->Start();

		//	// Load bikes into combo box
		//	LoadBikesIntoComboBox();
		//}


		// Constructor that receives both bikes AND sales
		frmSales(List<Bicycle^>^ bikes, List<Sale^>^ sales)
		{
			InitializeComponent();
			this->bikeList = bikes;
			this->salesList = sales;
			this->selectedBike = nullptr;

			// Setup timer
			timer1 = gcnew System::Windows::Forms::Timer();
			timer1->Interval = 1000;
			timer1->Tick += gcnew System::EventHandler(this, &frmSales::timer1_Tick);
			timer1->Start();

			LoadBikesIntoComboBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmSales()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ txtProfit;

	private: System::Windows::Forms::TextBox^ txtComission;

	private: System::Windows::Forms::TextBox^ txtCostOfSales;

	private: System::Windows::Forms::TextBox^ txtQuantitySold;

	private: System::Windows::Forms::TextBox^ txtAvailableStock;

	private: System::Windows::Forms::TextBox^ txtPrice;

	private: System::Windows::Forms::TextBox^ txtBikeName;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnClear;





	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;
	private: System::Windows::Forms::TextBox^ txtSalesId;
	private: System::Windows::Forms::TextBox^ txtBikeId;
	private: System::Windows::Forms::Label^ label10;

	protected:

	private: System::ComponentModel::IContainer^ components;

	private:

		List<Bicycle^>^ bikeList;
		List<Sale^>^ salesList;  // ← Add this for sales data
		Bicycle^ selectedBike;
		Sale^ selectedSale;
		bool isViewMode;

	private: System::Windows::Forms::ComboBox^ cmbBicycleId;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ btnCalculate;
private: System::Windows::Forms::Timer^ timer1;
private: System::Windows::Forms::StatusStrip^ statusStrip1;
private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	   String^ connString;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtSalesId = (gcnew System::Windows::Forms::TextBox());
			this->txtBikeId = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtProfit = (gcnew System::Windows::Forms::TextBox());
			this->txtComission = (gcnew System::Windows::Forms::TextBox());
			this->txtCostOfSales = (gcnew System::Windows::Forms::TextBox());
			this->txtQuantitySold = (gcnew System::Windows::Forms::TextBox());
			this->txtAvailableStock = (gcnew System::Windows::Forms::TextBox());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());
			this->txtBikeName = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->cmbBicycleId = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(48, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Record Sale";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtSalesId);
			this->groupBox1->Controls->Add(this->txtBikeId);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->txtProfit);
			this->groupBox1->Controls->Add(this->txtComission);
			this->groupBox1->Controls->Add(this->txtCostOfSales);
			this->groupBox1->Controls->Add(this->txtQuantitySold);
			this->groupBox1->Controls->Add(this->txtAvailableStock);
			this->groupBox1->Controls->Add(this->txtPrice);
			this->groupBox1->Controls->Add(this->txtBikeName);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(49, 170);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(844, 660);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sale Details";
			// 
			// txtSalesId
			// 
			this->txtSalesId->Location = System::Drawing::Point(363, 50);
			this->txtSalesId->Name = L"txtSalesId";
			this->txtSalesId->Size = System::Drawing::Size(426, 27);
			this->txtSalesId->TabIndex = 16;
			// 
			// txtBikeId
			// 
			this->txtBikeId->Location = System::Drawing::Point(363, 106);
			this->txtBikeId->Name = L"txtBikeId";
			this->txtBikeId->Size = System::Drawing::Size(426, 27);
			this->txtBikeId->TabIndex = 15;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(56, 53);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 20);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Sales ID : ";
			// 
			// txtProfit
			// 
			this->txtProfit->Location = System::Drawing::Point(363, 592);
			this->txtProfit->Name = L"txtProfit";
			this->txtProfit->Size = System::Drawing::Size(426, 27);
			this->txtProfit->TabIndex = 14;
			// 
			// txtComission
			// 
			this->txtComission->Location = System::Drawing::Point(363, 518);
			this->txtComission->Name = L"txtComission";
			this->txtComission->Size = System::Drawing::Size(426, 27);
			this->txtComission->TabIndex = 13;
			// 
			// txtCostOfSales
			// 
			this->txtCostOfSales->Location = System::Drawing::Point(363, 461);
			this->txtCostOfSales->Name = L"txtCostOfSales";
			this->txtCostOfSales->Size = System::Drawing::Size(426, 27);
			this->txtCostOfSales->TabIndex = 12;
			// 
			// txtQuantitySold
			// 
			this->txtQuantitySold->Location = System::Drawing::Point(363, 398);
			this->txtQuantitySold->Name = L"txtQuantitySold";
			this->txtQuantitySold->Size = System::Drawing::Size(426, 27);
			this->txtQuantitySold->TabIndex = 11;
			// 
			// txtAvailableStock
			// 
			this->txtAvailableStock->Location = System::Drawing::Point(363, 301);
			this->txtAvailableStock->Name = L"txtAvailableStock";
			this->txtAvailableStock->Size = System::Drawing::Size(426, 27);
			this->txtAvailableStock->TabIndex = 10;
			// 
			// txtPrice
			// 
			this->txtPrice->Location = System::Drawing::Point(363, 231);
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(426, 27);
			this->txtPrice->TabIndex = 9;
			// 
			// txtBikeName
			// 
			this->txtBikeName->Location = System::Drawing::Point(363, 167);
			this->txtBikeName->Name = L"txtBikeName";
			this->txtBikeName->Size = System::Drawing::Size(426, 27);
			this->txtBikeName->TabIndex = 8;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(57, 595);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 20);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Profit : ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(57, 525);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 20);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Commission  (%) : ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(56, 464);
			this->label7->Name = L"label7";
			this->label7->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label7->Size = System::Drawing::Size(125, 20);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Cost of Sales : ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(56, 401);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(124, 20);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Quantity Sold : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Bicycle ID : ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(55, 174);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Bicycle Name : ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(55, 238);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Price : ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(55, 308);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(138, 20);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Available Stock : ";
			this->label5->Click += gcnew System::EventHandler(this, &frmSales::label5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(1167, 123);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(507, 360);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSave->Location = System::Drawing::Point(745, 874);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(148, 54);
			this->btnSave->TabIndex = 7;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmSales::button1_Click);
			// 
			// btnClear
			// 
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(566, 874);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(145, 54);
			this->btnClear->TabIndex = 8;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &frmSales::button2_Click);
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(1167, 495);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 9;
			// 
			// cmbBicycleId
			// 
			this->cmbBicycleId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbBicycleId->FormattingEnabled = true;
			this->cmbBicycleId->Location = System::Drawing::Point(416, 93);
			this->cmbBicycleId->Name = L"cmbBicycleId";
			this->cmbBicycleId->Size = System::Drawing::Size(426, 33);
			this->cmbBicycleId->TabIndex = 10;
			this->cmbBicycleId->SelectedIndexChanged += gcnew System::EventHandler(this, &frmSales::cmbBicycleId_SelectedIndexChanged_1);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(62, 93);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(131, 25);
			this->label11->TabIndex = 17;
			this->label11->Text = L"Bicycle Name";
			// 
			// btnCalculate
			// 
			this->btnCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCalculate->Location = System::Drawing::Point(360, 874);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(148, 54);
			this->btnCalculate->TabIndex = 18;
			this->btnCalculate->Text = L"Calculate Profit";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &frmSales::btnCalculate_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &frmSales::timer1_Tick);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 931);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1746, 26);
			this->statusStrip1->TabIndex = 19;
			this->statusStrip1->Text = L"statusStrip1";
			this->statusStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &frmSales::statusStrip1_ItemClicked);
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(151, 20);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &frmSales::toolStripStatusLabel1_Click);
			// 
			// frmSales
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1746, 957);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->cmbBicycleId);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Name = L"frmSales";
			this->Text = L"frmSales";
			this->Load += gcnew System::EventHandler(this, &frmSales::frmSales_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}

	private: System::Void frmSales_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		// Check if salesList exists
		if (salesList == nullptr)
		{
			MessageBox::Show("salesList is NULL - No sales data loaded", "Debug",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		// Check if salesList has items
		if (salesList->Count == 0)
		{
			MessageBox::Show("salesList is EMPTY - No sales records found", "Debug",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		// Display each sale
		/*for (int i = 0; i < salesList->Count; i++)
		{
			MessageBox::Show("Sale " + (i + 1) + ":\n" +
				"Sale ID: " + salesList[i]->getSaleId() + "\n" +
				"Quantity Sold: " + salesList[i]->getQuantitySold(),
				"Sales Data", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}*/
	}

	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("Do you want to clear the Sales", "Clear Sales",
			System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			//cmbBike->SelectedIndex = -1;
			txtSalesId->Clear();
			txtBikeId->Clear();
			txtBikeName->Clear();
			txtAvailableStock->Clear();
			txtComission->Clear();
			txtCostOfSales->Clear();
			txtPrice->Clear();
			txtProfit->Clear();
			txtQuantitySold->Clear();

		}
	}

		   // Load bikes into ComboBox from the class list
		   void LoadBikesIntoComboBox()
		   {
			   cmbBicycleId->Items->Clear();

			   if (bikeList == nullptr || bikeList->Count == 0)
			   {
				  // MessageBox::Show("No bikes available. Please load bikes first.", "Error");
				   return;
			   }

			   // Add Bike Name to ComboBox (not ID)
			   for each (Bicycle ^ bike in bikeList)
			   {
				   cmbBicycleId->Items->Add(bike->getBikeName());  // ← Display Name
			   }

			   if (cmbBicycleId->Items->Count > 0)
				   cmbBicycleId->SelectedIndex = 0;

		   }


		   // Load bike picture
		   void LoadBikePicture(int bikeId)
		   {
			   try
			   {
				   String^ imagePath = Application::StartupPath + "\\..\\..\\images\\" + bikeId + ".png";
				   if (System::IO::File::Exists(imagePath))
				   {
					   pictureBox1->Image = System::Drawing::Image::FromFile(imagePath);
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

		   // Get sales for specific bike from salesList
		   List<Sale^>^ GetSalesForBike(int bikeId)
		   {
			   List<Sale^>^ bikeSales = gcnew List<Sale^>();

			   if (salesList != nullptr)
			   {
				   for each (Sale ^ sale in salesList)
				   {
					   if (sale->getBikeId() == bikeId)
					   {
						   bikeSales->Add(sale);
					   }
				   }
			   }
			   return bikeSales;
		   }

		   
	private: System::Void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (selectedBike == nullptr)
		{
			MessageBox::Show("Please select a bicycle first.");
			return;
		}

		int quantity;
		double costOfSale;
		double commission;

		if (!Int32::TryParse(txtQuantitySold->Text, quantity) || quantity <= 0)
		{
			MessageBox::Show("Enter valid quantity.");
			return;
		}

		if (!Double::TryParse(txtCostOfSales->Text, costOfSale) || costOfSale < 0)
		{
			MessageBox::Show("Enter valid cost of sale.");
			return;
		}

		if (!Double::TryParse(txtComission->Text, commission) || commission < 0 || commission > 100)
		{
			MessageBox::Show("Enter valid commission (0-100).");
			return;
		}

		double sellingPrice = selectedBike->getPrice();
		double revenue = sellingPrice * quantity;
		double cost = costOfSale * quantity;
		double commissionAmount = sellingPrice * quantity * (commission / 100);
		double profit = revenue - cost - commissionAmount;

		txtProfit->Text = "R " + profit.ToString("N2");

	
	}	

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (selectedBike == nullptr)
		{
			MessageBox::Show("Please select a bicycle first.");
			return;
		}

		int quantity;
		double costOfSale;
		double commission;

		if (!Int32::TryParse(txtQuantitySold->Text, quantity) || quantity <= 0)
		{
			MessageBox::Show("Enter valid quantity.");
			return;
		}

		if (!Double::TryParse(txtCostOfSales->Text, costOfSale) || costOfSale < 0)
		{
			MessageBox::Show("Enter valid cost of sale.");
			return;
		}

		if (!Double::TryParse(txtComission->Text, commission) || commission < 0 || commission > 100)
		{
			MessageBox::Show("Enter valid commission (0-100).");
			return;
		}

		double sellingPrice = selectedBike->getPrice();
		double revenue = sellingPrice * quantity;
		double cost = costOfSale * quantity;
		double commissionAmount = sellingPrice * quantity * (commission / 100);
		double profit = revenue - cost - commissionAmount;

		txtProfit->Text = "R " + profit.ToString("N2");
	}

		   void ClearForm()
		   {
			   txtQuantitySold->Clear();
			   txtCostOfSales->Clear();
			   txtComission->Clear();
			   txtProfit->Clear();
			   cmbBicycleId->SelectedIndex = -1;
			   txtBikeName->Clear();
			   txtPrice->Clear();
			   txtAvailableStock->Clear();
			   pictureBox1->Image = nullptr;
			   selectedBike = nullptr;
		   }

	private: System::Void cmbBicycleId_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e)
	{
		int index = cmbBicycleId->SelectedIndex;

		if (index >= 0 && index < bikeList->Count)
		{
			// Get bike using index
			selectedBike = bikeList[index];

			// Display bike details
			txtBikeId->Text = selectedBike->getBikeId().ToString();
			txtBikeName->Text = selectedBike->getBikeName();
			txtPrice->Text = selectedBike->getPrice().ToString("N2");
			txtAvailableStock->Text = selectedBike->getAvailableStock().ToString();

			// Get sale using SAME INDEX
			if (salesList != nullptr && index < salesList->Count)
			{
				
				Sale^ sale = salesList[index];

				// Display sale details
				txtSalesId->Text = sale->getSaleId().ToString();
				txtQuantitySold->Text = sale->getQuantitySold().ToString();
				txtCostOfSales->Text = sale->getCostOfSale().ToString("N2");
				txtComission->Text = sale->getCommissionPercent().ToString("N2");


				// Calculate profit
				double profit = sale->CalculateProfit(selectedBike->getPrice());
				txtProfit->Text = "R " + profit.ToString("N2");
			}

			/*for (int i = 0; i < salesList->Count; i++)
			{
				MessageBox::Show(salesList[i]->getSaleId() + "  " + salesList[i]->getQuantitySold());
			}*/
			

			// Load picture
			LoadBikePicture(selectedBike->getBikeId());
		}


	}


private: System::Void statusStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	// Display current date and time with seconds
	String^ currentDateTime = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");

	// Option 1: Update a label (add a label to your form first)
	// lblDateTime->Text = "Date/Time: " + currentDateTime;

	// Option 2: Update form title
	this->Text = "Record Sale - " + currentDateTime;

	// Option 3: Update a status strip (if you have one)
	toolStripStatusLabel1->Text = currentDateTime;
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
