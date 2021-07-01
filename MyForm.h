#pragma once

#ifndef MYFORM_H
#define MYFORM_H
namespace PracticeProj {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct Book 
	{
		char* name;
		char* author;
		float price;
		int circulation;
	};

	public ref class MyForm : public System::Windows::Forms::Form
	{
#pragma region MyForm generated props
	public:
		MyForm(void)
		{
			InitializeComponent();

			FillUpCLangComboBox(comboBox2);
			FillUpDataGridView(dataGridView1);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label1;
	internal: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::TextBox^ authorTextBox;
	private: System::Windows::Forms::TextBox^ priceTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ circulationTextBox;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameColmun;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ authorColmun;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ priceColmun;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ circulationColmun;
	private: System::Windows::Forms::TextBox^ seatchTextBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	internal: System::ComponentModel::Container^ components;
#pragma endregion

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->authorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->priceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->circulationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->nameColmun = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->authorColmun = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->priceColmun = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->circulationColmun = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->seatchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(897, 504);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Создать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(32, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 26);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Книжки з С";
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(32, 38);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(356, 24);
			this->comboBox2->Sorted = true;
			this->comboBox2->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->CausesValidation = false;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label2->Location = System::Drawing::Point(732, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 23);
			this->label2->TabIndex = 31;
			this->label2->Text = L"Назва";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->CausesValidation = false;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label4->Location = System::Drawing::Point(730, 67);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 23);
			this->label4->TabIndex = 33;
			this->label4->Text = L"Вартість";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->nameTextBox->Location = System::Drawing::Point(820, 94);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(247, 37);
			this->nameTextBox->TabIndex = 27;
			// 
			// authorTextBox
			// 
			this->authorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->authorTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->authorTextBox->Location = System::Drawing::Point(820, 135);
			this->authorTextBox->Name = L"authorTextBox";
			this->authorTextBox->Size = System::Drawing::Size(247, 37);
			this->authorTextBox->TabIndex = 28;
			// 
			// priceTextBox
			// 
			this->priceTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->priceTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->priceTextBox->Location = System::Drawing::Point(820, 53);
			this->priceTextBox->Name = L"priceTextBox";
			this->priceTextBox->Size = System::Drawing::Size(247, 37);
			this->priceTextBox->TabIndex = 29;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->CausesValidation = false;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label3->Location = System::Drawing::Point(732, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 23);
			this->label3->TabIndex = 32;
			this->label3->Text = L"Автор";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->CausesValidation = false;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label5->Location = System::Drawing::Point(730, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 23);
			this->label5->TabIndex = 34;
			this->label5->Text = L"Тираж";
			// 
			// circulationTextBox
			// 
			this->circulationTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->circulationTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->circulationTextBox->Location = System::Drawing::Point(820, 12);
			this->circulationTextBox->Name = L"circulationTextBox";
			this->circulationTextBox->Size = System::Drawing::Size(247, 37);
			this->circulationTextBox->TabIndex = 30;
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->nameColmun,
					this->authorColmun, this->priceColmun, this->circulationColmun
			});
			this->dataGridView1->Location = System::Drawing::Point(32, 178);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1035, 320);
			this->dataGridView1->TabIndex = 26;
			// 
			// nameColmun
			// 
			this->nameColmun->HeaderText = L"Назва";
			this->nameColmun->MinimumWidth = 6;
			this->nameColmun->Name = L"nameColmun";
			// 
			// authorColmun
			// 
			this->authorColmun->HeaderText = L"Автор";
			this->authorColmun->MinimumWidth = 6;
			this->authorColmun->Name = L"authorColmun";
			// 
			// priceColmun
			// 
			this->priceColmun->HeaderText = L"Вартість грн.";
			this->priceColmun->MinimumWidth = 6;
			this->priceColmun->Name = L"priceColmun";
			// 
			// circulationColmun
			// 
			this->circulationColmun->HeaderText = L"Тираж";
			this->circulationColmun->MinimumWidth = 6;
			this->circulationColmun->Name = L"circulationColmun";
			// 
			// seatchTextBox
			// 
			this->seatchTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->seatchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->seatchTextBox->Location = System::Drawing::Point(439, 38);
			this->seatchTextBox->Name = L"seatchTextBox";
			this->seatchTextBox->Size = System::Drawing::Size(247, 37);
			this->seatchTextBox->TabIndex = 35;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->CausesValidation = false;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label6->Location = System::Drawing::Point(525, 12);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 23);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Пошук";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button2->Location = System::Drawing::Point(580, 102);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 31);
			this->button2->TabIndex = 37;
			this->button2->Text = L"Знайти";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(1100, 553);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->seatchTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->authorTextBox);
			this->Controls->Add(this->priceTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->circulationTextBox);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"BookUs";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		System::Void FillUpCLangComboBox(ComboBox^ comboBox);
		System::Void FillUpDataGridView(DataGridView^ dataGridView);
	private:
		// Сгенерировать запись
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void ClearTextBoxes(Control^ textBox);

		int CountLines();

		bool IsDigitField(String^ str);
		char* ToCnstChr(String^ str);

		void FindLineByString(String^ textArg);
		void SwapChars(Book* book);
};
};

#endif
