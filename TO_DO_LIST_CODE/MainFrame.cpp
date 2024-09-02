#include "MainFrame.h"
#include <wx/wx.h>
#include<vector>
#include<string>
#include "Task.h"

//Trzeba wywo³aæ konstruktor klasy basowej wxFrame()
MainFrame::MainFrame(const wxString& title):wxFrame(nullptr,wxID_ANY,title)
{
	CreateControls();
	SetupSizers();
	BindEventHandlers();
	AddSavedTaska();
	SetBackgroundColour(wxColour(1, 118, 250));
}

void MainFrame::CreateControls()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));
	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	headlineText = new wxStaticText(panel, wxID_ANY, "To-Do List", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);

	headlineText->SetFont(headlineFont);
	//headlineText->SetBackgroundColour(*wxBLUE);

	inputField = new wxTextCtrl(panel, wxID_ANY,"",wxDefaultPosition,wxDefaultSize, wxTE_PROCESS_ENTER);
	addButton = new wxButton(panel, wxID_ANY, "ADD");
	checkList = new wxCheckListBox(panel, wxID_ANY);
	clearButton = new wxButton(panel, wxID_ANY, "Clear");

	


}

void MainFrame::SetupSizers()
{
	
	

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL); //g³ówny zmieniacz rozmiaru
	mainSizer->Add(headlineText, wxSizerFlags().CenterHorizontal());
	mainSizer->AddSpacer(25);

	wxBoxSizer* inputSizer = new wxBoxSizer(wxHORIZONTAL);
	inputSizer->Add(inputField, wxSizerFlags().Proportion(1));// proportional pozwala na rozszerzenie pionowe|
	inputSizer->AddSpacer(10);
	inputSizer->Add(addButton);

	mainSizer->Add(inputSizer, wxSizerFlags().Expand());// pozwala na rozszerzenie poziome -
	mainSizer->AddSpacer(10);
	mainSizer->Add(checkList, wxSizerFlags().Expand().Proportion(1));
	mainSizer->AddSpacer(10);
	mainSizer->Add(clearButton);

	wxGridSizer* outerSizer = new wxGridSizer(1);
	outerSizer->Add(mainSizer, wxSizerFlags().Border(wxALL,25).Expand());

	panel->SetSizer(outerSizer); // uk³ad panelu jest obs³ugiwany przez zmieniacz rozmiaru
	outerSizer->SetSizeHints(this);

}

void MainFrame::BindEventHandlers()
{
	addButton->Bind(wxEVT_BUTTON, &MainFrame::ONAddButtonClicked, this);
	inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::ONInputEnter,this);
	clearButton->Bind(wxEVT_BUTTON, &MainFrame::ONClearButtonClicked, this);
	checkList->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnWindowClosed, this);
}

void MainFrame::AddSavedTaska()
{
	std::vector<Task> tasks = LoadTaskFromFile("tasks.txt");

	for (const Task& task : tasks)
	{
		int index = checkList->GetCount();
		checkList->Insert(task.description, index);
		checkList->Check(index, task.done);
	}

}


void MainFrame::ONAddButtonClicked(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

void MainFrame::ONInputEnter(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

void MainFrame::ONClearButtonClicked(wxCommandEvent& evt)
{
	ClearTaskFromList();
}

void MainFrame::OnListKeyDown(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode())
	{
	case WXK_DELETE:
			DeleteSelectedTask();
			break;

	case WXK_UP:
		MoveSelectedTask(-1);
		break;

	case WXK_DOWN:
		MoveSelectedTask(1);
		break;

	}
}

void MainFrame::OnWindowClosed(wxCloseEvent& evt)
{
	std::vector<Task> tasks;

	for (int i = 0; i < checkList->GetCount(); i++)
	{
		Task task;
		task.description = checkList->GetString(i);
		task.done = checkList->IsChecked(i);
		tasks.push_back(task);

	}

	SaveTaskToFile(tasks,"tasks.txt");
	evt.Skip();

}

void MainFrame::AddTaskFromInput()
{
	wxString description = inputField->GetValue();

	if (!description.IsEmpty())
	{
		checkList->Insert(description, checkList->GetCount());
		inputField->Clear();
	}
	inputField->SetFocus();
}

void MainFrame::ClearTaskFromList()
{
	if (checkList->IsEmpty())
	{
		return;
	}

	wxMessageDialog dialog(this, "Are you sure you want to clear all taksk", "Clear", wxYES_NO | wxCANCEL);
	
	int result = dialog.ShowModal();
	if(result == wxID_YES)

		if (result == wxID_YES)
		{
			checkList->Clear();
		}
	
}

void MainFrame::DeleteSelectedTask()
{
	int selectedIndex = checkList->GetSelection();

	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}

	checkList->Delete(selectedIndex);

}

void MainFrame::MoveSelectedTask(int offset)
{
	int selectedIndex = checkList->GetSelection();

	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}

	int newIndex = selectedIndex + offset;

	if (newIndex >= 0 && newIndex < checkList->GetCount())
	{
		SwapTasks(selectedIndex, newIndex);
		checkList->SetSelection(newIndex, true);
	}
}

void MainFrame::SwapTasks(int i, int j)
{
	Task taskI{ checkList->GetString(i).ToStdString(),checkList->IsChecked(i) };
	Task taskJ{ checkList->GetString(j).ToStdString(),checkList->IsChecked(j) };

	checkList->SetString(i, taskJ.description);
	checkList->Check(i, taskJ.done);

	checkList->SetString(j, taskI.description);
	checkList->Check(j, taskI.done);
}
