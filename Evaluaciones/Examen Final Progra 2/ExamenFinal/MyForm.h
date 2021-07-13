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

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			CTexto* obja = new CTexto();
			int vidas, nPlantas;
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpPlantas = gcnew Bitmap("imgs/plantas.png");
			bmpZoombies = gcnew Bitmap("imgs/zoombies.png");
			bmpFondo = gcnew Bitmap("imgs/fondo.png");
			bmpBalas = gcnew Bitmap("imgs/guisante.png");
			bmpBloque = gcnew Bitmap("imgs/bloque.png");
			bmpFicha = gcnew Bitmap("imgs/ficha.png");
			vidas = obja->retornarNumero("datos.txt", 0);
			nPlantas = obja->retornarNumero("datos.txt", 1);
			controladora = new CControladora(vidas, nPlantas,
				buffer->Graphics, bmpPlantas, bmpZoombies, bmpBalas, bmpFondo, bmpBloque);
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
		Bitmap^ bmpFondo;
		Bitmap^ bmpBalas;
		Bitmap^ bmpBloque;
		Bitmap^ bmpFicha;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblVidas;

	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(16, 15);
			this->panel1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(995, 506);
			this->panel1->TabIndex = 0;
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(45, 7);
			this->lblVidas->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(13, 13);
			this->lblVidas->TabIndex = 0;
			this->lblVidas->Text = L"3";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1027, 536);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawImage(bmpFondo, panel1->ClientRectangle, Rectangle(0, 0, bmpFondo->Width, bmpFondo->Height), GraphicsUnit::Pixel);
		lblVidas->Text = controladora->getZoombie()->getVidas().ToString();
		controladora->run(buffer->Graphics, bmpPlantas, bmpZoombies, bmpBalas, bmpFondo, bmpBloque, bmpFicha);
		buffer->Render(g);
		if (controladora->getGano())
		{
			timer1->Enabled = false;
			MessageBox::Show("Ganaste");
			this->Close();
		}
		else
		{
			if (controladora->getZoombie()->getVidas() <= 0)
			{
				timer1->Enabled = false;
				MessageBox::Show("Perdiste");
				this->Close();
			}
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyData)
		{
		case Keys::Up:
			controladora->getZoombie()->mover(buffer->Graphics, 'W'); break;
		case Keys::Left:							
			controladora->getZoombie()->mover(buffer->Graphics, 'A'); break;
		case Keys::Down:							
			controladora->getZoombie()->mover(buffer->Graphics, 'S'); break;
		case Keys::Right:							
			controladora->getZoombie()->mover(buffer->Graphics, 'D'); break;
		case Keys::Space:
			controladora->disparar(bmpFicha);
		}
	}
};
}
