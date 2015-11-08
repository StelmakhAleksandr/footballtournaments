#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Champ
	:public Button
{
public:
	String ^id;
	String ^title;
	Champ();
	~Champ();
};

