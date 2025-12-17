#pragma once
#include "algoritmos.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>
namespace trabajo2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std::complex_literals;
	
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		int tam;
		double** matriz = new double* [tam];
		double** coeficientes;
		double** identidad = new double* [tam];
		double* x1 = new double [tam];
		double* x2 = new double[tam];
		int mayor ;
		int n;
	private: System::Windows::Forms::Button^ btn_lagrange;
	public:
	private: System::Windows::Forms::Button^ reales;
	private: System::Windows::Forms::TextBox^ txt_imaginario;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;

		//algoritmos* alg = new algoritmos(matriz, identidad, tam);

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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ imaginario;
	private: System::Windows::Forms::Button^ reverso;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->imaginario = (gcnew System::Windows::Forms::Button());
			this->reverso = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->btn_lagrange = (gcnew System::Windows::Forms::Button());
			this->reales = (gcnew System::Windows::Forms::Button());
			this->txt_imaginario = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.65F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(104, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(266, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Numero de Coeficientes del Polinomio ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(107, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(267, 92);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(545, 224);
			this->dataGridView1->TabIndex = 4;
			// 
			// imaginario
			// 
			this->imaginario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->imaginario->ForeColor = System::Drawing::SystemColors::Control;
			this->imaginario->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imaginario.Image")));
			this->imaginario->Location = System::Drawing::Point(362, 311);
			this->imaginario->Name = L"imaginario";
			this->imaginario->Size = System::Drawing::Size(179, 129);
			this->imaginario->TabIndex = 8;
			this->imaginario->Text = L"FFT Imaginarios";
			this->imaginario->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->imaginario->UseVisualStyleBackColor = false;
			this->imaginario->Click += gcnew System::EventHandler(this, &MyForm::imaginario_Click);
			// 
			// reverso
			// 
			this->reverso->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->reverso->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reverso->ForeColor = System::Drawing::SystemColors::Control;
			this->reverso->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reverso.Image")));
			this->reverso->Location = System::Drawing::Point(706, 311);
			this->reverso->Name = L"reverso";
			this->reverso->Size = System::Drawing::Size(179, 129);
			this->reverso->TabIndex = 9;
			this->reverso->Text = L"FFT Reverso";
			this->reverso->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->reverso->UseVisualStyleBackColor = false;
			this->reverso->Click += gcnew System::EventHandler(this, &MyForm::reverso_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button5->ForeColor = System::Drawing::SystemColors::Control;
			this->button5->Location = System::Drawing::Point(284, 63);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 24);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Todos";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// btn_lagrange
			// 
			this->btn_lagrange->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btn_lagrange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_lagrange->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_lagrange->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_lagrange.Image")));
			this->btn_lagrange->Location = System::Drawing::Point(531, 311);
			this->btn_lagrange->Name = L"btn_lagrange";
			this->btn_lagrange->Size = System::Drawing::Size(179, 129);
			this->btn_lagrange->TabIndex = 11;
			this->btn_lagrange->Text = L"Lagrange";
			this->btn_lagrange->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_lagrange->UseVisualStyleBackColor = false;
			this->btn_lagrange->Click += gcnew System::EventHandler(this, &MyForm::btn_lagrange_Click_1);
			// 
			// reales
			// 
			this->reales->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reales->ForeColor = System::Drawing::SystemColors::Control;
			this->reales->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reales.Image")));
			this->reales->Location = System::Drawing::Point(191, 311);
			this->reales->Name = L"reales";
			this->reales->Size = System::Drawing::Size(179, 129);
			this->reales->TabIndex = 12;
			this->reales->Text = L"FFT reales";
			this->reales->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->reales->UseVisualStyleBackColor = false;
			this->reales->Click += gcnew System::EventHandler(this, &MyForm::reales_Click);
			// 
			// txt_imaginario
			// 
			this->txt_imaginario->Location = System::Drawing::Point(869, 63);
			this->txt_imaginario->Name = L"txt_imaginario";
			this->txt_imaginario->Size = System::Drawing::Size(100, 20);
			this->txt_imaginario->TabIndex = 13;
			this->txt_imaginario->Text = L"1";
			this->txt_imaginario->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_imaginario_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(866, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(157, 17);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Raiz numero Imaginario";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::Control;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4
			});
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(33, 92);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1051, 224);
			this->listView1->TabIndex = 15;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Algoritmo";
			this->columnHeader1->Width = 175;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Polinomio1";
			this->columnHeader2->Width = 240;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Polinomio2";
			this->columnHeader3->Width = 282;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Respuesta(Multiplicacion)";
			this->columnHeader4->Width = 487;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(752, 63);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 24);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Limpiar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1115, 447);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_imaginario);
			this->Controls->Add(this->reales);
			this->Controls->Add(this->btn_lagrange);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->reverso);
			this->Controls->Add(this->imaginario);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(394, 30);
			this->Name = L"MyForm";
			this->Text = L"FFT-Erick Meza y Ronald Meza";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::btn_lagrange_Click_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
		if (textBox1->Text != "") {
			 tam = Convert::ToInt16(textBox1->Text);
			for (int i = 0; i < tam; i++)
			{
				dataGridView1->Columns->Add("column", "C" + Convert::ToString(i));
			}
			listView1->Visible = false;

		}
		else {
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();
			
		}



	}
	int denominador(int a,int n) {

		int aux=0, respuesta=1;
		for (int i = 0; i < n; i++)
		{
			if (a != i) {
				aux = a - i;
				respuesta = respuesta * aux;
			}
			
		}
	//std::cout << "el denominador es: " << respuesta << std::endl;
		return respuesta;
		

	}
	double roundoff(double value, unsigned char prec)
	{
		double pow_10 = pow(10.0f, (double)prec);
		return round(value * pow_10) / pow_10;
	}

	
	//si el grado total es 3 n debe ser 3+1
	double* evaluar(double *a,int n, int c) {
		double* res = new double[n]();
		
		double b = 0.0;
		for (int i = 0; i < n; i++)
		{


			for (int j = 0; j < c; j++)
			{
				
					//b = roundoff(System::Math::Pow(i, j), 1);
					//std::cout << "el evaluacion de b :" << b << std::endl;
					//std::cout << "dentro del metodo evaluacion de a : " << a[j] << std::endl;
					//std::cout << "el el valor de res :" << res[i] << std::endl;
					res[i] = res[i] + a[j] *roundoff(System::Math::Pow(i, j),0);
					//std::cout << "el evaluacion es :" << res[i] << std::endl;
					res[i] = roundoff(res[i], 0);
			}
			//std::cout << "el evaluacion es :" << res[i] << std::endl;
			
		}
		return res;
	}

	void multiplica2(int n, double *a) {
		int aux = 0, respuesta = 1;
		for (int i = 0; i < n; i++)
		{


			for (int j = 0; j < n; j++)
			{
				if (i != j) {
					

				}

			}
		}
	}

	double *multiplicar(double* a, double* b,int t1,int t2) {

		double* respuesta = new double[t1+1]();

		for (int i = 0; i < t1; i++)
		{
			for (int j = 0; j < t2; j++)
			{
				respuesta[i + j] += roundoff( a[i] *b[j],0);
				//std::cout<<std::endl <<" a1 " << a[i]<<std::endl;
				//std::cout <<std::endl<< "b1 "<< b[j]<<std::endl;
				
			}
			std::cout <<"" <<std::endl ;
			
		}
		//std::cout << " la multiplicacion es " << std::endl;
		//for (int i = 0; i < t1+1; i++)
		//{
			
			//std::cout << "  " << respuesta[i];
			

		//}
		return respuesta;

	}

	void imprimir_arreglo(double* a,int tam) {

		for (int j = 0; j < tam; j++)
		{
			std::cout <<" "<<roundoff(a[j],0);

		}
		std::cout << " " << std::endl;
	}

	void imprimir_matris(double **m,int fila,int columna) {

		for (int i = 0; i < fila ; i++)
		{
			for (int j = 0; j <columna; j++)
			{
				std::cout  <<" " << m[i][j];

			}
			std::cout << std::endl;
		}

	}

	double* matris_lagrange(int n,int p) {
		double* m;
		double* a1 = new double[2]();
		double* b1 = new double[2]();
		a1[0] = 1;
		b1[0] = 1;
		//para ver si es x-0 x-1 o x-1 x-2 o x-0 x-1
		if (p > 0) {
			a1[1] = 0;
			if (p > 1) {
				b1[1] = -1;
			}
			else
			{
				b1[1] = -2;
			}
		}
		else {
			a1[1] = -1;
			b1[1] = -2;

		}

		
				
	//	std::cout << " a1 " << a1[1] << std::endl;
	//	std::cout << " b1 " << b1[1] << std::endl;
		int t = 2;
		m = a1;
		int f = 0;
		int aux = 0;
		for (int i = 0; i < n-1; i++)
		{		
			
			if (std::abs(b1[1]) != p)
			{
			//	std::cout << std::endl << "el valor de b1 es :" << b1[1] << std::endl;
				//std::cout << "el valor de t+i" << (t + i) << std::endl;
				m = multiplicar(m, b1, t + i, 2);
				f++;
				
			}
			else {
				i--;
			}
			if (f == n - 1) {
				break;
			}
			
			b1[1] = b1[1] - 1;
			
				
				
			  
			
			
		}
		//std::cout << " m   vale" << std::endl;
		//for (int i = 0; i < n; i++)
		//{
		//	std::cout << m[i];
		//}
		return m;
	}

	double* matris_respuesta(int n,double *coeficiente1,double *coeficiente2,int tamcolum1,int tamcolum2) {

		double* b;
		double* evaluacion;
		double* evaluacion2;

		evaluacion = evaluar(coeficiente1, n, tamcolum1);
		evaluacion2 = evaluar(coeficiente2, n, tamcolum2);
		for (int i = 0; i < n ; i++)
		{

			evaluacion[i] = evaluacion[i] * evaluacion2[i];
			//std::cout <<" aqui eval es***"<<evaluacion[i] << std::endl;

		}

		double* res = new double[n + 1]();
		//std::cout << " entrando en el bucle res==  " << " [1] " << res[0] << " [1] " << res[1] << " [2] " << res[2] << " [3] " << res[3] << std::endl;
		for (int i = 0; i < n ; i++)
		{   
			b = matris_lagrange(n-1, i);
			//std::cout << std::endl<< " saliendo del b res==  " << b[i] << std::endl;
			for (int j = 0; j < n ; j++)
			{

				//std::cout << "el coeficiente es  " << coeficientes[i][j] << std::endl;
				//std::cout << "el valor de bj es :" << b[j] << std::endl;
				res[j] = res[j] + evaluacion[i] * b[j] / denominador(i, n );
				res[j] = roundoff(res[j], 0);
				//std::cout << " la evaluacion es =  " << evaluacion[i] << std::endl;
				//std::cout << " el denominador es=  " << denominador(i, n ) << std::endl;
				//std::cout << " bj=  " << b[j] << std::endl;
				//std::cout << " res==  " << res[j] << std::endl;
				
			}
			

		}

		return res;
	}


	double** traer_datos(double * ta) {
		
		if (tam != NULL) {
			std::string f = msclr::interop::marshal_as< std::string >(dataGridView1->RowCount.ToString());
			std::string c = msclr::interop::marshal_as< std::string >(dataGridView1->ColumnCount.ToString());
		
			int filas = 0;				 
			if (std::stoi(f) >= std::stoi(c)) {
				
				filas = 2*std::stoi(f);
			}
			else
			{
				filas = 2*std::stoi(c);
				
			}
			
			coeficientes = new double*[filas]();
			for (int i = 0; i < filas; i++)
			{
				coeficientes[i] = new double[filas]();

			}
			for (int i = 0; i < std::stoi(f); i++)
			{


				for (int j = 0; j < std::stoi(c); j++)
				{
					if (dataGridView1->Rows[i]->Cells[j]->Value != nullptr)
					{
						std::string dato = msclr::interop::marshal_as< std::string >(dataGridView1->Rows[i]->Cells[j]->Value->ToString());

						coeficientes[i][j] = std::stof(dato);

						mayor = j;


					}
					else
					{
						coeficientes[i][j] = 0;
					}
					
				}				
				ta[i] = mayor;				
				mayor = 0;




				
			}
		}
		return coeficientes;
	}

	double* voltear_matris(double* m,int tam) {

		double aux;
		int k = int(tam / 2);
		double* b = new double[tam];
		for (int i = 0; i < k; i++)
		{
			aux = m[(tam -1) - i];
			m[(tam-1)-i] = m[i];
			m[i] = aux;
			
		}
		b = m;
		return b;
	}

	
	Void btn_lagrange_Click_1(System::Object^ sender, System::EventArgs^ e) {
		double* rpta=NULL, *rpta1;
		int tt1 = 0,m=0;
		if (tam != NULL) {
			std::string f = msclr::interop::marshal_as< std::string >(dataGridView1->RowCount.ToString());
			std::string c= msclr::interop::marshal_as< std::string >(dataGridView1->ColumnCount.ToString());
			//std::cout <<"las filas son "<<f<<std::endl;
			//std::cout << "las columnas son " << c << std::endl;
			int filas = 0;
			
			if (std::stoi(f) >=std::stoi(c)) {
				//std::cout << "las filas mayor a columna" << filas << std::endl;
				 filas = std::stoi(f);
			}
			else
			{
				
				 filas = std::stoi(c);
				//std::cout << "las columna mayor a columna" << filas << std::endl;
			}
			//std::cout << "las filas " << filas << std::endl;
			
			//std::cout << filas << std::endl;
			coeficientes = new double* [filas]();
			double* ta = new double[std::stoi(f)]();
			mayor = 0;
			int p = 0;
			n = 0;
		    
			for (int i = 0; i < filas; i++)
			{
				coeficientes[i] = new double [filas]();

			}

			
			//for (int k = 0; k < int(Math::Ceiling((std::stoi(f) )/ 2)); k++)
			{


				for (int i = 0; i < std::stoi(f); i++)
				{


					for (int j = 0; j < std::stoi(c); j++)
					{
						if (dataGridView1->Rows[i]->Cells[j]->Value != nullptr)
						{
							std::string dato = msclr::interop::marshal_as< std::string >(dataGridView1->Rows[i]->Cells[j]->Value->ToString());

							coeficientes[i][j] = std::stof(dato);

							mayor = j;


						}
						else
						{
							coeficientes[i][j] = 0;
						}
						std::cout << coeficientes[i][j];
					}

					//n = n + mayor;
					ta[i] = mayor;
					std::cout << "el valor de en bucle principal n es : " << n << std::endl;
					mayor = 0;




					//imprimir_matris(coeficientes, filas);
				}

			}
			std::cout << "son un total de filas : " << std::stoi(f) - 1 <<std::endl;
			//imprimir_arreglo(ta, std::stoi(f));
			for (int k = 0; k < std::stoi(f)-2; k++)
			{


				if (rpta != NULL) {
					std::cout << "es diferente de null " << std::endl;
					std::cout << "el valor de n es : " << n << std::endl;
					
					rpta = voltear_matris(rpta, n);
					//imprimir_arreglo(rpta, n );
					//imprimir_arreglo(coeficientes[k + 1], std::stoi(c));
					rpta = matris_respuesta(n , rpta, coeficientes[k + 1], n, std::stoi(c));
					n = n + ta[k + 1];
					
					//imprimir_arreglo(rpta, n );
				}
				else {
					n = ta[0] + ta[1]+1;
					rpta = matris_respuesta(n, coeficientes[k], coeficientes[k + 1], std::stoi(c), std::stoi(c));
					tt1 = n;
					//std::cout << "n es : " << n;
					std::cout << "la respuestas es ***************" << std::endl;
				//	imprimir_arreglo(rpta, n );
				}

			}
			//	std::cout << "el arreglo es " << std::endl;
			//	std::cout << "el arreglo es " << std::endl;
			//	std::cout << "n es : " << n << std::endl;
				imprimir_arreglo(rpta, n);
				System::String^ algoritmo = "Lagrange";
				rpta1=voltear_matris(rpta, n);
				agregar_items_reales(algoritmo,coeficientes[0], coeficientes[1],rpta1,n);
			
				
				//multiplicar(coeficientes[0], coeficientes[1], n+1, std::stoi(c), std::stoi(c));
				
			
		

			


		}

	}
	double ** matris_vandermonde_reales(int tam) {
		
		double** aux = new double* [tam];
		for (int i = 0; i < tam; i++)
		{
			aux[i] = new double[tam];
		}
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
			{
				if (i == 0) {
					if (j == 0) {
						aux[i][j] = 1;
					}
					else
					{
						aux[i][j] = 0;
					}
				}
				else
				{
					if (j == 0) {
						aux[i][j] = 1;
					}
					else
					{
						aux[i][j] = std::pow(i, j);
					}
				}
			}

		}
		return aux;
		

}


	std::vector<std::vector<std::complex<double>>> matris_vandermonde_imaginario(int tam,std::complex<double> raiz) {

		std::vector<std::vector<std::complex<double>>> matrix;
		
		for (int i = 0; i < tam; i++)
		{
			std::vector<std::complex<double>> tmp;
			for (int j = 0; j < tam; j++)
			{
				if (i == 0) {
					
					tmp.push_back(std::complex<double>(1));
				}
				if (j == 0) {
					tmp.push_back(std::complex<double>(1));
				}
				else {
					tmp.push_back(std::pow(raiz, (i * j)));
				}
			}
			matrix.push_back(tmp);
		}

		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
			{
				std::cout << matrix[i][j];
			}
			std::cout << std::endl;

		}
		
		return matrix;

	}


	double* yk(double* y1, double* y2, int evaluaciones,double *grado) {

		
		double* eval = new double[evaluaciones];
		double* eval1 = evaluar(y1, evaluaciones, grado[0]+1);
		double* eval2= evaluar(y2, evaluaciones, grado[1]+1);
			for (int j = 0;  j < evaluaciones;  j++)
			{
				eval[j] = eval1[j] * eval2[j];
				
			}

			return eval;
}

	double* evaluacion_de_vandermode(double** matriz, double* evaluacion, int tam) {
		double* mul = new double[tam]();
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
			{
				//std::cout << std::endl << "matriz tiene  " << evaluacion[j] << std::endl;
				mul[i] = mul[i] + evaluacion[j] * matriz[i][j];
				//std::cout << std::endl<<"mul es  "<<mul[i] << std::endl;
			}
		}
		return mul;
	}

	double* multiplicacion_punto(double *a,double *b,int tam) {
		double *mul = new double[tam];
		for (int i = 0; i < tam; i++)
		{
			mul[i] = a[i] * b[i];
		}
		return mul;
	}
	
	double**  matriz_inversa(double ** m,int tama) {
		double pivote, aux;
		double** idn = new double* [tama]();
		for (int i = 0; i < tama; i++)
		{
			idn[i] = new double[tama]();

		}
		for (int i = 0; i < tama; i++)
		{
			for (int j = 0; j < tama; j++)
			{
				if (i == j) {
					idn[i][j] = 1;
				}
				else {
					idn[i][j] = 0;
				}

			}

		}
		for (int i = 0; i < tama; i++)
		{
			pivote = m[i][i];
			for (int j = 0; j < tama; j++)
			{
				m[i][j] = m[i][j] / pivote;
				idn[i][j] = idn[i][j] / pivote;

				//std::cout << "el valor de la celda " << m[i][j] << std::endl;
			//	std::cout << "el valor de identidad es " << m[i][j] << std::endl;
			}
			for (int k = 0; k < tama; k++) {

				if (i != k) {
					aux = m[k][i];
					for (int j = 0; j < tama; j++)
					{
						m[k][j] = m[k][j] - aux * m[i][j];
						idn[k][j] = idn[k][j] - aux * idn[i][j];
					}

				}

			}

		}

		
		
		return idn;



	}


	std::vector<std::complex<double>> evaluacion_vandermode_imaginario(std::vector<std::vector<std::complex<double>>>matriz, std::vector<std::complex<double>>evaluacion,int tam) {
		std::vector<std::complex<double>> mul;
		std::complex<double> *aux = new std::complex<double>[tam]();
		
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
			{
				//std::cout << std::endl << "matriz tiene  " << evaluacion[j] << std::endl;
				aux[i] = aux[i] + evaluacion[j] * matriz[i][j];
				
				//std::cout << std::endl<<"mul es  "<<mul[i] << std::endl;
			}
		}
		//mul.push_back(mul[i] + evaluacion[j] * matriz[i][j]);
		for (int i = 0; i < tam; i++)
		{
			mul.push_back(aux[i]);
		}




		return mul;

	}

	std::vector<std::complex<double>> multiplicacion_punto_imaginario(std::vector<std::complex<double>> a, std::vector<std::complex<double>>  b,int tam) {
		
		std::vector<std::complex<double>> mul ;
		for (int i = 0; i < tam; i++)
		{
			mul.push_back(a[i] * b[i]);
		}
		return mul;
	}
	std::vector<std::vector<std::complex<double>>> matriz_inversa_imaginario(std::vector<std::vector<std::complex<double>>>vandermonde,int t_evaluacion) {
		std::vector<std::vector<std::complex<double>>> matrix;
		std::complex<double> a = -1 ;


		std::cout << std::endl<< "la matriz de vandermonde original es : "<<std::endl;
		for (int i = 0; i < t_evaluacion; i++)
		{
			for (int j = 0; j < t_evaluacion; j++)
			{
				std::cout << vandermonde[i][j];
			}
			std::cout << std::endl;

		}

		std::cout << std::endl;
		for (int i = 0; i < t_evaluacion; i++)
		{
			std::vector<std::complex<double>> tmp;
			for (int j = 0; j < t_evaluacion; j++)
			{
				
				


				if (std::round(std::imag(vandermonde[i][j])) == 0) {
					
					tmp.push_back(vandermonde[i][j]);
					
				}
				else {
					std::cout << vandermonde[i][j] << std::endl;
					tmp.push_back(vandermonde[i][j] * a);
					
				}


			}
			matrix.push_back(tmp);

		}

		for (int i = 0; i < t_evaluacion; i++)
		{
			for (int j = 0; j < t_evaluacion; j++)
			{
				std::cout << matrix[i][j];
			}
			std::cout << std::endl;

		}

		return matrix;


	}
	std::vector<std::complex<double>> convertir_polinomio(double ** m,int fila, int t_evaluacion) {

		std::vector<std::complex<double>> polinomio;
		//std::complex<double> aux;
		for (int i = 0; i < t_evaluacion; i++)
		{


			polinomio.push_back(std::complex<double>(m[fila][i]));

		}
		
		return polinomio;
	}

	void imprimir_arreglo_complejo(std::vector<std::complex<double>> m, int t_evaluacion) {
		std::cout << std::endl<<"  el arreglo complejo es " << std::endl;
		for (int i = 0; i < t_evaluacion; i++)
		{
			
			std::cout <<"  " <<m[i];

		}
	}
	


	void agregar_items_reales(String^ nombre,double* pol1,double* pol2,double* respuesta,int tam) {
		
		System::String^ polinomio =" ", ^ polinomio2=" ", ^ rpta=" ",^ p;
		//respuesta = voltear_matris(respuesta, tam);
		for (int i = 0; i < tam; i++)
		{
			switch (i)
			{
			case 0:p = "";
				break;
			case 1:p = "x\u00B9";
				break;
			case 2:p = "x\u00B2";
				break;
			case 3:p = "x\u00B3";
				break;
			case 4:p = "x^4";
				break;
			case 5:p = "x^5";
				break;
			case 6:p = "x^6";
				break;
			case 7:p = "x^7";
				break;
			case 8:p = "x^8";
				break;	
			case 9:p = "x^9";
				break;
			default:
				p = "x^" + i.ToString();
				break;
			}
			polinomio = polinomio +"(" + roundoff(pol1[i], 0).ToString()+")" + p + "+";
			polinomio2 = polinomio2 +"("+ roundoff(pol2[i], 0).ToString() + ")" + p + "+";
			rpta = rpta + "("+roundoff(respuesta[i], 0).ToString()+")" + p + "+";
		}
		listView1->Visible = true;
		ListViewItem^ l = gcnew ListViewItem(nombre);
		l->SubItems->Add(polinomio);
		l->SubItems->Add(polinomio2);
		l->SubItems->Add(rpta);		
		listView1->Items->Add(l);
	}
	//falta terminar este 
	
	void agregar_items_imaginarios(String^ nombre, std::vector<std::complex<double>> pol1, std::vector<std::complex<double>> pol2, std::vector<std::complex<double>> respuesta, int tam) {

		System::String^ polinomio = " ", ^ polinomio2 = " ", ^ rpta = " ", ^ p;
		//respuesta = voltear_matris(respuesta, tam);
		for (int i = 0; i < tam; i++)
		{
			switch (i)
			{
			case 0:p = "";
				break;
			case 1:p = "x\u00B9";
				break;
			case 2:p = "x\u00B2";
				break;
			case 3:p = "x\u00B3";
				break;
			case 4:p = "x^4";
				break;
			case 5:p = "x^5";
				break;
			case 6:p = "x^6";
				break;
			case 7:p = "x^7";
				break;
			case 8:p = "x^8";
				break;
			case 9:p = "x^9";
				break;
			default:
				p = "x^" + i.ToString();
				break;
			}
			polinomio = polinomio +"(" +roundoff(std::real(pol1[i]), 0).ToString() +"," + roundoff(std::imag(pol1[i]), 0).ToString() + "i" + ")" + p + "+";
			polinomio2 = polinomio2 + "(" + roundoff(std::real(pol2[i]), 0).ToString() + "," + roundoff(std::imag(pol2[i]), 0).ToString() + "i" + ")" + p + "+";;
			rpta = rpta + "("+roundoff(std::real(respuesta[i]),0).ToString()+"," + roundoff(std::imag(respuesta[i]),0).ToString()+"i" + ")" + p + "+";
		}
		ListViewItem^ l = gcnew ListViewItem(nombre);
		l->SubItems->Add(polinomio);
		l->SubItems->Add(polinomio2);
		l->SubItems->Add(rpta);
		listView1->Items->Add(l);
		this->listView1->Visible = true;
	}
	std::vector<std::complex<double>> fft(std::vector<std::complex<double>> rr,int t_evaluacion) {
		std::vector<std::complex<double>> rpta;
		std::complex<double> denominador = t_evaluacion;
		for (int i = 0; i < t_evaluacion; i++)
		{
			rpta.push_back(rr[i] / denominador);
		}

		return rpta;
	}

