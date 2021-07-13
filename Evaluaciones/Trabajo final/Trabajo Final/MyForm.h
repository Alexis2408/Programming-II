#pragma once
#include "MyCredits.h"
#include "CController.h"
#include "CArchivoTexto.h"
#include "MySummary.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(int timeLimit, int nAliados, int nAgentes, int nHabitantes, int nMap)
		{
			nAllies = nAliados;
			numMapa = nMap;
			InitializeComponent();
			CArchivoTexto* obja = new CArchivoTexto();
			vector<string> datos = obja->LeerDesdeArchivo("Texto.txt");
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			obj = new CController(numMapa,buffer->Graphics);
			if (nMap == 1)
			{
				LeaderImg = gcnew Bitmap(gcnew String(datos.at(16).c_str()));
				AllyImg = gcnew Bitmap(gcnew String(datos.at(3).c_str()));
				PersonImg = gcnew Bitmap(gcnew String(datos.at(8).c_str()));
				PersonImg1 = gcnew Bitmap(gcnew String(datos.at(9).c_str()));
				PersonImg2 = gcnew Bitmap(gcnew String(datos.at(10).c_str()));
				PersonImg3 = gcnew Bitmap(gcnew String(datos.at(11).c_str()));
				AgentImg = gcnew Bitmap(gcnew String(datos.at(1).c_str()));
				ExtraImg = gcnew Bitmap(gcnew String(datos.at(5).c_str()));
				AllyImgInfected = gcnew Bitmap(gcnew String(datos.at(22).c_str()));
				PersonImgInfected = gcnew Bitmap(gcnew String(datos.at(24).c_str()));
				PersonImg1Infected = gcnew Bitmap(gcnew String(datos.at(25).c_str()));
				PersonImg2Infected = gcnew Bitmap(gcnew String(datos.at(26).c_str()));
				PersonImg3Infected = gcnew Bitmap(gcnew String(datos.at(27).c_str()));
			}
			else
			{
				int aux;
				aux = rand() % (2) + 1;
				if (aux == 1)
					LeaderImg = gcnew Bitmap(gcnew String(datos.at(17).c_str()));
				else
					LeaderImg = gcnew Bitmap(gcnew String(datos.at(18).c_str()));
				AllyImg = gcnew Bitmap(gcnew String(datos.at(4).c_str()));
				PersonImg = gcnew Bitmap(gcnew String(datos.at(12).c_str()));
				PersonImg1 = gcnew Bitmap(gcnew String(datos.at(13).c_str()));
				PersonImg2 = gcnew Bitmap(gcnew String(datos.at(14).c_str()));
				PersonImg3 = gcnew Bitmap(gcnew String(datos.at(15).c_str()));
				AgentImg = gcnew Bitmap(gcnew String(datos.at(2).c_str()));
				ExtraImg = gcnew Bitmap(gcnew String(datos.at(6).c_str()));
				AllyImgInfected = gcnew Bitmap(gcnew String(datos.at(23).c_str()));
				PersonImgInfected = gcnew Bitmap(gcnew String(datos.at(28).c_str()));
				PersonImg1Infected = gcnew Bitmap(gcnew String(datos.at(29).c_str()));
				PersonImg2Infected = gcnew Bitmap(gcnew String(datos.at(30).c_str()));
				PersonImg3Infected = gcnew Bitmap(gcnew String(datos.at(31).c_str()));
			}
			Clockimg = gcnew Bitmap(gcnew String(datos.at(21).c_str()));
			WallImg = gcnew Bitmap(gcnew String(datos.at(7).c_str()));
			obj->Init(timeLimit, nAllies, nHabitantes, nAgentes, buffer->Graphics, LeaderImg, AllyImg, PersonImg, AgentImg, ExtraImg, WallImg, PersonImg1, PersonImg2, PersonImg3);
			BitmapMapa1=gcnew Bitmap("images/mapOne.png");
			BitmapMapa2=gcnew Bitmap("images/mapTwo.png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		CController* obj;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ LeaderImg;
		Bitmap^ AllyImg;
		Bitmap^ PersonImg;
		Bitmap^ PersonImg1;
		Bitmap^ PersonImg2;
		Bitmap^ PersonImg3;
		Bitmap^ AllyImgInfected;
		Bitmap^ PersonImgInfected;
		Bitmap^ PersonImg1Infected;
		Bitmap^ PersonImg2Infected;
		Bitmap^ PersonImg3Infected;
		Bitmap^ AgentImg;
		Bitmap^ ExtraImg;
		Bitmap^ WallImg;
		Bitmap^ Clockimg;
		Bitmap^ BitmapMapa1;
		Bitmap^ BitmapMapa2;
		int numMapa;
		int nAllies;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ lblNumAllies;
	private: System::Windows::Forms::Label^ lblTimeLimit;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	private: System::Windows::Forms::Label^ label2;




	private: System::Windows::Forms::Panel^ panel1;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		   {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblNumAllies = (gcnew System::Windows::Forms::Label());
			this->lblTimeLimit = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Location = System::Drawing::Point(38, 58);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1280, 640);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(93, -6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(60, 49);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// lblNumAllies
			// 
			this->lblNumAllies->AutoSize = true;
			this->lblNumAllies->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNumAllies->Location = System::Drawing::Point(159, 14);
			this->lblNumAllies->Name = L"lblNumAllies";
			this->lblNumAllies->Size = System::Drawing::Size(19, 20);
			this->lblNumAllies->TabIndex = 2;
			this->lblNumAllies->Text = L"5\r\n";
			// 
			// lblTimeLimit
			// 
			this->lblTimeLimit->AutoSize = true;
			this->lblTimeLimit->Location = System::Drawing::Point(697, 11);
			this->lblTimeLimit->Name = L"lblTimeLimit";
			this->lblTimeLimit->Size = System::Drawing::Size(13, 13);
			this->lblTimeLimit->TabIndex = 3;
			this->lblTimeLimit->Text = L"0";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(652, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(39, 48);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(218, 14);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(64, 20);
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(288, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"5\r\n";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1356, 727);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->lblTimeLimit);
			this->Controls->Add(this->lblNumAllies);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Los Baby\'s";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		//Dibuja el mapa
		if (numMapa == 1)
			buffer->Graphics->DrawImage(BitmapMapa1, WallImg->Width / 4,  WallImg->Height/4, this->panel1->Width-2*(WallImg->Width / 4), this->panel1->Height-2 * (WallImg->Height / 4));
		else
			buffer->Graphics->DrawImage(BitmapMapa2, WallImg->Width / 4, WallImg->Height / 4, this->panel1->Width - 2 * (WallImg->Width / 4), this->panel1->Height - 2 * (WallImg->Height / 4));
		obj->Run(buffer->Graphics, LeaderImg, AllyImg, PersonImg, AgentImg, ExtraImg, WallImg, PersonImg1, PersonImg2, PersonImg3, Clockimg, AllyImgInfected, PersonImgInfected, PersonImg1Infected, PersonImg2Infected, PersonImg3Infected, numMapa);
		lblNumAllies->Text = nAllies.ToString();
		label2->Text = Convert::ToString(obj->get_score());
		buffer->Render(g);
		lblTimeLimit->Text = (obj->getTime()/10).ToString() + "   segundos";
		if (obj->getTime() == 0)
		{
			this->Visible = false;
			Close();
			MySummary^ sum = gcnew MySummary(obj->getWon());
			sum->ShowDialog();
			delete sum;
		}
		else
		{
			if (obj->getWon()) {
				this->Visible = false;
				Close();
				MySummary^ sum = gcnew MySummary(obj->getWon());
				sum->ShowDialog();
				delete sum;
			}
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:case Keys::Up:
			obj->moveLeader('W'); break;
		case Keys::S:case Keys::Down:
			obj->moveLeader('S'); break;
		case Keys::A:case Keys::Left:
			obj->moveLeader('A'); break;
		case Keys::D:case Keys::Right:
			obj->moveLeader('D'); break;
		}
	}
private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	timer1->Enabled = false;
	delete buffer;
}
private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::T) 
	{
		obj->addAlly(AllyImg,buffer->Graphics);
		if (nAllies > 0) nAllies--;
	}
}
};
}