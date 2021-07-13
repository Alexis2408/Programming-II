#pragma once

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MySummary : public System::Windows::Forms::Form
	{
	public:
		MySummary(bool gano)
		{
			InitializeComponent();
			this->gano = gano;
		}

	protected:
		~MySummary()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		bool gano;
	private:
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::PictureBox^ pBYouWin;
	private: System::Windows::Forms::PictureBox^ pBYouLose;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MySummary::typeid));
			this->pBYouWin = (gcnew System::Windows::Forms::PictureBox());
			this->pBYouLose = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBYouWin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBYouLose))->BeginInit();
			this->SuspendLayout();
			// 
			// pBYouWin
			// 
			this->pBYouWin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBYouWin.Image")));
			this->pBYouWin->Location = System::Drawing::Point(79, 28);
			this->pBYouWin->Name = L"pBYouWin";
			this->pBYouWin->Size = System::Drawing::Size(324, 223);
			this->pBYouWin->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBYouWin->TabIndex = 0;
			this->pBYouWin->TabStop = false;
			// 
			// pBYouLose
			// 
			this->pBYouLose->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBYouLose.Image")));
			this->pBYouLose->Location = System::Drawing::Point(79, 28);
			this->pBYouLose->Name = L"pBYouLose";
			this->pBYouLose->Size = System::Drawing::Size(324, 223);
			this->pBYouLose->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBYouLose->TabIndex = 1;
			this->pBYouLose->TabStop = false;
			// 
			// MySummary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(505, 517);
			this->Controls->Add(this->pBYouLose);
			this->Controls->Add(this->pBYouWin);
			this->Name = L"MySummary";
			this->Text = L"MySummary";
			this->Load += gcnew System::EventHandler(this, &MySummary::MySummary_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBYouWin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBYouLose))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MySummary_Load(System::Object^ sender, System::EventArgs^ e) {
		if (gano)
		{
			pBYouLose->Visible = false;
		}
		else pBYouWin->Visible = false;
	}
	};
}
