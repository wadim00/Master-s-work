//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Unit1.cpp", BetcherForm);
USEFORM("groupedItems.cpp", GridForm);
USEFORM("itemDetail.cpp", DetailForm);
USEFORM("Unit2.cpp", StructForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->UseMetropolisUI();
		TStyleManager::TrySetStyle("Obsidian");
		Application->Title = "Metropolis UI Application";
		Application->CreateForm(__classid(TGridForm), &GridForm);
		Application->CreateForm(__classid(TDetailForm), &DetailForm);
		Application->CreateForm(__classid(TBetcherForm), &BetcherForm);
		Application->CreateForm(__classid(TStructForm), &StructForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
