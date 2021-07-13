#pragma once
#include "CControladora.h"
namespace PrograPC2 {

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
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpCaballo = gcnew Bitmap("imagenes/Caballo.png");
			bmpAguila = gcnew Bitmap("imagenes/Aguila.png");
			bmpFondo = gcnew Bitmap("imagenes/FondoCampo.png");
			controladora = new CControladora(bmpCaballo, bmpAguila);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private:
		CControladora* controladora;
		Bitmap^ bmpCaballo;
		Bitmap^ bmpAguila;
		Bitmap^ bmpFondo;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(19, 17);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(716, 428);
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
			this->ClientSize = System::Drawing::Size(763, 483);
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
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::B:
			controladora->setCaballloColor('B'); break;
		case Keys::V:
			controladora->setCaballloColor('V'); break;
		case Keys::Z:
			controladora->setCaballloColor('Z'); break;
		case Keys::A:
			controladora->setCaballloColor('A'); break;
		case Keys::T:
			controladora->aumentarVelocidadCaballo(); break;
		case Keys::F:
			Close();
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		controladora->moverTodos(buffer->Graphics);
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, panel1->Width, panel1->Height);
		controladora->run(buffer->Graphics, bmpCaballo, bmpAguila);
		buffer->Render(g);

	}
	};
}
