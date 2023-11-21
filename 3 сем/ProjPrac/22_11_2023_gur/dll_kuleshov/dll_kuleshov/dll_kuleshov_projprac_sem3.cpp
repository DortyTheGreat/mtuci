#include "pch.h"

#include "dll_kuleshov_projprac_sem3.h"

using namespace System::Windows::Forms;
using namespace System;
using namespace Microsoft::Office::Interop;


using namespace System::Globalization;

using namespace System::Windows::Forms;
using namespace System;
using namespace System::IO;
using namespace System::Data::OleDb;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::Office::Interop;


using namespace System::Globalization;

namespace dllkuleshovprojpracsem3 {
	int Functions::GetCheckBoxScore4(CheckBox^ CB1, CheckBox^ CB2, CheckBox^ CB3, CheckBox^ CB4, bool S1, bool S2, bool S3, bool S4) {
		int ans = 0;
		if (!CB1->Checked && !CB2->Checked && !CB3->Checked && !CB4->Checked) return -1; // Вопрос не был выбран
		return (CB1->Checked == S1 && CB2->Checked == S2 && CB3->Checked == S3 && CB4->Checked == S4);
	}

	int Functions::GetCheckBoxScore3(CheckBox^ CB1, CheckBox^ CB2, CheckBox^ CB3, bool S1, bool S2, bool S3) {
		int ans = 0;
		if (!CB1->Checked && !CB2->Checked && !CB3->Checked) return -1; // Вопрос не был выбран
		return (CB1->Checked == S1 && CB2->Checked == S2 && CB3->Checked == S3);
	}

	int Functions::GetRadioButtonScore4(RadioButton^ RB1, RadioButton^ RB2, RadioButton^ RB3, RadioButton^ RB4, bool S1, bool S2, bool S3, bool S4) {
		if (!RB1->Checked && !RB2->Checked && !RB3->Checked && !RB4->Checked) return -1; // Вопрос не был выбран
		return (RB1->Checked == S1 && RB2->Checked == S2 && RB3->Checked == S3 && RB4->Checked == S4);
	}

	int Functions::GetRadioButtonScore3(RadioButton^ RB1, RadioButton^ RB2, RadioButton^ RB3, bool S1, bool S2, bool S3) {
		if (!RB1->Checked && !RB2->Checked && !RB3->Checked)  return -1; // Вопрос не был выбран
		return (RB1->Checked == S1 && RB2->Checked == S2 && RB3->Checked == S3 );
	}

	int Functions::GetTextBoxScore(TextBox^ TB, String^ answer) {
		if (TB->Text->Length == 0) return -1;
		return TB->Text == answer;
	}

	void Functions::validate(int call, List<GroupBox^>^ groups) {
		if (call == -1) {
			MessageBox::Show("Вы не ответили на вопрос", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			answers[question - 1] = call;
			groups[question - 1]->Visible = false;
			question++;
			if (question != 11)
				groups[question - 1]->Visible = true;
		}
	}

	void Functions::output_mas(int* mas, int len, DataGridView^ grid) {
		grid->RowCount = 2;
		grid->ColumnCount = len;

		for (int i = 0; i < len; i++)
		{
			grid->Rows[0]->Cells[i]->Value = String::Format("[{0}]", i);
			grid->Rows[1]->Cells[i]->Value = mas[i].ToString();
		}
	}

	void Functions::shakerSort(int* arr, int size) {
		bool swapped = true;
		int start = 0;
		int end = size - 1;

		while (swapped) {
			swapped = false;
			int t;
			for (int i = start; i < end; ++i) {
				if (arr[i] > arr[i + 1]) {
					t = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = t;
					swapped = true;
				}
			}

			if (!swapped) {
				break;
			}

			swapped = false;
			--end;

			for (int i = end - 1; i >= start; --i) {
				if (arr[i] > arr[i + 1]) {
					t = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = t;
					swapped = true;
				}
			}

			++start;
		}
	}

	void Functions::CreateAccessDbFile()
	{
		if (File::Exists(L"1dim_array.accdb"))
			File::Delete(L"1dim_array.accdb");

		ADOX::CatalogClass^ catalog = gcnew ADOX::CatalogClass();
		catalog->Create(ConnectionString);

		Marshal::FinalReleaseComObject(catalog->ActiveConnection);
		Marshal::FinalReleaseComObject(catalog);
	}

	void Functions::CreateAccessDbTables()
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

	void Functions::FillAccessDb(int* sourceArray, int* transformedArray, int sourceArrayLength, int transformedArrayLength)
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

	void Functions::zapisExcel(int* mas, int* rezmas, int n, int j)
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

}