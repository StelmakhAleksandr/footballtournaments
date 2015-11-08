#pragma once

namespace FC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddChampForm
	/// </summary>
	public ref class AddChampForm : public System::Windows::Forms::Form
	{
	public:
		AddChampForm()
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
		~AddChampForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lcname;
	protected:
	private: System::Windows::Forms::TextBox^  tcname;
	private: System::Windows::Forms::Label^  lctype;
	private: System::Windows::Forms::ComboBox^  cctype;
	private: System::Windows::Forms::Button^  badd;

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
			this->lcname = (gcnew System::Windows::Forms::Label());
			this->tcname = (gcnew System::Windows::Forms::TextBox());
			this->lctype = (gcnew System::Windows::Forms::Label());
			this->cctype = (gcnew System::Windows::Forms::ComboBox());
			this->badd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lcname
			// 
			this->lcname->AutoSize = true;
			this->lcname->Location = System::Drawing::Point(12, 21);
			this->lcname->Name = L"lcname";
			this->lcname->Size = System::Drawing::Size(60, 13);
			this->lcname->TabIndex = 0;
			this->lcname->Text = L"Название:";
			// 
			// tcname
			// 
			this->tcname->Location = System::Drawing::Point(78, 18);
			this->tcname->Name = L"tcname";
			this->tcname->Size = System::Drawing::Size(155, 20);
			this->tcname->TabIndex = 1;
			// 
			// lctype
			// 
			this->lctype->AutoSize = true;
			this->lctype->Location = System::Drawing::Point(0, 63);
			this->lctype->Name = L"lctype";
			this->lctype->Size = System::Drawing::Size(72, 13);
			this->lctype->TabIndex = 2;
			this->lctype->Text = L"Тип турнира:";
			// 
			// cctype
			// 
			this->cctype->FormattingEnabled = true;
			this->cctype->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Лига", L"Кубок" });
			this->cctype->Location = System::Drawing::Point(78, 60);
			this->cctype->Name = L"cctype";
			this->cctype->Size = System::Drawing::Size(155, 21);
			this->cctype->TabIndex = 3;
			// 
			// badd
			// 
			this->badd->Location = System::Drawing::Point(87, 183);
			this->badd->Name = L"badd";
			this->badd->Size = System::Drawing::Size(75, 23);
			this->badd->TabIndex = 4;
			this->badd->Text = L"Добавить";
			this->badd->UseVisualStyleBackColor = true;
			this->badd->Click += gcnew System::EventHandler(this, &AddChampForm::badd_Click);
			// 
			// AddChampForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(247, 218);
			this->Controls->Add(this->badd);
			this->Controls->Add(this->cctype);
			this->Controls->Add(this->lctype);
			this->Controls->Add(this->tcname);
			this->Controls->Add(this->lcname);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddChampForm";
			this->Text = L"Добавить Турнир";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void badd_Click(System::Object^  sender, System::EventArgs^  e);
};
}
