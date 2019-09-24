#pragma once
#include "Controladora.h"

namespace ConsoleApplication3 {

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
		//Componentes de graficador
		BufferedGraphicsContext^space;
		BufferedGraphics^ buffer;

		Controladora* objControlador = new Controladora();

		Bitmap^ bmpBloque = gcnew Bitmap("Imagenes\\bloque.png");
		//Mapas//
		Bitmap^ bmpNamekusei = gcnew Bitmap("Imagenes\\Namekusei.jpg");
		Bitmap^ TierraDesolada = gcnew Bitmap("Imagenes\\TierraDesolada.jpg");
		Bitmap^ Tierra = gcnew Bitmap("Imagenes\\Tierra.jpg");
		Bitmap^Planeta = gcnew Bitmap("Imagenes\\Planeta_vegita.jpg");

		//personaajes//

		Bitmap^ Majin_buu = gcnew Bitmap("Imagenes\\Mijinbuu.png");
		Bitmap^ bmpGoku = gcnew Bitmap("Imagenes\\Goku.png");

		//Ataquez

		Bitmap^ bmpAtaqueFreezer = gcnew Bitmap("Imagenes\\AtaqueFreezer.png");
		//Destino//

		Bitmap ^ Nave = gcnew Bitmap("Imagenes\\nave.png");
		Bitmap ^ TimeMachine = gcnew Bitmap("Imagenes\\TimeMachine.png");
		Bitmap ^ NaveSaiyajin = gcnew Bitmap("Imagenes\\NaveSaiyajin.png");
		Bitmap^ bmpBase = gcnew Bitmap("Imagenes\\base_1.png");
		Bitmap^ bmpEspinas = gcnew Bitmap("Imagenes\\espina.png");
	private: System::Windows::Forms::Timer^  timer1;

			 int nivel = 1;

	public:
		MyForm(void)
		{
			InitializeComponent();

			this->space = BufferedGraphicsManager::Current;
			this->buffer = space->Allocate(this->CreateGraphics(), this->ClientRectangle);


			bmpGoku->MakeTransparent(Color::White);
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
	private: System::ComponentModel::IContainer^  components;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 80;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(902, 596);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion

		void Iniciar_Juego() {

			this->Text = L"VIDAS : " + objControlador->Vidas().ToString();
			switch (objControlador->get_nivel()) {

			case 1: objControlador->DibujarMapa(buffer->Graphics, bmpBloque, bmpAtaqueFreezer,bmpNamekusei);
				objControlador->DibujaCompuerta(buffer->Graphics, Nave); break;
			case 2:
				objControlador->DibujarMapa(buffer->Graphics, bmpBloque, bmpAtaqueFreezer, TierraDesolada);
				objControlador->DibujaCompuerta(buffer->Graphics, TimeMachine); break;
			case 3:
				objControlador->DibujarMapa(buffer->Graphics, bmpBloque, bmpAtaqueFreezer, Tierra);
				objControlador->DibujaCompuerta(buffer->Graphics, NaveSaiyajin); break;

			case 4:
				objControlador->DibujarMapa(buffer->Graphics, bmpBloque, bmpAtaqueFreezer, Planeta);
				objControlador->DibujaCompuerta(buffer->Graphics, NaveSaiyajin); break;
			}

				objControlador->DibujarJugador(buffer->Graphics, bmpGoku);
				//objControlador->DibujaCompuerta(buffer->Graphics, Compuerta);
				objControlador->ColisionEnemigoJugador();
				objControlador->DibujaEnemigos(buffer->Graphics,Majin_buu, bmpAtaqueFreezer);
				//objControlador->InteraccionJyEsc();
				objControlador->PierdeJuego();
				objControlador->GanaJuego();
			
		}

	 private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		Iniciar_Juego();
		buffer->Render();

	}



	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		switch (e->KeyCode)
		{

		case Keys::Left: {objControlador->DireccionJugador(Direcciones::izquierda); }break;
		case Keys::Right: {objControlador->DireccionJugador(Direcciones::derecha); }break;
		case Keys::Up: {objControlador->DireccionJugador(Direcciones::arriba); }break;
		case Keys::Down: {objControlador->DireccionJugador(Direcciones::abajo); }break;

		}
	}



	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		objControlador->DireccionJugador(Direcciones::ninguna);
	}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
