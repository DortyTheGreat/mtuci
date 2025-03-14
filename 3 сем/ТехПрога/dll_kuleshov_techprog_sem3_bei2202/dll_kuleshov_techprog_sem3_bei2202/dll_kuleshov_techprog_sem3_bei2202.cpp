﻿#include "pch.h"
#include "dll_kuleshov_techprog_sem3_bei2202.h"
#include "Math.h"
#include <cstdlib>
#include <time.h>

using namespace System::Windows::Forms;
using namespace System;
using namespace System::IO;
using namespace System::Data::OleDb;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::Office::Interop;


using namespace System::Globalization;


namespace dll_kuleshov_techprog_sem3_bei2202 {


	double Functions_Class::input(TextBox^ t) {
		return Convert::ToDouble(t->Text);
	}

	void Functions_Class::output(double x, TextBox^ t) {
		t->Text = Convert::ToString(x);
	}

	double Functions_Class::get_Radius(double L) {
		return L / (2 * Math::PI);
	}

	double Functions_Class::get_Area(double L) {
		double S = Math::PI * Math::Pow(get_Radius(L), 2);
		return S;
	}

	void Functions_Class::get_Area_mult(double L1, double& S1, double L2, double& S2, double L3, double& S3) {
		S1 = Functions_Class::get_Area(L1);
		S2 = Functions_Class::get_Area(L2);
		S3 = Functions_Class::get_Area(L3);
	}

	

// ЛР №2
	void Functions_Class::gen_mas(double* mas, int n) {
		srand(time(0));
		for (int i = 0; i < n; i++) {
			mas[i] = ((double)((int)(rand() % 600) - 300)) / 10.0;
		}
	}

