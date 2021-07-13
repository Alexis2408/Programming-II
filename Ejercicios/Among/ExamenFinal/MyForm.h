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
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpPersonaje= gcnew Bitmap("imgs/personaje.png");
			bmpMap = gcnew Bitmap("imgs/map.png");
			controladora = new CControladora(bmpPersonaje);
			cont = 0;
			tiempoApariciones = 2;
			tiempoTotal = 60;
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
		Bitmap^ bmpMap;
		Bitmap^ bmpPersonaje;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		int cont;
		int tiempoApariciones;
		int tiempoTotal;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
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
		cont++;
		if (cont/10 == tiempoApariciones)
		{
			controladora->setAparicion(true);
			cont = 0;
		}
		if (cont == 10)
		{
			tiempoTotal--;
		}
		if (tiempoTotal == 0)
		{
			timer1->Enabled = false;
			this->Close();
		}
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawImage(bmpMap, 0, 0,panel1->ClientRectangle, GraphicsUnit::Pixel);
		/*lblVidas->Text = controladora->getJugador()->getVidas().ToString();*/
		controladora->run(buffer->Graphics, bmpPersonaje);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
	};
}