private: System::Void reales_Click(System::Object^ sender, System::EventArgs^ e) {
	double* grado,**vandermonde,**invvandermonde,*evaluacion, * evaluacion2,*yk1,*ress,**matrix;
	int fila,columna,tam,t_evaluacion;
	std::string f = msclr::interop::marshal_as< std::string >(dataGridView1->RowCount.ToString());
	std::string c = msclr::interop::marshal_as< std::string >(dataGridView1->ColumnCount.ToString());

	fila = std::stoi(f)-1;
	grado = new double[fila]();
	columna = std::stoi(c);
	fila >= columna ? tam=fila : tam=columna;
	matrix = traer_datos(grado);
	t_evaluacion = 2 * (columna);	
	
		
		double* pl = matrix[0];
		t_evaluacion = 2 * columna;
		std::cout << "la fila son   " << fila<<std::endl;
		for (int i = 0; i < fila-1
			; i++)
		{
			t_evaluacion = 2 + t_evaluacion;
			vandermonde = matris_vandermonde_reales(t_evaluacion);
			evaluacion = evaluacion_de_vandermode(vandermonde, pl, t_evaluacion);
			evaluacion2 = evaluacion_de_vandermode(vandermonde, matrix[i+1], t_evaluacion);
			yk1 = multiplicacion_punto(evaluacion, evaluacion2, t_evaluacion);
			invvandermonde = matriz_inversa(vandermonde, t_evaluacion);
			ress = evaluacion_de_vandermode(invvandermonde, yk1, t_evaluacion);
			std::cout << "res" << std::endl;
			imprimir_arreglo(ress,t_evaluacion);
			System::String^ algoritmo = "FFT Reales";
			agregar_items_reales(algoritmo, pl, matrix[i+1], ress, t_evaluacion);
			pl = ress;
			

		}
		

	

}


