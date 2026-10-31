#pragma once
#include "Bicycle.h"
#include "Sale.h"
//#include "frmMain.h"


namespace BicycleServices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Summary for frmSearch
	/// </summary>
	public ref class frmSearch : public System::Windows::Forms::Form
	{
	public:
		frmSearch(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			searchResults = gcnew List<Bicycle^>();
			bikesFromMain = gcnew List<Bicycle^>();
		}

		property String^ SearchText
		{
			void set(String^ value)
			{
				txtSearch->Text = value;
				PerformSearch();  // Auto search when text is set
			}
		}

		// Property to receive the bike list from main form (NOT by address)
		property List<Bicycle^>^ BikeList
		{
			void set(List<Bicycle^>^ value)
			{
				// DEBUG: Show when data is received
				MessageBox::Show("BikeList property called! Received " + value->Count + " bikes.");

				bikesFromMain = gcnew List<Bicycle^>();
				for each (Bicycle ^ bike in value)
				{
					Bicycle^ newBike = gcnew Bicycle();
					newBike->setBikeId(bike->getBikeId());
					newBike->setBikeName(bike->getBikeName());
					newBike->setPrice(bike->getPrice());
					newBike->setAvailableStock(bike->getAvailableStock());
					newBike->setImagePath(bike->getImagePath());
					bikesFromMain->Add(newBike);
				}

				// DEBUG: Show bikes were copied
				MessageBox::Show("Copied " + bikesFromMain->Count.ToString() + " bikes to local list.");
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmSearch()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::TextBox^ txtSearch;
		List<Bicycle^>^ searchResults;
		List<Bicycle^>^ bikesFromMain;  // Store bikes received from main form

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ btnSearch2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ rdbPrice;

	private: System::Windows::Forms::RadioButton^ rdbBikeName;

	private: System::Windows::Forms::RadioButton^ rdbBikeID;
	private: System::Windows::Forms::ListBox^ lstDisplaySearch;

	private: System::Windows::Forms::Button^ btnSearch;



	private: System::Windows::Forms::Label^ lblCount;
	private: System::Windows::Forms::Button^ btnExit;

	private: System::ComponentModel::IContainer^ components;
	protected:


	private:
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
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rdbPrice = (gcnew System::Windows::Forms::RadioButton());
			this->rdbBikeName = (gcnew System::Windows::Forms::RadioButton());
			this->rdbBikeID = (gcnew System::Windows::Forms::RadioButton());
			this->lstDisplaySearch = (gcnew System::Windows::Forms::ListBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->lblCount = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(12, 33);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(823, 30);
			this->txtSearch->TabIndex = 0;
			// 
			// btnSearch2
			// 
			this->btnSearch2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSearch2->Location = System::Drawing::Point(687, 784);
			this->btnSearch2->Name = L"btnSearch2";
			this->btnSearch2->Size = System::Drawing::Size(139, 45);
			this->btnSearch2->TabIndex = 1;
			this->btnSearch2->Text = L"Search";
			this->btnSearch2->UseVisualStyleBackColor = true;
			this->btnSearch2->Click += gcnew System::EventHandler(this, &frmSearch::btnSearch2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rdbPrice);
			this->groupBox1->Controls->Add(this->rdbBikeName);
			this->groupBox1->Controls->Add(this->rdbBikeID);
			this->groupBox1->Location = System::Drawing::Point(12, 110);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 204);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Search By";
			// 
			// rdbPrice
			// 
			this->rdbPrice->AutoSize = true;
			this->rdbPrice->Location = System::Drawing::Point(22, 138);
			this->rdbPrice->Name = L"rdbPrice";
			this->rdbPrice->Size = System::Drawing::Size(59, 20);
			this->rdbPrice->TabIndex = 3;
			this->rdbPrice->Text = L"Price";
			this->rdbPrice->UseVisualStyleBackColor = true;
			// 
			// rdbBikeName
			// 
			this->rdbBikeName->AutoSize = true;
			this->rdbBikeName->Location = System::Drawing::Point(22, 86);
			this->rdbBikeName->Name = L"rdbBikeName";
			this->rdbBikeName->Size = System::Drawing::Size(112, 20);
			this->rdbBikeName->TabIndex = 3;
			this->rdbBikeName->Text = L"Bicycle Name";
			this->rdbBikeName->UseVisualStyleBackColor = true;
			// 
			// rdbBikeID
			// 
			this->rdbBikeID->AutoSize = true;
			this->rdbBikeID->Checked = true;
			this->rdbBikeID->Location = System::Drawing::Point(22, 37);
			this->rdbBikeID->Name = L"rdbBikeID";
			this->rdbBikeID->Size = System::Drawing::Size(88, 20);
			this->rdbBikeID->TabIndex = 0;
			this->rdbBikeID->TabStop = true;
			this->rdbBikeID->Text = L"Bicycle ID";
			this->rdbBikeID->UseVisualStyleBackColor = true;
			// 
			// lstDisplaySearch
			// 
			this->lstDisplaySearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lstDisplaySearch->FormattingEnabled = true;
			this->lstDisplaySearch->ItemHeight = 20;
			this->lstDisplaySearch->Location = System::Drawing::Point(12, 364);
			this->lstDisplaySearch->Name = L"lstDisplaySearch";
			this->lstDisplaySearch->Size = System::Drawing::Size(823, 324);
			this->lstDisplaySearch->TabIndex = 3;
			// 
			// btnSearch
			// 
			this->btnSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSearch->Location = System::Drawing::Point(484, 785);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(139, 45);
			this->btnSearch->TabIndex = 4;
			this->btnSearch->Text = L"Clear";
			this->btnSearch->UseVisualStyleBackColor = true;
			// 
			// lblCount
			// 
			this->lblCount->Location = System::Drawing::Point(21, 800);
			this->lblCount->Name = L"lblCount";
			this->lblCount->Size = System::Drawing::Size(125, 29);
			this->lblCount->TabIndex = 5;
			this->lblCount->Text = L"Result Count : ";
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(305, 786);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(139, 44);
			this->btnExit->TabIndex = 6;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &frmSearch::btnExit_Click);
			// 
			// frmSearch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1465, 867);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->lblCount);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->lstDisplaySearch);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnSearch2);
			this->Controls->Add(this->txtSearch);
			this->Name = L"frmSearch";
			this->Text = L"frmSearch";
			this->Load += gcnew System::EventHandler(this, &frmSearch::frmSearch_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSearch2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// DEBUG: Check if bikesFromMain has data
		if (bikesFromMain == nullptr)
		{
			MessageBox::Show("bikesFromMain is NULL!");
			return;
		}

		if (bikesFromMain->Count == 0)
		{
			MessageBox::Show("bikesFromMain is EMPTY! No bikes to search.");
			return;
		}

		MessageBox::Show("Searching " + bikesFromMain->Count + " bikes...");

		PerformSearch();
	}

	private: System::Void frmSearch_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		searchResults = gcnew List<Bicycle^>();
	}



	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
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
			txtSearch->Text = "";
			rdbBikeID->Checked = true;
			lstDisplaySearch->Items->Clear();
			lblCount->Text = "0";

		}
	}
	
		   // PERFORM SEARCH - Searches the local list (no database)
	private: void PerformSearch()
	{
		String^ searchTerm = txtSearch->Text;

		// Validate search term
		if (String::IsNullOrWhiteSpace(searchTerm))
		{
			MessageBox::Show("Please enter a search term.", "Search Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Clear previous results
		lstDisplaySearch->Items->Clear();
		searchResults->Clear();

		// Check if we have data to search
		if (bikesFromMain->Count == 0)
		{
			lstDisplaySearch->Items->Add("No bike data available. Please open the database first.");
			lblCount->Text = "Result Count: 0";
			return;
		}

		// Search through the bikes received from main form
		for each (Bicycle ^ bike in bikesFromMain)
		{
			bool match = false;

			if (rdbBikeID->Checked)
			{
				// Search by ID
				int searchId;
				if (Int32::TryParse(searchTerm, searchId))
				{
					if (bike->getBikeId() == searchId)
						match = true;
				}
			}
			else if (rdbBikeName->Checked)
			{
				// Search by Name (partial match, case insensitive)
				if (bike->getBikeName()->ToLower()->Contains(searchTerm->ToLower()))
					match = true;
			}
			else if (rdbPrice->Checked)
			{
				// Search by Price
				double searchPrice;
				if (Double::TryParse(searchTerm, searchPrice))
				{
					if (bike->getPrice() == searchPrice)
						match = true;
				}
			}

			if (match)
			{
				searchResults->Add(bike);
			}
		}

		// Display results
		DisplayResults();
	}

		   // DISPLAY RESULTS
	private: void DisplayResults()
	{
		lstDisplaySearch->Items->Clear();

		if (searchResults->Count == 0)
		{
			String^ message = "No results found for: " + txtSearch->Text;

			// Add helpful message based on search type
			if (rdbBikeID->Checked)
				message += "\n\nTip: Make sure you are searching by ID (numbers only)";
			else if (rdbPrice->Checked)
				message += "\n\nTip: Make sure you are searching by Price (numbers only)";
			else if (rdbBikeName->Checked)
				message += "\n\nTip: Try typing part of the bike name";

			lstDisplaySearch->Items->Add(message);
			lblCount->Text = "Result Count: 0";
			return;
		}

		// Add header
		lstDisplaySearch->Items->Add(String::Format("{0,-6} {1,-45} {2,-12} {3,-10}",
			"ID", "Bike Name", "Price", "Stock"));
		lstDisplaySearch->Items->Add("---------------------------------------------------------------------------------------");

		// Add each result
		for each (Bicycle ^ bike in searchResults)
		{
			String^ stockDisplay = (bike->getAvailableStock() == 0) ? "OUT OF STOCK" : bike->getAvailableStock().ToString();

			String^ displayText = String::Format("{0,-6} {1,-45} R{2,8:N2} {3,-10}",
				bike->getBikeId().ToString(),
				bike->getBikeName(),
				bike->getPrice(),
				stockDisplay);

			lstDisplaySearch->Items->Add(displayText);
		}

		// Update count
		lblCount->Text = String::Format("Result Count: {0}", searchResults->Count);
	}


};
}
