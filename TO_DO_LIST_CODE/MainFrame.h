#pragma once
#include <wx/wx.h>


class MainFrame: public wxFrame
{
public:

	MainFrame(const wxString& title);

private:

	void CreateControls();
	void SetupSizers();
	void BindEventHandlers();
	void AddSavedTaska();

	void ONAddButtonClicked(wxCommandEvent& evt);
	void ONInputEnter(wxCommandEvent& evt);
	void ONClearButtonClicked(wxCommandEvent& evt);
	void OnListKeyDown(wxKeyEvent& evt);
	void OnWindowClosed(wxCloseEvent& evt);

	void AddTaskFromInput();
	void ClearTaskFromList();
	void DeleteSelectedTask();
	void MoveSelectedTask(int offset);
	void SwapTasks(int t, int j);

	
		wxPanel* panel;
		wxStaticText* headlineText;
		wxTextCtrl* inputField;
		wxButton* addButton;
		wxCheckListBox* checkList;
		wxButton* clearButton;
	


};

