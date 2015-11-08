#pragma once
#include "Sql.h"
#include "Champ.h"
namespace FC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddTeamsForm
	/// </summary>
	public ref class AddTeamsForm : public System::Windows::Forms::Form
	{
	public: Champ ^ch;
	public:
		AddTeamsForm(Champ ^ch)
		{
			InitializeComponent();
			this->ch = ch;
			Init();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddTeamsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^  cteams;
	protected:
	private: System::Windows::Forms::Button^  baddteams;


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
			this->cteams = (gcnew System::Windows::Forms::CheckedListBox());
			this->baddteams = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cteams
			// 
			this->cteams->FormattingEnabled = true;
			this->cteams->Location = System::Drawing::Point(10, 12);
			this->cteams->Name = L"cteams";
			this->cteams->Size = System::Drawing::Size(201, 199);
			this->cteams->TabIndex = 1;
			// 
			// baddteams
			// 
			this->baddteams->Location = System::Drawing::Point(63, 226);
			this->baddteams->Name = L"baddteams";
			this->baddteams->Size = System::Drawing::Size(75, 23);
			this->baddteams->TabIndex = 2;
			this->baddteams->Text = L"Добавить";
			this->baddteams->UseVisualStyleBackColor = true;
			this->baddteams->Click += gcnew System::EventHandler(this, &AddTeamsForm::baddteams_Click);
			// 
			// AddTeamsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(223, 261);
			this->Controls->Add(this->baddteams);
			this->Controls->Add(this->cteams);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddTeamsForm";
			this->Text = L"AddTeamsForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Init()
	{
		SqlClient::SqlDataReader ^_SqlDataReader = mySql::GetSqlDataReader(mySql::sConnect, "SELECT * FROM Teams");
		if (_SqlDataReader != nullptr && _SqlDataReader->HasRows)
		{
			int i = 0;
			while (_SqlDataReader->Read())
			{
				this->cteams->Items->Add(_SqlDataReader["teamname"]->ToString());
				i++;
			}
			_SqlDataReader->Close();
			delete _SqlDataReader;
		}
	}
	private: System::Void baddteams_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		SqlClient::SqlDataReader ^_SqlDataReader,^_SqlDataReader2;
		_SqlDataReader2 = mySql::GetSqlDataReader(mySql::sConnect, "delete Parts where champid='"+this->ch->id->ToString()+"'");
		for each(int index in cteams->CheckedIndices)
		{
			_SqlDataReader = mySql::GetSqlDataReader(mySql::sConnect, "SELECT * FROM Teams where teamname LIKE '"+cteams->Items[index]->ToString()+"'");
			_SqlDataReader->Read();
			_SqlDataReader2 = mySql::GetSqlDataReader(mySql::sConnect, "insert into Parts(champid,teamid)values('"+ this->ch->id+ "'," + _SqlDataReader["teamid"]->ToString() + ")");
		}
		_SqlDataReader2->Close();
		delete _SqlDataReader2;
		_SqlDataReader->Close();
		delete _SqlDataReader;
		this->Close();
	}
};
}
