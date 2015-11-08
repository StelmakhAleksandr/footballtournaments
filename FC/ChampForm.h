#pragma once
#include "Champ.h"
#include "AddTeamsForm.h"
#include "AddMatchForm.h"
namespace FC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChampForm
	/// </summary>
	public ref class ChampForm : public System::Windows::Forms::Form
	{
	public: Champ ^ch;
	public:
		ChampForm(Champ ^ch)
		{
			InitializeComponent();
			this->Text = ch->title;
			this->ch = ch;
			this->Init();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChampForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  baddt;
	protected:
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  bRefresh;
	private: System::Windows::Forms::Button^  bAddMatch;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  team;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  game;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  win;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  draw;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  defeat;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  gz;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Gp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Rm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  points;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->baddt = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->team = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->game = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->win = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->draw = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->defeat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gz = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Gp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->points = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bRefresh = (gcnew System::Windows::Forms::Button());
			this->bAddMatch = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// baddt
			// 
			this->baddt->Location = System::Drawing::Point(2, 2);
			this->baddt->Name = L"baddt";
			this->baddt->Size = System::Drawing::Size(139, 23);
			this->baddt->TabIndex = 1;
			this->baddt->Text = L"Добавить участника";
			this->baddt->UseVisualStyleBackColor = true;
			this->baddt->Click += gcnew System::EventHandler(this, &ChampForm::baddt_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->number,
					this->team, this->game, this->win, this->draw, this->defeat, this->gz, this->Gp, this->Rm, this->points
			});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::HotTrack;
			this->dataGridView1->Location = System::Drawing::Point(2, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(446, 80);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ChampForm::dataGridView1_CellContentClick);
			// 
			// number
			// 
			this->number->FillWeight = 25;
			this->number->Frozen = true;
			this->number->HeaderText = L"№";
			this->number->Name = L"number";
			this->number->ReadOnly = true;
			this->number->Width = 25;
			// 
			// team
			// 
			this->team->FillWeight = 300;
			this->team->Frozen = true;
			this->team->HeaderText = L"Команда";
			this->team->Name = L"team";
			this->team->ReadOnly = true;
			this->team->Width = 200;
			// 
			// game
			// 
			this->game->FillWeight = 20;
			this->game->HeaderText = L"И";
			this->game->Name = L"game";
			this->game->ReadOnly = true;
			this->game->Width = 20;
			// 
			// win
			// 
			this->win->FillWeight = 20;
			this->win->HeaderText = L"В";
			this->win->Name = L"win";
			this->win->ReadOnly = true;
			this->win->Width = 20;
			// 
			// draw
			// 
			this->draw->FillWeight = 20;
			this->draw->HeaderText = L"Н";
			this->draw->Name = L"draw";
			this->draw->ReadOnly = true;
			this->draw->Width = 20;
			// 
			// defeat
			// 
			this->defeat->FillWeight = 20;
			this->defeat->HeaderText = L"П";
			this->defeat->Name = L"defeat";
			this->defeat->ReadOnly = true;
			this->defeat->Width = 20;
			// 
			// gz
			// 
			this->gz->FillWeight = 30;
			this->gz->HeaderText = L"ГЗ";
			this->gz->MinimumWidth = 20;
			this->gz->Name = L"gz";
			this->gz->ReadOnly = true;
			this->gz->Width = 30;
			// 
			// Gp
			// 
			this->Gp->FillWeight = 30;
			this->Gp->HeaderText = L"ГП";
			this->Gp->Name = L"Gp";
			this->Gp->ReadOnly = true;
			this->Gp->Width = 30;
			// 
			// Rm
			// 
			this->Rm->FillWeight = 25;
			this->Rm->HeaderText = L"РМ";
			this->Rm->Name = L"Rm";
			this->Rm->ReadOnly = true;
			this->Rm->Width = 25;
			// 
			// points
			// 
			this->points->FillWeight = 25;
			this->points->HeaderText = L"О";
			this->points->Name = L"points";
			this->points->ReadOnly = true;
			this->points->Width = 25;
			// 
			// bRefresh
			// 
			this->bRefresh->Location = System::Drawing::Point(257, 2);
			this->bRefresh->Name = L"bRefresh";
			this->bRefresh->Size = System::Drawing::Size(75, 23);
			this->bRefresh->TabIndex = 3;
			this->bRefresh->Text = L"Обновить";
			this->bRefresh->UseVisualStyleBackColor = true;
			this->bRefresh->Click += gcnew System::EventHandler(this, &ChampForm::bRefresh_Click);
			// 
			// bAddMatch
			// 
			this->bAddMatch->Location = System::Drawing::Point(147, 2);
			this->bAddMatch->Name = L"bAddMatch";
			this->bAddMatch->Size = System::Drawing::Size(104, 23);
			this->bAddMatch->TabIndex = 4;
			this->bAddMatch->Text = L"добавить матч";
			this->bAddMatch->UseVisualStyleBackColor = true;
			this->bAddMatch->Click += gcnew System::EventHandler(this, &ChampForm::bAddMatch_Click);
			// 
			// ChampForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(451, 123);
			this->Controls->Add(this->bAddMatch);
			this->Controls->Add(this->bRefresh);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->baddt);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ChampForm";
			this->Text = L"Чемпионат";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
	public: System::Void Init()
	{
		this->dataGridView1->AutoSize = true;
		Color a;
		this->dataGridView1->Rows->Clear();
		String ^str = gcnew String("SELECT t.*,p.*,(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id) or (sm.partsid2=p.id)) )as game,(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id AND sm.g1>sm.g2) or (sm.partsid2=p.id AND sm.g2>sm.g1))  )as win,(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id AND sm.g1=sm.g2) or (sm.partsid2=p.id AND sm.g2=sm.g1))  )as draw,(SELECT count(Distinct(sm.Id)) FROM Matches sm,Parts sp where sp.champid=p.champid AND ((sm.partsid1=p.id AND sm.g1<sm.g2) or (sm.partsid2=p.id AND sm.g2<sm.g1))  )as defeat,(SELECT ISNULL(sum(Distinct(sm.g1)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid1=p.id AND sm.g1>sm.g2) )as gz1,(SELECT ISNULL(sum(Distinct(sm.g2)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid2=p.id AND sm.g1<sm.g2) )as gz2,(SELECT ISNULL(sum(Distinct(sm.g1)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid1=p.id AND sm.g1<sm.g2) )as gp1,(SELECT ISNULL(sum(Distinct(sm.g2)),0) FROM Matches sm,Parts sp where sp.champid=p.champid AND (sm.partsid2=p.id AND sm.g1>sm.g2) )as gp2 FROM Teams t left join Parts p on(t.teamid=p.teamid) where p.champid like'"+this->ch->id+"'");
		SqlClient::SqlDataReader ^_SqlDataReader = mySql::GetSqlDataReader(mySql::sConnect,str);
		if (_SqlDataReader != nullptr && _SqlDataReader->HasRows)
		{
			int i = 0;
			while (_SqlDataReader->Read())
			{
				this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = (i+1).ToString();
				this->dataGridView1->Rows[i]->Cells[1]->Value = _SqlDataReader["teamname"]->ToString();
				if (i % 2)
						a = Color::AliceBlue;
				else
					a = Color::Aqua;
				for (int j = 0; j < this->dataGridView1->Rows[i]->Cells->Count; j++)
					this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = a;
				this->dataGridView1->Rows[i]->Cells[2]->Value = _SqlDataReader["game"]->ToString();
				this->dataGridView1->Rows[i]->Cells[3]->Value = _SqlDataReader["win"]->ToString();
				this->dataGridView1->Rows[i]->Cells[4]->Value = _SqlDataReader["draw"]->ToString();
				this->dataGridView1->Rows[i]->Cells[5]->Value = _SqlDataReader["defeat"]->ToString();
				int gz1 = Convert::ToInt16(_SqlDataReader["gz1"]->ToString());
				int gz2 = Convert::ToInt16(_SqlDataReader["gz2"]->ToString());
				int gp1 = Convert::ToInt16(_SqlDataReader["gp1"]->ToString());
				int gp2 = Convert::ToInt16(_SqlDataReader["gp2"]->ToString());
				int win = Convert::ToInt16(_SqlDataReader["win"]->ToString());
				int draw = Convert::ToInt16(_SqlDataReader["draw"]->ToString());
				this->dataGridView1->Rows[i]->Cells[6]->Value = (gz1+gz2).ToString();
				this->dataGridView1->Rows[i]->Cells[7]->Value = (gp1+gp2).ToString();
				this->dataGridView1->Rows[i]->Cells[8]->Value = (gz1+gz2-gp1-gp2).ToString();
				this->dataGridView1->Rows[i]->Cells[9]->Value = (win*3+draw).ToString();
				this->dataGridView1->SortCompare += gcnew DataGridViewSortCompareEventHandler(this,&ChampForm::customSortCompare);
				i++;
			}
			_SqlDataReader->Close();
			delete _SqlDataReader;
		}
	}
	private: System::Void customSortCompare(System::Object ^sender, System::Windows::Forms::DataGridViewSortCompareEventArgs ^e)
	{
		int a1 = 0; Color a;
		if (Int32::TryParse(e->CellValue1->ToString(), a1))
		{
			int a2 = Convert::ToInt16(e->CellValue2->ToString());
			e->SortResult = a1.CompareTo(a2);
			e->Handled = true;
		}
		for (int i = 0; i < this->dataGridView1->RowCount; i++)
		{
			if (i % 2)
				a = Color::AliceBlue;
			else
				a = Color::Aqua;
			for (int j = 0; j < this->dataGridView1->Rows[i]->Cells->Count; j++)
				this->dataGridView1->Rows[i]->Cells[j]->Style->BackColor = a;
			this->dataGridView1->Rows[i]->Cells[0]->Value = i+1;
		}

			
	}
#pragma endregion
	private: System::Void baddt_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		AddTeamsForm ^atf = gcnew AddTeamsForm(ch);
		atf->ShowDialog();
	}
	private: System::Void bRefresh_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Init();
	}
	private: System::Void bAddMatch_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		AddMatchForm ^amf = gcnew AddMatchForm(ch);
		amf->ShowDialog();
	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
}
};
}
