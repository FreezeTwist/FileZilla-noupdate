#ifndef FILEZILLA_INTERFACE_FILELIST_STATUSBAR_HEADER
#define FILEZILLA_INTERFACE_FILELIST_STATUSBAR_HEADER

#include "option_change_event_handler.h"

#include <wx/statusbr.h>
#include <wx/timer.h>

#ifdef __WXMAC__
typedef wxStatusBarGeneric CFilelistStatusBarBase;
#else
typedef wxStatusBar CFilelistStatusBarBase;
#endif

class CFilelistStatusBar final : public CFilelistStatusBarBase, public COptionChangeEventHandler
{
public:
	CFilelistStatusBar(wxWindow* pParent);
	~CFilelistStatusBar();

	void SetDirectoryContents(int count_files, int count_dirs, int64_t total_size, int unknown_size, int hidden);
	void Clear();
	void SetHidden(int hidden);
	void TriggerUpdateText();
	void UpdateText();

	void AddFile(int64_t size);
	void RemoveFile(int64_t size);
	void AddDirectory();
	void RemoveDirectory();

	void SelectAll();
	void UnselectAll();
	void SelectFile(int64_t size);
	void UnselectFile(int64_t size);
	void SelectDirectory();
	void UnselectDirectory();

	void SetEmptyString(const wxString& empty);

	void SetConnected(bool connected);
protected:

	virtual void OnOptionsChanged(watched_options const& options);

	bool m_connected{};
	int m_count_files{};
	int m_count_dirs{};
	int64_t m_total_size{};
	int m_unknown_size{}; // Set to true if there are files with unknown size
	int m_hidden{};

	int m_count_selected_files{};
	int m_count_selected_dirs{};
	int64_t m_total_selected_size{};
	int m_unknown_selected_size{}; // Set to true if there are files with unknown size

	wxTimer m_updateTimer;

	wxString m_empty_string;
	wxString m_offline_string;

	DECLARE_EVENT_TABLE()
	void OnTimer(wxTimerEvent& event);
};

#endif
