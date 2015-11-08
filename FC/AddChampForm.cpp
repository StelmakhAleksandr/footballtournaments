#include "AddChampForm.h"
#include "mainForm.h"
using namespace FC;

System::Void AddChampForm::badd_Click(System::Object^  sender, System::EventArgs^  e)
{
	mySql::GetSqlDataReader(mySql::sConnect, "INSERT INTO Champs(title,ctype)VALUES('"+this->lcname->Text+"',"+this->cctype->SelectedIndex+")");
	this->Close();
}