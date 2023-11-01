﻿#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace dll_kuleshov_techprog_sem3_bei2202 {
	public ref class Functions_Class
	{
		public:
			// ЛР #1

			static double input(TextBox^ t);
			static void output(double x, TextBox^ t);

			static double get_Radius(double L);
			static double get_Area(double L);

			static void get_Area_mult(double L1, double& S1, double L2, double& S2, double L3, double& S3);

			// ЛР #2
			static void gen_mas(double* mas, int n);
			static void output_mas(double* mas, int len, DataGridView^ grid);

			static int count_in_bounds(double* mas, int n);
			static int set_mas(double* mas, int n, double* rezmas);

			// ЛР #3
			literal System::String^ ConnectionString = "Provider=Microsoft.ACE.OLEDB.16.0;Data Source=1dim_array.accdb";
			static void CreateAccessDbFile();

			static void CreateAccessDbTables();

			static void FillAccessDb(const double* sourceArray, const double* transformedArray, int sourceArrayLength, int transformedArrayLength);
	};
}
