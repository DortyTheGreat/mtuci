#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

namespace dllkuleshovprojpracsem3 {
	public ref class Functions
	{
		public:
			// TODO: Добавьте сюда свои методы для этого класса.

			static int* answers = new int[10];
			static int question = 1;

			static int GetCheckBoxScore4(CheckBox^ CB1, CheckBox^ CB2, CheckBox^ CB3, CheckBox^ CB4, bool S1, bool S2, bool S3, bool S4);
			static int GetCheckBoxScore3(CheckBox^ CB1, CheckBox^ CB2, CheckBox^ CB3, bool S1, bool S2, bool S3);

			static int GetRadioButtonScore4(RadioButton^ RB1, RadioButton^ RB2, RadioButton^ RB3, RadioButton^ RB4, bool S1, bool S2, bool S3, bool S4);
			static int GetRadioButtonScore3(RadioButton^ RB1, RadioButton^ RB2, RadioButton^ RB3, bool S1, bool S2, bool S3);
			static int GetTextBoxScore(TextBox^ TB, String^ answer);

			static void validate(int call, List<GroupBox^>^ groups);

			static void output_mas(int* mas, int len, DataGridView^ grid);
			static void shakerSort(int* arr, int size);

			literal System::String^ ConnectionString = "Provider=Microsoft.ACE.OLEDB.16.0;Data Source=results.accdb";
			static void CreateAccessDbFile();
			static void CreateAccessDbTables();
			static void FillAccessDb(int* sourceArray, int* transformedArray, int sourceArrayLength, int transformedArrayLength);

			static void zapisExcel(int* mas, int* rezmas, int n, int j);
	};
}
