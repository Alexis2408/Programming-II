#pragma once
#include "MyForm.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyData
	/// </summary>
	public ref class MyData : public System::Windows::Forms::Form
	{
	public:
		MyData(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^ tBTime;
	protected:

	private: System::Windows::Forms::Label^ nTiempo;
	private: System::Windows::Forms::Label^ nAliados;
	private: System::Windows::Forms::Label^ nHabitantes;
	private: System::Windows::Forms::Label^ nAgentes;
	private: System::Windows::Forms::NumericUpDown^ numAliados;
	private: System::Windows::Forms::NumericUpDown^ numHabitantes;


	private: System::Windows::Forms::NumericUpDown^ numAgentes;

	private: System::Windows::Forms::Button^ btnNext;


	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::RadioButton^ rBMap1;


	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>

	private:
		Graphics^ g;
		Bitmap^ bmpMapOne;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ lblSettings;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pBAllyHead1;
	private: System::Windows::Forms::PictureBox^ pBAgentHead1;
	private: System::Windows::Forms::PictureBox^ pBHabitantHead1;
	private: System::Windows::Forms::PictureBox^ pBAllyHead2;
	private: System::Windows::Forms::PictureBox^ pBAgentHead2;
	private: System::Windows::Forms::PictureBox^ pBHabitantHead2;




		   Bitmap^ bmpMapTwo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyData::typeid));
			this->tBTime = (gcnew System::Windows::Forms::TrackBar());
			this->nTiempo = (gcnew System::Windows::Forms::Label());
			this->nAliados = (gcnew System::Windows::Forms::Label());
			this->nHabitantes = (gcnew System::Windows::Forms::Label());
			this->nAgentes = (gcnew System::Windows::Forms::Label());
			this->numAliados = (gcnew System::Windows::Forms::NumericUpDown());
			this->numHabitantes = (gcnew System::Windows::Forms::NumericUpDown());
			this->numAgentes = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->rBMap1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->lblSettings = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pBAllyHead1 = (gcnew System::Windows::Forms::PictureBox());
			this->pBAgentHead1 = (gcnew System::Windows::Forms::PictureBox());
			this->pBHabitantHead1 = (gcnew System::Windows::Forms::PictureBox());
			this->pBAllyHead2 = (gcnew System::Windows::Forms::PictureBox());
			this->pBAgentHead2 = (gcnew System::Windows::Forms::PictureBox());
			this->pBHabitantHead2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAliados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHabitantes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAgentes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAllyHead1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAgentHead1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBHabitantHead1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAllyHead2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAgentHead2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBHabitantHead2))->BeginInit();
			this->SuspendLayout();
			// 
			// tBTime
			// 
			this->tBTime->Location = System::Drawing::Point(132, 91);
			this->tBTime->Maximum = 8;
			this->tBTime->Minimum = 1;
			this->tBTime->Name = L"tBTime";
			this->tBTime->Size = System::Drawing::Size(104, 45);
			this->tBTime->TabIndex = 0;
			this->tBTime->Value = 1;
			this->tBTime->Scroll += gcnew System::EventHandler(this, &MyData::tBTime_Scroll);
			// 
			// nTiempo
			// 
			this->nTiempo->AutoSize = true;
			this->nTiempo->Location = System::Drawing::Point(59, 101);
			this->nTiempo->Name = L"nTiempo";
			this->nTiempo->Size = System::Drawing::Size(42, 13);
			this->nTiempo->TabIndex = 4;
			this->nTiempo->Text = L"Tiempo";
			// 
			// nAliados
			// 
			this->nAliados->AutoSize = true;
			this->nAliados->Location = System::Drawing::Point(58, 156);
			this->nAliados->Name = L"nAliados";
			this->nAliados->Size = System::Drawing::Size(41, 13);
			this->nAliados->TabIndex = 5;
			this->nAliados->Text = L"Aliados";
			// 
			// nHabitantes
			// 
			this->nHabitantes->AutoSize = true;
			this->nHabitantes->Location = System::Drawing::Point(58, 286);
			this->nHabitantes->Name = L"nHabitantes";
			this->nHabitantes->Size = System::Drawing::Size(58, 13);
			this->nHabitantes->TabIndex = 6;
			this->nHabitantes->Text = L"Habitantes";
			// 
			// nAgentes
			// 
			this->nAgentes->AutoSize = true;
			this->nAgentes->Location = System::Drawing::Point(58, 220);
			this->nAgentes->Name = L"nAgentes";
			this->nAgentes->Size = System::Drawing::Size(46, 13);
			this->nAgentes->TabIndex = 7;
			this->nAgentes->Text = L"Agentes";
			this->nAgentes->Click += gcnew System::EventHandler(this, &MyData::nAgentes_Click);
			// 
			// numAliados
			// 
			this->numAliados->Location = System::Drawing::Point(132, 155);
			this->numAliados->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numAliados->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numAliados->Name = L"numAliados";
			this->numAliados->Size = System::Drawing::Size(90, 20);
			this->numAliados->TabIndex = 8;
			this->numAliados->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// numHabitantes
			// 
			this->numHabitantes->Location = System::Drawing::Point(132, 282);
			this->numHabitantes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numHabitantes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numHabitantes->Name = L"numHabitantes";
			this->numHabitantes->Size = System::Drawing::Size(90, 20);
			this->numHabitantes->TabIndex = 9;
			this->numHabitantes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// numAgentes
			// 
			this->numAgentes->Location = System::Drawing::Point(132, 219);
			this->numAgentes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numAgentes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numAgentes->Name = L"numAgentes";
			this->numAgentes->Size = System::Drawing::Size(90, 20);
			this->numAgentes->TabIndex = 10;
			this->numAgentes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(573, 447);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(75, 23);
			this->btnNext->TabIndex = 11;
			this->btnNext->Text = L"Next";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &MyData::btnNext_Click);
			// 
			// rBMap1
			// 
			this->rBMap1->AutoSize = true;
			this->rBMap1->Checked = true;
			this->rBMap1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rBMap1->Location = System::Drawing::Point(427, 71);
			this->rBMap1->Name = L"rBMap1";
			this->rBMap1->Size = System::Drawing::Size(71, 20);
			this->rBMap1->TabIndex = 14;
			this->rBMap1->TabStop = true;
			this->rBMap1->Text = L"Mapa 1";
			this->rBMap1->UseVisualStyleBackColor = true;
			this->rBMap1->CheckedChanged += gcnew System::EventHandler(this, &MyData::rBMap1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(423, 232);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(71, 20);
			this->radioButton2->TabIndex = 15;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Mapa 2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(461, 104);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(158, 95);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 16;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &MyData::pictureBox1_MouseLeave);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &MyData::pictureBox1_MouseHover);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(461, 258);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(158, 90);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 17;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseLeave += gcnew System::EventHandler(this, &MyData::pictureBox2_MouseLeave);
			this->pictureBox2->MouseHover += gcnew System::EventHandler(this, &MyData::pictureBox2_MouseHover);
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(271, 98);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(13, 13);
			this->lblTime->TabIndex = 18;
			this->lblTime->Text = L"1";
			// 
			// lblSettings
			// 
			this->lblSettings->AutoSize = true;
			this->lblSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSettings->Location = System::Drawing::Point(44, 37);
			this->lblSettings->Name = L"lblSettings";
			this->lblSettings->Size = System::Drawing::Size(140, 37);
			this->lblSettings->TabIndex = 19;
			this->lblSettings->Text = L"Settigns";
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(109, 447);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 20;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &MyData::btnBack_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(287, 98);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"min";
			// 
			// pBAllyHead1
			// 
			this->pBAllyHead1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBAllyHead1.Image")));
			this->pBAllyHead1->Location = System::Drawing::Point(260, 146);
			this->pBAllyHead1->Name = L"pBAllyHead1";
			this->pBAllyHead1->Size = System::Drawing::Size(45, 40);
			this->pBAllyHead1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBAllyHead1->TabIndex = 22;
			this->pBAllyHead1->TabStop = false;
			// 
			// pBAgentHead1
			// 
			this->pBAgentHead1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBAgentHead1.Image")));
			this->pBAgentHead1->Location = System::Drawing::Point(260, 208);
			this->pBAgentHead1->Name = L"pBAgentHead1";
			this->pBAgentHead1->Size = System::Drawing::Size(45, 40);
			this->pBAgentHead1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBAgentHead1->TabIndex = 23;
			this->pBAgentHead1->TabStop = false;
			// 
			// pBHabitantHead1
			// 
			this->pBHabitantHead1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBHabitantHead1.Image")));
			this->pBHabitantHead1->Location = System::Drawing::Point(260, 270);
			this->pBHabitantHead1->Name = L"pBHabitantHead1";
			this->pBHabitantHead1->Size = System::Drawing::Size(45, 40);
			this->pBHabitantHead1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBHabitantHead1->TabIndex = 24;
			this->pBHabitantHead1->TabStop = false;
			// 
			// pBAllyHead2
			// 
			this->pBAllyHead2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBAllyHead2.Image")));
			this->pBAllyHead2->Location = System::Drawing::Point(260, 146);
			this->pBAllyHead2->Name = L"pBAllyHead2";
			this->pBAllyHead2->Size = System::Drawing::Size(45, 40);
			this->pBAllyHead2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBAllyHead2->TabIndex = 25;
			this->pBAllyHead2->TabStop = false;
			this->pBAllyHead2->Visible = false;
			// 
			// pBAgentHead2
			// 
			this->pBAgentHead2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBAgentHead2.Image")));
			this->pBAgentHead2->Location = System::Drawing::Point(262, 208);
			this->pBAgentHead2->Name = L"pBAgentHead2";
			this->pBAgentHead2->Size = System::Drawing::Size(39, 40);
			this->pBAgentHead2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBAgentHead2->TabIndex = 26;
			this->pBAgentHead2->TabStop = false;
			this->pBAgentHead2->Visible = false;
			// 
			// pBHabitantHead2
			// 
			this->pBHabitantHead2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pBHabitantHead2.Image")));
			this->pBHabitantHead2->Location = System::Drawing::Point(261, 270);
			this->pBHabitantHead2->Name = L"pBHabitantHead2";
			this->pBHabitantHead2->Size = System::Drawing::Size(41, 40);
			this->pBHabitantHead2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pBHabitantHead2->TabIndex = 27;
			this->pBHabitantHead2->TabStop = false;
			this->pBHabitantHead2->Visible = false;
			// 
			// MyData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCyan;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(791, 482);
			this->Controls->Add(this->pBHabitantHead2);
			this->Controls->Add(this->pBAgentHead2);
			this->Controls->Add(this->pBAllyHead2);
			this->Controls->Add(this->pBHabitantHead1);
			this->Controls->Add(this->pBAgentHead1);
			this->Controls->Add(this->pBAllyHead1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->lblSettings);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->rBMap1);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->numAgentes);
			this->Controls->Add(this->numHabitantes);
			this->Controls->Add(this->numAliados);
			this->Controls->Add(this->nAgentes);
			this->Controls->Add(this->nHabitantes);
			this->Controls->Add(this->nAliados);
			this->Controls->Add(this->nTiempo);
			this->Controls->Add(this->tBTime);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyData";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyData";
			this->TransparencyKey = System::Drawing::SystemColors::ActiveCaption;
			this->Load += gcnew System::EventHandler(this, &MyData::MyData_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAliados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numHabitantes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAgentes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAllyHead1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAgentHead1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBHabitantHead1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAllyHead2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBAgentHead2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBHabitantHead2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void nAgentes_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnNext_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm^ frm;
	if (rBMap1->Checked)
	{
		frm = gcnew MyForm((int (tBTime->Value))*600, int(numAliados->Value), int(numAgentes->Value), int(numHabitantes->Value), 1);
	}
	else {
		frm = gcnew MyForm((int(tBTime->Value))*600, int(numAliados->Value), int(numAgentes->Value), int(numHabitantes->Value), 2);
	}
	
	this->Visible = false;
	frm->ShowDialog();
	this->Visible = true;
	Close();

}
private: System::Void MyData_Load(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}