	int Functions_Class::count_in_bounds(double* mas, int n) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (mas[i] >= 2 && mas[i] <= 10) {
				count++;
			}
		}
		return count;
	}

	

	void Functions_Class::output_mas(double* mas, int len, DataGridView^ grid) {
		grid->RowCount = 2;
		grid->ColumnCount = len;

		for (int i = 0; i < len; i++)
		{
			grid->Rows[0]->Cells[i]->Value = String::Format("[{0}]", i);
			grid->Rows[1]->Cells[i]->Value = mas[i].ToString("F3");
		}
	}

	

	int Functions_Class::set_mas(double* mas, int n, double* rezmas) {
		int cou = count_in_bounds(mas, n);
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (mas[i] < cou) {
				rezmas[j] = mas[i];
				j++;
			}
		}
		return j;
	}

	// ЛР #3
	

	void Functions_Class::CreateAccessDbFile()
	{
		if (File::Exists(L"1dim_array.accdb"))
			File::Delete(L"1dim_array.accdb");

		ADOX::CatalogClass^ catalog = gcnew ADOX::CatalogClass();
		catalog->Create(ConnectionString);

		Marshal::FinalReleaseComObject(catalog->ActiveConnection);
		Marshal::FinalReleaseComObject(catalog);
	}

	void Functions_Class::CreateAccessDbTables()
	{
		OleDbConnection connection(ConnectionString);
		connection.Open();

		OleDbCommand command(LR"(
        CREATE TABLE [ИсходныйМассив] (
        [Id] LONG NOT NULL PRIMARY KEY,
        [Value] DOUBLE NOT NULL);)", % connection);

		command.ExecuteNonQuery();

		command.CommandText = LR"(
        CREATE TABLE [РезультирующийМассив] (
        [Id] LONG NOT NULL PRIMARY KEY,
        [Value] DOUBLE NOT NULL);)";

		command.ExecuteNonQuery();
	}

	void Functions_Class::FillAccessDb(double* sourceArray, double* transformedArray, int sourceArrayLength, int transformedArrayLength)
	{
		if (!File::Exists(L"1dim_array.accdb"))
			return;

		OleDbConnection connection(ConnectionString);
		connection.Open();

		OleDbCommand command(String::Empty, % connection);

		command.CommandText = L"DELETE FROM [ИсходныйМассив]";
		command.ExecuteNonQuery();

		for (int i = 0; i < sourceArrayLength; ++i)
		{
			command.CommandText = String::Format(LR"(
            INSERT INTO [ИсходныйМассив]
            ([Id], [Value]) VALUES
            ({0}, {1});)", i, sourceArray[i].ToString(CultureInfo::InvariantCulture));

			command.ExecuteNonQuery();
		}

		command.CommandText = L"DELETE FROM [РезультирующийМассив]";
		command.ExecuteNonQuery();

		for (int i = 0; i < transformedArrayLength; ++i)
		{
			command.CommandText = String::Format(LR"(
            INSERT INTO [РезультирующийМассив]
            ([Id], [Value]) VALUES
            ({0}, {1});)", i, transformedArray[i].ToString(CultureInfo::InvariantCulture));

			command.ExecuteNonQuery();
		}
	}

	

	void Functions_Class::FillWordDocument(const double* sourceArray, const double* transformedArray, const int sourceArrayLength, const int transformedArrayLength)
	{
		Object^ typeMissing = Type::Missing;
		Object^ wdWord9TableBehavior = Word::WdDefaultTableBehavior::wdWord9TableBehavior;
		Object^ wdAutoFitContent = Word::WdAutoFitBehavior::wdAutoFitContent;
		Object^ wdGoToLine = Word::WdGoToItem::wdGoToLine;
		Object^ wdGoToLast = Word::WdGoToDirection::wdGoToLast;

		auto wordApplication = gcnew Word::ApplicationClass();
		auto wordDocument = wordApplication->Documents->Add(typeMissing, typeMissing, typeMissing, typeMissing);

		wordDocument->PageSetup->Orientation = Word::WdOrientation::wdOrientLandscape;

		wordDocument->PageSetup->TopMargin = wordApplication->CentimetersToPoints(1.25);
		wordDocument->PageSetup->RightMargin = wordApplication->CentimetersToPoints(1.25);
		wordDocument->PageSetup->BottomMargin = wordApplication->CentimetersToPoints(1.25);
		wordDocument->PageSetup->LeftMargin = wordApplication->CentimetersToPoints(1.25);

		wordApplication->Selection->TypeText(L"Исходный массив:");
		wordApplication->Selection->TypeParagraph();

		auto wordTable = wordDocument->Tables->Add(wordApplication->Selection->Range, 2, sourceArrayLength, wdWord9TableBehavior, wdAutoFitContent);

		for (int i = 0; i < sourceArrayLength; ++i)
		{
			wordTable->Cell(1, i + 1)->Range->InsertAfter(String::Format(L"[{0}]", i));
			wordTable->Cell(2, i + 1)->Range->InsertAfter(sourceArray[i].ToString(L"F3"));
		}

		wordApplication->Selection->GoTo(wdGoToLine, wdGoToLast, typeMissing, typeMissing);
		wordApplication->Selection->TypeParagraph();
		wordApplication->Selection->TypeText(L"Результирующий массив:");
		wordApplication->Selection->TypeParagraph();

		wordTable = wordDocument->Tables->Add(wordApplication->Selection->Range, 2, transformedArrayLength, wdWord9TableBehavior, wdAutoFitContent);

		for (int i = 0; i < transformedArrayLength; ++i)
		{
			wordTable->Cell(1, i + 1)->Range->InsertAfter(String::Format(L"[{0}]", i));
			wordTable->Cell(2, i + 1)->Range->InsertAfter(transformedArray[i].ToString(L"F3"));
		}

		wordDocument->Content->Font->Name = L"Times New Roman";
		wordDocument->Content->Font->Size = 12;

		wordApplication->Selection->GoTo(wdGoToLine, wdGoToLast, typeMissing, typeMissing);
		try {
		Object^ filename = Path::Combine(Directory::GetCurrentDirectory(), L"1dim_array.docx");
		wordDocument->SaveAs(filename, typeMissing,
			typeMissing, typeMissing, typeMissing,
			typeMissing, typeMissing, typeMissing,
			typeMissing, typeMissing, typeMissing,
			typeMissing, typeMissing, typeMissing,
			typeMissing, typeMissing);

		
			wordApplication->Visible = true;
		}
		catch(Exception^ ex){
			
		}
	}

	void Functions_Class::ProstViborSort(double* a, int n) {
		for (int i = 0; i < n - 1; ++i) {
			int k = i;
			double x = a[i];
			for (int j = i + 1; j < n; ++j) {
				if (a[j] < x) {
					k = j;
					x = a[j];
				}
			}
			a[k] = a[i];
			a[i] = x;
		}
	}

	
	void Functions_Class::ProstObmenSort(double* a, int n) {

		bool Flag = 1;
		int m = n - 1;

		while (m > 0 && Flag == 1) {
			Flag = 0;
			for (int i = 0; i < m; ++i) {
				if (a[i] > a[i + 1]) {
					double x = a[i];
					a[i] = a[i + 1];
					a[i + 1] = x;
					Flag = 1;
				}
			}
			--m;
		}
	}

	void Functions_Class::zapisExcel(double* mas, double* rezmas, int n, int j)
	{
		auto XL = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
		XL->Visible = true;
		Object^ t = Type::Missing;
		auto Workbook = XL->Workbooks->Add(t);
		String^ str;
		XL->Cells[1, 1] = "Исходный массив";
		for (int i = 0; i < n; i++)
		{
			XL->Cells[2, i + 1] = Convert::ToString(i);
			XL->Cells[3, i + 1] = Convert::ToString(mas[i]);
		}
		XL->Cells[5, 1] = "Результирующий массив"; 
		for (int i = 0; i < j; i++)
		{
			XL->Cells[6, i + 1] = Convert::ToString(i);
			XL->Cells[7, i + 1] = Convert::ToString(rezmas[i]);
		}
	}

	// ЛР №2
	void Functions_Class::gen_matrix(int** matr, int n, int m) {
		srand(time(0));
		for (int i = 0; i < n; i++) {
			matr[i] = new int[m];
			for (int j = 0; j < m; j++) {
				matr[i][j] = (int)(rand() % 60) - 30;
			}
		}
	
	}

	void Functions_Class::clear(int** mas, int n) {
		for (int i = 0; i < n; i++) {
			delete[](mas[i]);
		}
		delete[] mas;
	}

	void Functions_Class::output_matr(int** matr, int n, int m, DataGridView^ grid) {
		grid->ColumnCount = m + 1;
		grid->RowCount = n + 1;
		grid->Rows[0]->Cells[0]->Value = "[" + n + "]" + "[" + m + "]";
		for (int i = 0; i < n; i++) {
			grid->Rows[i + 1]->Cells[0]->Value = "[" + i + "]";
		}
		for (int j = 0; j < m; j++) {
			grid->Rows[0]->Cells[j + 1]->Value = "[" + j + "]";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				grid->Rows[i + 1]->Cells[j + 1]->Value = matr[i][j];
			}
		}
		int width = 0, height = 0;
		//Настройка ширины DataGridView
		for (int s = 0; s < grid->ColumnCount; s++) {
			width += grid->Columns[s]->Width;
		}
		if (width > 200 + 10)
			grid->Width = 200;
		else
			grid->Width = width + 10;

		for (int q = 0; q < grid->RowCount; q++) {
			height += grid->Rows[q]->Height;
		}
		if (height > 200 + 10)
			grid->Height = 200;
		else
			grid->Height = height + 10;

	}

	double Functions_Class::get_mean(int** matr, int n, int m) {
		double sum = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) > n && (matr[i][j] % 2 == 0)) {
					sum += matr[i][j];
					count += 1;
				}
			}
		}
		return sum / count;
	}

	int Functions_Class::create_array_7(int** matr, int n, int m, int* arr) {
		int h = 0;
		double mean = get_mean(matr, n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matr[i][j] > mean) {
					arr[h++] = matr[i][j];
				}
			}
		}
		return h;
	}

	void Functions_Class::output_mas(int* mas, int len, DataGridView^ grid) {
		grid->RowCount = 2;
		grid->ColumnCount = len;

		for (int i = 0; i < len; i++)
		{
			grid->Rows[0]->Cells[i]->Value = String::Format("[{0}]", i);
			grid->Rows[1]->Cells[i]->Value = mas[i].ToString();
		}
	}
}