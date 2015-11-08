#pragma once
#include <cliext\vector>
#include "Sql.h"
#include "Champ.h"
#include "AddChampForm.h"
#include "ChampForm.h"
namespace FC {
	using namespace cliext;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bConnect;
	private: vector<Champ^> bChamp;
	private: System::Windows::Forms::Button^  baddchamp;


	protected:
	protected:
	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bConnect = (gcnew System::Windows::Forms::Button());
			this->baddchamp = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bConnect
			// 
			this->bConnect->Location = System::Drawing::Point(2, 1);
			this->bConnect->Name = L"bConnect";
			this->bConnect->Size = System::Drawing::Size(122, 23);
			this->bConnect->TabIndex = 0;
			this->bConnect->Text = L"Подключиться К БД";
			this->bConnect->UseVisualStyleBackColor = true;
			this->bConnect->Click += gcnew System::EventHandler(this, &mainForm::bConnect_Click);
			// 
			// baddchamp
			// 
			this->baddchamp->Location = System::Drawing::Point(130, 1);
			this->baddchamp->Name = L"baddchamp";
			this->baddchamp->Size = System::Drawing::Size(106, 23);
			this->baddchamp->TabIndex = 1;
			this->baddchamp->Text = L"добавить турнир";
			this->baddchamp->UseVisualStyleBackColor = true;
			this->baddchamp->Click += gcnew System::EventHandler(this, &mainForm::baddchamp_Click);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 340);
			this->Controls->Add(this->baddchamp);
			this->Controls->Add(this->bConnect);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"mainForm";
			this->Text = L"Турниры";
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			this->ResumeLayout(false);

		}
	private: System::Void ClearVect(vector<Champ^>%vect)
	{
		for (int i = vect.size()-1; i >=0; i--)
		{
			delete vect[i];
			vect.pop_back();
		}
	}
#pragma endregion
	private: System::Void bConnect_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->ClearVect(bChamp);
		SqlClient::SqlDataReader ^_SqlDataReader = mySql::GetSqlDataReader(mySql::sConnect, "SELECT * FROM Champs");
		if (_SqlDataReader != nullptr && _SqlDataReader->HasRows)
		{
			int i = 0;
			while (_SqlDataReader->Read())
			{
				Champ ^bChamps = gcnew Champ;
				bChamps->Parent = this;
				bChamps->Text = _SqlDataReader["title"]->ToString();
				bChamps->Size = Drawing::Size(200, 40);
				bChamps->id = gcnew String(_SqlDataReader["id"]->ToString());
				bChamps->title = gcnew String(_SqlDataReader["title"]->ToString());
				bChamps->Location = Point(this->Width/2-bChamps->Width/2,50+bChamps->Height*i);
				bChamps->Click += gcnew EventHandler(this, &mainForm::bcclick);
				bChamp.push_back(bChamps);
				i++;
			}
			_SqlDataReader->Close();
			delete _SqlDataReader;
		}
	}
	public: System::Void bcclick(System::Object^  sender, System::EventArgs^  e)
	{
		Champ ^bc = (Champ^)sender;
		ChampForm ^cf = gcnew ChampForm(bc);
		cf->ShowDialog();
	}
	private: System::Void baddchamp_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		AddChampForm ^addc = gcnew AddChampForm;
		addc->ShowDialog();
	}
private: System::Void mainForm_Load(System::Object^  sender, System::EventArgs^  e) 
{
	//MessageBox::Show();
		
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
