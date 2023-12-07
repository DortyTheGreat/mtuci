#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;

namespace DLLPracticumVasilyevBEI2202 {
	public ref class Class1
	{
	public:
		static int n = 0;
		static int* mas = new int[10];
		
		static void Get_Inf();
		static bool Radio_B(RadioButton^ r1, RadioButton^ r2, RadioButton^ r3, int i);
		static bool Check_B(CheckBox^ cb1, CheckBox^ cb2, CheckBox^ cb3, int i);
		static bool Text_B(TextBox^ tb, String^ ans, int i);
		static bool ComboBox_check(ComboBox^ cmb, int i);
		static void Mix_Rb_CHb(RadioButton^ r1, RadioButton^ r2, RadioButton^ r3, CheckBox^ chb1, CheckBox^ chb2, CheckBox^ chb3, CheckBox^ chb4, CheckBox^ chb5, CheckBox^ chb6, CheckBox^ chb7, ListBox^ lb, int i);
		static bool LB_checked(CheckedListBox^ ch_lb, int i);
		static void Trackbar_output(TrackBar^ tb, Label^ l);
		static bool Trackbar_check(TrackBar^ tb, int i);
		static void LB_output(ListBox^ lb1, ListBox^ lb2, int q);
		static bool LB_proverka(ListBox^ lb2, String^ answer, int i);
		static void HSBar_output(HScrollBar^ sb1, Label^ l);
		static bool HSBar(HScrollBar^ sb1, int i);
		static void get_vals(int* arr1, int* arr2, int n);
		static void output_mas(int* arr, int n, DataGridView^ grid);
		static void WriteToWord(int* arr, int n);
		static void txt_input(DataGridView^ grid, String^ path);
		static void delete_question(int* mas, int q);
		// TODO: Добавьте сюда свои методы для этого класса.
	};
}
