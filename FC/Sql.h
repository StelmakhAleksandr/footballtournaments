#pragma once
using namespace System;
using namespace System::Windows::Forms;
ref class mySql
{
public:
	//static String^ sConnect = gcnew String("Data Source=(LocalDb)\\v11.0;Initial Catalog=master;Integrated Security=True;");
	static String^ sConnect = gcnew String("Data Source=(LocalDb)\\v11.0;Initial Catalog=\"" + Application::StartupPath->ToString() + "\\mydbData.mdf\"; Integrated Security = True");
	static System::Data::SqlClient::SqlDataReader ^GetSqlDataReader(System::String ^_ConnectionString, System::String ^_SQL)
	{
		System::Data::SqlClient::SqlDataReader ^_SqlDataReader = nullptr;
		System::Data::SqlClient::SqlConnection ^_SqlConnection = gcnew System::Data::SqlClient::SqlConnection();
		_SqlConnection->ConnectionString = _ConnectionString;
		try
		{
			_SqlConnection->Open();
		}
		catch (Exception ^_Exception)
		{
			MessageBox::Show(_Exception->Message);
			return nullptr;
		}
		try
		{
			System::Data::SqlClient::SqlCommand ^_SqlCommand = gcnew System::Data::SqlClient::SqlCommand(_SQL, _SqlConnection);
			_SqlDataReader = _SqlCommand->ExecuteReader();
		}
		catch (Exception ^_Exception)
		{
			MessageBox::Show(_Exception->Message);
			return nullptr;
		}
		return _SqlDataReader;
	}
	mySql();
};

