
#include "MyForm.h"


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <array>
#include <Windows.h>
#include <msclr/marshal.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace PracticeProj;



[STAThreadAttribute]
int main(array<String^>^ argv)
{
	setlocale(LC_ALL, "rus");

	FreeConsole();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	PracticeProj::MyForm frm;
	Application::Run(% frm);
}

// Обработка событыия нажатия главной кнопки
System::Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int txtCount = this->Controls->Count;
	for (int i = 0; i < txtCount; i++)
	{
		if (this->Controls[i]->Name->Contains("TextBox") && String::IsNullOrEmpty(this->Controls[i]->Text)) {
			MessageBox::Show("Усі поля повинні бути заповненими", "Пусте поле", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}
	}
	
	if(IsDigitField(circulationTextBox->Text) == false)
	{
		MessageBox::Show("У полі тиражу можуть бути лише цілі значення", "Невірні дані", MessageBoxButtons::OK, MessageBoxIcon::Error);
		circulationTextBox->Text = "";
		return;
	}

	double price = atof(MyForm::ToCnstChr(priceTextBox->Text));
	if(price <= 0)
	{
		MessageBox::Show("Ви вказали невірне значення ціни", "Невірні дані", MessageBoxButtons::OK, MessageBoxIcon::Error);
		priceTextBox->Text = "";
		return;
	}
	
	Book book;

	book.name = ToCnstChr(nameTextBox->Text);
	book.author = ToCnstChr(nameTextBox->Text);
	book.price = atof(ToCnstChr(priceTextBox->Text));
	book.circulation = atoi(ToCnstChr(circulationTextBox->Text));

	SwapChars(&book);

	FILE* file = fopen("books.txt", "ab");
	fprintf(file, "%s;%s;%.2lf;%s;\n", MyForm::ToCnstChr(nameTextBox->Text), MyForm::ToCnstChr(authorTextBox->Text), price, MyForm::ToCnstChr(circulationTextBox->Text));
	
	char* sus = book.name;
	char* piece = strtok(strdup(sus), " \\/,.-:;|");
	while (piece != NULL) {
		if (strcmp(piece, "С") == 0) {
			comboBox2->Items->Add(gcnew String(sus));
		}

		if (strcmp(piece, "C") == 0) {
			comboBox2->Items->Add(gcnew String(sus));
		}
		piece = strtok(NULL, " \\/,.-:;|");
	}
	fclose(file);



	for (int i = 0; i < txtCount; i++)
	{
		if(this->Controls[i]->Name->Contains("TextBox"))
			MyForm::ClearTextBoxes(this->Controls[i]);
	}

	dataGridView1->Select();
}

System::Void PracticeProj::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	FILE* file = fopen("books.txt", "rb");

	if (String::IsNullOrEmpty(seatchBox->Text)) {
		MessageBox::Show("Поле пошуку пусте, спробуйте ввести назву книги у поле \"Пошук\" ", "Шукана книга", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return System::Void();
	}

	if (!file) {
		MessageBox::Show("Не створено жодного запису!", "Відсутній файл", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}

	char buffer[256];
	char* request = ToCnstChr(seatchBox->Text);

	String^ str = "";

	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		char* part = strtok(strdup(buffer), ";");
		if (strcmp(request, part) == 0) {
			char* token = strtok(buffer, ";");
			while (token != NULL) {
				token = strtok(NULL, ";");
				str = String::Concat(str, gcnew String(token), " ");
			}
		}
	}
	
	if(!String::IsNullOrEmpty(str))
		MessageBox::Show(str, "Знайдено запис", MessageBoxButtons::OK, MessageBoxIcon::Information);
	else if(String::IsNullOrEmpty(str))
		MessageBox::Show(String::Concat("Не знайдено жодного запису за запитом \"", seatchBox->Text, "\""), "Відсутній запис", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	fclose(file);
	seatchBox->Text = "";
}

// Очистка полей
System::Void MyForm::ClearTextBoxes(Control^ textBox)
{
	textBox->Text = "";
}
int PracticeProj::MyForm::CountLines()
{
	int count_lines = 0;

	FILE* fileptr = fopen("books.txt", "rb");
	char chr = getc(fileptr);
	while (chr != EOF)
	{
		//Count whenever new line is encountered
		if (chr == 'n')
		{
			count_lines++;
		}
		//take next character from file.
		chr = getc(fileptr);
	}
	fclose(fileptr);
	return count_lines;
}

// Заполнение comboBox2 названиями книг по языку С
System::Void PracticeProj::MyForm::FillUpCLangComboBox(ComboBox^ comboBox)
{
	FILE* file = fopen("books.txt", "rb");
	int bufferLength = 255;
	if (file == NULL)
	{
		fclose(fopen("books.txt", "wb"));
		file = fopen("books.txt", "rb");
	}
	char line[255];

	while (fgets(line, bufferLength, file)) {
		if (line != NULL) {
			char* pch = strtok(line, ";");
			char* piece = strtok(_strdup(pch), " \\/,.-:;|");
			while (piece != NULL) {
				if (strcmp(piece, "C") == 0) {
					comboBox->Items->Add(gcnew String(pch));
				}

				if (strcmp(piece, "С") == 0) {
					comboBox->Items->Add(gcnew String(pch));
				}
				piece = strtok(NULL, " \\/,.-:;|");
			}
		}
	}
	fclose(file);
}

System::Void PracticeProj::MyForm::FillUpDataGridView(DataGridView^ dataGridView)
{
	FILE* file = fopen("books.txt", "rb");
	int bufferLength = 255;

	char* colmuns[4];

	if (file == NULL)
	{
		fclose(fopen("books.txt", "wb"));
		file = fopen("books.txt", "rb");
	}

	char line[255];
	int j = 0, i, lim = CountLines();
	while (fgets(line, bufferLength, file))
	{
		i = 0;
		char* pch = strtok(line, ";");
		for (; pch;) {
			colmuns[i] = strdup(pch);
			pch = strtok(NULL, ";");
			i++;
		}
		Book book; book.name = colmuns[0]; book.author = colmuns[1]; book.price = atof(colmuns[2]); book.circulation = atoi(colmuns[3]);
		SwapChars(&book);
		j++;
	}
	fclose(file);

}

// Конвертация из common language interface в const char*
char* MyForm::ToCnstChr(String^ str)
{
	msclr::interop::marshal_context oMarshalContext;
	char* ready = _strdup(oMarshalContext.marshal_as<const char*>(str));
	return ready;
}

void PracticeProj::MyForm::FindLineByString(String^ textArg)
{
	FILE* file = fopen("books.txt", "rb");	int bufferLength = 255, lineIndex = 0;
	if (file == NULL)
	{
		fclose(fopen("books.txt", "wb"));
		file = fopen("books.txt", "rb");
	}
	char line[255];
	while (fgets(line, bufferLength, file)) {
		if (strstr(line, ToCnstChr(textArg)) != NULL) {
			return System::Void();
		}
	}
	fclose(file);
}

void PracticeProj::MyForm::SwapChars(Book* book)
{	
	dataGridView1->Rows->Add(gcnew String(book->name), gcnew String(book->author), book->price, book->circulation);
}

// Проверка все ли символы в строке являются цифрами
bool MyForm::IsDigitField(String^ str)
{
	const char* field = MyForm::ToCnstChr(str);
	for(int i = 0; i < strlen(field);i++)
	{
		if(!isdigit(field[i]))
			return false;
	}
	return true;
}

