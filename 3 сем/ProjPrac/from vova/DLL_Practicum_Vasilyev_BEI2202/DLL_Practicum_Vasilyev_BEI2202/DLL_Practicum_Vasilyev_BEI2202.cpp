#include "pch.h"

#include "DLL_Practicum_Vasilyev_BEI2202.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;
using namespace Microsoft::Office::Interop;

namespace DLLPracticumVasilyevBEI2202 {
	void Class1::Get_Inf() {
		Process::Start("https://1drv.ms/w/s!ArcgnvUgitDSrRstzz4CTYBwb66A?e=vSxBOa");
	}
	bool Class1::Radio_B(RadioButton^ r1, RadioButton^ r2, RadioButton^ r3, int i) {
		if (!(r1->Checked) && !(r2->Checked) && !(r3->Checked)){
			MessageBox::Show("Надо ответить на вопрос!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return false;
		}
		else {
			if (r1->Checked) {
				MessageBox::Show("Верно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				n++;
				mas[i] = 1;
			}
			else {
				MessageBox::Show("Неверно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				mas[i] = 0;
			}
			return true;
		}
	}
	bool Class1::Text_B(TextBox^ tb, String^ ans, int i) {
		if (tb->Text == "") {
			MessageBox::Show("Надо ответить на вопрос!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return false;
		}
		else {
			if (tb->Text->ToLower() == ans) {
				MessageBox::Show("Верно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				n++;
				mas[i] = 1;
			}
			else {
				MessageBox::Show("Неверно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				mas[i] = 0;
			}
			return true;
		}
	}
	bool Class1::Check_B(CheckBox^ cb1, CheckBox^ cb2, CheckBox^ cb3, int i) {
		if (!(cb1->Checked) && !(cb2->Checked) && !(cb3->Checked)) {
			MessageBox::Show("Надо ответить на вопрос!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return false;
		}
		else {
			if (cb1->Checked && cb2->Checked) {
				MessageBox::Show("Верно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				n++;
				mas[i] = 1;
			}
			else {
				MessageBox::Show("Неверно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				mas[i] = 0;
			}
			return true;
		}
	}
	void Class1::Mix_Rb_CHb(RadioButton^ r1, RadioButton^ r2, RadioButton^ r3, CheckBox^ chb1, CheckBox^ chb2, CheckBox^ chb3, CheckBox^ chb4, CheckBox^ chb5, CheckBox^ chb6, CheckBox^ chb7, ListBox^ lb, int i) {
		bool f1 = false, f2 = false, f3 = false;

		lb->Items->Clear();
		lb->Items->Add("Размер блока:");
		if (!(r1->Checked) && !(r2->Checked) && !(r3->Checked)) {
			lb->Items->Add("Вы не ввели размер блока");
		}
		else {
			if (r1->Checked) {
				lb->Items->Add(r1->Text);
				f1 = true;
			}
			else {
				if (r2->Checked) 
					lb->Items->Add(r2->Text);
				else
					lb->Items->Add(r3->Text);
			}
		}

		lb->Items->Add(" ");
		lb->Items->Add("Длина ключа:");
		if (!(chb1->Checked) && !(chb2->Checked) && !(chb3->Checked)) {
			lb->Items->Add("Вы не ввели длину ключа");
		}
		else {
			if (chb1->Checked) {
				lb->Items->Add(chb1->Text);
			}
			if (chb2->Checked) {
				lb->Items->Add(chb2->Text);
			}
			if (chb3->Checked) {
				lb->Items->Add(chb3->Text);
			}
			if ((chb1->Checked) && (chb2->Checked) && (chb3->Checked)) {
				f2 = true;
			}
		}

		lb->Items->Add(" ");
		lb->Items->Add("Количество раундов:");
		if (!(chb4->Checked) && !(chb5->Checked) && !(chb6->Checked) && !(chb7->Checked)) {
			lb->Items->Add("Вы не ввели количество раундов");
		}
		else {
			if (chb4->Checked) {
				lb->Items->Add(chb4->Text);
			}
			if (chb5->Checked) {
				lb->Items->Add(chb5->Text);
			}
			if (chb6->Checked) {
				lb->Items->Add(chb6->Text);
			}
			if (chb7->Checked) {
				lb->Items->Add(chb7->Text);
			}
			if ((chb4->Checked) && (chb5->Checked) && (chb6->Checked) && !(chb7->Checked)) {
				f3 = true;
			}
		}

		if (f1 && f2 && f3) {
			MessageBox::Show("Правильно!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			n++;
			mas[i] = 1;
		}
		else {
			MessageBox::Show("Неправильно!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			mas[i] = 0;
		}
	}
	bool Class1::LB_checked(CheckedListBox^ ch_lb, int i) {
		if (ch_lb->CheckedItems->Count == 0) {
			MessageBox::Show("Надо ответить на вопрос!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return false;
		}
		else
		{
			if (ch_lb->CheckedIndices->Contains(0) && ch_lb->CheckedIndices->Contains(1) && ch_lb->CheckedIndices->Contains(2) && ch_lb->CheckedIndices->Contains(3) && ch_lb->CheckedIndices->Count == 4) {
				MessageBox::Show("Верно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				n++;
				mas[i] = 1;
			}
			else {
				MessageBox::Show("Неверно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				mas[i] = 0;
			}
			return true;
		}
	}
	void Class1::Trackbar_output(TrackBar^ tb, Label^ l) {
		if (tb->Value == 1) {
			l->Text = "Ваш ответ: ECB";
		}
		if (tb->Value == 2) {
			l->Text = "Ваш ответ: ABC";
		}
		if (tb->Value == 3) {
			l->Text = "Ваш ответ: BEC";
		}
		if (tb->Value == 4) {
			l->Text = "Ваш ответ: DGH";
		}
	}
	bool Class1::Trackbar_check(TrackBar^ tb, int i) {
		if (tb->Value == 1) {
			MessageBox::Show("Верно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			n++;
			mas[i] = 1;
		}
		else {
			MessageBox::Show("Неверно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			mas[i] = 0;
		}
		return true;
	}
	void Class1::LB_output(ListBox^ lb1, ListBox^ lb2, int q) {
		for (int i = 0; i < q; i++) {
			if (lb1->SelectedIndex == i) {
				lb2->Items->Add(lb1->SelectedItem);
				lb1->Items->RemoveAt(i);
			}
		}
	}
	bool Class1::LB_proverka(ListBox^ lb2, String^ answer, int i) {
		if (lb2->Items->Count == 0) {
			MessageBox::Show("Надо ответить на вопрос!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return false;
		}
		else {
			if ((lb2->Items[0] == answer)) {
				MessageBox::Show("Верно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				n++;
				mas[i] = 1;
			}
			else {
				MessageBox::Show("Неверно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				mas[i] = 0;
			}
			return true;
		}
	}
	void Class1::HSBar_output(HScrollBar^ sb1, Label^ l) {
		if (sb1->Value <= 25) {
			l->Text = "Ваш ответ: Сладкие";
		}
		else if (sb1->Value <= 50) {
			l->Text = "Ваш ответ: Красные";
		}
		else if (sb1->Value <= 75) {
			l->Text = "Ваш ответ: Невидимые";
		}
		else {
			l->Text = "Ваш ответ: Ядовитые";
		}
	}
	bool Class1::HSBar(HScrollBar^ sb1, int i) {
		if ((sb1->Value <= 75) && (sb1->Value > 50)) {
			MessageBox::Show("Верно! Идем дальше!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			n++;
			mas[i] = 1;
		}
		else {
			MessageBox::Show("Неверно! Идем дальше!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			mas[i] = 0;
		}
		return true;
	}
	bool Class1::ComboBox_check(ComboBox^ cmb, int i) {
		if (cmb->SelectedIndex == -1) {
			MessageBox::Show("Надо ответить на вопрос!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return false;
		}
		else {
			if (cmb->SelectedIndex == 1) {
				MessageBox::Show("Верно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				n++;
				mas[i] = 1;
			}
			else {
				MessageBox::Show("Неверно! Переходим к следующему вопросу!", "Тест", MessageBoxButtons::OK, MessageBoxIcon::Information);
				mas[i] = 0;
			}
			return true;
		}
	}
	//Вывод массива в элемент формы DataGridView
	void Class1::output_mas(int* arr, int n, DataGridView^ grid) {
		grid->ColumnCount = n;
		grid->RowCount = 2;
		for (int i = 0; i < n; i++) {
			int j = i + 1;
			grid->Rows[0]->Cells[i]->Value = "[" + j + "]";
			grid->Rows[1]->Cells[i]->Value = arr[i];
		}
		int width = 0;
		//Настройка ширины DataGridView
		for (int s = 0; s < grid->ColumnCount; s++) {
			width += grid->Columns[s]->Width;
			if (width > 350)
				grid->Width = 350;
			else
				grid->Width = width + 10;
		}
	}
	void Class1::WriteToWord(int* arr1, int n)
	{
		auto Wrd = gcnew Microsoft::Office::Interop::Word::ApplicationClass();
		Wrd->Visible = true;
		auto inf = Type::Missing;
		String^ str;
		auto Doc = Wrd->Documents->Add(inf, inf, inf, inf);
		Wrd->Selection->TypeText("Массив ответов");
		Wrd->Selection->TypeParagraph();
		Object^ t1 = Microsoft::Office::Interop::Word::WdDefaultTableBehavior::wdWord9TableBehavior;
		Object^ t2 = Microsoft::Office::Interop::Word::WdAutoFitBehavior::wdAutoFitContent;
		Wrd->Selection->TypeParagraph();
		Wrd->Selection->TypeParagraph();
		Microsoft::Office::Interop::Word::Table^ tbl = Wrd->ActiveDocument->Tables->Add(Wrd->ActiveDocument->Paragraphs[2]->Range, 2, n, t1, t2);
		for (int i = 0; i < n; i++)
		{
			tbl->Cell(1, i + 1)->Range->InsertAfter("[" + Convert::ToString(i) + "]");
			str = String::Format("{0:f0}", arr1[i]);
			tbl->Cell(2, i + 1)->Range->InsertAfter(str);
		}
	}
	void Class1::delete_question(int* mas, int q) {
		for (int i = q+1; i < 10; i++) {
			mas[i - 1] = mas[i];
		}
	}
	void Class1::get_vals(int* arr1, int* arr2, int n) {
		for (int i = 0; i < n; i++)
			arr2[i] = arr1[i];
	}

	void Class1::txt_input(DataGridView^ grid, String^ path){
		try
		{
			auto fk = System::Text::Encoding::GetEncoding(1251);
			auto sw = gcnew IO::StreamWriter(path, false, fk);
			for (int i = 0; i < grid->ColumnCount; i++)
			{
				String^ q = Convert::ToString(i + 1);
				String^ ans = Convert::ToString(grid->Rows[1]->Cells[i]->Value);

				sw->WriteLine(q + ")  " + ans);
			}
			sw->Close();
			delete sw;
			MessageBox::Show("Произошла запись в текстовый файл. Путь: Practicum_Forms_Vasilyev_BEI2202\\Practicum_Forms_Vasilyev_BEI2202\\" + path, "Запись в txt", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^ E)
		{
			MessageBox::Show("Произошла ошибка записи", "Ошибка");
		}
	}


}