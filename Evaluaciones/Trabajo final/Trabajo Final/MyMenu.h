#pragma once
#include "MyForm.h"
#include "MyCredits.h"
#include "MyData.h"
#include"CArchivoTexto.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyMenu : public System::Windows::Forms::Form
	{
	private:
		CArchivoTexto* mytext;
		Graphics^g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


	private: System::Windows::Forms::PictureBox^ pictureBox2;
		   Bitmap^ bmpInicio;
	public:
		MyMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			mytext = new CArchivoTexto();
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyMenu()
		{
			if (components)
			{
				delete components;
			}
			delete mytext, g;
		}
	private: System::Windows::Forms::Label^ titulo;

	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnExit;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnIndications;

	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyMenu::typeid));
			this->titulo = (gcnew System::Windows::Forms::Label());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnIndications = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// titulo
			// 
			this->titulo->AutoSize = true;
			this->titulo->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titulo->Location = System::Drawing::Point(244, 74);
			this->titulo->Name = L"titulo";
			this->titulo->Size = System::Drawing::Size(145, 47);
			this->titulo->TabIndex = 0;
			this->titulo->Text = L"e-Menu";
			// 
			// btnCreditos
			// 
			this->btnCreditos->Location = System::Drawing::Point(639, 388);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(127, 32);
			this->btnCreditos->TabIndex = 2;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MyMenu::btnCreditos_Click);
			// 
			// btnExit
			// 
			this->btnExit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnExit->Location = System::Drawing::Point(78, 388);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(93, 32);
			this->btnExit->TabIndex = 3;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyMenu::btnExit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(194, 124);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(283, 272);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// btnIndications
			// 
			this->btnIndications->Location = System::Drawing::Point(372, 388);
			this->btnIndications->Name = L"btnIndications";
			this->btnIndications->Size = System::Drawing::Size(90, 32);
			this->btnIndications->TabIndex = 15;
			this->btnIndications->Text = L"Indications";
			this->btnIndications->UseVisualStyleBackColor = true;
			this->btnIndications->Click += gcnew System::EventHandler(this, &MyMenu::btnIndications_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::CadetBlue;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(482, 220);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(142, 50);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 17;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyMenu::pictureBox2_Click);
			// 
			// MyMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(866, 513);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnIndications);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->titulo);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyMenu";
			this->Load += gcnew System::EventHandler(this, &MyMenu::MyMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		MyCredits^ crdts = gcnew MyCredits();
		this->Visible = false;
		crdts->ShowDialog();
		this->Visible = true;
		delete crdts;
	}

	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void MyMenu_Load(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void btnIndications_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Al inicio del Juego, debes configurar el tiempo T del juego, la cantidad de aliados, la cantidad de agentes, y la cantidad de habitantes.\n\n" +
			"La cantidad mínima para los aliados, agentes es 5 y habitantes es 10. La cantidad máxima es 20.\n\n" +
			"El primer nivel trata sobre la problemática de salud.\n\n"
			+ "El segundo nivel trata sobre la problemática de la seguridad ciudadana.\n\n" +
			"El líder se mueve únicamente con las teclas direccionales.\n\n" +
			"Los aliados ayudan al líder a cumplir con la misión de llevar provisiones o asistir a los habitantes que lo necesiten.\n\n" +
			"Los habitantes son personajes que habitan el mundo del nivel del juego que eliges.\n\n" +
			"Un agente busca eliminar a tu aliado mediante una colisión.Además se mueve de una forma automática.\n\n" +
			"Cada vez que una gente elimine a un aliado, se restan 5 puntos.\n\n" +
			"Cada vez que un aliado cumple con su objetivo se incrementa 10 puntos a favor.\n\n" +
			"Ganas el juego si llegas a 100 puntos.\n\n" +
			"Se pierde el juego cuando el tiempo se termina.\n\n" +
			"Finalmente, se mostrará un banner de victoria.");
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}

private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	MyData^ dts = gcnew MyData();
	this->Visible = false;
	dts->ShowDialog();
	this->Visible = true;
	delete dts;
}
};
}
