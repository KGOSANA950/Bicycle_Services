#include "Bicycle.h"
#include "Sale.h"
#include "frmMain.h"


using namespace System;
using namespace BicycleServices;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	frmMain^ main = gcnew frmMain;
	Application::Run(main);

	return 0;
}
