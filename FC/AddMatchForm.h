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
	/// —водка дл€ AddMatchForm
	/// </summary>
	public ref class AddMatchForm : public System::Windows::Forms::Form
	{
	public: Champ ^ch;
	public:
		AddMatchForm(Champ ^ch)
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AddMatchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  cuser1;
	private: System::Windows::Forms::ComboBox^  cuser2;
	protected:

	private: System::Windows::Forms::ComboBox^  g1;
	private: System::Windows::Forms::ComboBox^  g2;


	private: System::Windows::Forms::Button^  bAddMatch;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cuser1 = (gcnew System::Windows::Forms::ComboBox());
			this->cuser2 = (gcnew System::Windows::Forms::ComboBox());
			this->g1 = (gcnew System::Windows::Forms::ComboBox());
			this->g2 = (gcnew System::Windows::Forms::ComboBox());
			this->bAddMatch = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cuser1
			// 
			this->cuser1->FormattingEnabled = true;
			this->cuser1->Location = System::Drawing::Point(3, 12);
			this->cuser1->Name = L"cuser1";
			this->cuser1->Size = System::Drawing::Size(121, 21);
			this->cuser1->TabIndex = 0;
			this->cuser1->Text = L"выбрать";
			// 
			// cuser2
			// 
			this->cuser2->FormattingEnabled = true;
			this->cuser2->Location = System::Drawing::Point(223, 12);
			this->cuser2->Name = L"cuser2";
			this->cuser2->Size = System::Drawing::Size(121, 21);
			this->cuser2->TabIndex = 1;
			this->cuser2->Text = L"выбрать";
			// 
			// g1
			// 
			this->g1->FormattingEnabled = true;
			this->g1->Location = System::Drawing::Point(130, 12);
			this->g1->Name = L"g1";
			this->g1->Size = System::Drawing::Size(41, 21);
			this->g1->TabIndex = 2;
			this->g1->Text = L"0";
			// 
			// g2
			// 
			this->g2->FormattingEnabled = true;
			this->g2->Location = System::Drawing::Point(177, 12);
			this->g2->Name = L"g2";
			this->g2->Size = System::Drawing::Size(40, 21);
			this->g2->TabIndex = 3;
			this->g2->Text = L"0";
			// 
			// bAddMatch
			// 
			this->bAddMatch->Location = System::Drawing::Point(115, 68);
			this->bAddMatch->Name = L"bAddMatch";
			this->bAddMatch->Size = System::Drawing::Size(102, 23);
			this->bAddMatch->TabIndex = 4;
			this->bAddMatch->Text = L"добавить матч";
			this->bAddMatch->UseVisualStyleBackColor = true;
			this->bAddMatch->Click += gcnew System::EventHandler(this, &AddMatchForm::bAddMatch_Click);
			// 
			// AddMatchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(348, 103);
			this->Controls->Add(this->bAddMatch);
			this->Controls->Add(this->g2);
			this->Controls->Add(this->g1);
			this->Controls->Add(this->cuser2);
			this->Controls->Add(this->cuser1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddMatchForm";
			this->Text = L"AddMatchForm";
			this->ResumeLayout(false);

		}
		private: System::Void Init()
		{
			int MAXGOALS = 20;
			for (int i = 0; i < MAXGOALS; i++)
			{
				this->g1->Items->Add(i.ToString());
				this->g2->Items->Add(i.ToString());
			}
			this->g1->SelectedIndex = 0;
			this->g2->SelectedIndex = 0;
			SqlClient::SqlDataReader ^_SqlDataReader = mySql::GetSqlDataReader(mySql::sConnect, "SELECT * FROM Teams,Parts where Parts.teamid=Teams.teamid AND champid like '" + this->ch->id + "'");
			if (_SqlDataReader != nullptr && _SqlDataReader->HasRows)
			{
				int i = 0;
				while (_SqlDataReader->Read())
				{
					this->cuser1->Items->Add(_SqlDataReader["teamname"]->ToString());
					this->cuser2->Items->Add(_SqlDataReader["teamname"]->ToString());
					i++;
				}
				this->cuser1->SelectedIndex = 0;
				this->cuser2->SelectedIndex = 0;
				_SqlDataReader->Close();
				delete _SqlDataReader;
			}
		}
#pragma endregion
		private: System::Void bAddMatch_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (this->cuser1->Items[this->cuser1->SelectedIndex]->ToString() == this->cuser2->Items[this->cuser2->SelectedIndex]->ToString())
			{
				MessageBox::Show("команда не может играть против самой себ€");
				return;
			}
			String ^idu1, ^idu2;
			SqlClient::SqlDataReader ^idus = mySql::GetSqlDataReader(mySql::sConnect, "SELECT Parts.id FROM Teams,Parts where Parts.teamid=Teams.teamid AND teamname like '" + this->cuser1->Items[this->cuser1->SelectedIndex]->ToString() + "'");
			if (idus != nullptr && idus->HasRows)
			{
				idus->Read();
				idu1 = gcnew String(idus["id"]->ToString());
			}
			idus = mySql::GetSqlDataReader(mySql::sConnect, "SELECT Parts.id FROM Teams,Parts where Parts.teamid=Teams.teamid AND teamname like '" + this->cuser2->Items[this->cuser2->SelectedIndex]->ToString() + "'");
			if (idus != nullptr && idus->HasRows)
			{
				idus->Read();
				idu2 = gcnew String(idus["id"]->ToString());
			}
			idus->Close();
			delete idus;
			SqlClient::SqlDataReader ^cheakmatch = mySql::GetSqlDataReader(mySql::sConnect, "SELECT partsid1,partsid2 FROM Matches where (partsid1 like '" + idu1->ToString() + "' AND partsid2 like '" + idu2->ToString() + "') or (partsid2 like '" + idu1->ToString() + "' AND partsid1 like '" + idu2->ToString() + "')");
			if (cheakmatch != nullptr && cheakmatch->HasRows)
			{
				cheakmatch->Read();
				String ^tid = gcnew String(cheakmatch["partsid1"]->ToString());
				if (cheakmatch->Read())
				{
					MessageBox::Show("эти соперники уже сыграли две игры между собой");
					cheakmatch->Close();
					delete cheakmatch;
					return;
				}
				else if (idu1 == tid)
				{
					String ^temp = idu1;
					System::Windows::Forms::ComboBox ^ctemp = g1;
					idu1 = idu2;
					idu2 = temp;
					g1 = g2;
					g2 = ctemp;
				}
			}
			cheakmatch->Close();
			delete cheakmatch;
			SqlClient::SqlDataReader ^insmatch = mySql::GetSqlDataReader(mySql::sConnect, "INSERT INTO Matches(partsid1,partsid2,g1,g2)values('" + idu1->ToString() + "','" + idu2->ToString() + "'," + this->g1->Items[this->g1->SelectedIndex]->ToString() + "," + this->g2->Items[this->g2->SelectedIndex]->ToString()+ ")");
			insmatch->Close();
			delete insmatch;
			this->Close();
		}
};
}