private: System::Void imaginario_Click(System::Object^ sender, System::EventArgs^ e) {
	std::cout << std::fixed << std::setprecision(1);
	double* grado;
	int fila, columna, tam, t_evaluacion;
	std::vector<std::complex<double>> evaluacion, evaluacion1,polinomio1,polinomio2,yk1,respuesta,rr;
	std::string f = msclr::interop::marshal_as< std::string >(dataGridView1->RowCount.ToString());
	std::string c = msclr::interop::marshal_as< std::string >(dataGridView1->ColumnCount.ToString());
	std::string r= msclr::interop::marshal_as< std::string >(txt_imaginario->Text->ToString());
	fila = std::stoi(f) - 1;
	grado = new double[fila]();
	columna = std::stoi(c);
	fila >= columna ? tam = fila : tam = columna;
	matriz = traer_datos(grado);
	double raiz = std::stod(r);
	
	t_evaluacion = 2 * (columna);
	std::complex<double> n = std::stod(r) * 1i;
	
	
		polinomio1 = convertir_polinomio(matriz, 0, t_evaluacion);		
		std::vector<std::complex<double>>pl = polinomio1;
		t_evaluacion = 2 * columna;
		std::cout << "la fila son   " << fila << std::endl;
		for (int i = 0; i < fila - 1; i++)
		{
			
			std::vector<std::vector<std::complex<double>>> vandermonde_imaginario = matris_vandermonde_imaginario(t_evaluacion, std::complex<double>(n));
						 
			polinomio2 = convertir_polinomio(matriz, i+1, t_evaluacion);
			std::cout << "hasta aquii" << std::endl;
			evaluacion = evaluacion_vandermode_imaginario(vandermonde_imaginario, pl, t_evaluacion);
			std::cout << "hasta aquii2" << std::endl;
			evaluacion1 = evaluacion_vandermode_imaginario(vandermonde_imaginario, polinomio2, t_evaluacion);
			yk1 = multiplicacion_punto_imaginario(evaluacion, evaluacion1, t_evaluacion);
			std::cout << "hasta aquii3" << std::endl;
			std::vector<std::vector<std::complex<double>>> vandermonde_imaginario_inversa = matriz_inversa_imaginario(vandermonde_imaginario, t_evaluacion);
			std::cout << "multiplicacion en punto" << std::endl;
			rr = evaluacion_vandermode_imaginario(vandermonde_imaginario_inversa, yk1, t_evaluacion);
			respuesta = fft(rr, t_evaluacion);
			System::String^ algoritmo = "FFT Imaginario";
			agregar_items_imaginarios(algoritmo, pl, polinomio2, respuesta, t_evaluacion);
			pl  = respuesta;
			std::complex<double>a = 0;
			pl.push_back(a);
			pl.push_back(a);
			t_evaluacion = 2 + t_evaluacion;


		}


	
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

	imaginario_Click(sender, e);
	listView1->Visible = false;
	reales_Click(sender, e);
	listView1->Visible = false;
	btn_lagrange_Click_1(sender, e);
	listView1->Visible = true;

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	listView1->Items->Clear();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	Color base = Color::FromArgb(73, 77, 80);
	Color sbase = Color::FromArgb(92, 96, 99);
	Color dbase = Color::FromArgb(145, 113, 92);
	MyForm::BackColor = base;
	btn_lagrange->BackColor = sbase;
	reales->BackColor = sbase;
	imaginario->BackColor = sbase;
	reverso->BackColor = sbase;
	//listView1->BackColor = dbase;
	//dataGridView1->BackColor = dbase;
	
}
private: System::Void txt_imaginario_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void reverso_Click(System::Object^ sender, System::EventArgs^ e) {


	reales_Click(sender,e);
}
};
}
