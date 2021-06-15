#pragma once
#include"Controlador.h"

namespace TrabajoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formulario
	/// </summary>
	
	public ref class Formulario : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps == Imagenes
		Bitmap^ bmpLider;
		Bitmap^ bmpEnfermera;
		Bitmap^ bmpVirus;

		//Mapa
		Bitmap^ bmpMapa;

		//controlador
		CControlador* controlador;


	private: System::Windows::Forms::Timer^ timer1;
	public:
		Formulario(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//mapa
			bmpMapa = gcnew Bitmap("mapa1.png");

			//sprite Lider
			bmpLider = gcnew Bitmap("doctor.png");
			bmpEnfermera = gcnew Bitmap("enfermera.png");
			bmpVirus = gcnew Bitmap("virus.png");

			//controlador
			controlador = new CControlador(bmpLider);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formulario()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^ components;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Formulario::timer1_Tick);
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(776, 658);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::Formulario_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//mover
		controlador->moverVirus(buffer->Graphics);
		controlador->moverEnfermeras(buffer->Graphics);
		//dibujar
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, bmpMapa->Width * 0.9, bmpMapa->Height * 0.9);//dibujando mapa
		controlador->getLider()->dibujar(buffer->Graphics, bmpLider);
		controlador->dibujarEnfermeras(buffer->Graphics, bmpEnfermera);
		controlador->dibujarVirus(buffer->Graphics, bmpVirus);
               
		//Render
		buffer->Render(g);
	}
	private: System::Void Formulario_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controlador->getLider()->mover(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			controlador->getLider()->mover(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			controlador->getLider()->mover(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			controlador->getLider()->mover(buffer->Graphics, 'S'); break;
		case Keys::V:
			controlador->addAgente(bmpVirus); break;
		case Keys::E:
			controlador->addAliado(bmpEnfermera); break;
		}

	}
};
}
