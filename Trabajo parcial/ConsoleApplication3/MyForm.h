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
		/*MAPAS*/
		Bitmap^ bmpNamekusei = gcnew Bitmap("Imagenes\\Namekusei.jpg");
		Bitmap^ TierraDesolada = gcnew Bitmap("Imagenes\\TierraDesolada.jpg");
		Bitmap^ Tierra = gcnew Bitmap("Imagenes\\Tierra.jpg");
		/*PERSONAJES*/
		Bitmap^ Freezer = gcnew Bitmap("Imagenes\\Freezer.png");
		Bitmap^ Dabura = gcnew Bitmap("Imagenes\\dabura.png");
		Bitmap^ Spopovich = gcnew Bitmap("Imagenes\\spopovich.png");
		Bitmap^ Babidi = gcnew Bitmap("Imagenes\\babidi.png");
		Bitmap^ KidBoo = gcnew Bitmap("Imagenes\\kidboo.png");
		Bitmap^ Cell = gcnew Bitmap("Imagenes\\cell.png");
		Bitmap ^CapitanGinyu = gcnew Bitmap("Imagenes\\CapitanGinyu.png");
		Bitmap ^Recoome = gcnew Bitmap("Imagenes\\Recoome.png");
		Bitmap ^Zarbon = gcnew Bitmap("Imagenes\\zarbon.png");
		Bitmap ^CellJr = gcnew Bitmap("Imagenes\\celljr.png");
		Bitmap^ bmpGoku = gcnew Bitmap("Imagenes\\Goku.png");
		/*ATAQUES*/
		Bitmap^ bmpAtaqueFreezer = gcnew Bitmap("Imagenes\\AtaqueFreezer.png");
		/*DESTINO*/
		Bitmap ^ Nave = gcnew Bitmap("Imagenes\\nave.png");
		Bitmap ^ TimeMachine = gcnew Bitmap("Imagenes\\TimeMachine.png");
		Bitmap ^ NaveSaiyajin = gcnew Bitmap("Imagenes\\NaveSaiyajin.png");
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  lbVIDA;
	private: System::Windows::Forms::Label^  lbER;
	private: System::Windows::Forms::Label^  lbCONVERTIRSE;




			 int nivel = 1;
		
	public:
		MyForm(void)
		{
			InitializeComponent();

			this->space = BufferedGraphicsManager::Current;
			this->buffer = space->Allocate(this->CreateGraphics(), this->ClientRectangle);

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
		int energiarecolectada;
		int energiarestante;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lbVIDA = (gcnew System::Windows::Forms::Label());
			this->lbER = (gcnew System::Windows::Forms::Label());
			this->lbCONVERTIRSE = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 80;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(993, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 76);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// lbVIDA
			// 
			this->lbVIDA->AutoSize = true;
			this->lbVIDA->BackColor = System::Drawing::Color::Black;
			this->lbVIDA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbVIDA->Location = System::Drawing::Point(964, 141);
			this->lbVIDA->Name = L"lbVIDA";
			this->lbVIDA->Size = System::Drawing::Size(69, 24);
			this->lbVIDA->TabIndex = 1;
			this->lbVIDA->Text = L"VIDA :";
			// 
			// lbER
			// 
			this->lbER->AutoSize = true;
			this->lbER->BackColor = System::Drawing::Color::Black;
			this->lbER->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbER->Location = System::Drawing::Point(964, 186);
			this->lbER->Name = L"lbER";
			this->lbER->Size = System::Drawing::Size(306, 24);
			this->lbER->TabIndex = 2;
			this->lbER->Text = L"ENERGÍA POR RECOLECTAR :";
			// 
			// lbCONVERTIRSE
			// 
			this->lbCONVERTIRSE->AutoSize = true;
			this->lbCONVERTIRSE->BackColor = System::Drawing::Color::Black;
			this->lbCONVERTIRSE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCONVERTIRSE->ForeColor = System::Drawing::Color::Gold;
			this->lbCONVERTIRSE->Location = System::Drawing::Point(979, 343);
			this->lbCONVERTIRSE->Name = L"lbCONVERTIRSE";
			this->lbCONVERTIRSE->Size = System::Drawing::Size(0, 29);
			this->lbCONVERTIRSE->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1315, 494);
			this->Controls->Add(this->lbCONVERTIRSE);
			this->Controls->Add(this->lbER);
			this->Controls->Add(this->lbVIDA);
			this->Controls->Add(this->pictureBox1);
			this->ForeColor = System::Drawing::Color::White;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dragon Ball Z : The Game";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}

	 void Iniciar_Juego() {
		 if (objControlador->gano() == true) {
			 timer1->Enabled = false;
			 MessageBox::Show("GANASTE");
			 this->Close();
		 }

	
				 lbVIDA->Text = "VIDAS : " + objControlador->Vidas().ToString();
				 energiarestante = 20-objControlador->get_energiarecolectada();
				 lbER->Text = "ENERGIA POR RECOLECTAR : " +energiarestante.ToString();
				 energiarecolectada = objControlador->get_energiarecolectada();
				 switch (objControlador->get_nivel()) {
				 case 1: objControlador->DibujarMapa(buffer->Graphics, bmpBloque, bmpAtaqueFreezer, bmpNamekusei);
					 objControlador->DibujaCompuerta(buffer->Graphics, Nave);
					 objControlador->DibujaEnemigos(buffer->Graphics, CapitanGinyu,Recoome,Zarbon,Freezer, bmpAtaqueFreezer);
					objControlador->DibujarKi(buffer);
			
					 break;
				 case 2: objControlador->DibujarMapa(buffer->Graphics, bmpBloque, bmpAtaqueFreezer, TierraDesolada);
					 objControlador->DibujaCompuerta(buffer->Graphics, TimeMachine);
					 objControlador->DibujaEnemigos(buffer->Graphics, CellJr,CellJr,CellJr,Cell, bmpAtaqueFreezer);
					objControlador->DibujarKi(buffer);
					 break;
				 case 3: objControlador->DibujarMapa(buffer->Graphics, bmpBloque, bmpAtaqueFreezer, Tierra);
					 objControlador->DibujaCompuerta(buffer->Graphics, NaveSaiyajin);
					 objControlador->DibujaEnemigos(buffer->Graphics, Babidi,Spopovich,Dabura,KidBoo, bmpAtaqueFreezer);
					objControlador->DibujarKi(buffer);
					 break;
				 }

				 objControlador->DibujarJugador(buffer->Graphics, bmpGoku);
				 objControlador->ColisionEnemigoJugador();
				 objControlador->ColisionKiJugador();
				
			
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

		case Keys::Left: {objControlador->MoverJugador(Direcciones::izquierda, buffer->Graphics); }break;
		case Keys::A: {objControlador->MoverJugador(Direcciones::izquierda, buffer->Graphics); }break;
		case Keys::Right: {objControlador->MoverJugador(Direcciones::derecha, buffer->Graphics); }break;
		case Keys::D: {objControlador->MoverJugador(Direcciones::derecha, buffer->Graphics); }break;
		case Keys::Up: {objControlador->MoverJugador(Direcciones::arriba, buffer->Graphics); }break;
		case Keys::W: {objControlador->MoverJugador(Direcciones::arriba, buffer->Graphics); }break;
		case Keys::Down: {objControlador->MoverJugador(Direcciones::abajo, buffer->Graphics); }break;
		case Keys::S: {objControlador->MoverJugador(Direcciones::abajo, buffer->Graphics); }break;
		case Keys::B: {bmpGoku = gcnew Bitmap("Imagenes\\Goku.png");  // GOKU ESTADO NORMAL
		case Keys::G: {objControlador->guardarpartida(); }break;
		}break;
		}
	
		if ((energiarecolectada >=4) && (energiarecolectada <8)) {
			lbCONVERTIRSE->Text = "YA PUEDE CONVERTIRSE\n\t EN SUPER SAIYAJIN 1";
			switch (e->KeyCode) {
			case Keys::T: {bmpGoku = gcnew Bitmap("Imagenes\\GokuSSJ.png");  // GOKU ESTADO NORMAL
			}break;
			}
		}
		if ((energiarecolectada >= 8) && (energiarecolectada <12)) {
			lbCONVERTIRSE->Text = "YA PUEDE CONVERTIRSE\n\t EN SUPER SAIYAJIN 2";
			switch (e->KeyCode) {
			case Keys::T: {bmpGoku = gcnew Bitmap("Imagenes\\GokuSSJ2.png");  // GOKU ESTADO NORMAL
			}break;
			}
		}
		if ((energiarecolectada >= 12) && (energiarecolectada <16)) {
			lbCONVERTIRSE->Text = "YA PUEDE CONVERTIRSE\n\t EN SUPER SAIYAJIN 3";
			switch (e->KeyCode) {
			case Keys::T: {bmpGoku = gcnew Bitmap("Imagenes\\GokuSSJ3.png");  // GOKU ESTADO NORMAL
			}break;
			}
		}



	}
	

		

	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		objControlador->MoverJugador(Direcciones::ninguna,buffer->Graphics);
	}


private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