private: System::Void tBTime_Scroll(System::Object^ sender, System::EventArgs^ e) {
	lblTime->Text = tBTime->Value.ToString();
}
private: System::Void rBMap1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!rBMap1->Checked)
	{
		pBAllyHead1->Visible = false;
		pBAgentHead1->Visible = false;
		pBHabitantHead1->Visible = false;
		pBAllyHead2->Visible = true;
		pBAgentHead2->Visible = true;
		pBHabitantHead2->Visible = true;
	}
	else
	{
		pBAllyHead1->Visible = true;
		pBAgentHead1->Visible = true;
		pBHabitantHead1->Visible = true;
		pBAllyHead2->Visible = false;
		pBAgentHead2->Visible = false;
		pBHabitantHead2->Visible = false;
	}
}
private: System::Void pictureBox1_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBox1->Size = System::Drawing::Size(346, 229);
	this->pictureBox1->Location = System::Drawing::Point(383, 101);
	this->pictureBox2->Visible = false;
	this->radioButton2->Visible = false;
	this->rBMap1->Visible = false;
}
private: System::Void pictureBox1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBox1->Size = System::Drawing::Size(158, 95);
	this->pictureBox1->Location = System::Drawing::Point(461, 104);
	this->pictureBox2->Visible = true;
	this->radioButton2->Visible = true;
	this->rBMap1->Visible = true;
}
private: System::Void pictureBox2_MouseHover(System::Object^ sender, System::EventArgs^ e) {
   this->pictureBox2->Size = System::Drawing::Size(346, 229);
   this->pictureBox2->Location = System::Drawing::Point(383, 101);
   this->pictureBox1->Visible = false;
   this->radioButton2->Visible = false;
   this->rBMap1->Visible = false;
}
private: System::Void pictureBox2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBox2->Size = System::Drawing::Size(158, 90);
	this->pictureBox2->Location = System::Drawing::Point(461, 258);
	this->pictureBox1->Visible = true;
	this->radioButton2->Visible = true;
	this->rBMap1->Visible = true;
}
};
}
