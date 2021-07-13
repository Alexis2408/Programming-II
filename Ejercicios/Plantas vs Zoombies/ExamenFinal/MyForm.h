#pragma once
#include "CControladora.h"
#include "CTexto.h"
namespace ExamenFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			CTexto* obja = new CTexto();
			/*vector<string> datos = obja->leerInformacion("Texto.txt");
			obja->retornarNumero("cfg.txt", 0);*/
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpPlantas = gcnew Bitmap("imgs/lanzaguisantes.png");
			bmpZoombies = gcnew Bitmap("imgs/zoombie.png");
			bmpMapa = gcnew Bitmap("imgs/Patio.png");
			bmpBalas = gcnew Bitmap("imgs/guisante.png");
			bmpBloque = gcnew Bitmap("imgs/bloque.png");
			controladora = new CControladora(obja->retornarNumero("cfg.txt", 0), buffer->Graphics, bmpPlantas, bmpZoombies, bmpBalas, bmpMapa, bmpBloque);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete controladora;
		}

	private:
		CControladora* controladora;
		Bitmap^ bmpPlantas;
		Bitmap^ bmpZoombies;
		Bitmap^ bmpMapa;
		Bitmap^ bmpBalas;
		Bitmap^ bmpBloque;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1044, 557);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 562);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::DarkBlue);
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, panel1->ClientRectangle, GraphicsUnit::Pixel);
		/*lblVidas->Text = controladora->getJugador()->getVidas().ToString();*/
		controladora->run(buffer->Graphics, bmpPlantas, bmpZoombies, bmpBalas, bmpMapa, bmpBloque);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
	};
}
